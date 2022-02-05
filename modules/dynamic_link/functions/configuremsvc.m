%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% This program is free software; you can redistribute it and/or
% modify it under the terms of the GNU Lesser General Public
% License as published by the Free Software Foundation; either
% version 2.1 of the License, or (at your option) any later version.
%
% Alternatively, you can redistribute it and/or
% modify it under the terms of the GNU General Public License as
% published by the Free Software Foundation; either version 2 of
% the License, or (at your option) any later version.
%
% This program is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU Lesser General Public License for more details.
%
% You should have received a copy of the GNU Lesser General Public
% License along with this program. If not, see <http://www.gnu.org/licenses/>.
% LICENCE_BLOCK_END
%=============================================================================
function [status, message] = configuremsvc()
  % currently only VS 2017, VS 2019 and VS 2022
  status = false;
  message = '';
  clear('havecompiler');  % clear persistent variable
  if ~ispc()
    status = false;
    message = _('Not implemented on this platform.');
    return
  end
  try
    vsjon = vswhere();
    status = true;
  catch
    e = lasterror();
    message = e.message;
    return
  end

  if startsWith(vsjon.installationVersion, '17.')
    vsconfig = [modulepath('dynamic_link'), '/resources/msvc2022.json'];
  elseif startsWith(vsjon.installationVersion, '16.')
    vsconfig = [modulepath('dynamic_link'), '/resources/msvc2019.json'];
  else
    vsconfig = [modulepath('dynamic_link'), '/resources/msvc2017.json'];
  end
  [status, message] = checkExistFile(vsconfig);
  if ~status
    return
  end
  txt = fileread(vsconfig);
  msvc201X = jsondecode(txt);

  vsinfo_batch = [modulepath('dynamic_link'), '/resources/vcinfo.bat'];
  arch = computer('arch');
  vcvarsbatpath = [vsjon.installationPath,'/VC/Auxiliary/Build'];
  if strcmp(arch, 'win64')
    vcvarsbat = 'vcvars64.bat';
  else
    vcvarsbat = 'vcvars32.bat';
  end
  vcvarsbatfullfilename = [vcvarsbatpath, '/', vcvarsbat];
  vcinfo_batchpath = [modulepath('dynamic_link'), '/resources'];
  vcinfo_batch = 'vcinfo.bat';
  vcinfo_batchfullfilename = [vcinfo_batchpath, '/', vcinfo_batch];
  [status, message] = checkExistFile(vcinfo_batchfullfilename);
  if ~status
    return
  end
  [status, message] = checkExistFile(vcvarsbatfullfilename);
  if ~status
    return
  end
  current_PATH = getenv('PATH');
  if ~contains(current_PATH, vcvarsbatpath)
    setenv('PATH', [current_PATH, ';', vcvarsbatpath]);
  end
  if ~contains(getenv('PATH'), vcinfo_batchpath)
    setenv('PATH', [getenv('PATH'), ';', vcinfo_batchpath]);
  end
  names = {};
  values = {};
  for k = msvc201X.ENVIRONMENT_VARIABLES(:)'
    cmd = [vcinfo_batch, ' ', vcvarsbat, ' ', k{1}];
    [s, m] = unix(cmd);
    if (s ~= 0)
      status = false;
      message = [k{1}, ' ', _('environment variable does not exist.')];
      return
    end
    % ack to remove '\n' at the end
    m(m == 10) = '';
    if strcmp(k{1}, 'PATH') == true
       m = replace(m, current_PATH, '');
    end
    names = [names, k{1}];
    values = [values; m];
  end
  config = cell2struct(values, names);
  config.COMPILER_CHOICE = 'msvc';
  json = jsonencode(config);
  json = jsonprettyprint(json);
  filewrite([prefdir(), '/compiler_', arch, '.json'], json);
  loadcompilerconf();
  status = true;
  msg = '';
end
%=============================================================================
function [status, message] = checkExistFile(filename, errormsg)
  message = '';
  status = isfile(filename);
  if ~status
    message = [filename, ' ', _('does not exist.')];
  end
end
%=============================================================================

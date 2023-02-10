%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
filename = [modulepath('characters_encoding', 'tests'), '/olaf_Windows-1251.txt'];
assert_isequal(isfile(filename), true);
fid = fopen(filename, 'rt', 'n', 'windows-1251');
found = false;
while ~feof(fid)
  line = fgets(fid);
  if (~isdouble(line))
    if (startsWith(line, 'P.S. Когато преглеждах първата'))
      found = true;
      break;
    end
  end
end
fclose(fid);
assert_istrue(found);
%=============================================================================

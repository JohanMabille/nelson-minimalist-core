%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
a = nfilename();
assert_isequal(a, 'test_nfilename');
%=============================================================================
p = path();
this_file = mfilename('fullpathext');
addpath(fileparts(this_file, 'path'));
a = nfilename();
assert_isequal(a, 'test_nfilename');
%=============================================================================
run('nfilename1.m');
a = nfilename();
assert_isequal(a, 'test_nfilename');
%=============================================================================
path(p);
%=============================================================================

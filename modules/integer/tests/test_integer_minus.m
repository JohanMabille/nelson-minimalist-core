%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
R = (uint64(2 .^ 53) - 1);
REF = 9007199254740991u;
assert_isequal(R, REF);
%=============================================================================
R = (uint64(2 .^ 53) - 1) - (uint64(2 .^ 53) - 1000);
REF = uint64(999);
assert_isequal(R, REF);
%=============================================================================
R = (uint64(2 .^ 54) - 1) - (uint64(2 .^ 54) - 1000);
REF = uint64(999);
assert_isequal(R, REF);
%=============================================================================
R = (uint64(2 .^ 57) - 1) - (uint64(2 .^ 57) - 1000);
REF = uint64(999);
assert_isequal(R, REF);
%=============================================================================
R = (uint64(2 .^ 59) - 1) - (uint64(2 .^ 59) - 1000);
REF = uint64(999);
assert_isequal(R, REF);
%=============================================================================
R = (int64(2 .^ 53) - 1) - (int64(2 .^ 53) - 1000);
REF = int64(999);
assert_isequal(R, REF);
%=============================================================================
R = (int64(2 .^ 54) - 1) - (int64(2 .^ 54) - 1000);
REF = int64(999);
assert_isequal(R, REF);
%=============================================================================
R = uint8(0) - uint8(127);
REF = uint8(0);
assert_isequal(R, REF);
%=============================================================================
R = uint8(3) - uint8(4);
REF = uint8(0);
assert_isequal(R, REF);
%=============================================================================
R = uint8(4) - uint8(3);
REF = uint8(1);
assert_isequal(R, REF);
%=============================================================================
R = int8(-127) - int8(127);
REF = int8(intmin('int8'));
assert_isequal(R, REF);
%=============================================================================
R = int8(127) - int8(-127);
REF = int8(intmax('int8'));
assert_isequal(R, REF);
%=============================================================================
R = int8(3) - int8(4);
REF = int8(-1);
assert_isequal(R, REF);
%=============================================================================
R = int8(-3) - int8(4);
REF = int8(-7);
assert_isequal(R, REF);
%=============================================================================
R = int8(3) - int8(-4);
REF = int8(7);
assert_isequal(R, REF);
%=============================================================================
R = int8(-3) - int8(-4);
REF = int8(1);
assert_isequal(R, REF);
%=============================================================================
R = intmax('uint8') - intmax('uint8');
REF = intmin('uint8');
assert_isequal(R, REF);
%=============================================================================

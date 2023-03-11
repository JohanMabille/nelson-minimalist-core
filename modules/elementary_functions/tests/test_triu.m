%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
T = triu(ones(2, 0));
assert_isequal(T, ones(2, 0));
%=============================================================================
T = triu([1 2 3 4]);
assert_isequal(T, [1 2 3 4]);
%=============================================================================
T = triu([1 2 3 4], 2);
assert_isequal(T, [ 0     0     3     4]);
%=============================================================================
M = [1 2 3 4; 5 6 7 8; 9 10 11 12];
T = triu(M);
REF = [     1     2     3     4;
0     6     7     8;
0     0    11    12];
assert_isequal(T, REF);
%=============================================================================
M = [1 2 3 4; 5 6 7 8; 9 10 11 12];
T = triu(M, 0);
REF = [     1     2     3     4;
0     6     7     8;
0     0    11    12];
assert_isequal(T, REF);
%=============================================================================
M = [1 2 3 4; 5 6 7 8; 9 10 11 12];
T = triu(M, 1);
REF = [     0     2     3     4;
0     0     7     8;
0     0     0    12];
assert_isequal(T, REF);
%=============================================================================
M = [1 2 3 4; 5 6 7 8; 9 10 11 12];
T = triu(M, -1);
REF = [1     2     3     4;
5     6     7     8;
0    10    11    12];
assert_isequal(T, REF);
%=============================================================================
M = [1 2 3 4; 5 6 7 8; 9 10 11 12];
N = [9 10 11 12; 5 6 7 8; 1 2 3 4];
C = complex(M, N);
T = triu(C);
REF = [1.0000+9.0000i,   2.0000+10.0000i,   3.0000+11.0000i,   4.0000+12.0000i;
0.0000+0.0000i,   6.0000+6.0000i,   7.0000+7.0000i,   8.0000+8.0000i;
0.0000+0.0000i,   0.0000+0.0000i,  11.0000+3.0000i,  12.0000+4.0000i];
assert_isequal(T, REF);
%=============================================================================
M = [1 2 3 4; 5 6 7 8; 9 10 11 12];
N = [9 10 11 12; 5 6 7 8; 1 2 3 4];
C = complex(M, N);
T = triu(C, 1);
REF = [ 0.0000+0.0000i,   2.0000+10.0000i,   3.0000+11.0000i,   4.0000+12.0000i;
0.0000+0.0000i,   0.0000+0.0000i,   7.0000+7.0000i,   8.0000+8.0000i;
0.0000+0.0000i,   0.0000+0.0000i,   0.0000+0.0000i,  12.0000+4.0000i];
assert_isequal(T, REF);
%=============================================================================
M = [1 2 3 4; 5 6 7 8; 9 10 11 12];
N = [9 10 11 12; 5 6 7 8; 1 2 3 4];
C = complex(M, N);
T = triu(C, -1);
REF = [   1.0000+9.0000i,   2.0000+10.0000i,   3.0000+11.0000i,   4.0000+12.0000i;
5.0000+5.0000i,   6.0000+6.0000i,   7.0000+7.0000i,   8.0000+8.0000i;
0.0000+0.0000i,  10.0000+2.0000i, 11.0000+3.0000i,  12.0000+4.0000i];
assert_isequal(T, REF);
%=============================================================================

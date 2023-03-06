%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('atan'), 1);
assert_isequal(nargout('atan'), 1);
%=============================================================================
assert_isequal(atan(NaN),  NaN);
assert_isequal(atan(-NaN), NaN);
assert_isequal(atan(Inf), pi * 0.5);
assert_isequal(atan(-Inf), -pi * 0.5);
%=============================================================================
v = [1.   0.8660254   0.7071068   0.5   0.   0.  -0.5  -0.7071068  -0.8660254  -1];
r = atan(v);
ref = [ 0.7854    0.7137    0.6155    0.4636         0         0   -0.4636   -0.6155   -0.7137   -0.7854];
assert_isapprox(real(r), ref, 1e-4);
%=============================================================================
x = atan(0i);
ref = 0;
assert_isequal(x, ref);
%=============================================================================
X = atan(zeros(3, 3, 3));
REF = zeros(3, 3, 3);
assert_isequal(X, REF);
%=============================================================================
assert_isequal(atan([]), []);
%=============================================================================
assert_checkerror('atan(''a'')', [_('Undefined function ''atan'' for input arguments of type '''), class('a'), '''.']);
%=============================================================================

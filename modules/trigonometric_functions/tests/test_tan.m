%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('tan'), 1);
assert_isequal(nargout('tan'), 1);
%=============================================================================
assert_isequal(tan(NaN), NaN);
assert_isequal(tan(-NaN), NaN);
assert_isequal(tan(Inf), NaN);
assert_isequal(tan(-Inf), NaN);
%=============================================================================
v = [1.   0.8660254   0.7071068   0.5   0.   0.  -0.5  -0.7071068  -0.8660254  -1];
r = tan(v);
ref = [1.5574     1.1758     0.8545     0.5463     0.0000     0.0000    -0.5463    -0.8545    -1.1758    -1.5574];
assert_isapprox(r, ref, 1e-4);
%=============================================================================
x = tan(0i);
ref = 0;
assert_isequal(x, ref);
assert_isequal(tan(0), 0);
assert_isequal(tan(-0), 0);
%=============================================================================
X = tan(zeros(3, 3, 3));
REF = zeros(3, 3, 3);
assert_isequal(X, REF);
%=============================================================================
assert_isequal(tan([]), []);
%=============================================================================
assert_checkerror('tan(''a'')', [_('Undefined function ''tan'' for input arguments of type '''), class('a'), '''.']);
%=============================================================================

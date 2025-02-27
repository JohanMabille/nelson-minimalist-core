%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('cosh'), 1);
assert_isequal(nargout('cosh'), 1);
%=============================================================================
assert_isequal(cosh(NaN), NaN);
assert_isequal(cosh(Inf), Inf);
assert_isequal(cosh(-Inf), Inf);
%=============================================================================
A = cosh(0);
REF = 1;
assert_isequal(A, REF);
%=============================================================================
assert_checkerror('cosh(''a'')', [_('Undefined function ''cosh'' for input arguments of type '''), class('a'), '''.']);
%=============================================================================

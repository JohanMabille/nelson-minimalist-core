%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('conj'), 1)
assert_isequal(nargout('conj'), 1)
%=============================================================================
assert_isequal(conj(NaN), NaN);
%=============================================================================
assert_isequal(conj([]), []);
%=============================================================================
x = [1+i,-i;i,2i];
r = conj(x);
ref = [1-i,i;-i,-2i];
assert_isequal(r, ref);
%=============================================================================
x = single([1+i,-i;i,2i]);
r = conj(x);
ref = single([1-i,i;-i,-2i]);
assert_isequal(r, ref);
%=============================================================================

%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <--ADV-CLI MODE-->
%=============================================================================
f = figure();
surf(peaks);
colormap('cool');
r = f.ColorMap;
assert_isapprox(r(1:2, :), [0, 1.0000, 1.0000; 0.0039, 0.9961, 1.0000], 1e-3); 
%=============================================================================

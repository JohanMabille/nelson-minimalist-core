//=============================================================================
// Copyright (c) 2016-2017 Allan CORNET (Nelson)
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#include <Eigen/Dense>
#include "Transpose.hpp"
//=============================================================================
namespace Nelson {
    ArrayOf Transpose(ArrayOf A)
    {
        switch (A.getDataClass())
        {
            case NLS_DOUBLE:
            {
                ArrayOf Res(A);
                Eigen::Map<Eigen::MatrixXd> matOrigin((double*)Res.getDataPointer(), Res.getDimensions().getColumns(), Res.getDimensions().getRows());
                Eigen::Map<Eigen::MatrixXd> matTransposed((double*)Res.getDataPointer(), Res.getDimensions().getRows(), Res.getDimensions().getColumns());
                matTransposed = matOrigin.transpose().eval();
                return Res;
            }
            break;
        }
        return A;
    }
}
//=============================================================================

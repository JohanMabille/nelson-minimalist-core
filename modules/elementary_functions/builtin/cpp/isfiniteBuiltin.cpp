//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "isfiniteBuiltin.hpp"
#include "Error.hpp"
#include "OverloadFunction.hpp"
#include "IsFinite.hpp"
#include "InputOutputArgumentsCheckers.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::ElementaryFunctionsGateway::isfiniteBuiltin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargincheck(argIn, 1, 1);
    nargoutcheck(nLhs, 0, 1);
    bool bSuccess = false;
    if (eval->mustOverloadBasicTypes()) {
        retval = OverloadFunction(eval, nLhs, argIn, "isfinite", bSuccess);
    }
    if (!bSuccess) {
        if (argIn[0].isSparse() || argIn[0].isCell() || argIn[0].isHandle() || argIn[0].isStruct()
            || argIn[0].isClassStruct()) {
            retval = OverloadFunction(eval, nLhs, argIn, "isfinite", bSuccess);
            if (bSuccess) {
                return retval;
            }
        }
        retval << IsFinite(argIn[0]);
    }
    return retval;
}
//=============================================================================

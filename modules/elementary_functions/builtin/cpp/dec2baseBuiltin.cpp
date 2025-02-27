//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "dec2baseBuiltin.hpp"
#include "Error.hpp"
#include "OverloadFunction.hpp"
#include "DecimalToBase.hpp"
#include "InputOutputArgumentsCheckers.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::ElementaryFunctionsGateway::dec2baseBuiltin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargincheck(argIn, 2, 3);
    nargoutcheck(nLhs, 0, 1);
    bool bSuccess = false;
    if (eval->mustOverloadBasicTypes()) {
        retval = OverloadFunction(eval, nLhs, argIn, "dec2base", bSuccess);
    }
    if (!bSuccess) {
        if (argIn[0].isSparse() || argIn[0].isHandle() || argIn[0].isCell() || argIn[0].isStruct()
            || argIn[0].isClassStruct()) {
            retval = OverloadFunction(eval, nLhs, argIn, "dec2base", bSuccess);
            if (bSuccess) {
                return retval;
            }
        }
        if (!bSuccess) {
            bool needToOverload;
            ArrayOf param1 = argIn[0];
            ArrayOf param2 = argIn[1];
            ArrayOf param3;
            if (argIn.size() == 3) {
                param3 = argIn[2];
            } else {
                param3 = ArrayOf::doubleConstructor(0.);
            }
            ArrayOf res = DecimalToBase(param1, param2, param3, needToOverload);
            if (needToOverload) {
                retval = OverloadFunction(eval, nLhs, argIn, "dec2base");
            } else {
                retval << res;
            }
        }
    }
    return retval;
}
//=============================================================================
ArrayOfVector
Nelson::ElementaryFunctionsGateway::dec2hexBuiltin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargincheck(argIn, 1, 2);
    nargoutcheck(nLhs, 0, 1);
    bool bSuccess = false;
    if (eval->mustOverloadBasicTypes()) {
        retval = OverloadFunction(eval, nLhs, argIn, "dec2hex", bSuccess);
    }
    if (!bSuccess) {
        if (argIn[0].isSparse() || argIn[0].isHandle() || argIn[0].isCell() || argIn[0].isStruct()
            || argIn[0].isClassStruct()) {
            retval = OverloadFunction(eval, nLhs, argIn, "dec2hex", bSuccess);
            if (bSuccess) {
                return retval;
            }
        }
        if (!bSuccess) {
            bool needToOverload;
            ArrayOf param1 = argIn[0];
            ArrayOf param2 = ArrayOf::doubleConstructor(16.);
            ArrayOf param3;
            if (argIn.size() == 2) {
                param3 = argIn[1];
            } else {
                param3 = ArrayOf::doubleConstructor(0.);
            }
            ArrayOf res = DecimalToBase(param1, param2, param3, needToOverload);
            if (needToOverload) {
                retval = OverloadFunction(eval, nLhs, argIn, "dec2hex");
            } else {
                retval << res;
            }
        }
    }
    return retval;
}
//=============================================================================
ArrayOfVector
Nelson::ElementaryFunctionsGateway::dec2binBuiltin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargincheck(argIn, 1, 2);
    nargoutcheck(nLhs, 0, 1);
    bool bSuccess = false;
    if (eval->mustOverloadBasicTypes()) {
        retval = OverloadFunction(eval, nLhs, argIn, "dec2bin", bSuccess);
    }
    if (!bSuccess) {
        if (argIn[0].isSparse() || argIn[0].isHandle() || argIn[0].isCell() || argIn[0].isStruct()
            || argIn[0].isClassStruct()) {
            retval = OverloadFunction(eval, nLhs, argIn, "dec2bin", bSuccess);
            if (bSuccess) {
                return retval;
            }
        }
        if (!bSuccess) {
            bool needToOverload;
            ArrayOf param1 = argIn[0];
            ArrayOf param2 = ArrayOf::doubleConstructor(2.);
            ArrayOf param3;
            if (argIn.size() == 2) {
                param3 = argIn[1];
            } else {
                param3 = ArrayOf::doubleConstructor(0.);
            }
            ArrayOf res = DecimalToBase(param1, param2, param3, needToOverload);
            if (needToOverload) {
                retval = OverloadFunction(eval, nLhs, argIn, "dec2bin");
            } else {
                retval << res;
            }
        }
    }
    return retval;
}
//=============================================================================

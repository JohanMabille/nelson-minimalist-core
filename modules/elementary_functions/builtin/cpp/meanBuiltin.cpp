//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// Alternatively, you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program. If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#include "meanBuiltin.hpp"
#include "Error.hpp"
#include "OverloadFunction.hpp"
#include "OverloadRequired.hpp"
#include "Mean.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::ElementaryFunctionsGateway::meanBuiltin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    bool bSuccess = false;
    if (nLhs > 1) {
        Error(ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (eval->mustOverloadBasicTypes()) {
        retval = OverloadFunction(eval, nLhs, argIn, "mean", bSuccess);
    }
    if (!bSuccess) {
        ArrayOf res;
        bool needToOverload = false;
        bool omitNaN = false;
        bool isAll = false;
        indexType dim = 0;
        MEAN_OUT_TYPE outType = MEAN_OUT_TYPE::DEFAULT;
        switch (argIn.size()) {
        case 1: {
            res = Mean(argIn[0], dim, omitNaN, outType, needToOverload);
        } break;
        case 2: {
            // M = mean(A, 'all');
            // M = mean(A, dim);
            // M = mean(A, 'default'), M = mean(A, 'double'), M = mean(A, 'native')
            // M = mean(A, 'includenan'), M = mean(A, 'omitnan')
            ArrayOf param1 = argIn[0];
            ArrayOf param2 = argIn[1];
            if (param2.isRowVectorCharacterArray()
                || (param2.isStringArray() && param2.isScalar())) {
                std::wstring s = param2.getContentAsWideString();
                if (s == L"omitnan") {
                    omitNaN = true;
                } else if (s == L"includenan") {
                    omitNaN = false;
                } else if (s == L"all") {
                    isAll = true;
                } else if (s == L"default") {
                    outType = MEAN_OUT_TYPE::DEFAULT;
                } else if (s == L"double") {
                    outType = MEAN_OUT_TYPE::DOUBLE;
                } else if (s == L"native") {
                    outType = MEAN_OUT_TYPE::NATIVE;
                } else {
                    Error(_("Invalid second argument."));
                }
            } else {
                dim = param2.getContentAsScalarIndex(false);
            }

            if (isAll) {
                res = MeanAll(argIn[0], omitNaN, outType, needToOverload);
            } else {
                res = Mean(argIn[0], dim, omitNaN, outType, needToOverload);
            }

        } break;
        case 3: {
            // M = mean(A, 'all', nanflag)
            // M = mean(A, 'all', outtype)
            // M = mean(A, dim, nanflag)
            // M = mean(A, dim, outtype)
            ArrayOf param1 = argIn[0];
            ArrayOf param2 = argIn[1];
            ArrayOf param3 = argIn[2];
            if (param2.isRowVectorCharacterArray()
                || (param2.isStringArray() && param2.isScalar())) {
                std::wstring s = param2.getContentAsWideString();
                if (s == L"all") {
                    isAll = true;
                } else {
                    Error(_("Invalid second argument."));
                }
            } else {
                dim = param2.getContentAsScalarIndex(false);
            }
            if (param3.isRowVectorCharacterArray()
                || (param3.isStringArray() && param3.isScalar())) {
                std::wstring s = param3.getContentAsWideString();
                if (s == L"omitnan") {
                    omitNaN = true;
                } else if (s == L"includenan") {
                    omitNaN = false;
                } else if (s == L"default") {
                    outType = MEAN_OUT_TYPE::DEFAULT;
                } else if (s == L"double") {
                    outType = MEAN_OUT_TYPE::DOUBLE;
                } else if (s == L"native") {
                    outType = MEAN_OUT_TYPE::NATIVE;
                } else {
                    Error(_("Invalid third argument."));
                }
            } else {
                Error(_("Invalid third argument."));
            }
            if (isAll) {
                res = MeanAll(argIn[0], omitNaN, outType, needToOverload);
            } else {
                res = Mean(argIn[0], dim, omitNaN, outType, needToOverload);
            }
        } break;
        case 4: {
            // M = mean(A, 'all', nanflag, outtype)
            // M = mean(A, 'all', outtype, nanflag)
            // M = mean(A, dim, nanflag, outtype)
            // M = mean(A, dim, outtype, nanflag)
            ArrayOf param1 = argIn[0];
            ArrayOf param2 = argIn[1];
            ArrayOf param3 = argIn[2];
            ArrayOf param4 = argIn[3];
            if (param2.isRowVectorCharacterArray()
                || (param2.isStringArray() && param2.isScalar())) {
                std::wstring s = param2.getContentAsWideString();
                if (s == L"all") {
                    isAll = true;
                } else {
                    Error(_("Invalid second argument."));
                }
            } else {
                dim = param2.getContentAsScalarIndex(false);
            }
            bool haveNaNChoice = false;
            bool haveTypeChoice = false;
            if (param3.isRowVectorCharacterArray()
                || (param3.isStringArray() && param3.isScalar())) {
                std::wstring s = param3.getContentAsWideString();
                if (s == L"omitnan") {
                    omitNaN = true;
                    haveNaNChoice = true;
                } else if (s == L"includenan") {
                    omitNaN = false;
                    haveNaNChoice = true;
                } else if (s == L"default") {
                    outType = MEAN_OUT_TYPE::DEFAULT;
                    haveTypeChoice = true;
                } else if (s == L"double") {
                    outType = MEAN_OUT_TYPE::DOUBLE;
                    haveTypeChoice = true;
                } else if (s == L"native") {
                    outType = MEAN_OUT_TYPE::NATIVE;
                    haveTypeChoice = true;
                } else {
                    Error(_("Invalid third argument."));
                }
            } else {
                Error(_("Invalid third argument."));
            }
            if (param4.isRowVectorCharacterArray()
                || (param4.isStringArray() && param4.isScalar())) {
                std::wstring s = param4.getContentAsWideString();
                if (s == L"omitnan") {
                    if (haveNaNChoice) {
                        Error(_("Invalid 4th argument."));
                    }
                    omitNaN = true;
                } else if (s == L"includenan") {
                    if (haveNaNChoice) {
                        Error(_("Invalid 4th argument."));
                    }
                    omitNaN = false;
                } else if (s == L"default") {
                    if (haveTypeChoice) {
                        Error(_("Invalid 4th argument."));
                    }
                    outType = MEAN_OUT_TYPE::DEFAULT;
                } else if (s == L"double") {
                    if (haveTypeChoice) {
                        Error(_("Invalid 4th argument."));
                    }
                    outType = MEAN_OUT_TYPE::DOUBLE;
                } else if (s == L"native") {
                    if (haveTypeChoice) {
                        Error(_("Invalid 4th argument."));
                    }
                    outType = MEAN_OUT_TYPE::NATIVE;
                } else {
                    Error(_("Invalid 4th argument."));
                }
            } else {
                Error(_("Invalid 4th argument."));
            }
            if (isAll) {
                res = MeanAll(argIn[0], omitNaN, outType, needToOverload);
            } else {
                res = Mean(argIn[0], dim, omitNaN, outType, needToOverload);
            }
        } break;
        default: {
            Error(ERROR_WRONG_NUMBERS_INPUT_ARGS);
        } break;
        }
        if (needToOverload) {
            retval = OverloadFunction(eval, nLhs, argIn, "mean");
        } else {
            retval.push_back(res);
        }
    }
    return retval;
}
//=============================================================================

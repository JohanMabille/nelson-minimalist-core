//=============================================================================
// Copyright (c) 2016-2018 Allan CORNET (Nelson)
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
#include "integer_horzcat_integerBuiltin.hpp"
#include "Error.hpp"
#include "HorzCatInteger.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
static ArrayOfVector
integer_horzcat_integerBuiltin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn, Class intclass)
{
    ArrayOfVector retval;
    if (argIn.size() != 2) {
        Error(eval, ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    if (nLhs > 1) {
        Error(eval, ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    ArrayOf A = argIn[0];
    ArrayOf B = argIn[1];
    retval.push_back(HorzCatInteger(A, B));
    return retval;
}
//=============================================================================
ArrayOfVector
Nelson::IntegerGateway::int8_horzcat_int8Builtin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    return integer_horzcat_integerBuiltin(eval, nLhs, argIn, NLS_INT8);
}
//=============================================================================
ArrayOfVector
Nelson::IntegerGateway::int16_horzcat_int16Builtin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    return integer_horzcat_integerBuiltin(eval, nLhs, argIn, NLS_INT16);
}
//=============================================================================
ArrayOfVector
Nelson::IntegerGateway::int32_horzcat_int32Builtin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    return integer_horzcat_integerBuiltin(eval, nLhs, argIn, NLS_INT32);
}
//=============================================================================
ArrayOfVector
Nelson::IntegerGateway::int64_horzcat_int64Builtin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    return integer_horzcat_integerBuiltin(eval, nLhs, argIn, NLS_INT64);
}
//=============================================================================
ArrayOfVector
Nelson::IntegerGateway::uint8_horzcat_uint8Builtin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    return integer_horzcat_integerBuiltin(eval, nLhs, argIn, NLS_UINT8);
}
//=============================================================================
ArrayOfVector
Nelson::IntegerGateway::uint16_horzcat_uint16Builtin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    return integer_horzcat_integerBuiltin(eval, nLhs, argIn, NLS_UINT16);
}
//=============================================================================
ArrayOfVector
Nelson::IntegerGateway::uint32_horzcat_uint32Builtin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    return integer_horzcat_integerBuiltin(eval, nLhs, argIn, NLS_UINT32);
}
//=============================================================================
ArrayOfVector
Nelson::IntegerGateway::uint64_horzcat_uint64Builtin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    return integer_horzcat_integerBuiltin(eval, nLhs, argIn, NLS_UINT64);
}
//=============================================================================

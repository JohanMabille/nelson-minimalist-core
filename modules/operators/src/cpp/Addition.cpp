//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include <algorithm>
#include "nlsBuildConfig.h"
#include "lapack_eigen_config.hpp"
#if defined(_NLS_WITH_VML)
#include <mkl_vml.h>
#endif
#include "Addition.hpp"
#include "MatrixCheck.hpp"
#include "Error.hpp"
#include "i18n.hpp"
#include "StringArrayAddition.hpp"
#include "AdditionReal.hpp"
#include "AdditionComplex.hpp"
#include "AdditionInteger.hpp"
#include "FindCommonClass.hpp"
#include "BinaryOperatorsHelpers.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
static ArrayOf
Addition(const ArrayOf& A, const ArrayOf& B, NelsonType commonClass)
{
    ArrayOf res;
    if (A.isEmpty() || B.isEmpty()) {
        if (A.isScalar() || B.isScalar()) {
            if (A.isScalar()) {
                res = B;
            } else {
                res = A;
            }
        } else {
            res = binaryOperatorEmptyMatrixEmptryMatrix(A, B, commonClass, "+");
        }
        if (res.getDataClass() == NLS_DCOMPLEX) {
            if (res.allReal()) {
                res.promoteType(NLS_DOUBLE);
            }
        }
        if (res.getDataClass() == NLS_SCOMPLEX) {
            if (res.allReal()) {
                res.promoteType(NLS_SINGLE);
            }
        }
        return res;
    }
    if (commonClass >= NLS_UINT8 && commonClass <= NLS_INT64) {
        switch (commonClass) {
        case NLS_INT8:
            return integer_addition<int8>(NLS_INT8, A, B);
        case NLS_UINT8:
            return integer_addition<uint8>(NLS_UINT8, A, B);
        case NLS_INT16:
            return integer_addition<int16>(NLS_INT16, A, B);
        case NLS_UINT16:
            return integer_addition<uint16>(NLS_UINT16, A, B);
        case NLS_INT32:
            return integer_addition<int32>(NLS_INT32, A, B);
        case NLS_UINT32:
            return integer_addition<uint32>(NLS_UINT32, A, B);
        case NLS_INT64:
            return integer_addition<int64>(NLS_INT64, A, B);
        case NLS_UINT64:
            return integer_addition<uint64>(NLS_UINT64, A, B);
        default:
            Error(_W("Type not managed."));
            break;
        }
    } else {
        switch (commonClass) {
        case NLS_SINGLE: {
            if (A.isScalar() && B.isScalar()) {
                res = scalar_scalar_real_addition<single>(NLS_SINGLE, A, B);
            } else {
                Dimensions dimsA = A.getDimensions();
                Dimensions dimsB = B.getDimensions();
                if (SameSizeCheck(dimsA, dimsB)) {
#if defined(_NLS_WITH_VML)
                    Dimensions dimsC = A.getDimensions();
                    indexType Clen = dimsC.getElementCount();
                    single* ptrC = (single*)ArrayOf::allocateArrayOf(NLS_SINGLE, Clen);
                    const single* ptrA = (const single*)A.getDataPointer();
                    const single* ptrB = (const single*)B.getDataPointer();
                    res = ArrayOf(NLS_SINGLE, dimsC, ptrC, false);
                    vsAdd((MKL_INT)Clen, ptrA, ptrB, ptrC);
#else
                    res = matrix_matrix_real_addition<single>(NLS_SINGLE, A, B);
#endif
                } else {
                    res = real_addition<single>(NLS_SINGLE, A, B);
                }
            }
        } break;
        case NLS_DOUBLE: {
            if (A.isScalar() && B.isScalar()) {
                res = scalar_scalar_real_addition<double>(NLS_DOUBLE, A, B);
            } else {
                Dimensions dimsA = A.getDimensions();
                Dimensions dimsB = B.getDimensions();
                if (SameSizeCheck(dimsA, dimsB)) {
#if defined(_NLS_WITH_VML)
                    Dimensions dimsC = A.getDimensions();
                    indexType Clen = dimsC.getElementCount();
                    double* ptrC = (double*)ArrayOf::allocateArrayOf(NLS_DOUBLE, Clen);
                    const double* ptrA = (const double*)A.getDataPointer();
                    const double* ptrB = (const double*)B.getDataPointer();
                    res = ArrayOf(NLS_DOUBLE, dimsC, ptrC, false);
                    vdAdd((MKL_INT)Clen, ptrA, ptrB, ptrC);
#else
                    res = matrix_matrix_real_addition<double>(NLS_DOUBLE, A, B);
#endif
                } else {
                    res = real_addition<double>(NLS_DOUBLE, A, B);
                }
            }
        } break;
        case NLS_SCOMPLEX: {
            if (A.isScalar() && B.isScalar()) {
                res = scalar_scalar_complex_addition<single>(NLS_SCOMPLEX, A, B);
            } else {
                Dimensions dimsA = A.getDimensions();
                Dimensions dimsB = B.getDimensions();
                if (SameSizeCheck(dimsA, dimsB)) {
#if defined(_NLS_WITH_VML)
                    Dimensions dimsC = A.getDimensions();
                    indexType Clen = dimsC.getElementCount();
                    single* ptrC = (single*)ArrayOf::allocateArrayOf(NLS_SCOMPLEX, Clen);
                    res = ArrayOf(NLS_SCOMPLEX, dimsC, ptrC, false);
                    single* ptrA = (single*)A.getDataPointer();
                    single* ptrB = (single*)B.getDataPointer();
                    MKL_Complex8* ptrAz = reinterpret_cast<MKL_Complex8*>(ptrA);
                    MKL_Complex8* ptrBz = reinterpret_cast<MKL_Complex8*>(ptrB);
                    MKL_Complex8* ptrCz = reinterpret_cast<MKL_Complex8*>(ptrC);
                    vcAdd((MKL_INT)Clen, ptrAz, ptrBz, ptrCz);
#else
                    res = matrix_matrix_complex_addition<single>(NLS_SCOMPLEX, A, B);
#endif
                } else {
                    res = complex_addition<single>(NLS_SCOMPLEX, A, B);
                }
            }
            if (res.allReal()) {
                res.promoteType(NLS_SINGLE);
            }
        } break;
        case NLS_DCOMPLEX: {
            if (A.isScalar() && B.isScalar()) {
                res = scalar_scalar_complex_addition<double>(NLS_DCOMPLEX, A, B);
            } else {
                Dimensions dimsA = A.getDimensions();
                Dimensions dimsB = B.getDimensions();
                if (SameSizeCheck(dimsA, dimsB)) {
#if defined(_NLS_WITH_VML)
                    Dimensions dimsC = A.getDimensions();
                    indexType Clen = dimsC.getElementCount();
                    double* ptrC = (double*)ArrayOf::allocateArrayOf(NLS_DCOMPLEX, Clen);
                    res = ArrayOf(NLS_DCOMPLEX, dimsC, ptrC, false);
                    double* ptrA = (double*)A.getDataPointer();
                    double* ptrB = (double*)B.getDataPointer();
                    MKL_Complex16* ptrAz = reinterpret_cast<MKL_Complex16*>(ptrA);
                    MKL_Complex16* ptrBz = reinterpret_cast<MKL_Complex16*>(ptrB);
                    MKL_Complex16* ptrCz = reinterpret_cast<MKL_Complex16*>(ptrC);
                    vzAdd((MKL_INT)Clen, ptrAz, ptrBz, ptrCz);
#else
                    res = matrix_matrix_complex_addition<double>(NLS_DCOMPLEX, A, B);
#endif
                } else {
                    res = complex_addition<double>(NLS_DCOMPLEX, A, B);
                }
            }
            if (res.allReal()) {
                res.promoteType(NLS_DOUBLE);
            }
        } break;
        default: {
            Error(_W("Type not managed."));
        } break;
        }
    }
    return res;
}
//=============================================================================
ArrayOf
Addition(const ArrayOf& A, const ArrayOf& B, bool& needToOverload)
{
    needToOverload = false;
    ArrayOf res;
    if (A.isStringArray() || B.isStringArray()) {
        ArrayOf a = ArrayOf::toStringArray(A, needToOverload);
        if (needToOverload) {
            return res;
        }
        ArrayOf b = ArrayOf::toStringArray(B, needToOverload);
        if (needToOverload) {
            return res;
        }
        return stringArray_plus_stringArray(a, b);
    }
    NelsonType commonClass = FindCommonClass(A, B, needToOverload);
    if (!needToOverload) {
        if (A.getDataClass() == commonClass && B.getDataClass() == commonClass) {
            res = Addition(A, B, commonClass);
        } else {
            ArrayOf a = A;
            a.promoteType(commonClass);
            ArrayOf b = B;
            b.promoteType(commonClass);
            res = Addition(a, b, commonClass);
        }
    }
    return res;
}
//=============================================================================
} // namespace Nelson
//=============================================================================

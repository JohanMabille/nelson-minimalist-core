//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "nlsBuildConfig.h"
#include "lapack_eigen_config.hpp"
#include <complex>
#include <Eigen/Dense>
#include "Exponential.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
template <class T>
T
ExponentialComplexScalar(T value)
{
    // Z = X + i * Y
    // EXP(Z) = EXP(X) * (COS(Y) + i * SIN(Y))
    T res(exp(value.real()) * cos(value.imag()), exp(value.real()) * sin(value.imag()));
    return res;
}
//=============================================================================
template <class T>
T
ExponentialRealScalar(T value)
{
    return exp(value);
}
//=============================================================================
ArrayOf
Exponential(const ArrayOf& A, bool& needToOverload)
{
    ArrayOf res;
    needToOverload = false;
    NelsonType classA = A.getDataClass();
    if (classA == NLS_DOUBLE || classA == NLS_DCOMPLEX) {
        if (A.isSparse()) {
            needToOverload = true;
        } else {
            Dimensions dimsA = A.getDimensions();
            if (classA == NLS_DOUBLE) {
                double* ptrOut = (double*)ArrayOf::allocateArrayOf(
                    NLS_DOUBLE, dimsA.getElementCount(), stringVector(), false);
                auto* ptrIn = (double*)A.getDataPointer();
                Eigen::Map<Eigen::ArrayXd> matOut(ptrOut, dimsA.getElementCount());
                Eigen::Map<Eigen::ArrayXd> matIn(ptrIn, dimsA.getElementCount());
                matOut = matIn.array().exp();
                res = ArrayOf(NLS_DOUBLE, dimsA, ptrOut);
            } else {
                double* ptrOut = (double*)ArrayOf::allocateArrayOf(
                    NLS_DCOMPLEX, dimsA.getElementCount(), stringVector(), false);
                auto* Cz = reinterpret_cast<std::complex<double>*>(ptrOut);
                auto* ptrIn = (double*)A.getDataPointer();
                auto* Az = reinterpret_cast<std::complex<double>*>((double*)A.getDataPointer());
                Eigen::Map<Eigen::ArrayXcd> matOut(Cz, 1, dimsA.getElementCount());
                Eigen::Map<Eigen::ArrayXcd> matIn(Az, 1, dimsA.getElementCount());
#if defined(_NLS_WITH_VML)
                matOut = matIn.array().exp();
#else
                ompIndexType elementCount = dimsA.getElementCount();
#if defined(_NLS_WITH_OPENMP)
#pragma omp parallel for
#endif
                for (ompIndexType k = 0; k < elementCount; k++) {
                    matOut[k] = ExponentialComplexScalar<std::complex<double>>(matIn[k]);
                }

#endif
                res = ArrayOf(NLS_DCOMPLEX, dimsA, ptrOut);
                if (res.allReal()) {
                    res.promoteType(NLS_DOUBLE);
                }
            }
        }
    } else if (classA == NLS_SINGLE || classA == NLS_SCOMPLEX) {
        if (A.isSparse()) {
            needToOverload = true;
        } else {
            Dimensions dimsA = A.getDimensions();
            if (classA == NLS_SINGLE) {
                single* ptrOut = (single*)ArrayOf::allocateArrayOf(
                    NLS_SINGLE, dimsA.getElementCount(), stringVector(), false);
                auto* ptrIn = (single*)A.getDataPointer();
                Eigen::Map<Eigen::ArrayXf> matOut(ptrOut, dimsA.getElementCount());
                Eigen::Map<Eigen::ArrayXf> matIn(ptrIn, dimsA.getElementCount());
                matOut = matIn.array().exp();
                res = ArrayOf(NLS_SINGLE, dimsA, ptrOut);
            } else {
                single* ptrOut = (single*)ArrayOf::allocateArrayOf(
                    NLS_SCOMPLEX, dimsA.getElementCount(), stringVector(), false);
                auto* Cz = reinterpret_cast<std::complex<single>*>(ptrOut);
                auto* ptrIn = (single*)A.getDataPointer();
                auto* Az = reinterpret_cast<std::complex<single>*>((single*)A.getDataPointer());
                Eigen::Map<Eigen::ArrayXcf> matOut(Cz, 1, dimsA.getElementCount());
                Eigen::Map<Eigen::ArrayXcf> matIn(Az, 1, dimsA.getElementCount());
#if defined(_NLS_WITH_VML)
                matOut = matIn.array().exp();
#else
                ompIndexType elementCount = dimsA.getElementCount();
#if defined(_NLS_WITH_OPENMP)
#pragma omp parallel for
#endif
                for (ompIndexType k = 0; k < elementCount; k++) {
                    matOut[k] = ExponentialComplexScalar<std::complex<single>>(matIn[k]);
                }
#endif
                res = ArrayOf(NLS_SCOMPLEX, dimsA, ptrOut);
                if (res.allReal()) {
                    res.promoteType(NLS_SINGLE);
                }
            }
        }
    } else {
        needToOverload = true;
    }
    return res;
}
//=============================================================================
} // namespace Nelson
//=============================================================================

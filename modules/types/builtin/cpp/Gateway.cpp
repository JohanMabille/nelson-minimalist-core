//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#ifdef _MSC_VER
#pragma warning(disable : 4190)
#endif
//=============================================================================
#include "NelsonGateway.hpp"
#include "classBuiltin.hpp"
#include "isaBuiltin.hpp"
#include "iscellBuiltin.hpp"
#include "ischarBuiltin.hpp"
#include "isclassBuiltin.hpp"
#include "isdoubleBuiltin.hpp"
#include "isemptyBuiltin.hpp"
#include "isfloatBuiltin.hpp"
#include "ishandleBuiltin.hpp"
#include "isint16Builtin.hpp"
#include "isint32Builtin.hpp"
#include "isint64Builtin.hpp"
#include "isint8Builtin.hpp"
#include "isintegerBuiltin.hpp"
#include "islogicalBuiltin.hpp"
#include "isnumericBuiltin.hpp"
#include "isrealBuiltin.hpp"
#include "issingleBuiltin.hpp"
#include "issparseBuiltin.hpp"
#include "isstructBuiltin.hpp"
#include "isuint16Builtin.hpp"
#include "isuint32Builtin.hpp"
#include "isuint64Builtin.hpp"
#include "isuint8Builtin.hpp"
#include "isstringBuiltin.hpp"
#include "isvarnameBuiltin.hpp"
#include "types_Gateway.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"types";
//=============================================================================
static const nlsGateway gateway[] = {
    { "class", (ptrBuiltin)Nelson::TypeGateway::classBuiltin, 1, 2, CPP_BUILTIN_WITH_EVALUATOR },
    { "ischar", (ptrBuiltin)Nelson::TypeGateway::ischarBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "isstring", (ptrBuiltin)Nelson::TypeGateway::isstringBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isfloat", (ptrBuiltin)Nelson::TypeGateway::isfloatBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "iscell", (ptrBuiltin)Nelson::TypeGateway::iscellBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "isdouble", (ptrBuiltin)Nelson::TypeGateway::isdoubleBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "issingle", (ptrBuiltin)Nelson::TypeGateway::issingleBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isstruct", (ptrBuiltin)Nelson::TypeGateway::isstructBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isinteger", (ptrBuiltin)Nelson::TypeGateway::isintegerBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isint8", (ptrBuiltin)Nelson::TypeGateway::isint8Builtin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "isint16", (ptrBuiltin)Nelson::TypeGateway::isint16Builtin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isint32", (ptrBuiltin)Nelson::TypeGateway::isint32Builtin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isint64", (ptrBuiltin)Nelson::TypeGateway::isint64Builtin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isuint8", (ptrBuiltin)Nelson::TypeGateway::isuint8Builtin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isuint16", (ptrBuiltin)Nelson::TypeGateway::isuint16Builtin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isuint32", (ptrBuiltin)Nelson::TypeGateway::isuint32Builtin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isuint64", (ptrBuiltin)Nelson::TypeGateway::isuint64Builtin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "issparse", (ptrBuiltin)Nelson::TypeGateway::issparseBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "islogical", (ptrBuiltin)Nelson::TypeGateway::islogicalBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isnumeric", (ptrBuiltin)Nelson::TypeGateway::isnumericBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isa", (ptrBuiltin)Nelson::TypeGateway::isaBuiltin, 1, 2, CPP_BUILTIN_WITH_EVALUATOR },
    { "isreal", (ptrBuiltin)Nelson::TypeGateway::isrealBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "isempty", (ptrBuiltin)Nelson::TypeGateway::isemptyBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isclass", (ptrBuiltin)Nelson::TypeGateway::isclassBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "ishandle", (ptrBuiltin)Nelson::TypeGateway::ishandleBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isvarname", (ptrBuiltin)Nelson::TypeGateway::isvarnameBuiltin, 1, 1, CPP_BUILTIN },
};
//=============================================================================
int
TypesGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================

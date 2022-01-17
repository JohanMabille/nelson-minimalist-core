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
#include "NelsonGateway.hpp"
#include "dispBuiltin.hpp"
#include "displayBuiltin.hpp"
#include "formatBuiltin.hpp"
#include "echoBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"display_format";
//=============================================================================
static const nlsGateway gateway[] = {
    { "echo", (void*)Nelson::DisplayFormatGateway::echoBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "format", (void*)Nelson::DisplayFormatGateway::formatBuiltin, 1, 2 },
    { "disp", (void*)Nelson::DisplayFormatGateway::dispBuiltin, 0, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "display", (void*)Nelson::DisplayFormatGateway::displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "int8_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "int16_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "int32_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "int64_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "uint8_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "uint16_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "uint32_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "uint64_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "logical_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "char_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "double_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "single_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "struct_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "cell_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "handle_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "string_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparsedouble_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparselogical_display", (void*)Nelson::DisplayFormatGateway::generic_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "int8_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "int16_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "int32_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "int64_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "uint8_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "uint16_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "uint32_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "uint64_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "logical_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "char_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "double_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "single_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "struct_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "cell_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "handle_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "string_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparsedouble_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparselogical_disp", (void*)Nelson::DisplayFormatGateway::generic_dispBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
};
//=============================================================================
static bool
initializeModule(Nelson::Evaluator* eval)
{
    return true;
}
//=============================================================================
static bool
finishModule(Nelson::Evaluator* eval)
{
    return true;
}
//=============================================================================
NLSGATEWAYFUNCEXTENDED(gateway, (void*)initializeModule)
//=============================================================================
NLSGATEWAYINFO(gateway)
//=============================================================================
NLSGATEWAYREMOVEEXTENDED(gateway, (void*)finishModule)
//=============================================================================
NLSGATEWAYNAME()
//=============================================================================

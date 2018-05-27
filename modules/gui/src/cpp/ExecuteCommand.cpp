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
#include "ExecuteCommand.hpp"
#include "Evaluator.hpp"
#include "GetNelsonMainEvaluatorDynamicFunction.hpp"
#include "characters_encoding.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
bool
executeCommand(std::wstring commandToExecute)
{
    void* veval = GetNelsonMainEvaluatorDynamicFunction();
    if (veval != nullptr) {
        std::wstring _cmd = commandToExecute + L";";
        Evaluator* eval = (Evaluator*)veval;
        Interface* io = eval->getInterface();
        if (io != nullptr) {
            if (io->isAtPrompt()) {
                eval->addCommandToQueue(_cmd, true);
            } else {
                std::string ustr = wstring_to_utf8(_cmd);
                eval->evaluateString(ustr + "\n");
            }
            return true;
        }
    }
    return false;
}
//=============================================================================
}
//=============================================================================

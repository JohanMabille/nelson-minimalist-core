rem =============================================================================
rem Copyright (c) 2016-2017 Allan CORNET (Nelson)
rem =============================================================================
rem LICENCE_BLOCK_BEGIN
rem This program is free software: you can redistribute it and/or modify
rem it under the terms of the GNU General Public License as published by
rem the Free Software Foundation, either version 2 of the License, or
rem (at your option) any later version.
rem 
rem This program is distributed in the hope that it will be useful,
rem but WITHOUT ANY WARRANTY; without even the implied warranty of
rem MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
rem GNU General Public License for more details.
rem 
rem You should have received a copy of the GNU General Public License
rem along with this program.  If not, see <http://www.gnu.org/licenses/>.
rem LICENCE_BLOCK_END
rem =============================================================================

set QTDIR=%QTDIR32%
set VS_EXEC="C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\devenv.exe"
call %VS_EXEC% NelSon.sln

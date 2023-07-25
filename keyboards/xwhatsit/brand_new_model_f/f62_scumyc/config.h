/*
Copyright 2020 Purdea Andrei

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MATRIX_ROWS 8
#define MATRIX_COLS 9
// Note: physical column are 16, but only 11 are ever used. Column 0..9 match the physical column. Column 10 is physical column 15.

#define CAPSENSE_KEYMAP_COL_TO_PHYSICAL_COL(col) (((col) == 8)?15:(col))

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
#define MATRIX_COLS 14

// Note: columns 0, and 1 match physical column 0, and 1
//       columns k where k >= 2, match physical column k + 2
//         therefore column 2 matches physical column 4, and column 13 matches physical column 15
//       physical columns 2 and 3 are not used

#define CAPSENSE_KEYMAP_COL_TO_PHYSICAL_COL(col) (((col) >= 2)?((col) + 2):(col))

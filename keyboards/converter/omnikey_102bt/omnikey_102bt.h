#pragma once

#include "quantum.h"
#define XXX KC_NO



/*
  *         ,-----------------------------------------------.
  *         | 08| 10| 18| 20| 28| 30| 38| 40| 48| 50| 57| 5F|
  * ,---.   |-----------------------------------------------|     ,-----------.     ,-----------.
  * | 76|   | 05| 06| 04| 0C| 03| 0B| 83| 0A| 01| 09| 78| 07|     |17C| 7E|277|     |121|132|123|
  * `---'   `-----------------------------------------------'     `-----------'     `-----------'
  * ,-----------------------------------------------------------. ,-----------. ,---------------.
  * | 0E| 16| 1E| 26| 25| 2E| 36| 3D| 3E| 46| 45| 4E| 55| 6A| 66| |170|16C|17D| | 77|*4A| 7C| 7B|
  * |-----------------------------------------------------------| |-----------| |---------------|
  * | 0D  | 15| 1D| 24| 2D| 2C| 35| 3C| 43| 44| 4D| 54| 5B|  5D | |171|169|17A| | 6C| 75| 7D| 79|
  * |-----------------------------------------------------------| `-----------' |---------------|
  * | 58   | 1C| 1B| 23| 2B| 34| 33| 3B| 42| 4B| 4C| 52| 53| 5A |               | 6B| 73| 74| 6D|
  * |-----------------------------------------------------------|     ,---.     |---------------|
  * | 12 | 61| 1A| 22| 21| 2A| 32| 31| 3A| 41| 49| 4A| 51|  59  |     |175|     | 69| 72| 7A|15A|
  * |-----------------------------------------------------------| ,-----------. |---------------|
  * | 14|19| 11| 67 |     29         | 64 | 13 |111|*27|*2F|114| |16B|172|174| | 68| 70| 71| 63|
  * `-----------------------------------------------------------' `-----------' `---------------'
  */


#define LAYOUT(                                                                                                       \
   K78, K07, K7C, K7E, K77,                                                                                           \
   K05, K06, K76, K16, K1E, K26, K25, K2E, K36, K3D, K3E, K46, K45, K4E, K55, K66, K70, K6C, K7D, K08, K4A, K13, K7B, \
   K04, K0C, K0D, K15, K1D, K24, K2D, K2C, K35, K3C, K43, K44, K4D, K54, K5B, K37, K71, K69, K7A, K17, K75, K0F, K79, \
   K03, K0B, K38, K1C, K1B, K23, K2B, K34, K33, K3B, K42, K4B, K4C, K52, K6B, K73, K74, K28,                          \
   K00, K0A, K12, K1A, K22, K21, K2A, K32, K31, K3A, K41, K49, K2F, K59, K5D, K30, K18, K72, K19, K5A,                \
   K01, K09, K11, K58, K29, K0E, K14, K02, K10, K20, K1F, K27                                                         \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07 }, \
{ K08, K09, K0A, K0B, K0C, K0D, K0E, K0F }, \
{ K10, K11, K12, K13, K14, K15, K16, K17 }, \
{ K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
{ K20, K21, K22, K23, K24, K25, K26, K27 }, \
{ K28, K29, K2A, K2B, K2C, K2D, K2E, K2F }, \
{ K30, K31, K32, K33, K34, K35, K36, K37 }, \
{ K38, XXX, K3A, K3B, K3C, K3D, K3E, XXX }, \
{ XXX, K41, K42, K43, K44, K45, K46, XXX }, \
{ XXX, K49, K4A, K4B, K4C, K4D, K4E, XXX }, \
{ XXX, XXX, K52, XXX, K54, K55, XXX, XXX }, \
{ K58, K59, K5A, K5B, XXX, K5D, XXX, XXX }, \
{ XXX, XXX, XXX, XXX, XXX, XXX, K66, XXX }, \
{ XXX, K69, XXX, K6B, K6C, XXX, XXX, XXX }, \
{ K70, K71, K72, K73, K74, K75, K76, K77 }, \
{ K78, K79, K7A, K7B, K7C, K7D, K7E, XXX } \
}

/*
      0    1    2    3    4    5    6    7
0   { K00, K01, K02, K03, K04, K05, K06, K07 }, \
1   { K08, K09, K0A, K0B, K0C, K0D, K0E, K0F }, \
2   { K10, K11, K12, K13, K14, K15, K16, K17 }, \
3   { K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
4   { K20, K21, K22, K23, K24, K25, K26, K27 }, \
5   { K28, K29, K2A, K2B, K2C, K2D, K2E, K2F }, \
6   { K30, K31, K32, K33, K34, K35, K36, K37 }, \
7   { K38, K39, K3A, K3B, K3C, K3D, K3E, K3F }, \
8   { K40, K41, K42, K43, K44, K45, K46, K47 }, \
9   { K48, K49, K4A, K4B, K4C, K4D, K4E, K4F }, \
10  { K50, K51, K52, K53, K54, K55, K56, K57 }, \
11  { K58, K59, K5A, K5B, K5C, K5D, K5E, K5F }, \
12  { K60, K61, K62, K63, K64, K65, K66, K67 }, \
13  { K68, K69, K6A, K6B, K6C, K6D, K6E, K6F }, \
14  { K70, K71, K72, K73, K74, K75, K76, K77 }, \
15  { K78, K79, K7A, K7B, K7C, K7D, K7E, K7F }, \
*/
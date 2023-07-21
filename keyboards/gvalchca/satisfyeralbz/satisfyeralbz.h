#pragma once

#include "quantum.h"

#define BONGO_ENABLE

enum oled_modes {
  OLED_BONGO,
  OLED_BONGO_MIN,
  OLED_OFF,
  _NUM_OLED_MODES
};


// readability
#define XXX KC_NO

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k010, k011, k012,       k014, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k110, k111, k112, k113, k114, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k210, k211, k212, k213, k214, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k310, k311, k312,       k314, \
    k40,      k42, k43, k44, k45, k46, k47, k48, k49, k410, k411, k412, k413, k414, \
    k50, k51, k52,                k56,           k59, k510, k511, k512, k513, k514  \
) \
{ \
    {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k010, k011, k012,  XXX, k014}, \
    {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k110, k111, k112, k113, k114}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k210, k211, k212, k213, k214}, \
    {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k310, k311, k312,  XXX, k314}, \
    {k40, XXX, k42, k43, k44, k45, k46, k47, k48, k49, k410, k411, k412, k413, k414}, \
    {k50, k51, k52, XXX, XXX, XXX, k56, XXX, XXX, k59, k510, k511, k512, k513, k514}  \
}

#define LAYOUT_all( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k010, k011, k012,       k014, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k110, k111, k112, k113, k114, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k210, k211, k212, k213, k214, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k310, k311, k312,       k314, \
    k40,      k42, k43, k44, k45, k46, k47, k48, k49, k410, k411, k412, k413, k414, \
    k50, k51, k52,                k56,           k59, k510, k511, k512, k513, k514  \
) \
{ \
    {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k010, k011, k012,  XXX, k014}, \
    {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k110, k111, k112, k113, k114}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k210, k211, k212, k213, k214}, \
    {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k310, k311, k312,  XXX, k314}, \
    {k40, XXX, k42, k43, k44, k45, k46, k47, k48, k49, k410, k411, k412, k413, k414}, \
    {k50, k51, k52, XXX, XXX, XXX, k56, XXX, XXX, k59, k510, k511, k512, k513, k514}  \
}

void matrix_init_user(void);
void matrix_scan_user(void);

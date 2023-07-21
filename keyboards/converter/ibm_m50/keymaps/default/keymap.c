
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /*
    * ,-----------. ,-----------. ,---------------.
    * | 1C| 1D| 24| | 2D| D5| 3C| | 43| 44| 4C| 71|
    * |-----------| |-----------| |---------------|
    * | 1A| 22| 21| | 2A| 5A| 3A| | 41| 4B| 49| 4A|
    * |-----------| |-----------| |---------------|
    * | 16| 1E| 26| | 25| 09| 3D| | 3E| 46| 45| 52|
    * |-----------| |-----------| |---------------|
    * | 12| 05| 06| | 2E| 01| 36| | 55| 0A| 54| 4E|
    * |-----------| |-----------| |---------------|
    * | 14| 11| 04| | 2C| 66| 35| | 5B| 0B| 83| 33|
    * `-----------' `-----------' `---------------'
    */
         
    [0] = LAYOUT(
                 KC_A,   KC_B,   KC_C,      KC_P,   KC_Q,   KC_R,      KC_PAST,KC_PSLS,KC_PPLS,KC_PMNS, \
                 KC_D,   KC_E,   KC_F,      KC_S,   KC_T,   KC_U,      KC_7,   KC_8,   KC_9,   KC_PENT, \
                 KC_G,   KC_H,   KC_I,      KC_V,   KC_W,   KC_X,      KC_4,   KC_5,   KC_6,   KC_PCMM, \
                 KC_J,   KC_K,   KC_L,      KC_Y,   KC_Z,   KC_SLSH,   KC_1,   KC_2,   KC_3,   KC_TAB,  \
                 KC_M,   KC_N,   KC_O,      KC_LSFT,KC_SPC, KC_BSPC,   KC_0,   KC_PDOT,KC_LBRC,KC_RBRC  \
    ),
    [1] = LAYOUT(
                 KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
                 KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
                 KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
                 KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
                 KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS  \
    ),

};

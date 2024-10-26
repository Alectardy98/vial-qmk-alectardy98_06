
#include "cherry_4060_a.h"

#ifdef LED_MATRIX_ENABLE
#include "led_state.h"

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    {  7,  6,  5,  4 },
    { 11, 10,  9,  8 },
    { 15, 14, 13, 12 },
    { 19, 18, 17, 16 },
    { 23, 22, 21, 20 },
    { 27, 26, 25, 24 },
    { 31, 30, 29, 28 },
    {  3,  2,  1,  0 },
}, {
    // LED Index to Physical Position
              { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 },
    { 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 1 }, { 4, 1 }, { 5, 1 },
    { 0, 2 }, { 1, 2 }, { 2, 2 }, { 3, 2 }, { 4, 2 }, { 5, 2 },
    { 0, 3 }, { 1, 3 }, { 2, 3 }, { 3, 3 }, { 4, 3 }, { 5, 3 },
    { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 }, { 4, 4 }, { 5, 4 },
              { 1, 5 }, { 2, 5 }, { 3, 5 }, { 4, 5 }
}, {
    // LED Index to Flag
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4
} };

const led_matrix_t g_led_matrix[DRIVER_LED_TOTAL] = {
    // LED Index to Key Matrix
    { 7, 3 }, { 7, 2 }, { 7, 1 }, { 7, 0 },
    { 0, 3 }, { 0, 2 }, { 0, 1 }, { 0, 0 },
    { 1, 3 }, { 1, 2 }, { 1, 1 }, { 1, 0 },
    { 2, 3 }, { 2, 2 }, { 2, 1 }, { 2, 0 },
    { 3, 3 }, { 3, 2 }, { 3, 1 }, { 3, 0 },
    { 4, 3 }, { 4, 2 }, { 4, 1 }, { 4, 0 },
    { 5, 3 }, { 5, 2 }, { 5, 1 }, { 5, 0 },
    { 6, 3 }, { 6, 2 }, { 6, 1 }, { 6, 0 }
};
#endif

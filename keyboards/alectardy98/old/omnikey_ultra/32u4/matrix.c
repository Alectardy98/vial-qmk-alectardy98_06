
#include "debug.h"
#include "matrix.h"
#include "print.h"
#include "ps2.h"
#include "timer.h"

// Very sparse. Wasting this much space (12 rows for one key) makes prefix mapping much easier.
static matrix_row_t matrix[MATRIX_ROWS];
#define ROW(code) (code>>5)
#define COL(code) (code&0x1F)

inline
static void matrix_make(uint16_t code) {
    matrix[ROW(code)] |= ((matrix_row_t)1 << COL(code));
}

inline
static void matrix_break(uint16_t code) {
    matrix[ROW(code)] &= ~((matrix_row_t)1 << COL(code));
}

inline
static void matrix_clear(void) {
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) matrix[i] = 0;
}

__attribute__ ((weak))
void matrix_init_kb(void) {
    matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
    matrix_scan_user();
}

__attribute__ ((weak))
void matrix_init_user(void) {
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}

void matrix_init(void) {
    matrix_clear();

    ps2_host_init();

    matrix_init_quantum();
}

typedef enum {
    NORMAL,
    _F0,
    _F0_12,
    _E0,
    _E0_F0,
    _E1,
    _E1_F0,
    _12,                        //new state added for when left shift is pressed
    _12_F0                      //new state added for when left shift is followed by F0 (which normaly denotes the key release)
} state_t;

uint8_t matrix_scan(void) {
    static state_t state = NORMAL;

    uint8_t code = ps2_host_recv();

    bool sent = false;
    if (!code) return 0;

    switch (state) {
    case NORMAL:
        switch (code) {
        case 0xF0:
            state = _F0;
            break;
        case 0xE0:
            state = _E0;
            break;
        case 0xE1:
            state = _E1;
            break;
        case 0x12:
            state = _12;        //switch state added for left shift
            break;
        default:
            matrix_make(code);
            sent = true;
            break;
        }
        break;
    case _F0:
        switch (code) {
            case 0x12:                  // Sent when Num Lock enabled?
            state = _F0_12;        //switch state added for left shift
            break;
        default:
            matrix_break(0x000 | code);
            sent = true;
            break;
        }
        break;
    case _F0_12:                //State for when the key releaseing
        switch (code) {
            break;
        case 0x12:              //If we get a 12, We want to stay in this state
            break;
        case 0xF0:              //If we get a F0, We want to stay in this state=
            break;
        default:
            matrix_break(0x200 | code);
            sent = true;
            break;
        }
        break;
    case _E0:
        switch (code) {
        case 0xF0:
            state = _E0_F0;
            break;
        case 0x12:                  // Sent when Num Lock enabled?
            sent = true;
            break;
        default:
            matrix_make(0x100 | code);
            sent = true;
            break;
        }
        break;
    case _E0_F0:
        switch (code) {
        case 0x12:
            sent = true;
            break;
        default:
            matrix_break(0x100 | code);
            sent = true;
            break;
        }
        break;
    case _E1:
        switch (code) {
        case 0xF0:
            state = _E1_F0;
            break;
        case 0x14:                  // Pause is E1,14,77
            break;
        default:
            matrix_make(0x200 | code);
            sent = true;
            break;
        }
        break;
    case _E1_F0:
        switch (code) {
        case 0x14:
            state = _E1;
            break;
        default:
            matrix_break(0x200 | code);
            sent = true;
            break;
        }
        break;
    case _12:               //this was added when the key is first pressed, when the scan code _12 is seen it brings me to this case, and this part is working
        switch (code) {
        case 0xF0:          //This is sent when Key is released F0 12 F0 XX
            state = _12_F0;  //This is the state that I would like to switch to on key release
            sent = true;
            break;
        case 0x12:              //If we get a 12, We want to stay in this state
            break;
        default:
            matrix_make(0x200 | code);      //when in state _12, the following key is broken and sent +200 to the origonal scan code
            sent = true;
            break;
        }
        break;
    case _12_F0:                //State for when the key releaseing
        switch (code) {
            break;
        case 0x05:
            matrix_break(0x200 | code);
            sent = true;
            break;
        case 0x12:              //If we get a 12, We want to stay in this state
            break;
        case 0xF0:              //If we get a F0, We want to stay in this state=
            break;
        default:
            matrix_break(0x200 | code);
            sent = true;
            break;
        }
        break;

    }
    if (sent) {
        state = NORMAL;
    }

    dprintf("%02X%c", code, sent ? '\n' : ' ');
    matrix_scan_quantum();
    return 1;
}

void matrix_print(void) {
    print("\nr/c 0123456789ABCDEF0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        print_hex8(row); print(": ");
        print_bin_reverse32(matrix_get_row(row));
        print("\n");
    }
}

inline
matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}

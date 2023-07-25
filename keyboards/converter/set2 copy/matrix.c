
#include "debug.h"
#include "matrix.h"
#include "print.h"
#include "ps2.h"
#include "timer.h"

// Very sparse. Wasting this much space (12 rows for one key) makes prefix mapping much easier.
static matrix_row_t matrix[MATRIX_ROWS];
#define ROW(code) (code>>3)
#define COL(code) (code&0x7)

inline
static void matrix_make(uint8_t code) {
    matrix[ROW(code)] |= ((matrix_row_t)1 << COL(code));
}

inline
static void matrix_break(uint8_t code) {
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
    _E0,
    _E0_F0,
    _E1,
    _E1_F0
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
        case 0x83:                  //fix for f7
            matrix_make(0x00);
            sent = true;
            break;
        case 0x77:                  //fix for numlock
            matrix_make(0x08);
            sent = true;
            break;
        case 0x7D:                  //fix for numpad 9
            matrix_make(0x0F);
            sent = true;
            break;
        case 0x7C:                  //fix for numpad pound
            matrix_make(0x13);
            sent = true;
            break;
        case 0x6C:                  //fix for numpad 7
            matrix_make(0x17);
            sent = true;
            break;
        case 0x69:                  //fix for numpad 1
            matrix_make(0x18);
            sent = true;
            break;
        case 0x7A:                  //fix for numpad 3
            matrix_make(0x19);
            sent = true;
            break;
        case 0x70:                  //fix for numpad 0
            matrix_make(0x1F);
            sent = true;
            break;
        case 0x71:                  //fix for numpad dot
            matrix_make(0x27);
            sent = true;
            break;
        case 0x55:                  //fix for numpad equil
            matrix_make(0x28);
            sent = true;
            break;
        case 0x4A:                  //fix for question
            matrix_make(0x2F);
            sent = true;
            break;
        case 0x5A:                  //fix for Enter
            matrix_make(0x37);
            sent = true;
            break;
        case 0x14:                  //fix for Caps
            matrix_make(0x38);
            sent = true;
            break;
        default:
            matrix_make(code);
            sent = true;
            break;
        }
        break;
    case _F0:
        switch (code) {
        case 0x83:
            matrix_break(0x00);
            sent = true;
            break;
        case 0x77:
            matrix_break(0x08);
            sent = true;
            break;
        case 0x7D:
            matrix_break(0x0F);
            sent = true;
            break;
        case 0x7C:
            matrix_break(0x13);
            sent = true;
            break;
        case 0x6C:
            matrix_break(0x17);
            sent = true;
            break;
        case 0x69:
            matrix_break(0x18);
            sent = true;
            break;
        case 0x7A:
            matrix_break(0x19);
            sent = true;
            break;
        case 0x70:
            matrix_break(0x1F);
            sent = true;
            break;
        case 0x71:
            matrix_break(0x27);
            sent = true;
            break;
        case 0x55:
            matrix_break(0x28);
            sent = true;
            break;
        case 0x4A:
            matrix_break(0x2F);
            sent = true;
            break;
        case 0x5A:
            matrix_break(0x37);
            sent = true;
            break;
        case 0x14:
            matrix_break(0x38);
            sent = true;
            break;
        default:
            matrix_break( code);
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
        case 0x6B:                  // Sent left arrow
            matrix_make(0x02);
            sent = true;
            break;
        case 0x74:                  // Sent right arrow
            matrix_make(0x20);
            sent = true;
            break;
        case 0x75:                  // Sent up arrow
            matrix_make(0x30);
            sent = true;
            break;
        case 0x72:                  // Sent down arrow
            matrix_make(0x10);
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
        case 0x6B:                  // Sent left arrow
            matrix_break(0x02);
            sent = true;
            break;
        case 0x74:                  // Sent right arrow
            matrix_break(0x20);
            sent = true;
            break;
        case 0x75:                  // Sent up arrow
            matrix_break(0x30);
            sent = true;
            break;
        case 0x72:                  // Sent down arrow
            matrix_break(0x10);
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

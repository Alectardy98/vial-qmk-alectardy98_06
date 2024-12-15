#include <stdint.h>
#include <stdbool.h>
#include <util/atomic.h>
#include "action.h"
#include "led.h"
#include "print.h"
#include "util.h"
#include "debug.h"
#include "itw.h"
#include "matrix.h"

#define LED_OT  1
#define LED_LK  2
#define LED_F1  3
#define LED_F2  4
#define LED_F3  5
#define LED_F8  6
#define LED_F9  7
#define LED_F10 8

extern uint8_t kbd_state;
extern uint8_t received[KEYS];
extern void send_itw_led_codes(void);
extern void set_itw_led(uint8_t led, uint8_t mode);

static void matrix_make(uint8_t code);

static uint8_t matrix[MATRIX_ROWS];

#define ROW(code) (code & 0xF)
#define COL(code) ((code >> 4) & 0x7)

__attribute__ ((weak))
void matrix_init_kb(void)
{matrix_init_user();}

__attribute__ ((weak))
void matrix_scan_kb(void)
{matrix_scan_user();}

__attribute__ ((weak))
void matrix_init_user(void) {}

__attribute__ ((weak))
void matrix_scan_user(void) {}

inline uint8_t matrix_get_row(uint8_t row)
{return matrix[row];}

bool matrix_is_on(uint8_t row, uint8_t col)
{return (matrix_get_row(row) & (1 << col));}

#define print_matrix_header() print("\nr/c 01234567\n")
#define print_matrix_row(row) print_bin_reverse8(matrix_get_row(row))

void matrix_print(void) {
	print_matrix_header();

	for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
		print_hex8(row);
		print(": ");
		print_matrix_row(row);
		print("\n");
	}
}

bool led_update_user(led_t led_state)
{
	set_itw_led(LED_LK, led_state.caps_lock);
	set_itw_led(LED_OT, led_state.num_lock);

	return true;
}

inline static void matrix_make(uint8_t code)
{
	if (!matrix_is_on(ROW(code), COL(code)))
	{matrix[ROW(code)] |= 1 << COL(code);}
}

inline static void matrix_break(uint8_t code)
{
	if (matrix_is_on(ROW(code), COL(code)))
	{matrix[ROW(code)] &= ~(1 << COL(code));}
}

void matrix_clear(void)
{
	for (uint8_t x = 0; x < MATRIX_ROWS; x++)
	{matrix[x] = 0;}
}

void matrix_init(void)
{
	//debug_enable = true;
	//debug_matrix = true;
	//debug_keyboard = true;

	itw_init();

	for(uint8_t i = 0; i < MATRIX_ROWS; i++)
	{matrix[i] = 0;}

	matrix_init_kb();
}

uint8_t matrix_scan(void)
{
	//ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	//{
		if (kbd_state)
		{
			for (uint8_t c = 0; c < 0x80; c++)
			{
				bool is_pressed = false;

				for (uint8_t k = 0; k < KEYS; k++)
				{
					if (!received[k])
					{break;}

					uint8_t keycode = received[k] & 0x7F;

					if (keycode == c)
					{is_pressed = true;}

					//uprintf("%02X\n", keycode);
					//uprintf("row - %02X ; col - %02X\n\n", ROW(keycode), COL(keycode));

					matrix_make(keycode);
				}

				if (!is_pressed)
				{matrix_break(c);}
			}

			kbd_state = 0;
		}
	//}

	send_itw_led_codes();
	return 1;
}

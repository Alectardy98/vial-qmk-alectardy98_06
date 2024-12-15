#include <avr/interrupt.h>
#include <util/atomic.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>
#include "itw.h"

uint8_t received[KEYS];
uint8_t leds = 0xFF;
uint8_t previous_leds = 0;
uint8_t kbd_state = 0;

#define LED_OT  1
#define LED_LK  2
#define LED_F1  3
#define LED_F2  4
#define LED_F3  5
#define LED_F8  6
#define LED_F9  7
#define LED_F10 8

void clear_buffer(uint8_t *buffer)
{
	for (uint8_t x = 0; x < KEYS; x++)
	{buffer[x] = 0;}
}

void send_itw_led_codes(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		if (previous_leds != leds)
		{
			for (uint8_t page = 0x81; page <= 0x85; page += 4)
			{
				uint8_t setting = (leds & (0xF << (page & 0x04)));
				uint8_t packet = (setting >> (page & 0x04)) << 3;
				for (uint8_t b = 1; b <= 8; b++)
				{
					if (gpio_read_pin(B1))
					{
						gpio_write_pin_low(F7);
						return;
					}

					gpio_write_pin(F7, ((packet | page) >> (8 - b)) & 1);
					_delay_us(825);
				}
				gpio_write_pin_low(F7);
				_delay_us(825);
				_delay_us(825);
			}

			previous_leds = leds;
		}
	}
}

void toggle_itw_led(uint8_t led)
{
	if (led < 1 || led > 8)
	{return;}

	if (led)
	{leds ^= 1 << (led - 1);}
}

void set_itw_led(uint8_t led, uint8_t mode)
{
	if (led < 1 || led > 8)
	{return;}

	if (led)
	{
		if (! mode)
		{leds |= (1 << (led - 1));}
		else
		{leds &= ~(1 << (led - 1));}
	}
}

void itw_init(void)
{
	// initialize pins
	gpio_set_pin_output(F7);
	gpio_set_pin_output(F6);
	gpio_set_pin_input(B1);
	gpio_write_pin_high(B1);

	// restarts the keyboard
	gpio_write_pin_high(F7);
	gpio_write_pin_low(F6);
	_delay_ms(10);
	gpio_write_pin_high(F6);
	gpio_write_pin_low(F7);
	_delay_ms(1500);

	// enable interrupt for B1
	PCICR = 1 << PCIE0;
	PCMSK0 = 1 << PCINT1;

	send_itw_led_codes();
}

ISR(PCINT0_vect)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		if (! gpio_read_pin(B1))
		{return;}

		uint8_t new_buffer[KEYS];
		clear_buffer(new_buffer);

		uint8_t restart = 0;

		while(1)
		{
			uint8_t keycode = 0;

			_delay_us(400);

			if (restart && !gpio_read_pin(B1))
			{break;}

			for (uint8_t x = 0; x < 8; x++)
			{
				if (x)
				{_delay_us(400);}

				if (gpio_read_pin(B1))
				{keycode |= 1 << (7 - x);}
				_delay_us(425);
			}

			if (keycode == 0xFE)
			{kbd_state = 1;}

			for (uint8_t key = 0; key < KEYS; key++)
			{
				if (keycode == 0xFE)
				{
					received[key] = 0;
					continue;
				}

				if (! new_buffer[key])
				{
					new_buffer[key] = keycode;
					break;
				}
			}

			_delay_us(500);
			if (gpio_read_pin(B1))
			{
				_delay_us(825);
				if (gpio_read_pin(B1))
				{
					clear_buffer(received);
					_delay_us(425);
					break;
				}

				_delay_us(425);

				restart = 1;

				for(uint8_t t = 0; t <= 100; t++)
				{
					_delay_us(5);
					if (gpio_read_pin(B1))
					{break;}
				}

				continue;
			}

			break;
		}

		uint8_t b = 0;
		while (b < KEYS)
		{
			if (! new_buffer[b])
			{break;}

			for (uint8_t k = 0; k < KEYS; k++)
			{
				if (! received[k])
				{
					received[k] = new_buffer[b];
					kbd_state = 1;
					b--;
					break;
				}

				if (new_buffer[b] == received[k])
				{break;}
			}

			b++;
		}

		for (uint8_t k = 0; k < KEYS; k++)
		{
			if (! received[k])
			{break;}

			for (uint8_t b = 0; b < KEYS; b++)
			{
				if (! new_buffer[b])
				{
					for (uint8_t u = k; u < KEYS - 1; u++)
					{
						if (! received[u] && ! received[u + 1])
						{break;}
						received[u] = received[u + 1];
					}
					kbd_state = 1;
					break;
				}

				if (received[k] == new_buffer[b])
				{break;}

			}
		}
	}

	// clear all LEDs except OT, LK
	leds |= 0xFC;

	for (uint8_t key = 0; key < KEYS; key++)
	{
		if (! received[key])
		{break;}

		switch(received[key])
		{
			//case 0xEE: // OT
			//	set_itw_led(LED_OT, 1);
			//	break;

			//case 0xAE: // LK
			//	set_itw_led(LED_LK, 1);
			//	break;

			case 0xAB: // F1
				set_itw_led(LED_F1, 1);
				break;

			case 0xCB: // F2
				set_itw_led(LED_F2, 1);
				break;

			case 0x8B: // F3
				set_itw_led(LED_F3, 1);
				break;

			case 0xA3: // F8
				set_itw_led(LED_F8, 1);
				break;

			case 0xC3: // F9
				set_itw_led(LED_F9, 1);
				break;

			case 0x83: // F10
				set_itw_led(LED_F10, 1);
				break;
		}
	}
}

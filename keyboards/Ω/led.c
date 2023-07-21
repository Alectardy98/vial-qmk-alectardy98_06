// A document archiving all of my custom code

/*
#include "stdint.h"
#include "ps2.h"
#include "led.h"

 This is how LEDs overide on FAT on xwhatsit
  
 void matrix_scan_user(void) {                                         //note that this will run on a constant loop
     if (layer_state_is(_FN)){                                         // When in layer _FN, this will activate the scroll lock light
         led_set(host_keyboard_leds() | (1<<USB_LED_SCROLL_LOCK));
     } else if (layer_state_is(_NUM)){                                 //When in layer _NUM, this will activate Num lock light
         led_set(host_keyboard_leds() | (1<<USB_LED_NUM_LOCK));
     } else {                                                          // When in base layer turn everything off
         led_set(host_keyboard_leds() & ~(1<<USB_LED_NUM_LOCK));
         led_set(host_keyboard_leds() & ~(1<<USB_LED_SCROLL_LOCK));
     };
 };

 ///////////////////
  
  This is how LED overides work on PS2
  
  void led_set(uint8_t usb_led) {
      uint8_t ps2_led = 0;
      if (usb_led &  (1<<USB_LED_SCROLL_LOCK))
          ps2_led |= (1<<PS2_LED_SCROLL_LOCK);
      if (usb_led &  (1<<USB_LED_NUM_LOCK))
          ps2_led |= (1<<PS2_LED_NUM_LOCK);
      if (usb_led &  (1<<USB_LED_CAPS_LOCK))
          ps2_led |= (1<<PS2_LED_CAPS_LOCK);
      ps2_host_set_led(ps2_led);
  }

 ////////////////////////
  
 This is how Led Overides work on Gold Label

  void led_set(uint8_t usb_led) {
      uint8_t ps2_led = 0;
      if (layer_state_is(_FN))
          ps2_led |= (1<<PS2_LED_SCROLL_LOCK);
      if (layer_state_is(_NUM))
          ps2_led |= (1<<PS2_LED_NUM_LOCK);
      if (layer_state_is(_CAPS))
          ps2_led |= (1<<PS2_LED_CAPS_LOCK);
      ps2_host_set_led(ps2_led);
  }
  
  
  
  This is how Led Overides work on zenithal

  void led_set(uint8_t usb_led) {                          //Lock Light LED Overide
      if (layer_state_is(_FN)) {                           //Force Scroll Lock LED On when In layer FN
          writePinHigh(C6);
      } else {
          writePinLow(C6);
      }
      if (layer_state_is(_NUM)) {                          //Force Num Lock LED On when In layer NUM
          writePinHigh(C7);
      } else {
          writePinLow(C7);
      }
      if (usb_led &  (1<<USB_LED_CAPS_LOCK)) {            //Put Caps LED on when keybaoard state is Caps
          writePinHigh(F0);
      } else {
          writePinLow(F0);
      }
  }

*/

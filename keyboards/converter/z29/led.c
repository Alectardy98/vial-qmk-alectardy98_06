
#include "quantum.h"
#include "z29_state.h"

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
        z29_state.caps = led_state.caps_lock;
    }
    return true;
}

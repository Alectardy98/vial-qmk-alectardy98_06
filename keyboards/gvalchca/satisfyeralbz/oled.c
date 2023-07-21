#include "satisfyeralbz.h"

#ifdef BONGO_ENABLE
#include "bongo.h"
#endif

void draw_default(void);

#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) { return OLED_ROTATION_0; }

bool oled_task_kb(void) {
    if (!oled_task_user()) { return false; }
    if (!oled_task_needs_to_repaint()) {
        return false;
    }
    oled_clear();
    switch (oled_mode) {
        default:
        case OLED_BONGO:
            draw_bongo(false);
            break;
        case OLED_BONGO_MIN:
            draw_bongo(true);
            break;
    }
    return false;
}

// Request a repaint of the OLED image without resetting the OLED sleep timer.
// Used for things like clock updates that should not keep the OLED turned on
// if there is no other activity.
void oled_request_repaint(void) {
    if (is_oled_on()) {
        oled_repaint_requested = true;
    }
}

// Request a repaint of the OLED image and reset the OLED sleep timer.
// Needs to be called after any activity that should keep the OLED turned on.
void oled_request_wakeup(void) {
    oled_wakeup_requested = true;
}

// Check whether oled_task_user() needs to repaint the OLED image.  This
// function should be called at the start of oled_task_user(); it also handles
// the OLED sleep timer and the OLED_OFF mode.
bool oled_task_needs_to_repaint(void) {
    // In the OLED_OFF mode the OLED is kept turned off; any wakeup requests
    // are ignored.
    if ((oled_mode == OLED_OFF) && !clock_set_mode) {
        oled_wakeup_requested = false;
        oled_repaint_requested = false;
        oled_off();
        return false;
    }

    // If OLED wakeup was requested, reset the sleep timer and do a repaint.
    if (oled_wakeup_requested) {
        oled_wakeup_requested = false;
        oled_repaint_requested = false;
        oled_sleep_timer = timer_read32() + CUSTOM_OLED_TIMEOUT;
        oled_on();
        return true;
    }

    // If OLED repaint was requested, just do a repaint without touching the
    // sleep timer.
    if (oled_repaint_requested) {
        oled_repaint_requested = false;
        return true;
    }

    // If the OLED is currently off, skip the repaint (which would turn the
    // OLED on if the image is changed in any way).
    if (!is_oled_on()) {
        return false;
    }

    // If the sleep timer has expired while the OLED was on, turn the OLED off.
    if (timer_expired32(timer_read32(), oled_sleep_timer)) {
        oled_off();
        return false;
    }

    // Always perform a repaint if the OLED is currently on.  (This can
    // potentially be optimized to avoid unneeded repaints if all possible
    // state changes are covered by oled_request_repaint() or
    // oled_request_wakeup(), but then any missed calls to these functions
    // would result in displaying a stale image.)
    return true;
}


static void draw_line_h(uint8_t x, uint8_t y, uint8_t len) {
    for (uint8_t i = 0; i < len; i++) {
        oled_write_pixel(i + x, y, true);
    }
}

static void draw_line_v(uint8_t x, uint8_t y, uint8_t len) {
    for (uint8_t i = 0; i < len; i++) {
        oled_write_pixel(x, i + y, true);
    }
}

#endif
#include QMK_KEYBOARD_H

#include "quantum.h"
#include "process_magic.h"


enum keyboard_keycodes {
    LOCK_GUI = QK_KB,
    TOG_MACOS_KEYMAP,
    TOG_WIN_KEYMAP,
    SW_CTR_GUI,
    KC_AB,
    KC_MISSION_CONTROL_MAC,
    KC_LAUNCHPAD_MAC,
    KC_LCOMMAND,
    KC_RCOMMAND,
    KC_LOPTION,
    KC_ROPTION,
};

#define MKC_LG     LOCK_GUI
#define MKC_MACOS  TOG_MACOS_KEYMAP
#define MKC_WIN    TOG_WIN_KEYMAP
#define MKC_SWCG   SW_CTR_GUI
#define MKC_AB     KC_AB
#define MKC_MCTL   KC_MISSION_CONTROL_MAC
#define MKC_LPAD   KC_LAUNCHPAD_MAC
#define MKC_LCOMM  KC_LCOMMAND
#define MKC_RCOMM  KC_RCOMMAND
#define MKC_LOPT   KC_LOPTION
#define MKC_ROPT   KC_ROPTION

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


uint8_t mod_state;
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) { return false; }
    mod_state = get_mods();
    switch(keycode) {
        case MKC_LG:
            if (record->event.pressed) {
                process_magic(GU_TOGG, record);
            }
            return false;
        case MKC_MACOS:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << 2);
            }
            return false;
        case MKC_WIN:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << 0);
            }
            return false;
        case MKC_SWCG:
            if (record->event.pressed) {
                process_magic(CG_TOGG, record);
            }
            return false;
        case MKC_AB:
            {
                static bool lt_registered;
                static bool gt_registered;
                if (record->event.pressed) {
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_SHIFT);
                        register_code16(KC_LT);
                        lt_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        gt_registered = true;
                        register_code16(KC_GT);
                        return false;
                    }
                } else {
                    if (lt_registered) {
                        unregister_code16(KC_LT);
                        lt_registered = false;
                        return false;
                    }
                    if (gt_registered) {
                        unregister_code16(KC_GT);
                        gt_registered = false;
                        return false;
                    }
                }
                return false;
            }
        case MKC_MCTL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;
        case MKC_LPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;
        case MKC_LCOMM:
            if (record->event.pressed) {
                register_code(KC_LCMD);
            } else {
                unregister_code(KC_LCMD);
            }
            return false;
        case MKC_RCOMM:
            if (record->event.pressed) {
                register_code(KC_RCMD);
            } else {
                unregister_code(KC_RCMD);
            }
            return false;
        case MKC_LOPT:
            if (record->event.pressed) {
                register_code(KC_LOPT);
            } else {
                unregister_code(KC_LOPT);
            }
            return false;
        case MKC_ROPT:
            if (record->event.pressed) {
                register_code(KC_ROPT);
            } else {
                unregister_code(KC_ROPT);
            }
            return false;
        default:
            return true;
    }
    return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS]= {
  /* 0: defuault */
    [0] = LAYOUT(
	KC_F1, KC_F2,	KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSLS,  KC_BSPC, KC_NUM,  KC_PSLS,  KC_PAST, KC_PMNS,
	KC_F3, KC_F4,	KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_P7,   KC_P8,   KC_P9,    XXXXXXX, 
	KC_F5, KC_F6,	KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,   KC_P4,   KC_P5,   KC_P6,    KC_PPLS,  
	KC_F7, KC_F8,	KC_LSFT, KC_BSLS, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  KC_UP,    KC_P1,   KC_P2,   KC_P3,    XXXXXXX,
	KC_F9, KC_F10,	KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,                                     KC_RALT, MO(1),   KC_RGUI, KC_LEFT,  KC_RCTL,  KC_RGHT,  XXXXXXX, KC_P0,   KC_PDOT,  KC_PENT 
  ),
      //  ESC             F1       F2       F3       F4       F5       F6       F7      F8        F9       F10       F11     F12       PSCR   SLCK
    [1] = LAYOUT(
	XXXXXXX, XXXXXXX, KC_GRV,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,     KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, KC_MSEL, KC_VOLD, KC_VOLU,KC_MUTE, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT,   KC_MAIL, KC_WHOM, KC_CALC, KC_WSCH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, AU_ON,   AU_OFF,  CK_UP,  CK_DOWN, CK_RST,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HF_ON,   HF_OFF, HF_FDBK, HF_RST,  XXXXXXX, XXXXXXX, MKC_MACOS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, MKC_LG,  XXXXXXX, XXXXXXX,                                    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX 
  ),
    [2] = LAYOUT(
	KC_F1, KC_F2,	KC_ESC,  KC_1,     KC_2,      KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_MINS,  KC_EQL,   KC_BSLS,  KC_BSPC, KC_NUM,  KC_PSLS,  KC_PAST,  KC_PMNS,
	KC_F3, KC_F4,	KC_TAB,  KC_Q,     KC_W,      KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_P7,   KC_P8,   KC_P9,    XXXXXXX,
	KC_F5, KC_F6,	KC_CAPS, KC_A,     KC_S,      KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_QUOT,            KC_ENT,   KC_P4,   KC_P5,   KC_P6,    KC_PPLS,  
	KC_F7, KC_F8,	KC_LSFT, KC_BSLS,  KC_Z,      KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,  KC_RSFT,  KC_UP,    KC_P1,   KC_P2,   KC_P3,    XXXXXXX,
	KC_F9, KC_F10,	KC_LCTL, MKC_LOPT, MKC_LCOMM, KC_SPC,                                     MKC_RCOMM, MO(3), MKC_ROPT,  KC_LEFT,  KC_RCTL,  KC_RGHT,  XXXXXXX, KC_P0,   KC_PDOT,  KC_PENT
  ),
    [3] = LAYOUT(
	XXXXXXX, XXXXXXX, KC_GRV,  KC_MSEL, KC_VOLD, KC_VOLU,KC_MUTE, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT,   KC_MAIL, KC_WHOM, KC_CALC, KC_WSCH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,     KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, AU_ON,   AU_OFF,  CK_UP,  CK_DOWN, CK_RST,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HF_ON,   HF_OFF, HF_FDBK, HF_RST,  XXXXXXX, XXXXXXX, MKC_WIN,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX 
  ),
};

#ifdef AUDIO_ENABLE
  float caps_on[][2] = SONG(CAPS_LOCK_ON_SOUND);
  float caps_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);
  float num_on[][2] = SONG(NUM_LOCK_ON_SOUND);
  float num_off[][2] = SONG(NUM_LOCK_OFF_SOUND);
#endif

bool led_update_user(led_t led_state) {
    #ifdef AUDIO_ENABLE
    static uint8_t caps_state = 0;
    if (caps_state != led_state.caps_lock) {
        led_state.caps_lock ? PLAY_SONG(caps_on) : PLAY_SONG(caps_off);
        caps_state = led_state.caps_lock;
	}
	static uint8_t num_state = 0;
	if (num_state != led_state.num_lock) {
        led_state.num_lock ? PLAY_SONG(num_on) : PLAY_SONG(num_off);
        num_state = led_state.num_lock;
	}
    #endif
    return true;
}

#pragma once
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
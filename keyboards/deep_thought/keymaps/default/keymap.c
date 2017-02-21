#define UNICODE_ENABLE

#include "keymap_common.h"
#include "quantum.h"

#define KC_PND LALT(KC_4) //Pound sign

//Macros
#define AFLP M(0) //Angry table flip

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: dvorak */
    KEYMAP(
        TAB, QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   BSPC,FN3, \
        LCTL,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   ENT, \
        LSFT,SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z,   DEL, \
        CAPS,LGUI,ESC,LALT, SPC,      FN0, FN1, LEFT,DOWN,UP,  RGHT),

    KEYMAP(
        TAB, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   TRNS,TRNS, \
        TRNS,LBRC,RBRC,SLSH,EQL, MINS,NUHS,BSLS,GRV ,TRNS,TRNS,TRNS,\
        TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, DEL, \
        TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),

    KEYMAP(
        TRNS,EXLM,AT,  PND, DLR, PERC,CIRC,AMPR,ASTR,LPRN,RPRN,TRNS,TRNS, \
        TRNS,LCBR,RCBR,QUES,PLUS,UNDS,TILD,PIPE,TRNS,TRNS,TRNS,TRNS, \
        TRNS,INS, HOME,PGUP,PGDN,END, PSCR, F11, F12,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),

    {
        {KC_TRNS,AFLP,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
        {KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
        {KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
        {KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS}
    }
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_MOMENTARY(2),
    [2] = ACTION_LAYER_MOMENTARY(3)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (!record->event.pressed) {
    return MACRO_NONE;
  }

  switch(id) {
    case 0:
        return MACRO(TYPE(UC(0x0028)), TYPE(UC(0x30CE)), TYPE(UC(0x0CA0)), TYPE(UC(0x76CA)),
                     TYPE(UC(0x0CA0)), TYPE(UC(0x0029)), TYPE(UC(0x30CE)), TYPE(UC(0x5F61)),
                     TYPE(UC(0x234B)), TYPE(UC(0x2501)), TYPE(UC(0x253B)), END  ); // this sends the string 'hello' when the macro executes
      break;
  }
  return MACRO_NONE;
};

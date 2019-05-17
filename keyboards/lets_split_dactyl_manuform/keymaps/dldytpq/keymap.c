// This is a version of let's Split with the modifier keys moved into the thumbcluster.
// I left the matrix configuration as is, modified this file only.
// (actually I had to specify ROW2COL since in my CrocoDox I put them in the opposit direction.

//#include "lets_split.h"
#include "lets_split_dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"
//#include "keymap_steno.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _LAYER1 0
#define _LAYER2 1
#define _LAYER3 2
#define _LAYER4 3


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  TO_L1,
  TO_L2,
  TO_L3,
  TO_L4
};



// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER1
Note the alpha keys are in the lower case here.
Shift key is actually a momentary switch (MO) for Layer 2.

Note that Layer 3 switches from this layer are momentary only.
That is when that keys are held - layer 3 is activated, once they are released - it returns to layer 1.

 * ,-----------------------------------------++-----------------------------------------.
 * | Esc  |   '  |   y  |   f  |   ,  |BkSpc || Del  |   b  |   l  |   g  |   ;  |   x  |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * | MO L3|   r  |   i  |   a  |   n  |   w  ||   m  |   h  |   t  |   o  |   s  | MO L3|
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |  z   |   (  |   .  |   p  |   u  |   j  ||   k  |   c  |   d  |   v  |   )  |   q  |
 * +------+------+------+------+------+------++------+------+------+------+------+------+
		 |   +  |   <  |      |      ||      |      |   \  |   &  |
	         +------+------+      |LT L2 ||LT L2 |      +------+------+               
  		               |   e  |(LSft)||(RSft)| Space|
		               +------+------||------+------+
      Here	               | CMD  | Enter||  Tab |Opt/Alt|                Here 
	^	               +------+------||------+------+                  ^
 	+------mapped------    | LCtrl| ...  ||  ... | GUI  |  -------mapped---+
This row is wired  	       +------+------||------+------+    
on the 5th row (R4), 
hence in the key map it is in the two outermost positions.

 */
[_LAYER1] = KEYMAP( \
  KC_ESC,            KC_QUOTE,   KC_Y,          KC_F,          KC_COMM,        KC_BSPC,           KC_DEL,            KC_B,           KC_L,     KC_G,        KC_SCLN,     KC_X, \
  KC_FN3,            KC_R,       KC_I,          KC_A,          KC_N,           KC_W,              KC_M,              KC_H,           KC_T,     KC_O,        KC_S,        KC_FN3, \
  KC_Z,              KC_LPRN,    KC_DOT,        KC_P,          KC_U,           KC_J,              KC_K,              KC_C,           KC_D,     KC_V,        KC_RPRN,     KC_Q , \
  _______,           _______,    LSFT(KC_EQL),  LSFT(KC_COMM), KC_E,           KC_FN2,            KC_FN2,       KC_SPC,         KC_BSLS,  LSFT(KC_7),  _______,     _______, \
  KC_LCTL,           XXXXXXX,    _______,       _______,       KC_LGUI,        KC_ENTER,          KC_TAB,            KC_RALT,        _______,  _______,     XXXXXXX,     KC_LGUI \
),

/* LAYER2

This one seems to be primarily SHIFT layer for the alpha keys, 
and for other keys it is changes them.

It is activated from Layer 1 momentarily when Tab is held, and permanently when it only hit once.

Note this layer allows to switch to L3, L4 and stay there ( i.e locking in them)

 * ,-----------------------------------------++-----------------------------------------.
 * | ???? |   "  |   Y  |   F  |   ?  |BkSpc || Del  |   B  |   L  |   G  |   :  |   x  |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |TO L4 |   R  |   I  |   A  |   N  |   W  ||   M  |   H  |   T  |   O  |   S  | TO L4|
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |  Z   |   [  |   !  |   P  |   U  |   J  ||   K  |   C  |   D  |   V  |   ]  |   Q  |
 * +------+------+------+------+------+------++------+------+------+------+------+------+
		 |   ~  |   @  |      |      ||      |      |   |  |   %  |
	         +------+------+      |      ||      |      +------+------+               
  		               |   E  |to L1 ||to L1 | Space|
		               +------+------||------+------+
      Here	               | CMD  | Enter||  Tab |Opt/Alt|                Here 
	^	               +------+------||------+------+                  ^
 	+------mapped------    | LCtrl| TO L1|| TO L1| GUI  |  -------mapped---+
This row is wired  	       +------+------||------+------+    
on the 5th row (R4), 
hence in the key map it is in the two outermost positions.

NOTE: the shift keys (the MO(_LAYER2) ones in Layer 1) are transparent here.
      They are cannot be used for anything else since they are acting as the momentary switches.
 */
[_LAYER2] = KEYMAP( \
  TO_L4,             LSFT(KC_QUOTE),   LSFT(KC_Y),   LSFT(KC_F),  LSFT(KC_SLSH),  KC_BSPC,         KC_DEL,     LSFT(KC_B), LSFT(KC_L),     LSFT(KC_G),  LSFT(KC_SCLN), LSFT(KC_X), \
  _______,           LSFT(KC_R),       LSFT(KC_I),   LSFT(KC_A),  LSFT(KC_N),     LSFT(KC_W),      LSFT(KC_M), LSFT(KC_H), LSFT(KC_T),     LSFT(KC_O),  LSFT(KC_S),    TO_L4, \
  LSFT(KC_Z),        KC_LBRC,          LSFT(KC_1),   LSFT(KC_P),  LSFT(KC_U),     LSFT(KC_J),      LSFT(KC_K), LSFT(KC_C), LSFT(KC_D),     LSFT(KC_V),  KC_RBRC,       LSFT(KC_Q) , \
  _______,           _______,          LSFT(KC_GRV), LSFT(KC_2),  LSFT(KC_E),     TO_L1,           TO_L1,      KC_SPC,     LSFT(KC_BSLS),  LSFT(KC_5),  _______,       _______, \
  KC_LCTL,           TO_L1,            _______,      _______,     KC_LGUI,        KC_ENTER,        KC_TAB,     KC_RALT,    _______,        _______,     TO_L1,         KC_LGUI \
),

/* LAYER3
This layer is a combination of the F-keys, navigational keys, non-alpha and non-numeric characters.

Notice n/a defined for the modifiers that bring this layer up.
They cannot be set to other purpose.

 * ,-----------------------------------------++-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  ||  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |TO L1 |   $  |   /  |   =  |   -  |   {  ||   }  |   *  |   _  |   >  |   #  |TO L1 |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |  ... | ...  |  ... | Left |  Up  | ...  ||  ... | Down | Right| ...  |  ... |  ... |
 * +------+------+------+------+------+------++------+------+------+------+------+------+
		 |  ... | ...  |      |      ||      |      |  ... |   `  |
	         +------+------+      |      ||      |      +------+------+               
  		               |  ... | LT L4|| LT L4| Space|
		               +------+------||------+------+
      Here	               | CMD  | Enter||  Tab |Opt/Alt|                Here 
	^	               +------+------||------+------+                  ^
 	+------mapped------    | LCtrl| TO L1||TO L1 | GUI  |  -------mapped---+
This row is wired  	       +------+------||------+------+    
on the 5th row (R4), 
hence in the key map it is in the two outermost positions.

 */
[_LAYER3] = KEYMAP( \
  KC_F1,              KC_F2,      KC_F3,         KC_F4,    KC_F5,    KC_F6,             KC_F7,               KC_F8,      KC_F9,          KC_F10,       KC_F11,      KC_F12, \
  TO_L1,              LSFT(KC_4), LSFT(KC_SLSH), KC_EQUAL, KC_MINUS, LSFT(KC_LBRC),     LSFT(KC_RBRC),       LSFT(KC_8), LSFT(KC_MINUS), LSFT(KC_DOT), LSFT(KC_3),  TO_L1, \
  XXXXXXX,            XXXXXXX,    XXXXXXX,       KC_LEFT,  KC_UP,    XXXXXXX,           XXXXXXX,             KC_DOWN,    KC_RIGHT,       XXXXXXX,      XXXXXXX,     XXXXXXX, \
  _______,            _______,    XXXXXXX,       XXXXXXX,  XXXXXXX,  KC_FN4,            KC_FN4,          XXXXXXX,    KC_GRV,         XXXXXXX,      _______,     _______, \
  KC_LCTL,            TO_L1,      _______,       _______,  KC_LGUI,  KC_ENTER,          KC_TAB,              KC_RALT,    _______,        _______,      TO_L1,       KC_LGUI \
),

/* LAYER4
This layer is a combination of the numbers and some navigational keys.
It is 3rd layer with "shift". "Shift" here is a layer momentary switch when held, permanent when hit once.


 * ,-----------------------------------------++-----------------------------------------.
 * | TO L1|  F2  |  F3  |  F4  |  F5  |  F6  ||  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * | TO L2|   6  |   4  |   0  |   2  |   7  ||   9  |   3  |   1  |   5  |   8  |  n/a |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |  ... | ...  |  ... | Home | PgUp | ...  ||  ... | PgDn | End  | ...  |  ... |  ... |
 * +------+------+------+------+------+------++------+------+------+------+------+------+
		 |  ... | ...  |      |      ||      |      |  ... |  ^   |
	         +------+------+      |      ||      |      +------+------+               
  		               |  ... | LT L3|| LT L3| Space|
		               +------+------||------+------+
      Here	               | CMD  | Enter||  Tab |Opt/Alt|                Here 
	^	               +------+------||------+------+                  ^
 	+------mapped------    | LCtrl| TO L1|| TO L1| GUI  |  -------mapped---+
This row is wired  	       +------+------||------+------+    
on the 5th row (R4), 
hence in the key map it is in the two outermost positions.

 */
[_LAYER4] = KEYMAP( \
  TO_L1,             XXXXXXX,     XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,                 XXXXXXX,    XXXXXXX,        XXXXXXX,      XXXXXXX,    XXXXXXX, \
  TO_L1,             KC_6,        KC_4,          KC_0,     KC_2,     KC_7,              KC_9,                    KC_3,       KC_1,           KC_5,         KC_8,       TO_L1, \
  XXXXXXX,           XXXXXXX,     XXXXXXX,       KC_HOME,  KC_PGUP,  XXXXXXX,           XXXXXXX,                 KC_PGDN,    KC_END,         XXXXXXX,      XXXXXXX,    XXXXXXX, \
  _______,           _______,     XXXXXXX,       XXXXXXX,  XXXXXXX,  TO_L3,             TO_L3,                   XXXXXXX,    XXXXXXX,        LSFT(KC_6),   _______,    _______, \
  KC_LCTL,           TO_L1,        _______,       _______,  KC_LGUI,  KC_ENTER,         KC_TAB,                  KC_RALT,    _______,        _______,      TO_L1,     KC_LGUI \
)
                                                                                                                                                                    


};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_LAYER1)                // FN1 - Momentary Layer 1
,    [2] = ACTION_LAYER_TAP_TOGGLE(_LAYER2)                // FN2 - Momentary Layer 2
,    [3] = ACTION_LAYER_TAP_TOGGLE(_LAYER3)                // FN3 - Momentary Layer 3
,    [4] = ACTION_LAYER_TAP_TOGGLE(_LAYER4)                // FN4 - Momentary Layer 4
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

   case TO_L1:
      if (record->event.pressed) {
	print("Entered L3 section\n");
        layer_off(_LAYER2);
        layer_off(_LAYER3);
        layer_off(_LAYER4);
        layer_on(_LAYER1);

      }
      return false;
      break;

   case TO_L2:
      if (record->event.pressed) {
	print("Entered L2 section\n");
        layer_off(_LAYER1);
        layer_off(_LAYER3);
        layer_off(_LAYER4);
        layer_on(_LAYER2);

      }
      return false;
      break;

   case TO_L3:
      if (record->event.pressed) {
	print("Entered L3 section\n");
        layer_off(_LAYER1);
        layer_off(_LAYER2);
        layer_off(_LAYER4);
        layer_on(_LAYER3);

      }
      return false;
      break;

   case TO_L4:
      if (record->event.pressed) {
	print("Entered L4 section\n");
        layer_off(_LAYER1);
        layer_off(_LAYER2);
        layer_off(_LAYER3);
        layer_on(_LAYER4);

      }
      return false;
      break;


 }

  return true;
}
 

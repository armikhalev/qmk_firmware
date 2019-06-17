// This is a version of let's Split with the modifier keys moved into the thumbcluster.
// I left the matrix configuration as is, modified this file only.
// (actually I had to specify ROW2COL since in my CrocoDox I put them in the opposit direction.

//#include "lets_split.h"
#include "lets_split_dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _DVORAK 0
#define _CURSORRGHT 1
#define _CURSORLEFT 2
#define _NUMBERS 3
#define _EXTRARIGHT 4
#define _NUMBERS_SHIFT 5
#define _NUMPAD 16
//  these two layers are transparent ones intentionally.
//  When their respective switches are held together - the extra right will be initiated.
#define _DUMMY1 10
#define _DUMMY2 11

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  NUMPAD,
  // These three wiil work as RAISE, LOWER  and ADJUST in the original PLANCK
  CURSORRGHT = LT(_CURSORRGHT, KC_SPC),
  CURSORLEFT = LT(_CURSORLEFT, KC_SPC),
  NUMBERS,
  NUMBERS_LAYER = OSL(_NUMBERS_SHIFT),
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak                                 
 * ,-----------------------------------------++-----------------------------------------.
 * | Esc  |   '  |   ,  |   .  |   p  |   y  ||   f  |   g  |   c  |   r  |   l  |   /  |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * | Tab  |   a  |   o  |   e  |   u  |   i  ||   d  |   h  |   t  |   n  |   s  |   -  |
Hold: _Extraright       |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Ctrl |   ;  |   q  |   j  |   k  |   x  ||   b  |  m   |   w  |   v  |   z  |RCtrl |
 * +------+------+------+------+------+------++------+------+------+------+------+------+
		 | Left | Right  |      |      ||      |      | Up | Down |
	         +------+------+      |      ||      |      +------+------+               
  		                   | LSft |CursLt||CursRt| Space |
		               +------+------||------+------+
      Here	            | Numbers | Bspc || Enter | Numbers |                Here 
	^	               +------+------||------+------+                  ^
 	+------mapped------    | GUI  | LAlt || RAlt | GUI  |  -------mapped---+
This row is wired  	       +------+------||------+------+    
on the 5th row (R4), 
hence in the key map it is in the two outermost positions.

 */

[_DVORAK] = KEYMAP( \
  KC_ESC,                   KC_QUOT,   KC_COMM,            KC_DOT,         KC_P,           KC_Y,           KC_F,          KC_G,          KC_C,    KC_R,    KC_L,    KC_SLSH, \
  LT(_EXTRARIGHT, KC_TAB),  KC_A,      KC_O,               KC_E,           KC_U,           KC_I,           KC_D,          KC_H,          KC_T,    KC_N,    KC_S,    KC_MINS, \
  KC_LCTL,                  KC_SCLN,   KC_Q,               KC_J,           KC_K,           KC_X,           KC_B,          KC_M,          KC_W,    KC_V,    KC_Z,    KC_RCTL, \
  _______, _______,                    KC_LEFT,       RGUI_T(KC_RIGHT),   OSM(MOD_LSFT), CURSORLEFT,      CURSORRGHT,     KC_SPC,        RGUI_T(KC_UP),    KC_DOWN,  _______, _______, \
  KC_LGUI, KC_LALT,          _______,     _______, KC_BSPC,       NUMBERS_LAYER,   NUMBERS_LAYER,   KC_ENT,        _______,  _______,  KC_RALT,  KC_LGUI \
),


/*

Layers below are used on top of Dvorak layer defined above.
                                           +-------+
The keys which are shown empty, like this: |       |, represent a transparent key,
                                           +-------+
meaning the key from the underlaying layer (i.e. Dvorak) will be used.
In the keymaps those keys are defined as "_______".

                                           +-------+         +-------+
The keys which are shown solid, like this: | XXXXX | or this |  ...  |, represent an opaque/blocking key�
                                           +-------+         +-------+
Such key is not doing anything in that layer nor allowing the key from the underlaying layer
to be invoked.
In the keymaps those keys are defined as "XXXXXXX".

Most of the modifiers are the same in all layers.
So in most layers they are defined as transparent keys,
letting the keys from Dvorak layer to do the work.

With that idea all the layers below leave the unmodified keys as transparent keys.
In the same time - the layers block the keys that have no sense to be used 
in that given layer. For instance in the cursor control layers 
some of the keys are not used in the layer, but they are blocked to avoid
alpha-keys from Dvorak layer to appear.

For the same reason the keymaps below are shown simplified,
without separate thumbcluster.

*/



/* Cursor Control on the right (Right Space)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |Break |WheelD|MousUp|WheelU| Del  |  Ins | Home |  Up  | End  |   `  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   +  |SelAll|MousLt|MousDn|MousRt|MsBtRt| PgUp | Left | Down |Right | ALT  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |LCl(z)| DEl  | INS  | MsBtLe| ...  | PgDn ||MsBtMi|MsBtRt| Ctrl |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   X  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_CURSORRGHT] = KEYMAP( \
  KC_GRV,  KC_BRK,     KC_WH_D,      KC_MS_U,      KC_WH_U,   KC_DEL,   KC_INS,   KC_HOME, KC_UP,   KC_END,  KC_GRV,  KC_DEL,  \
  KC_PLUS, LCTL(KC_A), KC_MS_L,      KC_MS_D,      KC_MS_R,   KC_BTN2,  KC_PGUP,  KC_LEFT, KC_DOWN, KC_RGHT, KC_LALT, KC_ENT, \
  _______, LCTL(KC_Z), LSFT(KC_DEL), LCTL(KC_INS), KC_BTN1,   XXXXXXX,  KC_PGDN,  KC_UP,   KC_LEFT, KC_RGHT, KC_RCTL, _______, \
  _______, _______,    _______,      _______,      _______,   _______,  _______,  _______, _______, _______, _______, _______, \
  _______, _______,    _______,      _______,      _______,   _______,  _______,  _______, _______, _______, _______, _______  \
),



 /* Cursor Control on the left (Left Space)
 * ,-----------------------------------------------------------------------------------.
 * |      |Break | Home |  Up  | End  |  Ins | Del  | Home |  Up  | End  |   `  | Del  |
 * |------+------+------+------+------+------+-------------+------+------+------+------|
 * | Enter|SelAll|Left | Down  |Right | PgUp | xxx  |Left | Down  |Right | ALT  |Enter |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |      | xxx  |MsBtRt|MsBtMi|MsBtLe| PgDn | xxx  | Cut  | Copy | Paste| xxx  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   X  |	    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_CURSORLEFT] = KEYMAP( \
  _______, KC_BRK,          KC_HOME, KC_UP,   KC_END,  KC_INS,        KC_DEL,  KC_HOME,      KC_UP,        KC_END,      KC_GRV,  KC_DEL , \
  KC_ENT,  LCTL(KC_A),      KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP,       XXXXXXX, KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_LALT, KC_ENT, \
  _______, XXXXXXX,         KC_BTN2, KC_BTN3, KC_BTN1, KC_PGDN,       XXXXXXX, LCTL(KC_DEL), LCTL(KC_INS), LSFT(KC_INS), XXXXXXX, _______, \
  _______, _______,         _______, _______, _______, _______,       _______, _______,      _______,      _______,      _______, _______, \
  _______, _______,         _______, _______, _______, _______,       _______, _______,      _______,      _______,      _______, _______  \

),


 /* Numbers on the home row, FNs on the top row, symbols in the second row
 * (Lower or Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |BackSp|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   F1 |   F2 |   F3 |   F4 |   F5 |   F6 |   F7 |   F8 |   F9 |   F10|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F12 | LAlt |LShift| LAlt | RAlt |RShift|   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS] = KEYMAP( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_F11,  KC_F12,  KC_LALT, KC_LSFT, KC_LALT, KC_RALT, KC_RSFT, KC_COMM, KC_DOT,  KC_SLSH, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

 /* Shifted: Numbers on the home row, Shift Numbers on the usual place top row, not-fit right side chars on the lower row
 * (Lower or Raise)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   \  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   =  |   1  |    2 |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   {  |   [  |   ]  |   }  |      |      |   {  |   [  |   ]  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS_SHIFT] = KEYMAP( \
  KC_GRV,  KC_EXCLAIM, KC_AT,    KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_BSLS, \
  KC_EQL,  KC_1,       KC_2,     KC_3,    KC_4,      KC_5,       KC_6,          KC_7,         KC_8,        KC_9,          KC_0,           KC_KP_SLASH, \
  _______, KC_LCBR,    KC_LBRC,  KC_RBRC, KC_RCBR, _______, _______,            KC_LCBR,      KC_LBRC,     KC_RBRC,       KC_RCBR,        _______, \
  _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* ExtraRightSide (the keys from the right side which did not fit into the matrix)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   `  |      |      |      |      |   `  |   =  |   (  |   )  |   -  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CAPSLK|      |   ******    |      |      |      |      |      |      |  '   |      |
                   This is the
		  keys turning
                  this layer on
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   [  |   ]  |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EXTRARIGHT] = KEYMAP( \
  _______, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,       KC_GRV,  KC_EQL,  KC_LPRN, KC_RPRN, KC_MINS, _______, \
  KC_CAPS, XXXXXXX, _______, _______, XXXXXXX,      XXXXXXX,       XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_QUOT, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,       XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_BSLS, _______, \
  _______, _______, _______, _______, _______,      _______,       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,      _______,       _______, _______, _______, _______, _______, _______  \
 
),

// TODO: This layer is not working properly, I do not use it anyway. 
/* Numbers on the home row, and the right side turned into a numpad
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |BackSp|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   +  |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |LShift| LAlt | RAlt |   1  |   2  |   3  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Exit | Exit |      |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] =  KEYMAP( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS,  KC_4,    KC_5,    KC_6,    KC_PAST, KC_PENT, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT, KC_LALT, KC_RALT,  KC_1,    KC_2,    KC_3,    KC_PSLS, _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, DVORAK,  DVORAK,   _______, KC_0,    KC_DOT,  _______, _______ \
),

/* Dummy layers, both transparent, used to implement the extra right layer switch: S+D both held down.
*/

[_DUMMY1] = KEYMAP( \
  _______, _______,          _______,      _______,      _______,      _______,             _______,  _______, _______, _______, _______, _______, \
  _______, _______,          _______,      _______,      _______,      _______,             _______,  _______, _______, _______, _______, _______, \
  _______, _______,          _______,      _______,      _______,      _______,             _______,  _______, _______, _______, _______, _______, \
  _______, _______,          _______,      _______,      _______,      _______,             _______,  _______, _______, _______, _______, _______, \
  _______, _______,          _______,      _______,      _______,      _______,             _______,  _______, _______, _______, _______, _______  \
) 
,
[_DUMMY2] = KEYMAP( \
  _______, _______,          _______,      _______,      _______,      _______,             _______,  _______, _______, _______, _______, _______, \
  _______, _______,          _______,      _______,      _______,      _______,             _______,  _______, _______, _______, _______, _______, \
  _______, _______,          _______,      _______,      _______,      _______,             _______,  _______, _______, _______, _______, _______, \
  _______, _______,          _______,      _______,      _______,      _______,             _______,  _______, _______, _______, _______, _______, \
  _______, _______,          _______,      _______,      _______,      _______,             _______,  _______, _______, _______, _______, _______  \
) 


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

   case DVORAK:
      if (record->event.pressed) {
        layer_off(_CURSORRGHT);
        layer_off(_CURSORLEFT);
        layer_off(_NUMBERS);
        layer_off(_NUMBERS_SHIFT);
        layer_off(_EXTRARIGHT);
        layer_off(_NUMPAD);
        layer_on(_DVORAK);

      }
      return false;
      break;

   case NUMPAD:
     if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
          layer_invert(_DVORAK);
          layer_invert(_NUMPAD);
      }
      return false;
      break;

    case CURSORRGHT:
      if (record->event.pressed) {
        layer_on(_CURSORRGHT);
        update_tri_layer(_CURSORRGHT, _CURSORLEFT, _NUMBERS);
      } else {
        layer_off(_CURSORRGHT);
        update_tri_layer(_CURSORRGHT, _CURSORLEFT, _NUMBERS);
       }
      return true;// false;
      break;
    case CURSORLEFT:
      if (record->event.pressed) {
        layer_on(_CURSORLEFT);
        update_tri_layer(_CURSORRGHT, _CURSORLEFT, _NUMBERS);
      } else {
        layer_off(_CURSORLEFT);
        update_tri_layer(_CURSORRGHT, _CURSORLEFT, _NUMBERS);
      }
      return true;// 	false;
      break;
 }
  return true;
}
 

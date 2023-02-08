// kb: crkbd
// km: neoncornecatdogwin

#include QMK_KEYBOARD_H

enum corne_layers { // las capas en este keymap
    _WIN10,
    _MACOS,
    _SYMB,
    _NUMP,
    _TUNE
};

enum custom_keycodes { // dando nombre de keycodes por definir
    SYMB = SAFE_RANGE,
    NUMP,
    HUI,
    HUD,
    OS
};

/*
enum td_keycodes {
    ESCAPE,
//    COMMAND,
//    ALT
};

// definiendo el keycode TD_CAPLOCK
// un pulso: Left Shift
// dos pulsos: Caps Lock
qk_tap_dance_action_t tap_dance_actions[] = {
    [ESCAPE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_DEL),
//    [ALT] = ACTION_TAP_DANCE_DOUBLE(KC_ALGR, KC_LALT)
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // Las keycodes en cada capa

/*
      .------------------------------------------------.                         .-------------------------------------------------.
      |    TAB    | ' "" | < , |  > .  |   P   |    Y  |                         |   F   |   G   |   C   |   R   |   L   | BACKSPC |
      |-----------+------+-----+-------+-------+-------|          _WIN10         |-------+-------+-------+-------+-------+---------|
      |LCTL_T/ESC |   A  |  S  |   D   |   F   |   G   |                         |   D   |  H    |   T   |   N   |   S   | SFT  -_ |
      |-----------+------+-----+-------+-------+-------|                         |-------+-------+-------+-------+-------+---------|
      |LSFT       | ; :  |  Q  |   J   |   K   |   X   |                         |     B   |  M    |   W   |   V   |   Z   |/(SFT) |
      '---------------------------------------------------------|       |----------------------------------------------------------'
                               |  LGUI       | SYMB    | SPACE  |       | SPACE | NUMP ENTER |  ALTGR CAPS |
                               '--------------------------------'       '----------------------------------'
*/

  [_WIN10] = LAYOUT_split_3x6_3(
//  .-----------------------------------------------------.                    .-----------------------------------------------------.
            KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|    /* _WIN10 */    |--------+--------+--------+--------+--------+--------|
     LCTL_T(KC_ESC), KC_A,    KC_O,    KC_E,   KC_U, KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,   KC_S, KC_MINS,
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT, KC_SCLN, KC_Q,    KC_J,   KC_K, KC_X,                     KC_B,    KC_M,    KC_W,    KC_V,   KC_Z, RSFT_T(KC_SLSH),
//  '--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                LALT_T(KC_LGUI), MT(SYMB,KC_ENT), KC_SPC,      KC_SPC, MT(NUMP,KC_ENT), RALT_T(KC_CAPS)
                                      //'--------------------------'  '--------------------------------'
  ),

/*
      .------------------------------------------------.                         .-------------------------------------------------.
      | ESC DEL|   Q   |   W   |   E   |   R   |   T   |                         |   Y   |   U   |   I   |   O   |   P   | BACKSPC |
      |--------+-------+-------+-------+-------+-------|          _MACOS         |-------+-------+-------+-------+-------+---------|
      |SFT ( ) |   A   |   S   |   D   |   F   |   G   |                         |   H   |   J   |   K   |   L   | - _ / | '' ?    | 
      |--------+-------+-------+-------+-------+-------|                         |-------+-------+-------+-------+-------+---------|
      |CTRL < >|   Z   |   X   |   C   |   V   |   B   |                         |   N   |   M   |  , ;  |  . :  | + * = |  ' "    |
      '---------------------------------------------------------|       |----------------------------------------------------------'
                               |  CMD  CAPS  | SYMB    | SPACE  |       | SPACE | NUMP ENTER |  ALTGR ALT  |
                               '--------------------------------'       '----------------------------------'
*/

  [_MACOS] = LAYOUT_split_3x6_3(
//  .-----------------------------------------------------.                    .-----------------------------------------------------.
     KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,   KC_I,  KC_O,   KC_P,  KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|    /* _MACOS */    |--------+--------+--------+--------+--------+--------|
LCTL_T(KC_ESC), KC_A,  KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,  KC_L,  KC_MINUS, KC_MINS,
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,   KC_M, KC_COMM,  KC_DOT, KC_PLUS,  RSFT_T(KC_SLSH),
//  '--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                   LALT_T(KC_LGUI), MT(SYMB,KC_ENT), KC_SPC,    KC_SPC, MT(NUMP,KC_ENT), RALT_T(KC_CAPS)
                                      //'--------------------------'  '--------------------------------'
  ),

/*
      .--------------------------------------------------.                         .-------------------------------------------------.
      | LCA(DEL)  |   !  |   @   |  (    |   )   |  DEL  |                         |   =   |   #   |   |   |   ~   |       | BACKSPC |
      |-----------+------+-------+-------+-------+-------|          _SYMB          |-------+-------+-------+-------+-------+---------|
      | LCTL(ESC) |   %  |       |  {    |   }   |       |                         |   &   |   ^   |   /   |   \   |   ?   |         |
      |-----------+------+-------+-------+-------+-------|                         |-------+-------+-------+-------+-------+---------|
      | LGUI(V)   | COPY | PASTE |  [    |   ]   |   CUT |                         |   *   |   `   |   $   |   <   |   >   |         |
      '---------------------------------------------------------|       |------------------------------------------------------------'
                            |     GUI    |           |   SPACE  |       | SPACE | NUMP ENTER | ALTGR ALT |
                            '-----------------------------------'       '--------------------------------'
*/

  [_SYMB] = LAYOUT_split_3x6_3(
//  .-----------------------------------------------------.                    .-----------------------------------------------------.
LCA(KC_DEL), KC_EXLM, KC_AT, KC_LPRN, KC_RPRN,  KC_DEL,                          KC_EQL,  KC_HASH, KC_PIPE, KC_TILDE, XXXXXXX, KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|     /* _SYMB */    |--------+--------+--------+--------+--------+--------|
LCTL_T(KC_ESC), KC_PERC, KC_S, KC_LCBR, KC_RCBR, XXXXXXX,                     KC_AMPR, KC_CIRC, KC_SLSH, KC_BSLS,  KC_QUES, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LGUI(KC_V), LCTL(KC_C), LCTL(KC_V), KC_LBRC, KC_RBRC, LCTL(KC_X),                KC_ASTR, KC_GRV,  KC_DLR,  KC_LABK,  KC_RABK, XXXXXXX,
//  '--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                        LGUI(KC_LSFT),   _______,  KC_SPC,      KC_SPC, MT(NUMP,KC_ENT), KC_ALGR
                                    //'----------------------------'  '---------------------------------'
  ),

/*
      .------------------------------------------------.                         .-------------------------------------------------.
      |   -    |   +   |   1   |   2   |   3   |   ,   |                         |   >   |  HOME |   UP  |  END  |   ^   | BACKSPC |
      |--------+-------+-------+-------+-------+-------|          _NUMP          |-------+-------+-------+-------+-------+---------|
      | LCTL   |   *   |   4   |   5   |   6   |   .   |                         |   <   | LEFT  | DOWN  | RIGHT |    /   |        |
      |--------+-------+-------+-------+-------+-------|                         |-------+-------+-------+-------+-------+---------|
      | LSFT   |   =   |   7   |   8   |   9   |   0   |                         |       |       |       |       |       |         |
      '---------------------------------------------------------|       |----------------------------------------------------------'
                               |  CMD  CAPS  | ENTER SYMB| SPACE|       | SPACE |             | ALTGR  ALT |
                               '--------------------------------'       '----------------------------------'
*/

  [_NUMP] = LAYOUT_split_3x6_3(
//  .-----------------------------------------------------.                    .-----------------------------------------------------.
     KC_MINUS, KC_PPLS,  KC_1,   KC_2,    KC_3,   KC_COMM,                      KC_RABK, KC_HOME,  KC_UP,  KC_END,  KC_CIRC, KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|    /* _NUMP */     |--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_ASTR,  KC_4,   KC_5,    KC_6,   KC_DOT,                       KC_LABK, KC_LEFT, KC_DOWN, KC_RIGHT, KC_SLASH, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_EQUAL,  KC_7,   KC_8,    KC_9,   KC_0,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  '--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                   KC_LGUI, MT(SYMB,KC_ENT), KC_SPC,    KC_SPC, _______, KC_ALGR
                               //'---------------------------------'  '--------------------------'
  ),
  
/*
      .------------------------------------------------.                         .-------------------------------------------------.
      |   F1   |  F2   | F3    |F4     | F5    | F6    |                         |   F7  |   F8  |   F9  |  F10  |  F11  |   F12   |
      |--------+-------+-------+-------+-------+-------|          _TUNE          |-------+-------+-------+-------+-------+---------|
      |  TOG   |  HUI  | PLAIN |BREATH | RMOOD | RSWIRL|                         |       |       |       |       |      |          |
      |--------+-------+-------+-------+-------+-------|                         |-------+-------+-------+-------+-------+---------|
      |  SAI   |  HUD  | SAD   | VAI   | VAD   |  OS   |                         |       |       |       |       |       |         |
      '---------------------------------------------------------|       |----------------------------------------------------------'
                             |  CAPS  CMD  |          |  SPACE  |       | SPACE |       |  ALTGR ALT |
                             '----------------------------------'       '----------------------------'
*/

  [_TUNE] = LAYOUT_split_3x6_3(
//  .-----------------------------------------------------.                    .---------------------------------------------------.
      KC_F1,    KC_F2,  KC_F3,    KC_F4,   KC_F5,   KC_F6,                       KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
//  |--------+--------+--------+--------+--------+--------|     /* _TUNE */    |--------+--------+--------+--------------+---------|
      RGB_TOG,  HUI,    RGB_M_P,  RGB_M_B, RGB_M_R, RGB_M_SW,                    KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------------|
      RGB_SAI,  HUD,    RGB_SAD , RGB_VAI, RGB_VAD, OS,                          KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
//  '--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+------'
                                          KC_TAB, _______, KC_SPC,      KC_SPC, _______, KC_ALGR
                                      //'--------------------------'  '--------------------------'
  )
};

// ---------------------- variables -----------------------------

led_t led_usb_state;

#define WPM 15 // si current_wpm >= WPM entonces el gato empieza a tocar el keyboard
#define ANIM_FRAME_DURATION 200 // cuanto tiempo mostrar cada frame
#define ANIM_SIZE_DOG 96 // numero de pixeles en cada frame del perro
#define ANIM_SIZE_CAT 320 // numero de pixeles en cada frame del gato

uint32_t anim_dog_timer;
uint32_t anim_cat_timer;
uint32_t anim_dog_sleep;
uint32_t anim_cat_sleep;

uint8_t mod_state;
bool key_registered;

uint8_t current_dog_frame = 0; // current dog frame
uint8_t current_cat_frame = 0; // current cat frame
uint8_t current_wpm = 0; // current_wpm parte como 0
uint8_t current_hue;
uint8_t current_val;
uint8_t mode_value;
uint8_t hue_value;
uint8_t sat_value;
uint8_t val_value;

bool showedJump = true;
bool isJumping = false;

char hue_str[4];
char sat_str[4];
char val_str[4];
char mode_str[4];
char wpm_str[4];

// --------------------------------------------------------------

void keyboard_post_init_user(void) {
    current_hue = rgblight_get_hue();
    current_val = RGBLIGHT_LIMIT_VAL;
}    
        
layer_state_t layer_state_set_user(layer_state_t state) {

    switch (get_highest_layer(state)) {
    
        case _TUNE:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(HSV_WHITE);
            }
            break;    
            
        case _NUMP:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(HSV_TEAL);
            }    
            break;        
        case _SYMB:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(245, 255, current_val);
            }
            break;

        case _MACOS: 
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(current_hue, 255, current_val);
            }
            break;   

        case _WIN10: 
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(current_hue, 249, current_val);
            }
            break;  
    }
    
    return state;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_sethsv(20, 255, current_val); // amarillo
    } else { 
        rgblight_sethsv(current_hue, 255, current_val);
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_LPRN):
        case LCTL_T(KC_LABK):
        case MT(KC_LGUI,KC_TAB):   
        case MT(SYMB,KC_TAB):
        case MT(SYMB,KC_ENT):
        case MT(NUMP,KC_ENT):
        case RALT_T(KC_CAPS):
            return 125;
            
        default:
            return TAPPING_TERM;
    }
    
}

#ifdef OLED_ENABLE // si OLED_ENABLE = yes en rules.mk
#include <stdio.h>

static void render_dog(int DOG_X, int DOG_Y) { // esta funcion contien                  e los frames y logica de la animacion del perro

    static const char PROGMEM sit[2][ANIM_SIZE_DOG] = { // frames de sit
        { // 'sit1' 32x22px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
            0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
            0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        { // 'sit2' 32x22px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
            0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
            0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };

    static const char PROGMEM walk[2][ANIM_SIZE_DOG] = { // frames de walk
        { // 'walk1' 32x22px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80,
            0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03,
            0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        { // 'walk2' 32x22px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e,
            0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    static const char PROGMEM run[2][ANIM_SIZE_DOG] = { // frames de run
        { // 'run1' 32x22px
            0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
            0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01,
            0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        { // 'run2' 32x22px
            0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
            0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37,
            0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    static const char PROGMEM bark[2][ANIM_SIZE_DOG] = { // frames de bark
        { // 'bark1' 32x22px
            0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
            0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        { // 'bark2' 32x22px
            0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
            0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    static const char PROGMEM sneak[2][ANIM_SIZE_DOG] = { // frames de sneak
        { // 'sneak1' 32x22px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04,
            0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06,
            0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        },

        { // 'sneak2' 32x22px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04,
            0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04,
            0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    void animate_dog(void) { // logica de la animacion del perro

        if (isJumping || !showedJump) { // si isJumping = true o showedJump = false

            oled_set_cursor(DOG_X,DOG_Y +2);
            oled_write("     ", false);

            oled_set_cursor(DOG_X,DOG_Y -1);

            showedJump = true;

        } else { // si isJumping = true y showedJump = true

            oled_set_cursor(DOG_X,DOG_Y -1);
            oled_write("     ", false);

            oled_set_cursor(DOG_X,DOG_Y);
        }

        // cada accion del perro (sit, walk, run, bark y sneak) tiene 2 frames
        current_dog_frame = (current_dog_frame + 1) % 2; // con esta formula current_dog_frame toma los valores 1 y 0 los cuales se van turnando

        if(led_usb_state.caps_lock) { // si esta activado Caps Lock
            oled_write_raw_P(bark[abs(1 - current_dog_frame)], ANIM_SIZE_DOG); // perro ladra

        } else if ( (keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT)) ) { // KC_LSFT o KC_RSFT presionado
            oled_write_raw_P(sneak[abs(1 - current_dog_frame)], ANIM_SIZE_DOG); // perro en sneaking

        } else if ( (keyboard_report->mods & MOD_BIT (KC_LCTL)) || (keyboard_report->mods & MOD_BIT (KC_RCTL)) ) { // KC_LCTL o KC_RCTL presionado
            oled_write_raw_P(walk[abs(1 - current_dog_frame)], ANIM_SIZE_DOG); // perro camina

        } else if (keyboard_report->mods & MOD_BIT (KC_RALT)) { // KC_RALT presionado
            oled_write_raw_P(run[abs(1 - current_dog_frame)], ANIM_SIZE_DOG); // perro corre

        } else { // si no se cumple ninguna de las condiciones anteriores
            oled_write_raw_P(sit[abs(1 - current_dog_frame)], ANIM_SIZE_DOG); // perro se sienta
        }
    }
    
    if (timer_elapsed32(anim_dog_timer) > ANIM_FRAME_DURATION) {
    
        anim_dog_timer = timer_read32();
        animate_dog();
        
        if (current_wpm != 0) { 
            anim_dog_sleep = timer_read32();
        }
    }        
}

static void render_layer(void) { // esta funcion muestra las capas en el OLED y resalta la capa presente
    if (IS_LAYER_ON(_MACOS)) { 
        oled_write_P(PSTR("MACOS"), layer_state_is(_MACOS) && !layer_state_is(_SYMB) && !layer_state_is(_NUMP) && !layer_state_is(_TUNE));
    } else {
        oled_write_P(PSTR("WIN10"), layer_state_is(_WIN10));
    }    
    oled_write_P(PSTR("SYMB\n"), layer_state_is(_SYMB) && !layer_state_is(_TUNE));
    oled_write_P(PSTR("NUMP\n"), layer_state_is(_NUMP) && !layer_state_is(_TUNE));
    oled_write_P(PSTR("TUNE\n"), layer_state_is(_TUNE));
}

static void render_mode(void) {
    mode_str[3] = '\0';
    mode_str[2] = '0' + mode_value % 10;
    mode_str[1] = '0' + ( mode_value /= 10) % 10;
    mode_str[0] = '0' + mode_value / 10;
    oled_write("M ", false);
    oled_write(mode_str, false); // printear valor de WPM
}   

static void render_hsv(void) {
    oled_write("H ", false);
    hue_str[3] = '\0';
    hue_str[2] = '0' + hue_value % 10;
    hue_str[1] = '0' + ( hue_value /= 10) % 10;
    hue_str[0] = '0' + hue_value / 10;
    oled_write(hue_str, false);
    
    oled_write("S ", false);
    sat_str[3] = '\0';
    sat_str[2] = '0' + sat_value % 10;
    sat_str[1] = '0' + ( sat_value /= 10) % 10;
    sat_str[0] = '0' + sat_value / 10;
    oled_write(sat_str, false);
    
    oled_write("V ", false);
    val_str[3] = '\0';
    val_str[2] = '0' + val_value % 10;
    val_str[1] = '0' + ( val_value /= 10) % 10;
    val_str[0] = '0' + val_value / 10;
    oled_write(val_str, false);    
}    

static void render_cat(void) { // esta funcion contiene los frames y logica de la animacion del gato

    static const char PROGMEM idle[1][ANIM_SIZE_CAT] = { // frames de idle
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00,
        0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f,
        0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19,
        0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
        }
    };

    static const char PROGMEM tap[2][ANIM_SIZE_CAT] = { // frames de tap
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0xff, 0xff, 0xff, 0x7c, 0x70, 0x40, 0x40,
        0x61, 0x5e, 0x80, 0xc0, 0xbc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0f, 0x3f, 0xf8, 0xf0, 0xf0, 0x20,
        0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19,
        0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
        },
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00,
        0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f,
        0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0xfe, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0f, 0x3f, 0xff, 0x03, 0x01, 0x03, 0x07, 0x18, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0x00, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01
        },
    };

    void animate_cat(void) { // logica de la animacion del gato

        if(current_wpm < WPM){ // si current_wpm menor a WPM
            oled_write_raw_P(idle[0], ANIM_SIZE_CAT); // gato en idle (solo hay un frame en esta accion)
         }

         if(current_wpm >= WPM){ // si current_wpm mayor o igual a WPM
             current_cat_frame = (current_cat_frame + 1) % 2; //para alternar entre los 2 frames de tap
             oled_write_raw_P(tap[abs((2-1)-current_cat_frame)], ANIM_SIZE_CAT); // gato haciendo tap
         }
    }

    if (timer_elapsed32(anim_cat_timer) > ANIM_FRAME_DURATION) { // timer_elapsed32(anim_ghost_timer) tiempo transcurrido en ms desde la ultima vez que se actualizo anim_ghost_timer
        
        anim_cat_timer = timer_read32(); // se actualiza anim_ghost_timer
        animate_cat(); // se ejecuta animate_ghost()
        
        if (current_wpm != 0) { 
            anim_cat_sleep = timer_read32(); // se actualiza anim_ghost_sleep
        }
    }      
}

static void render_wpm(void) {
    oled_write(" WPM\n", false);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + current_wpm % 10;
    wpm_str[1] = '0' + ( current_wpm /= 10) % 10;
    wpm_str[0] = '0' + current_wpm / 10;
    oled_write(" ", false);
    oled_write(wpm_str, false); // printear valor de WPM
} 

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_270;
    }
    return rotation;
    // rotacion de 270 en ambas pantallas OLED (master y slave)
    // de manera que el punto inicial este en un cierto extremo
    // y se siga cierta orientacion
}

// el OLED es de 128x32 pixeles
// cada page es de 8 pixeles a lo largo del lado con 128 px
// por lo que hay 16 pages a lo largo de los 128 px
bool oled_task_user(void) { // funcion en la cual se indica que poner en cada OLED

    current_wpm = get_current_wpm();
    mode_value = rgblight_get_mode();
    hue_value = rgblight_get_hue();
    sat_value = rgblight_get_sat();
    val_value = rgblight_get_val();
    
    /*
    if ( (timer_elapsed32(anim_ghost_sleep) > 120000) && (timer_elapsed32(anim_fishing_sleep) > 120000) && (current_wpm == 0) ) {
        if (is_oled_on()) {
            oled_off();
        }    
        timer_init();
        return;
    }
    */    

    if ( (timer_elapsed32(anim_dog_sleep) > 60000) && (timer_elapsed32(anim_cat_sleep) > 60000) && (current_wpm == 0) ) {
        if (is_oled_on()) {
            oled_off();
        }    
        timer_init();
        return false;
    }
    
    if (current_wpm != 0 && !is_oled_on()) {
        oled_on();
    }    
    
    led_usb_state = host_keyboard_led_state();

    if (is_keyboard_master()) { // OLED del master
        render_dog(0,1); // lo del perro
        oled_set_cursor(0,5);
        render_layer(); // lo de las capas
        oled_set_cursor(0,10);
        render_mode(); // lo del HSV
        oled_set_cursor(0,11);
        render_hsv();
    } else { // OLED del slave
        render_cat(); // lo del gato
        oled_set_cursor(0,11);
        render_wpm(); // lo del WPM
    }

    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    mod_state = get_mods();

    switch (keycode) {
        case HUI:
            if (record->event.pressed) {
                current_hue = current_hue + 5;
                if (current_hue > 255) {
                    current_hue = current_hue - 256;
                }    
            } else {
                ;
            }
            return false;    
            
        case HUD:
            if (record->event.pressed) {
                current_hue = current_hue - 5;
                if (current_hue < 0) {
                    current_hue = 256 + current_hue;
                }    
            } else {
                ;
            }
            return false;  

        case SYMB:
            if (record->event.pressed) {
                layer_on(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            }
            return false;

        case MT(SYMB,KC_ENT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_ENT);
            } else if (record->event.pressed) {
                layer_on(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            }
            return false;
        case MT(NUMP,KC_ENT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_ENT);
            } else if (record->event.pressed) {
                layer_on(_NUMP);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_NUMP);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            }
            return false;

        case MT(KC_LGUI,KC_TAB):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_TAB);
            } else if (record->event.pressed) { 
                register_code16(KC_LCMD);
            } else {
                unregister_code16(KC_LCMD);
            }
            return false;

        case RALT_T(KC_CAPS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_CAPS);
                return false;
            }
            break;   

        case LCTL_T(KC_LABK):
            if (record->tap.count && record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    tap_code16(KC_RABK); // >
                } else {
                    tap_code16(KC_LABK); // <
                }
            } else if (record->event.pressed) {
                register_code16(KC_LCTL);
            } else {
                unregister_code16(KC_LCTL);
            }
            return false; 

        case LSFT_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    tap_code16(KC_RPRN); // )
                } else {
                    tap_code16(KC_LPRN); // (
                }
            } else if (record->event.pressed) {
                register_code16(KC_LSFT);
            } else {
                unregister_code16(KC_LSFT);
            }
            return false; 



            if (record->event.pressed) { // al presionar el keycode
                if (get_mods() & MOD_BIT(KC_ALGR)) {
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(KC_ALGR);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_N)); // registrar ALTGR + n
                        tap_code16(LSFT(KC_N));
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(KC_ALGR);
                        tap_code16(ALGR(KC_N)); // registrar ALTGR + n
                        tap_code16(KC_N); // registrar n
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado o bloq mayus activado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_N)); 
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado ni bloq mayus activado
                        tap_code16(KC_N);
                        key_registered = true;
                        return false;
                    }    
                }            
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false; 


        case OS: 
            if (record->event.pressed) {
                if (IS_LAYER_OFF(_MACOS)) {
                    layer_on(_MACOS);
                } else {
                    layer_off(_MACOS);
                }
            } else {
                ;
            }
            return false;     
            
    
    }
    return true;
}
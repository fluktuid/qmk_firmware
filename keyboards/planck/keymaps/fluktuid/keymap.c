#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_contributions.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  COLEMAK,
  WORKMAN,
  NEO,
  PLOVER,
  EXT_PLV,
  RGB_SLD,// = EZ_SAFE_RANGE,
  DE_LSPO,
  DE_RSPC,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAVI,
  _NEO_Q,
  _MOUSE,
  _DVORAK,
  _COLEMAK,
  _WORKMAN,
  _NEO,
  _PLOVER
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAVI MO(_NAVI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_TAB,            KC_Q,     KC_W,    KC_E,    KC_R,  KC_T,     KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_BSPACE,
    LT(_NEO_Q,KC_CAPS),KC_A,     KC_S,    KC_D,    KC_F,  KC_G,     KC_H,  KC_J,  KC_K,     KC_L,    DE_SCLN,  DE_HASH,
    KC_LSHIFT,         KC_Z,     KC_X,    KC_C,    KC_V,  KC_B,     KC_N,  KC_M,  KC_COMMA, KC_DOT,  KC_SLASH, KC_RSHIFT, 
    KC_ESCAPE,         KC_LCTRL, KC_LALT, KC_LGUI, LOWER, KC_SPACE, KC_NO, RAISE, NAVI,     KC_RALT, MO(5),    KC_ENTER
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_TILD,  KC_EXLM, KC_AT,   KC_HASH,        KC_DLR,       KC_PERC,         KC_CIRC, KC_AMPR,       KC_ASTR,         KC_LPRN,  KC_RPRN,   DE_ACUT,
    KC_DELETE,DE_LABK, DE_RABK, DE_EURO,        DE_LCBR,      DE_AT,           KC_PIPE, KC_UNDS,       KC_RCBR,         ALGR(DE_L),KC_PLUS,  KC_PIPE,
    _______,  _______, _______, DYN_REC_START1, DYN_REC_STOP, DYN_MACRO_PLAY1, _______, KC_NONUS_HASH, KC_NONUS_BSLASH, KC_COMMA, _______,       _______,
    _______,  _______, _______, _______,        _______,      _______,         KC_NO,   _______,       _______,         KC_MNXT,  KC_AUDIO_MUTE, _______
  ),

  [_RAISE] = LAYOUT_planck_grid(
    DE_CIRC, KC_1,    KC_2,    KC_3,           KC_4,         KC_5,            KC_6,    KC_7,          KC_8,            KC_9,              KC_0,            KC_DELETE,
    _______, _______, DE_SS,   _______,        DE_MINS,      DE_EQL,          _______, KC_LBRACKET,   KC_RBRACKET,     DE_AE,             DE_OE,           DE_UE,
    _______, _______, _______, DYN_REC_START2, DYN_REC_STOP, DYN_MACRO_PLAY2, _______, KC_NONUS_HASH, KC_NONUS_BSLASH, KC_PGUP,           KC_PGDOWN,       _______,
    _______, _______, _______, _______,        _______,      _______,         KC_NO,   _______,       _______,         KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    _______,     _______, AU_OFF,            AU_ON,            AU_TOG,        PLOVER,     RGB_SPI,            RGB_SPD, KC_BRIGHTNESS_UP,KC_BRIGHTNESS_DOWN, _______, EEPROM_RESET, 
    _______,     _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,  KC_AUDIO_MUTE, QWERTY, TOGGLE_LAYER_COLOR, RGB_TOG, RGB_VAI,         RGB_VAD,            _______, RESET,          
    KC_ASON,     _______, MU_ON,             MU_OFF,           MU_TOG,        QWERTY, RGB_RMOD,           RGB_MOD, RGB_SAI,         RGB_SAD,            RGB_SLD, KC_ASOFF,       
    WEBUSB_PAIR, _______, _______,           _______,          _______,       QWERTY,  KC_NO,              _______, RGB_HUI,         RGB_HUD,            _______, _______
  ),

  [_NAVI] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_HOME,       KC_PGDOWN,     KC_PGUP,     KC_END,         _______, _______,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LEFT,       KC_DOWN,       KC_UP,       KC_RIGHT,       _______, _______,
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,         _______,       _______,     _______,        _______, _______
  ),

  [_NEO_Q] = LAYOUT_planck_grid(
    _______, KC_DOT,  DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_LABK, DE_RABK, DE_EXLM, DE_EQL,  DE_AMPR, _______,
    _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QST,  DE_LPRN, DE_RPRN, DE_MINS, DE_AT,   _______,
    _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV,  DE_PERC, DE_DQOT, DE_QUOT, DE_SCLN, KC_PLUS, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,   _______, _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______,       _______, KC_MS_WH_UP,   KC_MS_ACCEL2, KC_MS_ACCEL1, KC_MS_ACCEL0, _______, _______,
    _______, _______, _______, _______, KC_WWW_SEARCH, _______, KC_MS_LEFT,    KC_MS_DOWN,   KC_MS_UP,     KC_MS_RIGHT,  _______, _______,
    _______, _______, _______, _______, _______,       _______, KC_MS_WH_DOWN, KC_MS_BTN1,   KC_MS_BTN2,   KC_MS_BTN3,   _______, _______,
    _______, _______, _______, _______, _______,       _______, KC_NO,         _______,      _______,      _______,      _______, _______
  ),

  /* Colemak
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,             KC_Q,     KC_W,    KC_F,    KC_P,  KC_G,     KC_J,  KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    LT(_NEO_Q,KC_CAPS), KC_A,     KC_R,    KC_S,    KC_T,  KC_D,     KC_H,  KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,            KC_Z,     KC_X,    KC_C,    KC_V,  KC_B,     KC_K,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSHIFT,
    KC_ESCAPE,          KC_LCTRL, KC_LALT, KC_LGUI, LOWER, KC_SPACE, KC_NO, RAISE, NAVI,    KC_RALT, MO(5),   KC_ENTER
  ),

  /* Dvorak
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,             KC_QUOT,  KC_COMM, KC_DOT,  KC_P,  KC_Y,     KC_F,  KC_G,  KC_C, KC_R,    KC_L,  KC_BSPC,
    LT(_NEO_Q,KC_CAPS), KC_A,     KC_O,    KC_E,    KC_U,  KC_I,     KC_D,  KC_H,  KC_T, KC_N,    KC_S,  KC_SLSH,
    KC_LSHIFT,          KC_SCLN,  KC_Q,    KC_J,    KC_K,  KC_X,     KC_B,  KC_M,  KC_W, KC_V,    KC_Z,  KC_RSHIFT,
    KC_ESCAPE,          KC_LCTRL, KC_LALT, KC_LGUI, LOWER, KC_SPACE, KC_NO, RAISE, NAVI, KC_RALT, MO(5), KC_ENTER
  ),

  [_WORKMAN] = LAYOUT_planck_grid(
    KC_TAB,             KC_Q,     KC_D,    KC_R,    KC_W,  KC_B,     KC_J,  KC_F,  KC_U,     KC_P,    KC_COMMA, KC_BSPACE,
    LT(_NEO_Q,KC_CAPS), KC_A,     KC_S,    KC_H,    KC_T,  KC_G,     KC_Y,  KC_N,  KC_E,     KC_O,    KC_I,     DE_SCLN,
    KC_LSHIFT,          KC_Z,     KC_X,    KC_M,    KC_C,  KC_V,     KC_K,  KC_L,  KC_COMMA, KC_DOT,  KC_SLASH, KC_RSHIFT,  
    KC_ESCAPE,          KC_LCTRL, KC_LALT, KC_LGUI, LOWER, KC_SPACE, KC_NO, RAISE, NAVI,     KC_RALT, MO(5),    KC_ENTER
  ),

  [_NEO] = LAYOUT_planck_grid(
    KC_TAB,             KC_X,     KC_V,    KC_L,    KC_C,  KC_W,     KC_K,  KC_H,  KC_G,     KC_F,    KC_Q,  KC_BSPACE,
    LT(_NEO_Q,KC_CAPS), KC_U,     KC_I,    KC_A,    KC_E,  KC_O,     KC_S,  KC_N,  KC_R,     KC_T,    KC_D,  KC_Y,
    KC_LSHIFT,          DE_AE,    DE_OE,   DE_UE,   KC_P,  KC_Z,     KC_B,  KC_M,  KC_COMMA, KC_DOT,  KC_J,  KC_RSHIFT,
    KC_ESCAPE,          KC_LCTRL, KC_LALT, KC_LGUI, LOWER, KC_SPACE, KC_NO, RAISE, NAVI,     KC_RALT, MO(5), KC_ENTER
  ),

  /* Plover layer (http://opensteno.org)
   * ,-----------------------------------------------------------------------------------.
   * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_PLOVER] = LAYOUT_planck_grid(
      XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
      XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
      EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
  ),
};


#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  planck_ez_right_led_level(2);
  planck_ez_left_led_level(2);
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {0,0,0}, {0,0,0}, {157,72,106}, {0,0,0}, {0,0,0}, {0,0,0}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {157,72,106}, {157,72,106}, {157,72,106}, {157,72,106}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208} },

    [2] = { {0,0,0}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {0,0,0}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {0,0,0}, {0,0,0}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {207,210,243}, {0,0,0}, {0,0,0}, {150,84,193}, {150,84,193}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {73,251,204}, {73,251,204}, {73,250,155}, {207,210,243}, {0,0,0}, {0,0,147}, {138,88,208}, {138,88,208}, {0,0,0}, {198,155,215}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,205,155}, {207,210,243}, {0,0,0}, {0,0,147}, {0,0,147}, {0,0,147}, {0,0,0}, {0,0,0}, {198,252,237}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {207,210,243}, {0,0,0}, {0,0,147}, {0,0,147}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {135,255,255}, {135,255,255}, {135,255,255}, {135,255,255}, {135,255,255}, {128,61,188}, {73,250,190}, {73,250,190}, {128,61,188}, {0,0,0}, {0,0,0}, {0,0,0}, {135,255,255}, {135,255,255}, {135,255,255}, {135,255,255}, {135,255,255}, {216,166,195}, {216,166,195}, {216,166,195}, {216,166,195}, {0,0,0}, {0,0,0}, {0,0,0}, {135,255,255}, {135,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {0,0,0}, {0,0,0}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {0,0,0}, {0,0,0}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {144,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {207,93,255}, {228,196,238}, {228,196,238}, {228,196,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,183}, {0,0,0}, {216,166,195}, {216,166,195}, {216,166,195}, {216,166,195}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {207,93,255}, {206,173,253}, {206,173,253}, {228,196,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [11] = { {0,0,0}, {106,242,237}, {106,242,237}, {106,242,237}, {106,242,237}, {106,220,237}, {106,220,237}, {106,242,237}, {106,242,237}, {106,242,237}, {106,242,237}, {0,0,0}, {0,0,0}, {106,242,237}, {106,242,237}, {106,242,237}, {106,242,237}, {106,220,237}, {106,220,237}, {106,242,237}, {106,242,237}, {106,242,237}, {106,242,237}, {0,0,0},{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,214,142}, {0,0,0}, {0,0,0}, {106,242,237}, {106,242,237}, {106,242,237}, {106,242,237}, {106,242,237}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void set_layer_color_matrix(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        continue;
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 11:
      set_layer_color(11);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case NEO:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_off(_NAVI);
        layer_off(_NEO_Q);
        layer_off(_MOUSE);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    case DE_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case DE_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return update_tri_layer_state(state, _LOWER, _NAVI,  _MOUSE);
}

#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;


#define _DVORAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _GAME 4
#define _NAVIGATION 5


#define KC_ KC_TRNS
#define _______ KC_TRNS

// Navigation
#define KC_ADJT TO(_ADJUST)
#define KC_RASE MO(_RAISE)
#define KC_GAME TO(_GAME)
#define KC_LOWR MO(_LOWER)
#define KC_DVOR TO(_DVORAK)
#define KC_NAVI TO(_NAVIGATION)
#define KC_RST  RESET

#define KC_BL_S BL_STEP
#define KC_BL_T BL_TOGG
#define KC_BL_B BL_BRTG
#define KC_DBUG DEBUG

// RGB Multi-Modes
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_RMOD
#define KC_MOD  RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_RSPI RGB_SPI
#define KC_RSPD RGB_SPD

// RGB Individual modes
#define KC_PLAI RGB_M_P
#define KC_BREA RGB_M_B
#define KC_RAIN RGB_M_R
#define KC_SWIL RGB_M_SW
#define KC_SNAK RGB_M_SN
#define KC_KNIT RGB_M_K
#define KC_XMAS RGB_M_X
#define KC_GRAD RGB_M_G
#define KC_RGBT RGB_M_T

// Desktop Navigation
#define KC_DLEF LGUI(LCTL(KC_LEFT))
#define KC_DRHT LGUI(LCTL(KC_RIGHT))
#define KC_DNEW LGUI(LCTL(KC_D))
#define KC_DEXT LGUI(LCTL(KC_F4))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GESC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,MINS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LGUI,SCLN, Q  , J  , K  , X  ,HOME,         , B  , M  , W  , V  , Z  ,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LCTL,LOWR,ENT ,         SPC ,RASE,LALT
  //                  `----+----+----'        `----+----+----'-
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,SLSH,RPRN,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RST , 1  ,DLEF, UP ,DRHT, 5  ,               NAVI, P7 , P8 , P9 ,PMNS,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT,    ,LEFT,DOWN,RGHT,QUES,               EQL , P4 , P5 , P6 ,PPLS,GAME,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BL_S,BL_T,BL_B,DEXT,DNEW,SLSH,END ,         ,RPRN, P1 , P2 , P3 ,PEQL,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,DEL ,        SPC ,    , P0
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,EXLM, AT ,HASH,DLR ,LPRN,               RPRN,AMPR,ASTR,LPRN,RPRN,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT,MPRV,MNXT,VOLU,PGUP,LCBR,               RCBR,HOME,PSCR,    ,    ,SLSH,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     MUTE,MSTP,MPLY,VOLD,PGDN,LBRC,END ,         ,RBRC,END ,APP ,    ,ADJT,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,        SPC ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,               PLAI,BREA,RAIN,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RTOG,MOD ,RHUI,RSAI,RVAI,RSPI,               SWIL,SNAK,KNIT,    ,    ,PSCR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,RMOD,RHUD,RSAD,RVAD,RSPD,               XMAS,GRAD,RGBT,    ,    ,DVOR,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BL_S,RST ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),
  
    [_GAME] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GESC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,DVOR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL, Z  , X  , C  , V  , B  ,ENT ,         , N  , M  ,COMM,DOT ,SLSH,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LOWR,SPC ,         SPC ,RASE,LALT
  //                  `----+----+----'        `----+----+----'
  ),
  
    [_NAVIGATION] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,--------+-------+-------+--------+----+----.
     GESC, 1  , 2  , 3  , 4  , 5  ,                6      , 7     , 8     , 9      , 0  ,BSPC,
  //|----+----+----+----+----+----|              |--------+-------+-------+--------+----+----|
     TAB ,    ,    , UP ,    ,    ,               MS_WH_UP,MS_BTN2,MS_UP  ,MS_BTN3 ,    ,DVOR,
  //|----+----+----+----+----+----|              |--------+-------+-------+--------+----+----|
     LSFT, A  ,LEFT,DOWN,RGHT,    ,               MS_BTN1 ,MS_LEFT,MS_DOWN,MS_RIGHT,    ,QUOT,
  //|----+----+----+----+----+----+----.    ,----|--------+-------+-------+--------+----+----|
     LCTL,    ,    ,    ,    ,    ,SPC ,    ,   MS_WH_DOWN,       ,       ,        ,    ,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+--------+-------+-------+--------+----+----'
                       LGUI,LOWR,ENT ,         SPC ,RASE  ,LALT
  //                  `----+----+----'        `----+------+----'
  )

};


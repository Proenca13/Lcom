#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "Controller/Timer/timer.h"
#include "Controller/Timer/i8254.h"
#include "Controller/Video/graphic.h"
#include "Controller/Keyboard/keyboard.h"
#include "Controller/Mouse/mouse.h"
#include "Controller/RTC//rtc.h"
#include "configs.h"
#include "Viewer/view.h"
#include "Model/game.h"
#ifndef SHARED_STATE_H
#define SHARED_STATE_H
typedef enum {
    RUNNING,
    END
} ProgramState;
typedef enum {
    PLAY,
    STOP
} GameState;
typedef enum {
    STARTMENU,
    CONTROLLERMENU,
    GAMEOVER,
    WINMENU,
    GAMEMENU
} MenuState;
void timer_state();
void keyboard_state();
void mouse_state();
void rtc_state();
void cell_state_keyboard();
void cell_state_mouse();
#endif //SHARED_STATE_H

//
// Created by joao on 23-04-2024.
//
#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "Controller/Timer/timer.h"
#include "Controller/Timer/i8254.h"
#include "Controller/Video/graphic.h"
#include "Controller/Keyboard/keyboard.h"
#include "Controller/Mouse/mouse.h"
#include "configs.h"
#ifndef SHARED_MODEL_H
#define SHARED_MODEL_H
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
    GAMEMENU,
    ENDMENU
} MenuState;
void keyboard_state();
#endif //SHARED_MODEL_H

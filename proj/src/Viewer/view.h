//
// Created by joao on 24-04-2024.
//

#ifndef SHARED_VIEW_H
#define SHARED_VIEW_H
#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "Controller/Timer/timer.h"
#include "Controller/Timer/i8254.h"
#include "Controller/Video/graphic.h"
#include "Controller/Keyboard/keyboard.h"
#include "Controller/Mouse/mouse.h"
#include "Controller/RTC//rtc.h"
#include "Model/model.h"
#include "configs.h"
#include "Model/xpm/startgame.xpm"
#include "Model/xpm/mouse.xpm"
void display_time();
void draw_state();
void draw_main_menu();
void draw_mouse();
int draw_sprite(Sprite *sprite, int x, int y);

#endif //SHARED_VIEW_H

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
#include "Model/xpm/Start.xpm"
#include "Model/xpm/Start2.xpm"
#include "Model/xpm/mouse.xpm"
#include "Model/xpm/Controls.xpm"
#include "Model/xpm/Controls2.xpm"
#include "Model/xpm/Exit.xpm"
#include "Model/xpm/Exit2.xpm"
#include "Model/xpm/Title.xpm"
#include "Model/xpm/dirt.xpm"
#include "Model/xpm/arrows.xpm"
#include "Model/xpm/DaySky.xpm"
#include "Model/xpm/NightSky.xpm"
#include "Model/xpm/AfternoonSky.xpm"
#include "Model/xpm/dyog.xpm"

void draw_state();
void draw_main_menu();
void draw_game_menu();
void draw_mouse();
void draw_game();
void draw_controls_menu();
Sprite *check_time_sprite();
int draw_sprite(Sprite *sprite, int x, int y);

#endif //SHARED_VIEW_H

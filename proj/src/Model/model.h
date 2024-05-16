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
#include "Controller/RTC//rtc.h"
#include "configs.h"
#include "sprite.h"
#include "Viewer/view.h"
#ifndef SHARED_MODEL_H
#define SHARED_MODEL_H

void create_sprites();
void destroy_sprites();
#endif //SHARED_MODEL_H

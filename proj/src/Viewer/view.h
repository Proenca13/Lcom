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
#include "configs.h"
void display_time();
#endif //SHARED_VIEW_H

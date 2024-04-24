//
// Created by joao on 24-04-2024.
//

#ifndef SHARED_RTC_H
#define SHARED_RTC_H
#include <lcom/lcf.h>

#include <stdbool.h>
#include <stdint.h>

#define IRQ_RTC 8
#define RTC_IRQ_SET BIT(5)

#define SECONDS 0
#define MINUTES 2
#define HOURS 4
#define DAY_OF_THE_WEEK 6
#define DAY_OF_THE_MONTH  7
#define MONTH  8
#define YEAR  9
#define RTC_ADDR_REG 0x70
#define RTC_DATA_REG 0x71 // read or write

#define UPDATING BIT(7)

#define REGISTER_A 10;
#define REGISTER_B 11;
typedef struct {
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t day_week;
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
} Time_Irl;
int read_rtc(uint8_t command, uint8_t *st);
int rtc_update();
int rtc_update_time();
int rtc_subscribe_int();
int rtc_unsubscribe_int();

#endif //SHARED_RTC_H

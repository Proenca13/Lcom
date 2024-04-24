#include "rtc.h"
Time time;
int read_rtc(uint8_t command, uint8_t *st){
    if(sys_outb(RTC_ADDR_REG,command)!=0)return 1;
    return util_sys_inb(RTC_DATA_REG,st);
}
int rtc_update(){
    uint8_t st;
    if(read_rtc(10,&st)!=0)return 1;
    return st & UPDATING;
}
int rtc_update_time(){
    if(rtc_update()!=0)return 1;
    uint8_t status;
    if(read_rtc(SECONDS,&status)!=0)return 1;
    time.seconds = status;
    if(read_rtc(MINUTES,&status)!=0)return 1;
    time.minutes = status;
    if(read_rtc(HOURS,&status)!=0)return 1;
    time.hours = status;
    if(read_rtc(DAY_OF_THE_WEEK,&status)!=0)return 1;
    time.day_week = status;
    if(read_rtc(DAY_OF_THE_MONTH,&status)!=0)return 1;
    time.day = status;
    if(read_rtc(MONTH,&status)!=0)return 1;
    time.month = status;
    if(read_rtc(YEAR,&status)!=0)return 1;
    time.year = status;
    return 0;
}

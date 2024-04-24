#include "view.h"
extern Time_Irl timeIrl;
void display_time(){
    printf("%d/%d/%d %d @%d:%d:%d\n", 2000 + timeIrl.year, timeIrl.month, timeIrl.day, timeIrl.day_week ,timeIrl.hours, timeIrl.minutes, timeIrl.seconds);
}

#include "model.h"
extern uint8_t scancode;
uint8_t entry = 0;
extern uint8_t byte_counter;
extern struct packet mouse_packet;
MenuState menuState = STARTMENU;
ProgramState programState = RUNNING;
GameState gameState = STOP;
extern Time_Irl timeIrl;
int counter_timer = 0;
extern uint16_t x;
extern uint16_t y;
void timer_state(){
    counter_timer++;
}
void keyboard_state(){
    kbc_ih();
   if(menuState == STARTMENU){
       switch (scancode) {
           case BRK_ESC:
               programState = END;
               break;
           case ARROW_DOWN_BRK:
               entry++;
               if(entry > 2)entry = 0;
               break;
           case ARROW_UP_BRK:
               entry--;
               if(entry < 0)entry = 2;
               break;
           case ENTER_BRK:
               if(entry == 0)gameState = PLAY;
               if(entry == 1)menuState = CONTROLLERMENU;
               if(entry == 2)programState = END;
               entry = 0;
               break;
       }
   }
   if(menuState == CONTROLLERMENU){
       switch (scancode) {
           case BRK_ESC:
               menuState = STARTMENU;
               break;
       }
   }
}
void mouse_state() {
    mouse_ih();
    mouse_sync_bytes();
    if (byte_counter == 3) {
        mouse_bytes_to_packet();
        byte_counter = 0;
    }
}
void rtc_state(){
    if(counter_timer%FREQUENCY==0)rtc_update_time();
}

#include "model.h"
extern uint8_t scancode;
extern uint8_t byte_counter;
uint8_t entry = 0;
MenuState menuState = STARTMENU;
ProgramState programState = RUNNING;
GameState gameState = STOP;
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

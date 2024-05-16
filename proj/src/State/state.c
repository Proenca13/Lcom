#include "state.h"
MenuState menuState = STARTMENU;
ProgramState programState = RUNNING;
GameState gameState = STOP;
int counter_timer = 0;
extern int16_t x;
extern int16_t y;
extern uint8_t scancode;
int8_t entry = -1;
int8_t pause_entry = 0;
extern uint8_t byte_counter;
extern struct packet mouse_packet;
extern Time_Irl timeIrl;
extern vbe_mode_info_t modeInfo;
extern Sprite *start_button_sprite;
extern Sprite *controls_button_sprite;
extern Sprite *exit_button_sprite;
void timer_state(){
    swap_buffers();
    counter_timer++;
}
void keyboard_state(){
    kbc_ih();
    if(menuState == STARTMENU && gameState != PLAY){
        switch (scancode) {
            case BRK_ESC:
                programState = END;
                break;
            case ARROW_DOWN_MAKE:
                entry++;
                if(entry > 2)entry = 0;
                break;
            case ARROW_UP_MAKE:
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
    else if(gameState == PLAY){
        switch (scancode) {
            case BRK_ESC:
                gameState = STOP;
                menuState = GAMEMENU;
                break;
        }
    }
    else if(menuState == GAMEMENU){
        switch (scancode) {
            case BRK_ESC:
                gameState = PLAY;
                break;
            case ARROW_DOWN_MAKE:
                pause_entry++;
                if(pause_entry > 1)pause_entry = 0;
                break;
            case ARROW_UP_MAKE:
                pause_entry--;
                if(pause_entry < 0)pause_entry = 1;
                break;
            case ENTER_BRK:
                if(pause_entry == 0)gameState = PLAY;
                if(pause_entry == 1)menuState = STARTMENU;
                pause_entry = 0;
                break;
        }
    }
    else if(menuState == CONTROLLERMENU){
        switch (scancode) {
            case BRK_ESC:
                menuState = STARTMENU;
                break;
            case ENTER_BRK:
                menuState = STARTMENU;
                break;
        }
    }
    draw_state();
}
void mouse_state() {
    mouse_ih();
    mouse_sync_bytes();
    if (byte_counter == 3) {
        mouse_bytes_to_packet();
        byte_counter = 0;
        if((x > start_button_sprite->x && x < start_button_sprite->x + start_button_sprite->width) && (y > start_button_sprite->y && y < start_button_sprite->y + start_button_sprite->height)){
            entry = 0;
            if(mouse_packet.lb){
                gameState = PLAY;
            }
        }
        if((x > controls_button_sprite->x && x < controls_button_sprite->x + controls_button_sprite->width) && (y > controls_button_sprite->y && y < controls_button_sprite->y + controls_button_sprite->height)){
            entry = 1;
            if(mouse_packet.lb){
                menuState = CONTROLLERMENU;
            }
        }
        if((x > exit_button_sprite->x && x < exit_button_sprite->x + exit_button_sprite->width) && (y > exit_button_sprite->y && y < exit_button_sprite->y + exit_button_sprite->height)){
            entry = 2;
            if(mouse_packet.lb){
                programState = END;
            }
        }
    }
    draw_state();
}
void rtc_state(){
    if(counter_timer%FREQUENCY==0)rtc_update_time();
}

#include "model.h"
extern uint8_t scancode;
int8_t entry = 0;
extern uint8_t byte_counter;
extern struct packet mouse_packet;
MenuState menuState = STARTMENU;
ProgramState programState = RUNNING;
GameState gameState = STOP;
extern Time_Irl timeIrl;
extern vbe_mode_info_t modeInfo;
int counter_timer = 0;
extern uint16_t x;
extern uint16_t y;

Sprite *start_button_sprite;
Sprite *start_button2_sprite;
Sprite *cursor_mouse;
Sprite *controls_button_sprite;
Sprite *controls_button2_sprite;
Sprite *exit_button_sprite;
Sprite *exit_button2_sprite;
Sprite *title_sprite;
Sprite *dirt_block;


void create_sprites(){
    start_button_sprite = create_sprite((xpm_map_t)start_button_xpm);
    start_button2_sprite = create_sprite((xpm_map_t)start_button2_xpm);
    cursor_mouse = create_sprite((xpm_map_t)cursor_xpm);
    controls_button_sprite = create_sprite((xpm_map_t)Controls_button);
    controls_button2_sprite = create_sprite((xpm_map_t)Controls_button2);
    exit_button_sprite = create_sprite((xpm_map_t)Exit);
    exit_button2_sprite = create_sprite((xpm_map_t)Exit2);
    title_sprite = create_sprite((xpm_map_t)Title_xpm);
    dirt_block = create_sprite((xpm_map_t)Dirt_block);

}
void destroy_sprites(){
    destroy_sprite(start_button_sprite);
    destroy_sprite(start_button2_sprite);
    destroy_sprite(cursor_mouse);
    destroy_sprite(controls_button_sprite);
    destroy_sprite(exit_button_sprite);
    destroy_sprite(title_sprite);
    destroy_sprite(dirt_block);
}
void timer_state(){
    swap_buffers();
    counter_timer++;
}
void keyboard_state(){
    kbc_ih();
   if(menuState == STARTMENU){
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
    }
    draw_state();
}
void rtc_state(){
    if(counter_timer%FREQUENCY==0)rtc_update_time();
}

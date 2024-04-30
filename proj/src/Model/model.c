#include "model.h"
extern uint8_t scancode;
int8_t entry = -1;
int8_t pause_entry = 0;
extern uint8_t byte_counter;
extern struct packet mouse_packet;
MenuState menuState = STARTMENU;
ProgramState programState = RUNNING;
GameState gameState = STOP;
extern Time_Irl timeIrl;
extern vbe_mode_info_t modeInfo;
int counter_timer = 0;
extern int16_t x;
extern int16_t y;

Sprite *start_button_sprite;
Sprite *start_button2_sprite;
Sprite *cursor_mouse;
Sprite *controls_button_sprite;
Sprite *controls_button2_sprite;
Sprite *exit_button_sprite;
Sprite *exit_button2_sprite;
Sprite *title_sprite;
Sprite *control_title_sprite;
Sprite *paused_title_sprite;
Sprite *dirt_block;
Sprite *arrows_sprite;
Sprite *day_sky_sprite;
Sprite *night_sky_sprite;
Sprite *afternoon_sky_sprite;
Sprite *dyog_sprite;
Sprite *dyog2_sprite;
Sprite *continue_button_sprite;
Sprite *continue_button2_sprite;
Sprite *right_click_sprite;
Sprite *left_click_sprite;
Sprite *esc_sprite;
Sprite *f_sprite;
Sprite *space_sprite;

void create_sprites(){
    start_button_sprite = create_sprite((xpm_map_t)start_button_xpm);
    arrows_sprite = create_sprite((xpm_map_t)arrows_xpm);
    start_button2_sprite = create_sprite((xpm_map_t)start_button2_xpm);
    cursor_mouse = create_sprite((xpm_map_t)cursor_xpm);
    controls_button_sprite = create_sprite((xpm_map_t)Controls_button);
    controls_button2_sprite = create_sprite((xpm_map_t)Controls_button2);
    exit_button_sprite = create_sprite((xpm_map_t)Exit);
    exit_button2_sprite = create_sprite((xpm_map_t)Exit2);
    title_sprite = create_sprite((xpm_map_t)Title_xpm);
    control_title_sprite = create_sprite((xpm_map_t)Controls_Title);
    paused_title_sprite = create_sprite((xpm_map_t)paused);
    dirt_block = create_sprite((xpm_map_t)Dirt_block);
    day_sky_sprite = create_sprite((xpm_map_t)Day_sky);
    night_sky_sprite = create_sprite((xpm_map_t)Night_sky);
    afternoon_sky_sprite = create_sprite((xpm_map_t)Afternoon_Sky);
    dyog_sprite = create_sprite((xpm_map_t)dyog);
    dyog2_sprite =  create_sprite((xpm_map_t)dyog2);
    continue_button_sprite = create_sprite((xpm_map_t)continue_button_xpm);
    continue_button2_sprite = create_sprite((xpm_map_t)continue_button2_xpm);
    right_click_sprite = create_sprite((xpm_map_t)Right_click);
    left_click_sprite = create_sprite((xpm_map_t)Left_click);
    esc_sprite = create_sprite((xpm_map_t)ESC);
    f_sprite = create_sprite((xpm_map_t)F);
    space_sprite = create_sprite((xpm_map_t)space);
}

void destroy_sprites(){
    destroy_sprite(start_button_sprite);
    destroy_sprite(start_button2_sprite);
    destroy_sprite(controls_button_sprite);
    destroy_sprite(controls_button2_sprite);
    destroy_sprite(exit_button_sprite);
    destroy_sprite(exit_button2_sprite);
    destroy_sprite(title_sprite);
    destroy_sprite(control_title_sprite);
    destroy_sprite(paused_title_sprite);
    destroy_sprite(dirt_block);
    destroy_sprite(arrows_sprite);
    destroy_sprite(cursor_mouse);
    destroy_sprite(day_sky_sprite);
    destroy_sprite(night_sky_sprite);
    destroy_sprite(afternoon_sky_sprite);
    destroy_sprite(dyog_sprite);
    destroy_sprite(dyog2_sprite);
    destroy_sprite(continue_button_sprite);
    destroy_sprite(continue_button2_sprite);
    destroy_sprite(right_click_sprite);
    destroy_sprite(left_click_sprite);
    destroy_sprite(esc_sprite);
    destroy_sprite(f_sprite);
    destroy_sprite(space_sprite);
}

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

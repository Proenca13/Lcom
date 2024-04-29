#include "view.h"
extern Time_Irl timeIrl;
extern MenuState menuState ;
extern ProgramState programState;
extern GameState gameState;
extern vbe_mode_info_t modeInfo;
extern uint16_t x;
extern uint16_t y;

extern int8_t entry;
extern int8_t pause_entry;

extern Sprite *start_button_sprite;
extern Sprite *start_button2_sprite;
extern Sprite *cursor_mouse;
extern Sprite *arrows_sprite;
extern Sprite *controls_button_sprite;
extern Sprite *controls_button2_sprite;
extern Sprite *exit_button_sprite;
extern Sprite *title_sprite;
extern Sprite *exit_button2_sprite;
extern Sprite *dirt_block;
extern Sprite *day_sky_sprite;
extern Sprite *night_sky_sprite;
extern Sprite *afternoon_sky_sprite;


void draw_state(){
    if(gameState != PLAY){
        if(menuState == STARTMENU )draw_main_menu();
        if(menuState == CONTROLLERMENU) draw_controls_menu();
        if(menuState == GAMEMENU )draw_game_menu();
    }
   if(gameState == PLAY)draw_game();
   draw_mouse();
}
void draw_main_menu(){
    draw_sprite(check_time_sprite(),0,0);
    draw_sprite(title_sprite,modeInfo.XResolution/4,50);
    draw_sprite(entry == 0 ? start_button2_sprite:start_button_sprite,modeInfo.XResolution/4,modeInfo.YResolution/5 + 50);
    draw_sprite(entry == 1? controls_button2_sprite:controls_button_sprite,modeInfo.XResolution/4,(modeInfo.YResolution*2)/5+ 50);
    draw_sprite(entry==2?exit_button2_sprite:exit_button_sprite,modeInfo.XResolution/4,(modeInfo.YResolution*3)/5+ 50);
}
void draw_game(){
    draw_sprite(dirt_block,0,0);
    draw_sprite(title_sprite,modeInfo.XResolution/4,50);
}
void draw_game_menu(){
    draw_sprite(dirt_block,0,0);
    draw_sprite(title_sprite,modeInfo.XResolution/4,50);
    draw_sprite(pause_entry == 0? start_button2_sprite:start_button_sprite,modeInfo.XResolution/4,modeInfo.YResolution/5 + 50);
    draw_sprite(pause_entry == 1? exit_button2_sprite:exit_button_sprite,modeInfo.XResolution/4,(modeInfo.YResolution*2)/5+ 50);
}
void draw_mouse(){
    draw_sprite(cursor_mouse,x,y);
}
void draw_controls_menu() {
    draw_sprite(dirt_block,0,0);
    draw_sprite(title_sprite,modeInfo.XResolution/4,50);
    draw_sprite(arrows_sprite,modeInfo.XResolution/8,150);
    draw_sprite(entry==0?exit_button2_sprite:exit_button_sprite,modeInfo.XResolution/4,modeInfo.YResolution - 60);
}
int draw_sprite(Sprite *sprite, int x, int y) {
    uint16_t height = sprite->height;
    uint16_t width = sprite->width;
    sprite->x = x;
    sprite->y= y;
    uint32_t current_color;
    for (int h = 0 ; h < height ; h++) {
        for (int w = 0 ; w < width ; w++) {
            current_color = sprite->map[w + h*width];
            if(current_color == TRANSPARENT)continue;
            if (vg_draw_pixel(x + w, y + h, current_color) != 0) return 1;
        }
    }
    return 0;
}

Sprite *check_time_sprite(){
    rtc_update_time();
    if (timeIrl.hours >= 22 || timeIrl.hours < 6)return night_sky_sprite;
    else if(timeIrl.hours >= 6 && timeIrl.hours < 14 )return  day_sky_sprite;
    else if(timeIrl.hours >=  14 && timeIrl.hours < 22)return afternoon_sky_sprite;
    return day_sky_sprite;

}



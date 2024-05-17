#include "view.h"
extern Time_Irl timeIrl;
extern MenuState menuState ;
extern ProgramState programState;
extern GameState gameState;
extern vbe_mode_info_t modeInfo;
extern uint16_t x;
extern uint16_t y;
extern uint8_t rows ;
extern uint8_t cols ;
extern int8_t entry;
extern int8_t pause_entry;
extern int8_t game_over_entry;

extern Sprite *start_button_sprite;
extern Sprite *start_button2_sprite;
extern Sprite *cursor_mouse;
extern Sprite *arrows_sprite;
extern Sprite *controls_button_sprite;
extern Sprite *controls_button2_sprite;
extern Sprite *exit_button_sprite;
extern Sprite *title_sprite;
extern Sprite *control_title_sprite;
extern Sprite *paused_title_sprite;
extern Sprite *exit_button2_sprite;
extern Sprite *dirt_block;
extern Sprite *day_sky_sprite;
extern Sprite *night_sky_sprite;
extern Sprite *afternoon_sky_sprite;
extern Sprite *dyog_sprite;
extern Sprite *dyog2_sprite;
extern Sprite *continue_button_sprite;
extern Sprite *continue_button2_sprite;
extern Sprite *right_click_sprite;
extern Sprite *left_click_sprite;
extern Sprite *esc_sprite;
extern Sprite *f_sprite;
extern Sprite *space_sprite;
extern Sprite *grass_sprite;
extern Sprite *selected_grass_sprite;
extern Sprite *tnt_sprite;
extern Sprite *cobblestone_sprite;
extern Sprite *selected_cobblestone_sprite;
extern Sprite *tile1_sprite;
extern Sprite *selected_tile1_sprite;
extern Sprite *tile2_sprite;
extern Sprite *selected_tile2_sprite;
extern Sprite *tile3_sprite;
extern Sprite *selected_tile3_sprite;
extern Sprite *tile4_sprite;
extern Sprite *selected_tile4_sprite;
extern Sprite *tile5_sprite;
extern Sprite *selected_tile5_sprite;
extern Sprite *tile6_sprite;
extern Sprite *selected_tile6_sprite;
extern Sprite *tile7_sprite;
extern Sprite *selected_tile7_sprite;
extern Sprite *tile8_sprite;
extern Sprite *selected_tile8_sprite;
extern Sprite *flag_sprite;
extern Sprite *selected_flag_sprite;
extern Sprite *game_over_sprite;

extern Block* **grid;

void draw_state(){
    if(gameState != PLAY){
        if(menuState == STARTMENU )draw_main_menu();
        if(menuState == CONTROLLERMENU) draw_controls_menu();
        if(menuState == GAMEMENU )draw_game_menu();
        if(menuState == GAMEOVER)draw_game_over_menu();
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
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int x = modeInfo.XResolution/2 -( 4 * grid[i][j]->block_sprite->width) + i * grid[i][j]->block_sprite->width;
            int y = modeInfo.YResolution/2 -( 4 * grid[i][j]->block_sprite->height) + j * grid[i][j]->block_sprite->height + 25;
            if(grid[i][j]->state == Not_Revealed){
                if(grid[i][j]->is_selected == true){
                    draw_sprite(selected_grass_sprite , x, y);
                }
                else{
                    draw_sprite(grass_sprite, x, y);
                }
            }
            else if(grid[i][j]->state == Revealed){
                if(grid[i][j]->is_selected == true){
                    draw_sprite(grid[i][j]->selected_block_sprite, x, y);;
                }
                else{
                    draw_sprite(grid[i][j]->block_sprite, x, y);
                }

            }
            else if(grid[i][j]->state == Flagged){
                if(grid[i][j]->is_selected == true){
                    draw_sprite(selected_flag_sprite, x, y);;
                }
                else{
                    draw_sprite(flag_sprite, x, y);
                }

            }

        }
    }
}
void draw_game_menu(){
    draw_sprite(dirt_block,0,0);
    draw_sprite(paused_title_sprite,modeInfo.XResolution/4,50);
    draw_sprite(pause_entry==0?continue_button2_sprite:continue_button_sprite,modeInfo.XResolution/4,modeInfo.YResolution/5 + 50);
    draw_sprite(pause_entry == 1? exit_button2_sprite:exit_button_sprite,modeInfo.XResolution/4,(modeInfo.YResolution*2)/5+ 50);
    draw_sprite(dyog_sprite,modeInfo.XResolution-200,modeInfo.YResolution - 200);
    draw_sprite(dyog2_sprite,0,modeInfo.YResolution - 200);
}
void draw_game_over_menu(){
    draw_sprite(dirt_block,0,0);
    draw_sprite(game_over_sprite,modeInfo.XResolution/4,50);
    draw_sprite(game_over_entry==0?continue_button2_sprite:continue_button_sprite,modeInfo.XResolution/4,modeInfo.YResolution/5 + 50);
    draw_sprite(game_over_entry == 1? exit_button2_sprite:exit_button_sprite,modeInfo.XResolution/4,(modeInfo.YResolution*2)/5+ 50);
    draw_sprite(dyog_sprite,modeInfo.XResolution-200,modeInfo.YResolution - 200);
    draw_sprite(dyog2_sprite,0,modeInfo.YResolution - 200);
}
void draw_mouse(){
    draw_sprite(cursor_mouse,x,y);
}
void draw_controls_menu() {
    draw_sprite(dirt_block,0,0);
    draw_sprite(control_title_sprite,modeInfo.XResolution/4,50);
    draw_sprite(arrows_sprite,modeInfo.XResolution/8,150);
    draw_sprite(entry==0?exit_button2_sprite:exit_button_sprite,modeInfo.XResolution/4,modeInfo.YResolution - 60);
    draw_sprite(right_click_sprite, modeInfo.XResolution/12 + 20, 300);
    draw_sprite(left_click_sprite, modeInfo.XResolution/12 + 120, 300);
    draw_sprite(f_sprite, (modeInfo.XResolution / 8) *4.5, 150);
    draw_sprite(space_sprite, (modeInfo.XResolution / 8) *4.5, 270);
    draw_sprite(esc_sprite, (modeInfo.XResolution / 8) *4.5, 390);
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
    printf("hours = %d  \n",timeIrl.hours);
    if (timeIrl.hours >= 22 || timeIrl.hours < 6)return night_sky_sprite;
    else if(timeIrl.hours >= 6 && timeIrl.hours < 14 )return  day_sky_sprite;
    else if(timeIrl.hours >=  14 && timeIrl.hours < 22)return afternoon_sky_sprite;
    return day_sky_sprite;
}



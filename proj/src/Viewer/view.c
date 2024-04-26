#include "view.h"
extern Time_Irl timeIrl;
extern MenuState menuState ;
extern ProgramState programState;
extern GameState gameState;
extern vbe_mode_info_t modeInfo;
extern uint16_t x;
extern uint16_t y;

extern Sprite *start_button_sprite;
extern Sprite *cursor_mouse;
void display_time(){
    printf("%d/%d/%d %d @%d:%d:%d\n", 2000 + timeIrl.year, timeIrl.month, timeIrl.day, timeIrl.day_week ,timeIrl.hours, timeIrl.minutes, timeIrl.seconds);
}
void draw_state(){
    if(menuState == STARTMENU)draw_main_menu();
    draw_mouse();
}
void draw_main_menu(){
    draw_sprite(start_button_sprite,modeInfo.XResolution/2,modeInfo.YResolution/2);
}
void draw_mouse(){
    draw_sprite(cursor_mouse,x,y);
}
int draw_sprite(Sprite *sprite, int x, int y) {
    uint16_t height = sprite->height;
    uint16_t width = sprite->width;
    uint32_t current_color;
    for (int h = 0 ; h < height ; h++) {
        for (int w = 0 ; w < width ; w++) {
            current_color = sprite->map[w + h*width];
            if (vg_draw_pixel(x + w, y + h, current_color) != 0) return 1;
        }
    }
    return 0;
}

#include "state.h"
#include <unistd.h>
MenuState menuState = STARTMENU;
ProgramState programState = RUNNING;
GameState gameState = STOP;
int counter_timer = 0;
extern int16_t x;
extern int16_t y;
extern uint8_t scancode;
int8_t entry = -1;
int8_t pause_entry = 0;
int8_t game_over_entry = 0;
int8_t win_entry = 0;
extern uint8_t byte_counter;
extern struct packet mouse_packet;
extern Time_Irl timeIrl;
extern vbe_mode_info_t modeInfo;
extern Sprite *start_button_sprite;
extern Sprite *controls_button_sprite;
extern Sprite *exit_button_sprite;

extern Grid_entry grid_entry;
extern Block* **grid;

void timer_state(){
    swap_buffers();
    counter_timer++;
}
void keyboard_state(){
    kbc_ih();
    if(gameState != PLAY){
        if(menuState == STARTMENU ){
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
                    if(entry == 0){
                        gameState = PLAY;
                        create_game();
                    }
                    else if(entry == 1)menuState = CONTROLLERMENU;
                    else if(entry == 2)programState = END;
                    entry = 0;
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
                    if(pause_entry > 2)pause_entry = 0;
                    break;
                case ARROW_UP_MAKE:
                    pause_entry--;
                    if(pause_entry < 0)pause_entry = 2;
                    break;
                case ENTER_BRK:
                    if(pause_entry == 0)gameState = PLAY;
                    else if(pause_entry == 1){
                        grid_entry.x = 0;
                        grid_entry.y = 0;
                        destroy_game();
                        create_game();
                        gameState = PLAY;
                    }
                    else if(pause_entry == 2){
                        menuState = STARTMENU;
                        destroy_game();
                    }
                    pause_entry = 0;
                    break;
            }
        }
        else if(menuState == GAMEOVER){
            switch (scancode) {
                case BRK_ESC:
                    menuState = STARTMENU;
                    break;
                case ARROW_DOWN_MAKE:
                    game_over_entry++;
                    if(game_over_entry > 1)game_over_entry = 0;
                    break;
                case ARROW_UP_MAKE:
                    game_over_entry--;
                    if(game_over_entry < 0)game_over_entry = 1;
                    break;
                case ENTER_BRK:
                    if(game_over_entry == 0){
                        gameState = PLAY;
                        create_game();
                    }
                    else if(game_over_entry == 1){
                        menuState = STARTMENU;
                    }
                    game_over_entry = 0;
                    break;
            }
        }
        else if(menuState == WINMENU){
            switch (scancode) {
                case BRK_ESC:
                    menuState = STARTMENU;
                    break;
                case ARROW_DOWN_MAKE:
                    win_entry++;
                    if(win_entry > 1)win_entry = 0;
                    break;
                case ARROW_UP_MAKE:
                    win_entry--;
                    if(win_entry < 0)win_entry = 1;
                    break;
                case ENTER_BRK:
                    if(win_entry == 0){
                        gameState = PLAY;
                        create_game();
                    }
                    else if(win_entry == 1){
                        menuState = STARTMENU;
                    }
                    win_entry = 0;
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
    }
    else {
        if (scancode == BRK_ESC) {
                gameState = STOP;
                menuState = GAMEMENU;
        }
        else cell_state();
    }
    draw_state();
}
void mouse_state() {
    mouse_ih();
    mouse_sync_bytes();
    if (byte_counter == 3) {
        mouse_bytes_to_packet();
        byte_counter = 0;
        if(gameState != PLAY){
            if (menuState == STARTMENU ){
                if((x > start_button_sprite->x && x < start_button_sprite->x + start_button_sprite->width) && (y < start_button_sprite->y && y > start_button_sprite->y - start_button_sprite->height)){
                    entry = 0;
                    if(mouse_packet.lb){
                        gameState = PLAY;
                    }
                }
                if((x > controls_button_sprite->x && x < controls_button_sprite->x + controls_button_sprite->width) && (y < controls_button_sprite->y && y > controls_button_sprite->y - controls_button_sprite->height)){
                    entry = 1;
                    if(mouse_packet.lb){
                        menuState = CONTROLLERMENU;
                    }
                }
                if((x > exit_button_sprite->x && x < exit_button_sprite->x + exit_button_sprite->width) && (y < exit_button_sprite->y && y > exit_button_sprite->y - exit_button_sprite->height)){
                    entry = 2;
                    if(mouse_packet.lb){
                        programState = END;
                    }
                }
            }
        }
        else{

        }

    }
    draw_state();
}
void rtc_state(){
    if(counter_timer%FREQUENCY==0)rtc_update_time();
}
void cell_state(){
    switch (scancode) {
        case ARROW_DOWN_MAKE:
                grid[grid_entry.x][grid_entry.y]->is_selected = false;
                grid_entry.y++;
                if(grid_entry.y > 7)grid_entry.y= 0;
                grid[grid_entry.x][grid_entry.y]->is_selected = true;
                break;
        case ARROW_UP_MAKE:
            grid[grid_entry.x][grid_entry.y]->is_selected = false;
            grid_entry.y--;
            if(grid_entry.y <0)grid_entry.y = 7;
            grid[grid_entry.x][grid_entry.y]->is_selected = true;
            break;
        case ARROW_LEFT_MAKE:
            grid[grid_entry.x][grid_entry.y]->is_selected = false;
            grid_entry.x--;
            if(grid_entry.x< 0)grid_entry.x = 7;
            grid[grid_entry.x][grid_entry.y]->is_selected = true;
            break;
        case ARROW_RIGHT_MAKE:
            grid[grid_entry.x][grid_entry.y]->is_selected = false;
            grid_entry.x++;
            if(grid_entry.x> 7)grid_entry.x = 0;
            grid[grid_entry.x][grid_entry.y]->is_selected = true;
            break;
        case SPACE_BRK:
            if(check_first_touch()){
                placeBombs();
            }
            if(grid[grid_entry.x][grid_entry.y]->state == Not_Revealed || grid[grid_entry.x][grid_entry.y]->state == Flagged) {
                grid[grid_entry.x][grid_entry.y]->state = Revealed;
                if(check_win()){
                    draw_state();
                    sleep(3);
                    menuState = WINMENU;
                    gameState = STOP;
                    destroy_game();
                    grid_entry.x = 0;
                    grid_entry.y = 0;
                }
                if(grid[grid_entry.x][grid_entry.y]->type == BOMB){
                    menuState = GAMEOVER;
                    gameState = STOP;
                    destroy_game();
                    grid_entry.x = 0;
                    grid_entry.y = 0;
                }
                if(grid[grid_entry.x][grid_entry.y]->type == EMPTY)reveal_near_zeros(grid_entry.x,grid_entry.y);
            }
            break;
        case F_BRK:
            if(grid[grid_entry.x][grid_entry.y]->state == Not_Revealed && check_can_flag()) {
                grid[grid_entry.x][grid_entry.y]->state = Flagged;
            }
            else if(grid[grid_entry.x][grid_entry.y]->state == Flagged) {
                 grid[grid_entry.x][grid_entry.y]->state = Not_Revealed;
             }
            break;
        }

    return;
}

#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "sprite.h"
#ifndef SHARED_GAME_H
#define SHARED_GAME_H
typedef enum{
    Flagged,
    Revealed,
    Not_Revealed
}BlockState;
typedef enum{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    BOMB,
    EMPTY
}BlockType;
typedef struct {
    int16_t x,y;
} Grid_entry;
typedef struct {
    Sprite *block_sprite;
    Sprite *selected_block_sprite;
    BlockType type;
    int16_t row,col;
    bool is_selected;
    BlockState state;
} Block;
void SetPosition(int16_t row, int16_t col);
void SetSprite(Sprite *block);
void SetId(BlockType type);
void SetSelected(bool is_selected);
void SetState(BlockState state);
void placeBombs();
void count_bombs_around(int16_t x,int16_t y);
Block *create_block(Sprite *block_sprite,Sprite *selected_block_sprite,BlockType type, int16_t row, int16_t col,bool is_selected,BlockState state);
void create_game();
void destroy_game();
int check_win();
#endif //SHARED_GAME_H

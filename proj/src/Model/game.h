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
    Sprite *block_sprite;
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
Block *create_block(Sprite *block_sprite,BlockType type, int16_t row, int16_t col,bool is_selected,BlockState state);
void create_game();
void destroy_game();
#endif //SHARED_GAME_H

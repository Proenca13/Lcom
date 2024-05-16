#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "sprite.h"
#ifndef SHARED_GAME_H
#define SHARED_GAME_H
typedef enum{
    Flagged,
    Revealed,
    Not_Reveled;
}BlockState;
typedef struct {
    Sprite *block;
    char id;
    int16_t row,col;
    bool is_selected;
    BlockState state;
} Block;
void SetPosition(int16_t row, int16_t col);
void SetSprite(Sprite *block);
void SetId(char id);
void SetSelected(bool is_selected);
void SetState(BlockState state);
void draw_block(const Block block);
void create_block(Sprite *block,char id, int16_t row, int16_t col,bool is_selected,BlockState state);
void create_game();
#endif //SHARED_GAME_H

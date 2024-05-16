#include "game.h"
extern Sprite *grass_sprite;
uint8_t rows = 8;
uint8_t cols = 8;
Block* **grid;
Block *create_block(Sprite *block_sprite,BlockType type, int16_t row, int16_t col,bool is_selected,BlockState state){
    Block *block = (Block *) malloc (sizeof(Block));
    block->block_sprite = block_sprite;
    block->type= type;
    block->row = row;
    block->col = col;
    block->is_selected = is_selected;
    block->state = state;
    return block;
}

void create_game(){
    grid = malloc(rows * sizeof(Block *));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(cols * sizeof(Block));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Sprite *block_sprite = grass_sprite;
            BlockType type = EMPTY;
            int16_t row = i;
            int16_t col = j;
            bool is_selected = false;
            BlockState state = Not_Revealed;
            grid[i][j] = create_block(block_sprite, type, row, col, is_selected, state);
        }
    }
}
void destroy_game(){
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

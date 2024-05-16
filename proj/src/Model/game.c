#include "game.h"
extern Sprite *grass_sprite;
extern Sprite *tnt_sprite;
extern Sprite *selected_grass_sprite;
uint8_t rows = 8;
uint8_t cols = 8;
Grid_entry grid_entry = {0, 0};
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
void placeBombs(){
    int bombs_placed = 0;
    while (bombs_placed < 10) {
        int random_row = rand() % rows;
        int random_col = rand() % cols;

        if (grid[random_row][random_col]->type != BOMB) {
            grid[random_row][random_col]->type = BOMB;
            grid[random_row][random_col]->block_sprite = tnt_sprite;
            bombs_placed++;
        }
    }
}
void count_bombs_around(int16_t x , int16_t y){
    uint8_t count = 0;
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int k = 0; k < 8; k++) {
        int n_row = x + dr[k];
        int n_col = y + dc[k];
        if (n_row >= 0 && n_row < rows && n_col >= 0 && n_col < cols) {
            if (grid[n_row][n_col]->type == BOMB) {
                count++;
            }
        }
    }
    switch (count) {
        case 0:
            grid[x][y]->type = EMPTY;
            break;
        case 1:
            grid[x][y]->type = ONE;
            break;
        case 2:
            grid[x][y]->type = TWO;
            break;
        case 3:
            grid[x][y]->type = THREE;
            break;
        case 4:
            grid[x][y]->type = FOUR;
            break;
        case 5:
            grid[x][y]->type = FIVE;
            break;
        case 6:
            grid[x][y]->type = SIX;
            break;
        case 7:
            grid[x][y]->type = SEVEN;
            break;
        case 8:
            grid[x][y]->type = EIGHT;
            break;
    }
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
    placeBombs();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           count_bombs_around( i , j) ;
        }
    }
}
void destroy_game(){
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

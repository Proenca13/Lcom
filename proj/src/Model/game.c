#include "game.h"
void create_game(){
    int rows = 8;
    int cols = 8;
    Block **grid = malloc(rows * sizeof(Block *));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(cols * sizeof(Block));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            create_block();
        }
    }
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
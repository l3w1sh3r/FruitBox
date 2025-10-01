#ifndef DEFS_H
#define DEFS_H

// Screen size
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Board settings
#define BOARD_COLS 6
#define BOARD_ROWS 8
#define CELL_SIZE 64

#define BOARD_WIDTH (BOARD_COLS * CELL_SIZE)
#define BOARD_HEIGHT (BOARD_ROWS * CELL_SIZE)

// Board position
#define BOARD_X ((SCREEN_WIDTH - BOARD_WIDTH) / 2)
#define BOARD_Y ((SCREEN_HEIGHT - BOARD_HEIGHT) / 2)

#endif
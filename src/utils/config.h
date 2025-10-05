// definitions and constants

#ifndef CONFIG_H
#define CONFIG_H

// Screen size
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640
#define WINDOW_TITLE "Fruit Box"

// Grid settings
#define GRID_SIZE 8   // 8x8
#define APPLE_SIZE 64 // each apple is 64x64 px

// Auto-centering offsets
#define GRID_PIXEL_SIZE (GRID_SIZE * APPLE_SIZE)
#define GRID_OFFSET_X ((WINDOW_WIDTH - GRID_PIXEL_SIZE) / 2)
#define GRID_OFFSET_Y ((WINDOW_HEIGHT - GRID_PIXEL_SIZE) / 2)

// Game settings
#define GAME_TIME 60.0f   // total game time in seconds
#define TARGET_SUM 10     // apples sum to clear
#define APPLE_MAX_VALUE 9 // random apple value max
#define APPLE_MIN_VALUE 1 // random apple value min

// Assets paths
#define ASSETS_PATH "assets/"
#define IMAGES_PATH ASSETS_PATH "images/"
#define SOUNDS_PATH ASSETS_PATH "sounds/"
#define FONTS_PATH ASSETS_PATH "fonts/"
#define APPLE_IMAGE IMAGES_PATH "appleWithoutLeaf.png"
#define BACKGROUND_IMAGE IMAGES_PATH "ingameSquareBackground.png"
#define MENU_BACKGROUND_IMAGE IMAGES_PATH "menuBackground.png"

// colors
#define COLOR_BG_R 30
#define COLOR_BG_G 30
#define COLOR_BG_B 30
#define COLOR_BG_A 255

#define COLOR_TEXT_R 255
#define COLOR_TEXT_G 255
#define COLOR_TEXT_B 255
#define COLOR_TEXT_A 255

#define COLOR_SELECTION_R 0
#define COLOR_SELECTION_G 255
#define COLOR_SELECTION_B 0
#define COLOR_SELECTION_A 100 // transparent green box

#endif // CONFIG_H
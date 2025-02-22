#include "map.hpp"
#include <raylib.h>

TileMap::TileMap() {
    tileX = 0;
    tileY = 0;
    tileWidth = 32;
    tileHeight = 32;
    tileset = LoadTexture("assets/Tiles/Grass.png");
    if (tileset.id == 0) {
        TraceLog(LOG_ERROR, "Failed to load texture: assets/Tiles/Grass.png");
    } else {
        TraceLog(LOG_INFO, "Texture loaded successfully: assets/Tiles/Grass.png");
    }
}

void TileMap::Draw() {
    //DrawTexture(tileset, tileX, tileY, WHITE);

    if(tileset.id == 0) {
        TraceLog(LOG_ERROR, "Failed to draw texture: assets/Tiles/Grass.png");
    } else {
        TraceLog(LOG_INFO, "Texture drawn successfully: assets/Tiles/Grass.png");
    }

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    Rectangle sourceRec = { 0.0f, 0.0f, (float)tileset.width, (float)tileset.height };
    Rectangle destRec = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };
    Vector2 origin = { 0.0f, 0.0f };

    DrawTexturePro(tileset, sourceRec, destRec, origin, 0.0f, WHITE); 
}

TileMap::~TileMap() {
    if(tileset.id != 0) {
        UnloadTexture(tileset);
        TraceLog(LOG_INFO, "Texture unloaded successfully: assets/Tiles/Grass.png");
    } else {
        TraceLog(LOG_ERROR, "Failed to unload texture: assets/Tiles/Grass.png");
    }
}
#include <raylib.h>
#include "headers/map.hpp"

TileMap::TileMap() {
    tileX = 0;
    tileY = 0;
    tileWidth = 32;
    tileHeight = 32;
    tileset = LoadTexture("assets/tiles/Grass.png");
}

TileMap::~TileMap() {
    UnloadTexture(tileset);
}

void TileMap::Draw() {

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    Rectangle sourceRec = { 0.0f, 0.0f, (float)tileset.width, (float)tileset.height };
    Rectangle destRec = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };
    Vector2 origin = { 0.0f, 0.0f };

    DrawTexturePro(tileset, sourceRec, destRec, origin, 0.0f, WHITE); 

    DrawRectangle(0, 0, 32, 32, WHITE);
}
#pragma once
#include <raylib.h>

class TileMap {
    public:
        TileMap();
        ~TileMap();
        void Draw();
    private:
        float tileX, tileY;
        float tileWidth, tileHeight;
        Texture2D tileset;
};	
#ifndef PLAYER_HPP
#define PLAYER_HPP

#pragma once
#include <raylib.h>
#include <vector>

class Player {
    public:
        Player();
        void Update();
        void Draw();
        Vector2 position;
    private:
        float x, y;
        float width, height;
        Texture2D texture;
};

#endif
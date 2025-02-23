#ifndef PLAYER_HPP
#define PLAYER_HPP

#pragma once
#include <raylib.h>


class Player {
    public:
        Player();
        ~Player();
        void Update();
        void Draw();
        Vector2 position;
    private:
        float x, y;
        int width, height;
        int frameWidth, frameHeight;
        int currentFrame;
        int framesCounter;
        int frameSpeed;
        Rectangle frameRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };
        Texture2D texture;  
};

#endif
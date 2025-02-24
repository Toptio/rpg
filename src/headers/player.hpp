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
        Texture2D texture;  
        int frameWidth, frameHeight;
        int currentFrame;
        int framesCounter;
        int frameSpeed;
        Rectangle frameRec;
};

#endif
#ifndef PLAYER_HPP
#define PLAYER_HPP

#pragma once
#include <raylib.h>
#include "include/Animator.h"


class Player {
    public:
        Player();
        ~Player();
        void Update();
        void Draw();
        Vector2 position;
    private:
        int frameWidth, frameHeight;
        Texture2D playerIdle;
        Animator playerIdleAnim{"PlayerIdle", 6, 1, 5};
};

#endif
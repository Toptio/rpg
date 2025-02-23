#include "headers/player.hpp"
#include <raylib.h>
#include <vector>

Player::Player() {
    texture = LoadTexture("assets/player/Soldier-idle.png");
    width = 32;
    height = 32;
    frameWidth = texture.width / 6;
    frameHeight = texture.height;
    position.x = GetScreenWidth() / 2 - frameWidth / 2;
    position.y = GetScreenHeight() / 2 - frameHeight / 2;
    currentFrame = 0;
    framesCounter = 0;
    frameSpeed = 10.f;
    frameRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };
}

void Player::Draw() {
    //DrawRectangle(position.x, position.y, width, height, WHITE);
    DrawTextureRec(texture, frameRec, position, WHITE);
}   

void Player::Update(){
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        y -= 5;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        y += 5;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        x -= 5;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        x += 5;
    }

    framesCounter += GetFrameTime() * frameSpeed;
    if(framesCounter >= 1) {
        framesCounter = 0;
        currentFrame++;
        if(currentFrame > 5) {
            currentFrame = 0;
        }
    }

    // Update player animation frame
    frameRec.x = currentFrame * frameWidth;
}

Player::~Player() {
    
}
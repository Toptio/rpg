#include "headers/player.hpp"
#include <raylib.h>
#include <vector>

Player::Player() {
    texture = LoadTexture("assets/player/Soldier-idle.png");
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
    /*Rectangle destRec = { position.x, position.y, 32, 32 };
    Vector2 origin = { 0, 0 };
    DrawTexturePro(texture, frameRec, destRec, origin, 0.0f, WHITE); */
    DrawTextureRec(texture, frameRec, position, WHITE);
}   

void Player::Update(){
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        position.y -= 5;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        position.y += 5;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        position.x -= 5;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        position.x += 5;
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
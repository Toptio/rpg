#include <raylib.h>
#include <vector>
#include "headers/player.hpp"
#include "include/Animator.h"


Player::Player() {
    frameWidth = 32;
    frameHeight = 32;
    position.x = GetScreenWidth() / 2 - frameWidth / 2;
    position.y = GetScreenHeight() / 2 - frameHeight / 2;
    playerIdle = LoadTexture("assets/player/Soldier-Idle.png");
    playerIdleAnim.AssignSprite(playerIdle);
    playerIdleAnim.SetLooping(true);
}

Player::~Player() {
    UnloadTexture(playerIdle);
}

void Player::Draw() {
    // Set the destination rectangle to the desired size (e.g., 64x64)
    Rectangle frameRec = {position.x, position.y, 256, 256};
    Vector2 origin = {0, 0};
    DrawTexturePro(playerIdleAnim.GetSprite(), playerIdleAnim.GetFrameRec(), frameRec, origin, 0.0f, WHITE);
}

void Player::Update() {
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

    playerIdleAnim.Play();
}
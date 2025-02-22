#include "player.hpp"
#include <raylib.h>
#include <vector>

Player::Player() {
    position.x = 400;
    position.y = 225;
    width = 50;
    height = 50;
}

void Player::Draw() {
    DrawRectangle(x, y, width, height, WHITE);
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
}
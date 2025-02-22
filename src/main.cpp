#include <raylib.h>
#include "player.hpp"
#include "map.hpp"

enum class GameState
{
    MENU,
    GAMEPLAY,
    GAMEOVER,
    QUIT
};

GameState gameState = GameState::MENU;

void UpdateQuit() {
    const char* text = "Are you sure you want to exit? Y/N";
    int textWidth = MeasureText(text, 20);
    int textX = GetScreenWidth() / 2 - textWidth / 2;
    int textY = GetScreenHeight() / 2;
    DrawText(text, textX, textY, 20, WHITE);
    if (IsKeyPressed(KEY_Y)) {
        CloseWindow();
    }
    if (IsKeyPressed(KEY_N)) {
        gameState = GameState::MENU;
    }
}

void UpdateMenu() {
    const char* text = "Press ENTER to start";
    int textWidth = MeasureText(text, 20);
    int textX = GetScreenWidth() / 2 - textWidth / 2;
    int textY = GetScreenHeight() / 2;
    DrawText(text, textX, textY, 20, WHITE);
    if (IsKeyPressed(KEY_ENTER)) {
        gameState = GameState::GAMEPLAY;
    }
    if (IsKeyPressed(KEY_ESCAPE)) {
        gameState = GameState::QUIT;
    }
}

void UpdateGameplay(Player& player, TileMap& map) {
    map.Draw();
    player.Update();
    player.Draw();
    if (IsKeyPressed(KEY_ESCAPE)) {
        gameState = GameState::MENU;
    }
}

void UpdateGameOver() {
    const char* text = "Game Over";
    int textWidth = MeasureText(text, 20);
    int textX = GetScreenWidth() / 2 - textWidth / 2;
    int textY = GetScreenHeight() / 2;
    DrawText(text, textX, textY, 20, WHITE);
    if (IsKeyPressed(KEY_ENTER))   {
        gameState = GameState::MENU;
    }
    if (IsKeyPressed(KEY_ESCAPE)) {
        gameState = GameState::QUIT;
    }
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "RPG");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    Player player;
    TileMap map;

    bool fullScren = false;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        if(IsKeyPressed(KEY_F)) {
            if(fullScren) {
                fullScren = false;
                SetWindowSize(800, 450);
            } else {
                fullScren = true;
                SetWindowSize(GetMonitorWidth(0), GetMonitorHeight(0));
            }
        }

        switch (gameState) {
            case GameState::MENU:
                UpdateMenu();
                break;
            case GameState::GAMEPLAY:
                UpdateGameplay(player, map);
                break;
            case GameState::GAMEOVER: 
                UpdateGameOver();
                break;
            case GameState::QUIT:
                UpdateQuit();
                break;
        }

        EndDrawing();
        }
    
        CloseWindow();
        return 0;
}
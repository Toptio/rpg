#include <raylib.h>
#include "headers/player.hpp"
#include "headers/map.hpp"

// Enumeration for game states
enum class GameState
{
    MENU,
    GAMEPLAY,
    GAMEOVER,
    QUIT
};

// Initial game state
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

// Need to pass player and map by reference to update them
void UpdateGameplay(Player& player, TileMap& map) {
    map.Draw();
    player.Draw(), player.Update();

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

    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "RPG");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    InitAudioDevice();

    // Create player and map
    Player player;
    TileMap map;

    bool fullScreen = false;

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        if (IsKeyPressed(KEY_F)) {
            ToggleFullscreen();
            fullScreen = !fullScreen;
        }

        // Update game state
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
        
        CloseAudioDevice();

        CloseWindow();
        return 0;
}
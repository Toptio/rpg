#include <raylib.h>
#include "player.hpp"
#include "map.hpp"

int main() 
{

    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Window");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    bool exitWindowRequested = false;
    bool isInMenu = true;
    bool fullScreen = false;

    TileMap tileMap;
    Player player;

    while (!WindowShouldClose()) 
    {
        if(WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true; 

        if(isInMenu && !exitWindowRequested) {
            if(IsKeyPressed(KEY_ENTER)) {
                isInMenu = false;
            }
        }
        else if (!isInMenu && !exitWindowRequested) {
            if(IsKeyPressed(KEY_ESCAPE)) {
                isInMenu = true;
            }
        }

        if(IsKeyPressed(KEY_F)) {
            if(fullScreen) {
                fullScreen = false;
                ToggleFullscreen();
            }
            else {
                fullScreen = true;
                ToggleFullscreen();
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // Get the current screen width and height
        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        // Exit Window Logic
        if(exitWindowRequested) {
            DrawText("Are you sure you want to exit? (y/n)", 10, 10, 20, WHITE);
            if(IsKeyPressed(KEY_Y)) {
                break;
            }
            if(IsKeyPressed(KEY_N)) {
                exitWindowRequested = false;
            }
        } else if(isInMenu) {
            // Menu logic
            int textWidth = MeasureText("Press Enter to Start", 20);
            int textX = (screenWidth - textWidth) / 2;
            int textY = screenHeight / 2;
            DrawText("Press Enter to Start", textX, textY, 20, WHITE);
        }
        else {
            // Game logic
            DrawText("Game", 10, 30, 20, WHITE);
            tileMap.Draw();
            player.Draw(), player.Update();
        }

        EndDrawing();


    }
    
    CloseWindow();

    return 0;
}
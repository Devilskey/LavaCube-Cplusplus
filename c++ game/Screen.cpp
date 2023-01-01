#include "Screen.h"
#include <raylib.h>
#include "player.h"


static void Load() {

    DrawRectangleGradientV(0, 0, 500, 500, RED, BLACK);
    DrawRectangle(0, 460, 500, 40,  RED);
}

static void RenderGame(float Score, bool startGame) {
    Load();
    DrawFPS(400, 0);
    DrawRectangle(500 / 2 - 66, 0, 132, 36, BLACK);

    DrawRectangle(500 / 2 - 64, 0, player::ReturnSize(), 30, GREEN);


    DrawText(TextFormat("Score: %d", (int)Score), 0, 0, 20, LIGHTGRAY);

}


static void RenderMenu(int width, bool startGame) {
    Load();
    DrawFPS(400, 0);
    DrawText("Lavacube", (width / 2) - 100, 10, 40, WHITE);
    DrawText("Press space to start", width / 2 - 110, 200, 20, WHITE);
    DrawRectangle(500 / 2 - 32, 400, 64, 64, WHITE);
}


static void RenderGameOver(float Score, float highScore) {
    Load();
    DrawRectangle(0, 0, 500, 500, BLACK);
    DrawText("Press space to go to the menu", 500 / 2 - 150, 200, 20, WHITE);
    DrawText(TextFormat("Score: %d", (int)Score), 500 / 2 - 150, 220, 20, WHITE);
    DrawText(TextFormat("HighScore: %d", (int)highScore), 500 / 2 - 150, 240, 20, WHITE);

    if (Score > highScore) 
        DrawText("NEW HIGHSCORE", 40, 270, 50, VIOLET);

}
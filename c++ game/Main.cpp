#include <iostream>
#include "main.h"
#include "raylib.h"
#include "player.h"
#include "Screen.cpp"
#include "Coins.h"
#include "Modes.h"
#include "meteorite.h"
using namespace std;

Coins* coin1 = new Coins();
Coins* coin2 = new Coins();

int main() {
	InitWindow(width, Height, Title);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();

            if (startGame) 
            {
                RenderGame(score, startGame);

                coin1->Spawn(player::PlayerEntitie, GOLD);
                coin2->SpawnS(player::PlayerEntitie, GRAY);

                player::PlayerController();
                if (player::CheckNotDead() == 1) {
                    startGame = false;
                    gameOver = true;
                }

                score += coin1->CheckCollision(player::PlayerEntitie);
                score += coin2->CheckCollisionS(player::PlayerEntitie);

                meteorite::Controller();
                meteorite::CheckCollisionS(player::PlayerEntitie);

                Modes::ModeUpdate();
                player::SetKrimpingSpeed(score);
                score += 100 * deltatime;
                deltatime = (1 * GetFrameTime()) / 100;
            }
            else if (!startGame && gameOver) 
            {
                RenderGameOver(score, highScore);
                if (IsKeyDown(KEY_ENTER)) { 
                    if (score > highScore) highScore = score;
                    gameOver = false; 
                }
            }
            else 
            {
                RenderMenu(width, startGame);
                score = 0;
                player::PlayerEntitie.width = 64;
                player::PlayerEntitie.height = 64;
                if (IsKeyDown(KEY_SPACE))startGame = true;
            }

            ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}


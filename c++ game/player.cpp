#include "player.h"

float speed = 500;
float jump = 1000;
float gravity = 300;

float jumptime;
float jumptimeOrignal = 0.5;

float maxY = 400;
float maxX = 436;

float KrimpingSpeed = 1;
bool krimpSpeedmode = false;


Rectangle player::PlayerEntitie = {
    (500 / 2) - 32,
    400,
    64,
    64,
};

void player::PlayerController()
{
    //Movement Code
    if (IsKeyDown(KEY_LEFT) && PlayerEntitie.x > 0) PlayerEntitie.x -= (speed * GetFrameTime());
    if (IsKeyDown(KEY_RIGHT) && PlayerEntitie.x < maxX) PlayerEntitie.x += (speed  * GetFrameTime());
  
    if (PlayerEntitie.y < maxY)
        PlayerEntitie.y += (gravity * GetFrameTime());
    else {
        if (IsKeyDown(KEY_UP)) jumptime = jumptimeOrignal;
    }
    
    //Gravity / jumping code
    if (jumptime > 0 && IsKeyDown(KEY_UP)) {
        PlayerEntitie.y -= (jump * GetFrameTime());
        jumptime -= GetFrameTime();
    }
    else if (jumptime > 0 && !IsKeyDown(KEY_UP)) {
        jumptime = 0;
    }

    //Krimping Code
    if (PlayerEntitie.height > 0.00001) {
        PlayerEntitie.height -= KrimpingSpeed * GetFrameTime();
        PlayerEntitie.width -= KrimpingSpeed * GetFrameTime();
        maxX += KrimpingSpeed * GetFrameTime();
        maxY += KrimpingSpeed * GetFrameTime();
    }

    //Render player Code
    DrawRectangleRec(PlayerEntitie, WHITE);
}

int player::CheckNotDead()
{
    if (PlayerEntitie.height > 3.2) {
        return 0;
    }
    maxY = 400;
    maxX = 436;
    PlayerEntitie.width = 64;
    PlayerEntitie.height = 64;
    PlayerEntitie.x = (500 / 2) - 32 ;
    PlayerEntitie.y = 400;
    return 1;
}

void player::GrowAndKrimp(int add)
{
    if ((PlayerEntitie.width + add) <= 64) {
        PlayerEntitie.width += add;
        PlayerEntitie.height += add;
        maxY -= add;
        maxX -= add;
    }
    else if (PlayerEntitie.width < 64) {
        PlayerEntitie.width = 64;
        PlayerEntitie.height = 64;
        maxY = 400;
        maxX = 436;
    }
}

int player::ReturnSize() {
    return PlayerEntitie.height * 2;
}

void player::SetJumpSpeed(bool _Original) {
    if (_Original) 
        jumptimeOrignal = 0.5f;
    else 
        jumptimeOrignal = 0.25f;
}

void player::SetKrimpingSpeedModes(bool _modeOn) {
        krimpSpeedmode = _modeOn;
}

void player::SetKrimpingSpeed(int score) {
    if (score < 100) KrimpingSpeed = 1;
    else if (score > 100 && score < 500)  KrimpingSpeed = 1;
    else if (score > 500 && score < 1000)  KrimpingSpeed = 1.5f;
    else if (score > 1000 && score < 2000)  KrimpingSpeed = 2;
    else if (score > 2000 && score < 5000)  KrimpingSpeed = 3;
    else if (score > 5000 && score < 7500)  KrimpingSpeed = 4;
    else if (score > 7500 && score < 12500)  KrimpingSpeed = 6;
    else if (score > 12500 && score < 15000)  KrimpingSpeed = 8;
    else if (score > 1500 && score < 20000)  KrimpingSpeed = 10;
    else if (score > 20000 && score < 30000)  KrimpingSpeed = 12;
    else if (score > 30000 && score < 50000)  KrimpingSpeed = 14;
    else if (score > 50000 && score < 100000)  KrimpingSpeed = 16;
    else if (score > 100000 && score < 150000)  KrimpingSpeed = 18;
    else if (score > 150000 && score < 200000)  KrimpingSpeed = 20;
    else if (score > 200000 && score < 300000)  KrimpingSpeed = 24;
    else if (score > 300000 && score < 500000)  KrimpingSpeed = 28;
    else if (score > 500000 && score < 750000)  KrimpingSpeed = 32;
    else if (score > 750000 && score < 1000000)  KrimpingSpeed = 36;
    else if (score > 1000000 && score < 2000000)  KrimpingSpeed = 40;

    if (krimpSpeedmode) KrimpingSpeed = KrimpingSpeed * 2;
    DrawText(TextFormat("Score: %d", (int)KrimpingSpeed), 500 / 2, 45, 10, LIGHTGRAY);
}

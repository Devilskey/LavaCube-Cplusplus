#include "Modes.h"
#include <raylib.h>
#include <stdlib.h>
#include "player.h"
#include "meteorite.h"

static float timer;
static int mode;
static bool justStarted = false;

void Modes::ModeReset() {
	player::SetJumpSpeed(true);
	player::SetKrimpingSpeedModes(false);
	meteorite::Setmode(false);
	timer = 10;
	justStarted = false;
	mode = 3;
}

void Modes::ModeUpdate() {
	if (!justStarted) {
		timer = 10;
		justStarted = true;
		mode = 3;
		return;
	}

	if (timer < 0) {
		player::SetJumpSpeed(true);
		player::SetKrimpingSpeedModes(false);
		meteorite::Setmode(false);
		mode = (rand() % 2) + 1;
		timer = 10;
	}

	switch (mode) {
		case 0:
			DrawText("2X Gravity", 500 / 2, 35, 10, LIGHTGRAY);
			player::SetJumpSpeed(false);
			break;
		case 1:
			DrawText("Meteorite", 500 / 2, 35, 10, LIGHTGRAY);
			meteorite::Setmode(true);
			break;
		case 2:
			DrawText("2X heat", 500 / 2, 35, 10, LIGHTGRAY);
			player::SetKrimpingSpeedModes(true);
			break;
		case 3:
			DrawText("nothing", 500 / 2, 35, 10, LIGHTGRAY);
			break;
		default:
			break;
	}
	float bar = timer * 12.8;

	DrawRectangle(500 / 2 - 64, 30, bar, 5, PINK);
	timer -= GetFrameTime() / 2;
}
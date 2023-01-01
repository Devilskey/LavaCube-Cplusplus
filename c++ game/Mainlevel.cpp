#include "Mainlevel.h"

Rectangle Mainlevel::ground;

void Mainlevel::Load() {

	DrawRectangleGradientV(0, 0, 500, 500, RED, BLACK);

	ground.x = 0;
	ground.y = 460;
	ground.width = 500;
	ground.height = 40;
	DrawRectangleRec(ground, RED);
}
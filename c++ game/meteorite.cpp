#include "meteorite.h"

static float gravity = 200;
Vector2 Position = {0, 525 };
float radius = 20;

bool mode = false;

void meteorite::Setmode(bool _mode)
{
	mode = _mode;
}


void meteorite::Reset()
{
	mode = false;
	Position.y = 525;

}


void meteorite::Controller()
{
	DrawCircleV(Position, radius, DARKBROWN);

	if (Position.y < 525)
		Position.y += gravity * GetFrameTime();
	else if (mode) {
		Position.x = (rand() % 480 + 20);
		Position.y = -50;
	}
}

void meteorite::CheckCollisionS(Rectangle Player) {
	if (CheckCollisionCircleRec(Position, 10, Player)) {
		Position.y = 525;
		player::GrowAndKrimp(-32);
	}
}

#include "Coins.h"
#include <cstdlib>
#include "player.h"

Color color;

Vector2 posGold = {
	(rand() % 450) + 50,
	(rand() % 300) + 100
};

void Coins::Spawn(Rectangle Player, Color _color) {
	color = _color;
	DrawEllipse(posGold.x, posGold.y, 20, 20, color);
}

int Coins::CheckCollision(Rectangle Player) {
	if (CheckCollisionCircleRec(posGold, 10, Player)) {
		posGold.x = (rand() % 500);
		posGold.y = (rand() % 300) + 100;
		player::GrowAndKrimp(3);
		return 25;
	}
	return 0;
}

Vector2 posSilver = {
	(rand() % 450) + 50,
	(rand() % 300) + 100
};

void Coins::SpawnS(Rectangle Player, Color _color) {
	color = _color;
	DrawEllipse(posSilver.x, posSilver.y, 20, 20, color);
}

int Coins::CheckCollisionS(Rectangle Player) {
	if (CheckCollisionCircleRec(posSilver, 10, Player)) {
		posSilver.x = (rand() % 500);
		posSilver.y = (rand() % 300) + 100;
		player::GrowAndKrimp(1);
		return 10;
	}
	return 0;
}

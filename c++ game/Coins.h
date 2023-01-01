#pragma once
#include <raylib.h>
class Coins
{
public:
	void Spawn(Rectangle Player, Color _color);
	static int CheckCollision(Rectangle Player);
	void SpawnS(Rectangle Player, Color _color);
	int CheckCollisionS(Rectangle Player);
};


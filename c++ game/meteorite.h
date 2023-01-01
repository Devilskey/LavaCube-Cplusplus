#pragma once
#include <raylib.h>
#include <stdlib.h>
#include "player.h"
class meteorite
{
public:
	static void Setmode(bool _mode);
	static void Controller();
	static void CheckCollisionS(Rectangle Player);
};


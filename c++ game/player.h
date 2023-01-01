#pragma once
#include <raylib.h>
#include <iostream>

class player
{
public:
	static Rectangle PlayerEntitie;
	static void PlayerController();
	static int CheckNotDead();
	static void GrowAndKrimp(int add);
	static int ReturnSize();
	static void SetJumpSpeed(bool _Original);
	static void SetKrimpingSpeedModes(bool _modeOn);
	static void SetKrimpingSpeed(int score);
};


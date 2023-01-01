#include "LevelManager.h"
#include <raylib.h>

void LevelManager::RenderLevel(char level[][2])
{
	int posx = 0;
	int posy = 0;

	for (int i = 0; i < 2; i++) {
		if (level[i][0] = 'b') {
			DrawRectangle(posx, posy, 250, 250, BLACK);
		}else {
			DrawRectangle(posx, posy, 250, 250, RED);
		}
		posx += 16;
		if (level[i][1] = 'b') {
			DrawRectangle(posx, posy, 250, 250, BLACK);
		}else {
			DrawRectangle(posx, posy, 250, 250, RED);
		}
		posy += 16;
	   posx = 0;
	}
}

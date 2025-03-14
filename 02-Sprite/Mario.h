#pragma once

#include "MovingObject.h"

#include "Animation.h"
#include "Animations.h"

#define MARIO_WIDTH 14
class CMario : public CMovingObject
{
public:
	CMario(float x, float y, float vx, float vy)
		: CMovingObject(x, y, vx, vy) {}

	void Update(DWORD dt);
	void Render();
};



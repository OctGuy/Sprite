#pragma once
#include "MovingObject.h"
#include "Animation.h"
#include "Animations.h"

class CGoomba : public CMovingObject
{
public:
	CGoomba(float x, float y, float width, float height, float vx, float vy)
		: CMovingObject(x, y, width, height, vx, vy) {}

	void Update(DWORD dt);

	void Render();
};
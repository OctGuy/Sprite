#pragma once

#include "MovingObject.h"
#include "Goomba.h"
#include "debug.h"

#include "Animation.h"
#include "Animations.h"

#define MARIO_WIDTH 14
class CMario : public CMovingObject
{
public:
	CMario(float x, float y, float width, float height, float vx, float vy)
		: CMovingObject(x, y, width, height, vx, vy) {}

	void Update(DWORD dt);
	void Render();

	bool CheckCollision(LPGAMEOBJECT other);

	//Collision handling
	void OnCollision(LPGAMEOBJECT other);
};



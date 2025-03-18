#pragma once

#include "MovingObject.h"
#include "Goomba.h"
#include "debug.h"

#include "Animation.h"
#include "Animations.h"

#define MARIO_WIDTH 14
class CMario : public CMovingObject
{
protected:
	bool direction; //true: right, false: left
	bool isJumping; 
public:
	CMario(float x, float y, float width, float height, float vx, float vy)
		: CMovingObject(x, y, width, height, vx, vy) {
		direction = true; // Right direction for default
		isJumping = false;
	}

	void Update(DWORD dt);
	void Render();

	bool CheckCollision(LPGAMEOBJECT other);

	//Collision handling
	void OnCollision(LPGAMEOBJECT other);
};



#pragma once

#include "GameObject.h"

class CMovingObject : public CGameObject
{
protected:
	float vx;
	float vy;
public:
	CMovingObject(float x, float y, float vx, float vy) :
		CGameObject(x, y), vx(vx), vy(vy) {
	}
};
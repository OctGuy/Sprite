#include "Game.h"
#include "Mario.h"

void CMario::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH) {

		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
		}
	}
}

void CMario::Render()
{
	LPANIMATION ani;

	//[RED FLAG][TODO]: Student needs to think about how to associate this animation/asset to Mario!!
	if (vx > 0) ani = CAnimations::GetInstance()->Get(500);
	else ani = CAnimations::GetInstance()->Get(501);

	ani->Render(x, y);
}

bool CMario::CheckCollision(LPGAMEOBJECT other)
{
	return CGameObject::CheckCollision(other);
}


void CMario::OnCollision(LPGAMEOBJECT other)
{
	DebugOut(L"[INFO] Something hit Mario.\n");
	CGoomba* goomba = dynamic_cast<CGoomba*>(other);

	if (goomba)
	{
		vx = 0;
		vy = 0.2f;
	}
}

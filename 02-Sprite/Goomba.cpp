#include "Goomba.h"
#include "Game.h"

void CGoomba::Update(DWORD dt)
{
	x += vx * dt;

	float Width = CGame::GetInstance()->GetBackBufferWidth();

	if (x < 0 || x > Width)
	{
		vx = -vx;
	}
}

void CGoomba::Render()
{
	LPANIMATION ani;

	ani = CAnimations::GetInstance()->Get(520);

	ani->Render(x, y);
}

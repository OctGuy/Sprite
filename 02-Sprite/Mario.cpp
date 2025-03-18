#include "Game.h"
#include "Mario.h"

#define MARIO_JUMP_SPEED 0.7f
#define MARIO_GRAVITY 0.005f


void CMario::Update(DWORD dt)
{
	/*x += vx * dt;
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
	}*/

	// Get the game instance to access input
	CGame* game = CGame::GetInstance();

	// Handle WASD input for horizontal movement
	if (GetAsyncKeyState('A') & 0x8000) // Move left
	{
		vx = -0.1; 
		direction = false; // set direction to left
	}
	else if (GetAsyncKeyState('D') & 0x8000) // Move right
	{
		vx = 0.1;
		direction = true; // set direction to right
	}
	else
	{
		vx = 0; // Stop moving when no key is pressed
	}

    // Handle space input for jumping
    if (GetAsyncKeyState(VK_SPACE) & 0x8000 && !isJumping)
    {
        vy = -MARIO_JUMP_SPEED; // Jump speed
        isJumping = true;
		y += vy * dt;
    }

	//isJumping = false;
    vy += MARIO_GRAVITY * dt; // Apply gravity to vertical velocity
	y += vy * dt;
    // Update position based on velocity
    x += vx * dt;

	// Handle landing
	if (y >= 130.0)
	{
		y = 130.0;
		vy = 0;
		isJumping = false;
	}

	// Boundary checking with backbuffer width
	int BackBufferWidth = game->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH)
	{
		if (x <= 0)
		{
			x = 0;
			vx = 0; // Stop movement at left boundary
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
			vx = 0; // Stop movement at right boundary
		}
	}
}

void CMario::Render()
{
	LPANIMATION ani;

	// Determine the animation based on Mario's state
	if (isJumping) {
		// Jumping state
		if (direction == true) {
			// Jumping right
			ani = CAnimations::GetInstance()->Get(504); // Replace 504 with the actual animation ID for jumping right
		}
		else {
			// Jumping left
			ani = CAnimations::GetInstance()->Get(505); // Replace 505 with the actual animation ID for jumping left
		}
	}
	else if (vx > 0) {
		// Moving right
		ani = CAnimations::GetInstance()->Get(500); // Replace 500 with the actual animation ID for moving right
	}
	else if (vx < 0) {
		// Moving left
		ani = CAnimations::GetInstance()->Get(501); // Replace 501 with the actual animation ID for moving left
	}
	else {
		// Stationary
		if (direction == true) {
			// Facing right
			ani = CAnimations::GetInstance()->Get(502); // Replace 502 with the actual animation ID for stationary facing right
		}
		else {
			// Facing left
			ani = CAnimations::GetInstance()->Get(503); // Replace 503 with the actual animation ID for stationary facing left
		}
	}

	// Render the determined animation at Mario's current position
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

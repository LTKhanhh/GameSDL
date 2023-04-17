#include "Player.h"
#include<iostream>

void Player::Render(SDL_Renderer* ren)
{
	animationTimer++;
	if (animationTimer < 16)
	{
		SDL_RenderCopyEx(ren, getTexture(), &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer >= 16 && animationTimer <= 32)
	{
		SDL_RenderCopyEx(ren, Tex1, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer > 32)
	{
		SDL_RenderCopyEx(ren, Tex2, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	if (animationTimer > 48)
	{
		animationTimer = 0;
	}
}

void Player::Gravity()
{
	if (JumpState())
	{
		down = down + 0.06;
		jumpHeight = jumpHeight + gravity;
		Ypos = Ypos + gravity  + jumpHeight+down;
		setDest(25, Ypos, 24, 34);
		if (jumpHeight > 0)
		{
			inJump = false;
			jumpHeight = -6;
		}
	}
	else
	{
		down = down + 0.06;
		Ypos = Ypos + gravity + down;
		setDest(25, Ypos, 24, 34);
	}
}

void Player::Jump()
{
	if (jumpTimer - lastJump > 160)  //inJump
	{
		down = 0;
		inJump = true;
		lastJump = jumpTimer;
	}
	else   //not inJump
	{
		Gravity();
	}
}

void Player::GetJumpTime()
{
	jumpTimer = SDL_GetTicks();
}

bool Player::JumpState()
{
	return inJump;
}

void Player::Reset()
{
	Ypos = 256;
	down = 0;
}

void Player::CreateTexture1(const char* address, SDL_Renderer* ren)
{
	Tex1 = TextureManager::Texture(address, ren);
}

void Player::CreateTexture2(const char* address, SDL_Renderer* ren)
{
	Tex2 = TextureManager::Texture(address, ren);
}

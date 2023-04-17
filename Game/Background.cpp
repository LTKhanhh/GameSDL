#include "Background.h"

void Background::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

void Background::GroundRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

void Background::GroundUpdate1()
{
	if (distance1 <= -400)
	{
		distance1 = 400;
	}
	else
	{
		distance1--;
		setSrc(0, 0, 112, 336);
		setDest(distance1, 530, 112, 800);
	}
}

void Background::GroundUpdate2()
{
	if (distance2 <= -400)
	{
		distance2 = 400;
	}
	else
	{
		distance2--;
		setSrc(0, 0, 112, 336);
		setDest(distance2, 530, 112, 800);
	}
}


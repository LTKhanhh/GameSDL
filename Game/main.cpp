#include"GameLoop.h"

GameLoop* g = new GameLoop();

int main(int argc, char** argv)
{
	double first;
	double last = 0;
	
	g->Intialize();

	if (g->RenderMenu() ==0) {
		g->PlayMusic();
		g->Render();
		g->Wait();

		while (g->getGameState())
		{
			
			if (g->getDie() == 0) {
				g->Event();
				g->Update();
				g->Render();
				//limit 60 fps
				first = SDL_GetTicks();
				if (first - last < 16.7)
				{
					SDL_Delay(16.7 - (first - last));
				}
				last = first;
			}
			else
			{
				g->RenderMenuLose();
			}
			if (g->getDie() == 1) {
				Mix_PauseMusic();
			}
			else {
				Mix_ResumeMusic();
			}
		}
		g->Clear();
	}
	else {
		g->Clear();
	}
	
	return 0;
}
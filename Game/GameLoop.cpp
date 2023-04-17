#include"GameLoop.h"
#include<string>
TTF_Font* g_font_text ;
Mix_Music* gMusic = NULL;
Mix_Chunk* gJump = NULL;
Mix_Chunk* gPunch = NULL;
GameLoop::GameLoop()
{
	window = NULL;
	renderer = NULL;
	GameState = false;
	p.setSrc(0, 0, 24, 34);            //set source file image
	p.setDest(25, HEIGHT / 2, 24, 34); //set dest file image 
	ground1.setSrc(0, 0, 112, 336);
	ground1.setDest(0, 530, 112, 800);
	ground2.setSrc(0, 0, 112, 336);
	ground2.setDest(400, 530, 112, 800);
	massage.setSrc(0, 0, 267, 184);
	massage.setDest(WIDTH / 2, HEIGHT / 2, 267, 184);
}

bool GameLoop::getGameState()
{
	return GameState;
}
bool GameLoop::getDie()
{
	return isDie;
}

void GameLoop::Intialize()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			std::cout << "Succeeded!" << std::endl;
			GameState = true;
			p.CreateTexture("Image/yellowbird1.png", renderer);
			p.CreateTexture1("Image/yellowbird2.png", renderer);
			p.CreateTexture2("Image/yellowbird3.png", renderer);
			b.CreateTexture("Image/background.png", renderer);
			ground1.CreateTexture("Image/base.png", renderer);
			ground2.CreateTexture("Image/base.png", renderer);
			massage.CreateTexture("Image/massage1.png", renderer);
			Createcol1("Image/pipe.png", renderer);
			Createcol2("Image/pipe 2.png", renderer);
			
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			}

			//Initialize SDL_ttf
			if (TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
			}
		}
		else
		{
			std::cout << "Not created!" << std::endl;
		}
	}
	else
	{
		std::cout << "window not created!" << std::endl;
	}

	Block C;
	c.push_back(C);
	pt.setColor(Point::WHITE_TEXT);
	pt_menu.setColor(Point::WHITE_TEXT);
	g_font_text = TTF_OpenFont("font/ARCADE.ttf", 48);
	gJump = Mix_LoadWAV("sound/ting.wav");
	gPunch= Mix_LoadWAV("sound/punch.wav");
}

void GameLoop::Event()
{
	p.GetJumpTime();
	SDL_PollEvent(&event1);
	if (event1.type == SDL_QUIT)
	{
		GameState = false;
	}
	const Uint8 *keyboardstate = SDL_GetKeyboardState(NULL);
	if (event1.type == SDL_KEYDOWN)
	{
		if (keyboardstate[SDL_SCANCODE_SPACE]|| keyboardstate[SDL_SCANCODE_UP] )
		{
			
			if (!p.JumpState())
			{
				p.Jump();
			}
			else
			{
				p.Gravity();
			}
		}
		
	}
	else
	{
		p.Gravity();
	}
	
}

void GameLoop::Update()
{	
	//Update column
	if (c.back().Col1.x < WIDTH - Column_Gap)
	{
		Block C;
		c.push_back(C);
	}
	if (c.front().Col1.x < -100)
	{
		c.pop_front();
	}
	int x = c.size();
	for (int i=0; i<x; i++)
	{
		c[i].move();
		
	}
	//update point
	for (int i = 0; i < x; i++)
	{
		if (SDL_HasIntersection(&p.getDest(), &c[i].Col1) == SDL_TRUE || SDL_HasIntersection(&p.getDest(), &c[i].Col2) == SDL_TRUE)
		{
			isDie = true;
			Mix_PlayChannel(-1, gPunch, 0);
		}
		if (p.getDest().y >= ground1.getDest().y || p.getDest().y >= ground2.getDest().y) {
			isDie = true;
			Mix_PlayChannel(-1, gPunch, 0);
		}
		if (c[i].Col1.x == 0) {
			Point++;
			Mix_PlayChannel(-1, gJump, 0);
		}
	}
	ground1.GroundUpdate1();
	ground2.GroundUpdate2();
	std::string count_str = std::to_string(Point);
	pt.SetText(count_str);
	pt.loadFromRenderedText(g_font_text, renderer);
}
void GameLoop::Render()
{
	SDL_RenderClear(renderer);
	b.Render(renderer);            //render background
	ground1.GroundRender(renderer);
	ground2.GroundRender(renderer);
	int x = c.size();
	//render Column
	for(int i=0; i<x; i++)
	{ 
		c[i].RenderCol1(renderer, col1);
		c[i].RenderCol2(renderer, col2);
	}
	//render bird
	p.Render(renderer);
	//render point
	pt.RenderText(renderer, WIDTH * 0.5, 2);
	SDL_RenderPresent(renderer);
}
//wait to play
void GameLoop::Wait()
{
	massage.GroundRender(renderer);
	while (1)
	{
		SDL_PollEvent(&event1);
		if (event1.type == SDL_QUIT)
		{
			GameState = false;
			break;
		}
		else
		{
			if(event1.type == SDL_KEYDOWN)
				if (event1.key.keysym.sym == SDLK_UP || event1.key.keysym.sym == SDLK_SPACE)
				{
					break;
				}
		}
	}
}
int GameLoop::RenderMenu() {
	SDL_RenderClear(renderer);
	int i=mn1.ShowMenu(renderer, g_font_text, "Play Game", "Exit", "Image/background-day.png");
	return i;
}
void GameLoop::RenderMenuLose()
{
	SDL_RenderClear(renderer);
	
	int i = mn1.ShowMenu1(renderer, g_font_text, "Play Again", "Exit","Your Score: "+ std::to_string(Point), "Image/background-day.png");
	if (i == 0)
	{
		PlayAgain();
	}
	else
		if (i == 1)
		{
			GameState = false;
		}
}
void GameLoop::Clear()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
//Create texture column
void GameLoop::Createcol1(const char* address, SDL_Renderer* ren)
{
	col1 = TextureManager::Texture(address, ren);
}
void GameLoop::Createcol2(const char* address, SDL_Renderer* ren)
{
	col2 = TextureManager::Texture(address, ren);
}

void GameLoop::PlayAgain()
{
	isDie = 0;
	c.clear();
	Block C;
	c.push_back(C);
	Point = 0;
	p.setDest(25, HEIGHT / 2, 24, 34);
	p.Ypos = 256;
	Render();
	Wait();
}
	


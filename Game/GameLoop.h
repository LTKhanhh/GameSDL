#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<SDL_ttf.h>
#include"Player.h"
#include"Background.h"
#include"Block.h"
#include"TextureManager.h"
#include"Point.h"
#include"Menu.h"
#include <deque>
#include<SDL_mixer.h>
class GameLoop
{
private:
	Player p;
	Background b;
	Background ground1, ground2;
	Point pt;
	Point pt_menu;             
	Menu mn1;
	std::deque<Block> c;
	const int HEIGHT = 600;
	const int WIDTH = 800;
	const int Column_Gap = 200;
	bool GameState;
	SDL_Window* window;
	SDL_Event event1;
	SDL_Renderer* renderer;
	
public:
	bool isDie=0;
	int Point = 0;
	SDL_Texture* col1;
	SDL_Texture* col2;
	void Createcol1(const char* address, SDL_Renderer* ren);
	void Createcol2(const char* address, SDL_Renderer* ren);
	GameLoop();
	bool getGameState();
	bool getDie();
	void Update();
	void Intialize();
	void Event();
	void Render();
	void Wait();
	void Clear();
	int RenderMenu();
	void RenderMenuLose();
	void PlayAgain();
	void PlayMusic();
};
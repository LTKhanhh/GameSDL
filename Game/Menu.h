#pragma once
#include "Point.h"
#include "Object.h"
#include "Background.h"
#include <windows.h>
#include <vector>
#include <string>
//screen
const int HEIGHT = 600;
const int WIDTH = 800;
class Menu {
public:
	bool Checkmouse(const SDL_Rect& object1, const SDL_Rect& object2);
    int ShowMenu(SDL_Renderer* ren, TTF_Font* font,
        const std::string& menu1,
        const std::string& menu2,
        const std::string& img_name);
    int ShowMenu1(SDL_Renderer* ren, TTF_Font* font,
        const std::string& menu1,
        const std::string& menu2,
        const std::string& menu3,
        const std::string& img_name);
private:

};
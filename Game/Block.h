#pragma once
#include"Object.h"

class Block
{
public:
    //khoi tao
    Block();
    //cot tren man hinh
    SDL_Rect Col1;
    SDL_Rect Col2;
    // Di chuyen cot
    void move();

    //ve cot
    void RenderCol1(SDL_Renderer* ren, SDL_Texture* col);
    void RenderCol2(SDL_Renderer* ren, SDL_Texture* col);

private:

    //Do dai ban dau cua cot
    const int COLUMN_WIDTH = 52;
    const int COLUMN_HEIGHT = 400;

    // Khoang trong de chim bay qua
    const int gapspace = 140;
    int speed = 1;

};

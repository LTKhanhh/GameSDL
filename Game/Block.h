#pragma once
#include"Object.h"

class Block:public Object
{
public:

    //Khoi tao
    //Column();

    //cot tren man hinh
    SDL_Texture* col1;
    SDL_Texture* col2;
    SDL_Rect Col1;
    SDL_Rect Col2;
    // Di chuyen cot
    void move();

    //ve cot
    void Render(SDL_Renderer* ren);
    void Createcol1(const char* address, SDL_Renderer* ren);
    void Createcol2(const char* address, SDL_Renderer* ren);
    void setPos();
private:

    //Do dai ban dau cua cot
    const int COLUMN_WIDTH = 60;
    const int COLUMN_HEIGHT = 600;

    // Khoang trong de chim bay qua
    const int gapspace = 250;

    float speed = 1;

};

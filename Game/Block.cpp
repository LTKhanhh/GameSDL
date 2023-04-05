#include<iostream>
#include"Block.h"

int random(int x, int y)
{
    return rand() % (y - x + 1) + x;
}

void Block::setPos()
{
    srand(time(0));
    int x = random(250, 400);
    int y = random(x, 700);
    
    //Khoi tao cot shita
    Col1.x = 800 - 100;
    Col1.y = random(x, y);
    Col1.w = COLUMN_WIDTH;
    Col1.h = COLUMN_HEIGHT;
    //Khoi tao cot ue
    Col2.x = 800 - 100;
    Col2.y = -gapspace + Col1.y - COLUMN_HEIGHT;
    Col2.w = COLUMN_WIDTH;
    Col2.h = COLUMN_HEIGHT;
}


void Block::move()
{
    Col1.x -= speed;
    Col2.x -= speed;
}

void Block::Render(SDL_Renderer* ren) {
    SDL_RenderCopy(ren, col1, &getSrc(), &Col1);
    SDL_RenderCopy(ren, col2, &getSrc(), &Col1);
}
void Block::Createcol1(const char* address, SDL_Renderer* ren)
{
    col1 = TextureManager::Texture(address, ren);
}
void Block::Createcol2(const char* address, SDL_Renderer* ren)
{
    col2 = TextureManager::Texture(address, ren);
}
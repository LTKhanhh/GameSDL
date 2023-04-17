#include<iostream>
#include"Block.h"

int random(int x, int y)
{
    return rand() % (y - x + 1) + x;
}

Block::Block()
{
    srand(time(0));
    
    int x = random(50, 150);
    int y = random(x, 400);
    
    //Khoi tao cot shita
    Col1.x = 800;
    Col1.h = random(x,y);
    Col1.y = 530-Col1.h;
    Col1.w = COLUMN_WIDTH;
    
    //Khoi tao cot ue
    Col2.x = 800;
    Col2.y = +Col1.y-gapspace-COLUMN_HEIGHT;
    Col2.w = COLUMN_WIDTH;
    Col2.h = COLUMN_HEIGHT;
}


void Block::move()
{
    Col1.x -= speed;
    Col2.x -= speed;
}

void Block::RenderCol1(SDL_Renderer* ren, SDL_Texture* col) {
    SDL_RenderCopy(ren, col, NULL, &Col1);
}

void Block::RenderCol2(SDL_Renderer* ren, SDL_Texture* col) {
    SDL_RenderCopy(ren, col, NULL, &Col2);
}
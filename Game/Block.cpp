#include<iostream>
#include"Block.h"

int random(int x, int y)
{
    return rand() % (y - x + 1) + x;
}

Block::Block()
{
    srand(time(0));
    
    int x = random(200, 300);
    int y = random(x, 450);
    
    //Khoi tao cot shita
    Col1.x = 800;
    Col1.y = random(x,y);
    Col1.w = COLUMN_WIDTH;
    Col1.h = COLUMN_HEIGHT;
    
    //Khoi tao cot ue
    Col2.x = 800;
    Col2.y = Col1.y-gapspace-COLUMN_HEIGHT;
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
#pragma once
#include"Object.h"
#include<iostream>
#include<SDL_ttf.h>

class Point
{
public:
    Point(void);
    bool loadFromRenderedText(TTF_Font* gFont, SDL_Renderer* screen);
    /*void Free();*/
    enum TextColor {
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2,
    };
    void setColor(Uint8 red, Uint8 green, Uint8 blue);
    void setColor(int type);

    void RenderText(SDL_Renderer* screen, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    void SetText(const std::string& text) { str_pt_ = text; }
    std::string GetText() const { return str_pt_; }

private:
    std::string str_pt_;
    SDL_Color text_color_;
    SDL_Texture* texture_;
    int width_;
    int height_;

};
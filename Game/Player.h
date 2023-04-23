#pragma once
#include "Object.h"

class Player :public Object
{
private:
    double gravity = 0.2;
    
    double down = 0;
    bool inJump = false;
    double jumpHeight = -4;
    double jumpTimer;
    double lastJump = 0;
    SDL_Texture* Tex1;
    SDL_Texture* Tex2;
    SDL_Texture* Pause;
    SDL_Texture* Resume;
    int animationTimer;
public:
    void Gravity();
    void GetJumpTime();
    void Jump();
    bool JumpState();
    void CreateTexture1(const char* address, SDL_Renderer* ren);
    void CreateTexture2(const char* address, SDL_Renderer* ren);
    void Render(SDL_Renderer* ren);
    void Reset();
    int Ypos = 300;
    void pause();
    void resume();
    void CreateResume(const char* address, SDL_Renderer* ren);
    void CreatePause(const char* address, SDL_Renderer* ren);
};




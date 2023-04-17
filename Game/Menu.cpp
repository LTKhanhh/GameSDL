#include"Menu.h"

int Menu::ShowMenu(SDL_Renderer* ren, TTF_Font* font,
    const std::string& menu1,
    const std::string& menu2,
    const std::string& img_name)
{
    std::string select1 = menu1.c_str();
    std::string select2 = menu2.c_str();
    char* imagefile = (char*)img_name.c_str();
    int x = 0;
    int y = 0;
    int time;
    const int NoM = 2;     //number of menu
    std::string Menu[NoM];
    Menu[0] = select1;
    Menu[1] = select2;
    SDL_Texture* menu[NoM];
    bool selected[NoM] = { 0, 0 };
    SDL_Color color[2] = { { 255, 255, 255 },{ 255, 0, 0 } };
    Point text_menu[NoM];
    //text of menu1
    text_menu[0].SetText(Menu[0]);
    text_menu[0].setColor(color[0].r, color[0].g, color[0].b);
    text_menu[0].loadFromRenderedText(font, ren);
    //text of menu2
    text_menu[1].SetText(Menu[1]);
    text_menu[1].setColor(color[0].r, color[0].g, color[0].b);
    text_menu[1].loadFromRenderedText(font, ren);
    //set rect of menu
    SDL_Rect pos[NoM];
    pos[0].x = WIDTH * 0.3 - 150;
    pos[0].y = HEIGHT * 0.8 - 40;
    pos[1].x = WIDTH * 0.3 - 150;
    pos[1].y = HEIGHT * 0.8 + 40;

    Background menu_bgr;
    menu_bgr.CreateTexture(imagefile, ren);
    SDL_Event event;
    while (1) {
          time = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                return 1;
            //vị trí con trỏ chuột -> menu chọn đổi màu
            case SDL_MOUSEMOTION:
                x = event.motion.x;
                y = event.motion.y;
                for (int i = 0; i < NoM; ++i)
                {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                        y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        if (!selected[i])
                        {
                            selected[i] = 1;
                            
                            text_menu[i].SetText(Menu[i]);
                            text_menu[i].setColor(color[1].r, color[1].g, color[1].b);
                            text_menu[i].loadFromRenderedText(font, ren);
                        }
                    }
                    else
                    {
                        if (selected[i])
                        {
                            selected[i] = 0;
                            text_menu[i].SetText(Menu[i]);
                            text_menu[i].setColor(color[0].r, color[0].g, color[0].b);
                            text_menu[i].loadFromRenderedText(font, ren);
                        }
                    }
                }
                break;
            //click chuột ->chọn menu 1:exit, 0:play
            case SDL_MOUSEBUTTONDOWN:
                x = event.button.x;
                y = event.button.y;
                for (int i = 0; i < NoM; ++i) {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                        y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        /*text_menu[0].Free();
                        text_menu[1].Free();*/
                            return i;
                    }
                }
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    /*text_menu[0].Free();
                    text_menu[1].Free();*/
                   
                    return 1;
                }
            
            }
        }
        //render menu
        menu_bgr.Render(ren);
        for (int i = 0; i < NoM; ++i)
        {
            text_menu[i].RenderText(ren, pos[i].x, pos[i].y);
            pos[i].w = text_menu[i].getWidth();
            pos[i].h = text_menu[i].getHeight();
        }
        SDL_RenderPresent(ren);
        if (16.7 > (SDL_GetTicks() - time))
            SDL_Delay(16.7 - (SDL_GetTicks() - time));
    }
    return 0;
}
int Menu::ShowMenu1(SDL_Renderer* ren, TTF_Font* font,
    const std::string& menu1,
    const std::string& menu2,
    const std::string& menu3,
    const std::string& img_name)
{
    std::string select1 = menu1.c_str();
    std::string select2 = menu2.c_str();
    std::string select3 = menu3.c_str();
    char* imagefile = (char*)img_name.c_str();
    int x = 0;
    int y = 0;
    int time;
    const int NoM = 3;     //number of menu
    std::string Menu[NoM];
    Menu[0] = select1;
    Menu[1] = select2;
    Menu[2] = select3;
    SDL_Texture* menu[NoM];
    bool selected[NoM] = { 0, 0 };
    SDL_Color color[2] = { { 255, 255, 255 },{ 255, 0, 0 } };
    Point text_menu[NoM];
    //text of menu1
    text_menu[0].SetText(Menu[0]);
    text_menu[0].setColor(color[0].r, color[0].g, color[0].b);
    text_menu[0].loadFromRenderedText(font, ren);
    //text of menu2
    text_menu[1].SetText(Menu[1]);
    text_menu[1].setColor(color[0].r, color[0].g, color[0].b);
    text_menu[1].loadFromRenderedText(font, ren);
    text_menu[2].SetText(Menu[2]);
    text_menu[2].setColor(color[1].r, color[1].g, color[1].b);
    text_menu[2].loadFromRenderedText(font, ren);
    //set rect of menu
    SDL_Rect pos[NoM];
    pos[0].x = WIDTH * 0.3 - 150;
    pos[0].y = HEIGHT * 0.8 - 40;
    pos[1].x = WIDTH * 0.3 - 150;
    pos[1].y = HEIGHT * 0.8 + 40;
    pos[2].x = WIDTH * 0.3 - 150;
    pos[2].y = HEIGHT * 0.8 - 120;
    Background menu_bgr;
    menu_bgr.CreateTexture(imagefile, ren);
    SDL_Event event;
    while (1) {
        time = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                return 1;
                //vị trí con trỏ chuột -> menu chọn đổi màu
            case SDL_MOUSEMOTION:
                x = event.motion.x;
                y = event.motion.y;
                for (int i = 0; i < NoM-1; ++i)
                {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                        y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        if (!selected[i])
                        {
                            selected[i] = 1;

                            text_menu[i].SetText(Menu[i]);
                            text_menu[i].setColor(color[1].r, color[1].g, color[1].b);
                            text_menu[i].loadFromRenderedText(font, ren);
                        }
                    }
                    else
                    {
                        if (selected[i])
                        {
                            selected[i] = 0;
                            text_menu[i].SetText(Menu[i]);
                            text_menu[i].setColor(color[0].r, color[0].g, color[0].b);
                            text_menu[i].loadFromRenderedText(font, ren);
                        }
                    }
                }
                break;
                //click chuột ->chọn menu 1:exit, 0:play
            case SDL_MOUSEBUTTONDOWN:
                x = event.button.x;
                y = event.button.y;
                for (int i = 0; i < NoM-1; ++i) {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                        y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        /*text_menu[0].Free();
                        text_menu[1].Free();*/
                        return i;
                    }
                }
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    /*text_menu[0].Free();
                    text_menu[1].Free();*/

                    return 1;
                }

            }
        }
        //render menu
        menu_bgr.Render(ren);
        for (int i = 0; i < NoM; ++i)
        {
            text_menu[i].RenderText(ren, pos[i].x, pos[i].y);
            pos[i].w = text_menu[i].getWidth();
            pos[i].h = text_menu[i].getHeight();
        }
        SDL_RenderPresent(ren);
        if (16.7 > (SDL_GetTicks() - time))
            SDL_Delay(16.7 - (SDL_GetTicks() - time));
    }
    return 0;
}
//check mouse & menu
//bool Menu::Checkmouse(const SDL_Rect& object1, const SDL_Rect& object2)
//{
//    int left_a = object1.x;
//    int right_a = object1.x + object1.w;
//    int top_a = object1.y;
//    int bottom_a = object1.y + object1.h;
//
//    int left_b = object2.x;
//    int right_b = object2.x + object2.w;
//    int top_b = object2.y;
//    int bottom_b = object2.y + object2.h;
//
//    // Case 1: size object 1 < size object 2
//    if (left_a > left_b && left_a < right_b)
//    {
//        if (top_a > top_b && top_a < bottom_b)
//        {
//            return true;
//        }
//    }
//
//    if (left_a > left_b && left_a < right_b)
//    {
//        if (bottom_a > top_b && bottom_a < bottom_b)
//        {
//            return true;
//        }
//    }
//
//    if (right_a > left_b && right_a < right_b)
//    {
//        if (top_a > top_b && top_a < bottom_b)
//        {
//            return true;
//        }
//    }
//
//    if (right_a > left_b && right_a < right_b)
//    {
//        if (bottom_a > top_b && bottom_a < bottom_b)
//        {
//            return true;
//        }
//    }
//
//    // Case 2: size object 1 < size object 2
//    if (left_b > left_a && left_b < right_a)
//    {
//        if (top_b > top_a && top_b < bottom_a)
//        {
//            return true;
//        }
//    }
//
//    if (left_b > left_a && left_b < right_a)
//    {
//        if (bottom_b > top_a && bottom_b < bottom_a)
//        {
//            return true;
//        }
//    }
//
//    if (right_b > left_a && right_b < right_a)
//    {
//        if (top_b > top_a && top_b < bottom_a)
//        {
//            return true;
//        }
//    }
//
//    if (right_b > left_a && right_b < right_a)
//    {
//        if (bottom_b > top_a && bottom_b < bottom_a)
//        {
//            return true;
//        }
//    }
//
//    // Case 3: size object 1 = size object 2
//    if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
//    {
//        return true;
//    }
//
//    return false;
//}

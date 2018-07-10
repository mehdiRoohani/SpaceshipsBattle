#pragma once
#include "Unit.h"

class Background:public Unit
{
    SDL_Rect spriteClips[1];
public:
    Background();
    Background(Texture* image, Point pos,int id);
    ~Background();
    void Render(SDL_Renderer* gRenderer);
    void setSpriteClips();
};

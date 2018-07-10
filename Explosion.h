#pragma once
#include "Unit.h"
#include <iostream>

class Explosion:public Unit
{
protected:
    int sprite;
    SDL_Rect spriteClips[12];
public:
    Explosion(Texture*,Point pos,int id);
    Explosion();
    ~Explosion();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    bool GetAlive();
    void setSpriteClips();
};

#pragma once

#include"Explosion.h"

class ExplosionH : public Explosion
{
private:
    enum ANIMATION_FRAMES {FLYING_FRAMES = 4};
    SDL_Rect spriteClips[ FLYING_FRAMES ];
    int xtemp  ;
public:
    ExplosionH(LTexture* image, float x, float y, float angle);
    virtual ~ExplosionH();
    virtual void Move(int);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};

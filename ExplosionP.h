#pragma once

#include"Explosion.h"

class ExplosionP : public Explosion
{
private:
    enum ANIMATION_FRAMES {FLYING_FRAMES = 4};
    SDL_Rect spriteClips[ FLYING_FRAMES ];
public:
    ExplosionP(LTexture* image, float x, float y, float angle);
    virtual ~ExplosionP();
    virtual void Move(int);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};

#pragma once
#include"Explosion.h"

class ExplosionE : public Explosion
{
private:
    enum ANIMATION_FRAMES {FLYING_FRAMES = 5};
    SDL_Rect spriteClips[ FLYING_FRAMES ];
public:
    ExplosionE(Texture* image, Point pos, float angle);
    virtual ~ExplosionE();
    virtual void Move(int);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};

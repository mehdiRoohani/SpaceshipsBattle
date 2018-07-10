#pragma once
#include <iostream>
#include "Unit.h"

class Projectile: public Unit
{
protected:
    SDL_Rect spriteClips[3];
    float turretAngle;
public:
    Projectile();
    Projectile(Texture* image, Point pos,float angle,float tAngle,int id);
    ~Projectile();
    virtual void Move();
    void Rotate(int);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};

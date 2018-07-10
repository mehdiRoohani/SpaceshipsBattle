#pragma once
#include <iostream>
#include "Projectile.h"

class LaserProjectile: public Projectile
{
private:

public:
    LaserProjectile();
    LaserProjectile(Texture* image, Point pos, float angle,float tAngle,int id);
    ~LaserProjectile();
    void Render(long int& frame, SDL_Renderer* gRenderer);
};




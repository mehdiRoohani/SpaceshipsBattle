#pragma once
#include <iostream>
#include "Projectile.h"

class BomberProjectile: public Projectile
{
private:

public:
    BomberProjectile();
    BomberProjectile(Texture* image, Point pos,float angle,float tAngle,int id);
    ~BomberProjectile();
    void Render(long int& frame, SDL_Renderer* gRenderer);
};



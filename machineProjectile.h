#pragma once
#include <iostream>
#include "Projectile.h"

class MachineProjectile: public Projectile
{
private:

public:
    MachineProjectile();
    MachineProjectile(Texture* image, Point pos, float angle,float tAngle,int id);
    ~MachineProjectile();
    void Render(long int& frame, SDL_Renderer* gRenderer);
};


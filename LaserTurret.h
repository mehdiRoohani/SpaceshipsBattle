#pragma once
#include <iostream>
#include"Turret.h"

class LaserTurret: public Turret
{
private:

public:
    LaserTurret();
    ~LaserTurret();
    LaserTurret(Texture* image, Point pos,float tAngle,float tpAngle,int id);
    Unit** fire(long int& frame,int id);
    void Render(long int& frame, SDL_Renderer* gRenderer, float tAngle);
};

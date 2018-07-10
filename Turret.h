#pragma once
#include <iostream>
#include "Unit.h"
#include "Projectile.h"
#include "LaserProjectile.h"
#include "BomberProjectile.h"
#include "machineProjectile.h"
#include "Queue.h"

class Turret:public Unit{

protected:
    int type;
    float range;
    float targetHyp;
    float targetBase;
    float targetPerp;
    float targetAngle;
    Point tp;
    float rotationLimit;
    Unit* projectile[1];
    float tankAngle;
    float turretPosAngle; //angle at which turret is placed initially with respect to tank.
    SDL_Rect spriteClips[1];
    SDL_Point pointOfRotation;
public:
    Turret();
    Turret(Texture* image, Point pos,float angle,float tAngle,int id);
    ~Turret();
    bool checkRange(Unit*);
    Unit* switchTarget(Unit*);
    void Rotate(int direction);
    void updatePosition(Point pos);
    bool selectTarget(Unit*);
    virtual Unit** fire(long int& frame,int id);
    float returnRange();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, float tAngle);
};

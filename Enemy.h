#pragma once
#include <iostream>
#include "Unit.h"
#include "Turret.h"
#include "LaserTurret.h"
#include "BomberTurret.h"
#include "machineTurret.h"
#include "Queue.h"
#include "HealthBar.h"

class Enemy : public Unit{

private:
    HealthBar* hBar;
    Turret* turret[8];
    Unit* projectile[8];
    float hypoteneous[9];
    float base[9];
    float height[9];
    float angleVariation[9];
    bool turretPosition[8];
    bool turretFire[8];
    SDL_Rect spriteClips[2];
    bool flag=false;
public:
    Enemy();
    Enemy(Texture* image, Point pos, float ang,int id);
    ~Enemy();
    void loadTurret(int,int);
    void Rotate(int);
    void Move(int);
    void Move();
    void updateHealth(float healthValue);
    bool selectTarget(Unit* enemy);
    Unit** fire(long int& frame,int id);
    void Render(long int& frame, SDL_Renderer* gRenderer);
};


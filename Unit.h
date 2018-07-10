#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Point.h"
#include <math.h>
#include "Texture.h"

using namespace std;


enum MOTION {RIGHT, LEFT, UP, DOWN};

class Unit{

protected:
    int id;
    static const double PI = 3.14159265;
    int wid;
    int hei;
    float speedy;
    float speedx;
    Point position;
    float rotation;
    Unit* Target;
    float health;
    float damageValue;
    Texture* image;
    float angle;
    float friction;
    bool alive=false;
    SDL_Rect collider;
    SDL_Rect spriteClips[2];
    int turretType[8];

public:
    Unit();
    Unit(Texture* image, Point pos,int id);
    ~Unit();
    int getId();
    float getAngle();
    SDL_Rect getRect();
    virtual void Rotate(int);
    virtual void Move(int);
    virtual void Move();
    virtual void updateHealth(float healthValue);
    float getHealth();
    float getDamageValue();
    virtual bool selectTarget(Unit* enemy);
    virtual Unit** fire(long int& frame,int id);
    bool checkCollision(SDL_Rect a, SDL_Rect b);
    void setAlive(bool al);
    bool getAlive();
    void updatePosition(Point pos);
    Point returnPosition();
    int* returnTType();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};








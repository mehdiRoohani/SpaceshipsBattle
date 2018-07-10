#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Point.h"
#include <math.h>
#include "Texture.h"
#include "Unit.h"

using namespace std;

class HealthBar:public Unit{
private:
    Texture* image;
    SDL_Rect spriteClips[2];
    SDL_Point pointOfRotation;
public:
    HealthBar();
    ~HealthBar();
    HealthBar(Texture* image, Point pos,float angle, float healthV);
    void updateHealth(float);
    void Render(long int& frame, SDL_Renderer* gRenderer);
};

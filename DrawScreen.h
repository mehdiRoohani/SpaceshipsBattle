#pragma once
#include "Texture.h"
#include <SDL.h>
#include <stdio.h>
#include "Point.h"
#include <fstream>
#include <iostream>

using namespace std;
class DrawScreen
{
protected:
    Texture* image;
    SDL_Rect spriteClips;
    Point position;
    float width;
    float height;
    FILE* filePointer;                          //Declaring a file pointer

public:
    DrawScreen();
    ~DrawScreen();
    DrawScreen(Texture* image, Point pos);
    bool checkClick(SDL_Rect a, Point p);
//    virtual void SetPosition(Texture* image, int x, int y);
    virtual void Render(SDL_Renderer* gRenderer);
};

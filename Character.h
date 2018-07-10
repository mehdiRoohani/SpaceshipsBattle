#pragma once

#include <iostream>
#include "SDL.h"
#include "string"
#include "Texture.h"
#include "Point.h"

class Character
{
private:
    Point position;
    int letter;
    int capital;
    int startx, starty;
    float charWidth;
    float charHeight;
    char text;
    Texture* image;
    SDL_Rect spriteClips;
public:
    Character();
    ~Character();
    void generateCharacter(Texture* image, Point pos, char text);
    float characterWidth();
    float characterHeight();
    void Render(SDL_Renderer* gRenderer);

};

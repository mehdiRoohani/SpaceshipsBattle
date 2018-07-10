#pragma once
#include "string"
#include "Character.h"
#include "Texture.h"
#include "Point.h"

class Word
{
private:
    Character* charr;
    int noOfLetters;
public:
    Word();
    ~Word();
    Word(Texture* image, Point pos, char* text);
    void Render(SDL_Renderer* gRenderer);
};

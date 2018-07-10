#pragma once
#include "SDL.h"
#include "string"
#include "Word.h"
#include "Texture.h"
#include "Point.h"

class Button
{
protected:
    Point position;
    SDL_Rect buttonRect;
    Button* charr;
    int noOfLetters;
    SDL_Rect ButtonLeft;
    SDL_Rect ButtonCenter;
    SDL_Rect ButtonRight;
    SDL_Rect ButtonBackground;
    Texture gSpriteSheetTexture;
    Texture* middle;
    Texture* left;
    Texture* right;
    Word* buttonWord;
    int width, height, widthshift;
public:
    Button();
    ~Button();
    Button(Texture* image, Point pos, char* text);
    int returnNoOfLetter();
    SDL_Rect returnButtonRect();
    void setButWidth(int nl);
    void Render(SDL_Renderer* gRenderer,int nl);
};

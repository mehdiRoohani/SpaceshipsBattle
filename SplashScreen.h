#pragma once
#include "Word.h"
#include "Button.h"
#include "Texture.h"
#include "DrawScreen.h"
#include "Point.h"
#include <iostream>
#include <SDL.h>


using namespace std;

class SplashScreen : public DrawScreen
{
    int state;
public:
    SplashScreen();
    ~SplashScreen();
    SplashScreen(Texture* image, Point pos);
    void Render(SDL_Renderer* gRenderer);

};


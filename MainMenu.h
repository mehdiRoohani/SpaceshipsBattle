#pragma once
#include "Word.h"
#include "Button.h"
#include "Texture.h"
#include "DrawScreen.h"

using namespace std;

class MainMenu : public DrawScreen
{
    Button* NG;
    Button* LG;
    Button* Qut;
    int maxNoOfL;
    int isFile;

public:
    MainMenu();
    MainMenu(Texture* image,Texture* image1, Point pos);
    ~MainMenu();
    int Event(SDL_Event e,const Uint8* currentKeyStates,bool*,int* state,bool*);
    void Render(SDL_Renderer* gRenderer);
    int Play (Texture* image, SDL_Renderer* gRenderer,int state);
};

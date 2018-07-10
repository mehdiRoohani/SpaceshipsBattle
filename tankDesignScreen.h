#include <stdlib.h>
#include <time.h>
#include "Tank.h"
#include "Backgound.h"
#include "Word.h"
#include "Button.h"
#include "DrawScreen.h"


using namespace std;

class tankDesignScreen : public DrawScreen
{
protected:
    Background* display;        //BACKDROP OBJECT
    Tank* tank;                 //PLAYER TANK
    Turret* turret[3];          //TURRETS
    float hypoteneous[8];
    float base[8];
    float height[8];
//    Word* word;
    long int frame;             //ANIMATION FRAME
    SDL_Rect buttonRect[8];
    SDL_Rect turretRect[3];
    bool choseTurret;
    int typeTa;
    int tankType[8];

public:
    tankDesignScreen();
    tankDesignScreen(Texture* gameImage,Texture* gameSprite,Texture* fontImage, Point pos);
    ~tankDesignScreen();
    void Render(SDL_Renderer* gRenderer);
    int* Event(SDL_Event e,const Uint8* currentKeyStates,bool* mouseClicked,int* state);
    void Play();
};


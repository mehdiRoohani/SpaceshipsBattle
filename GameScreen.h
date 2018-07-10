#include <stdlib.h>
#include <time.h>
#include "Tank.h"
#include "Enemy.h"
#include "Backgound.h"
#include "Queue.h"
#include "Word.h"
#include "Button.h"
#include "DrawScreen.h"


using namespace std;

class GameScreen : public DrawScreen
{
protected:

    long int frame;             //ANIMATION FRAME
    long int bulletInterval;    //BULLETS INTERVAL

    int random;
    Queue q;                    //QUEUE

    Background* display;        //BACKDROP OBJECT
    Tank* tank;                 //PLAYER TANK
    Enemy** enemyTank;               //ENEMY TANK
    int* type;
    Button* saveButton;
    ofstream myfile;
    int noOfLines;
    char buff[13][32];                           //Declaring a character array to store a line

public:
    GameScreen();
    GameScreen(Texture* gameImage,Texture* fontImg, Point pos,int*,int );
    ~GameScreen();
    void Render(SDL_Renderer* gRenderer);
    void Event(SDL_Event e,const Uint8* currentKeyStates,bool* mouseClicked,int* state);
    void Play(int* state, int* isFile);
    void saveGame();
    int LineCounter();
    //int Play (Texture* image3,int* state, SDL_Renderer* gRenderer);  //image3 is basically wo wali image jis se fariha shozab ne sprites liye hain ball e.t.c

};


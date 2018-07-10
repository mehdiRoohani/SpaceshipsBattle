#include "tankDesignScreen.h"

tankDesignScreen::tankDesignScreen()
{
//    welcome = new Word(fontImage,(this->position.shift(113,-50)), "a");
//    NG=NULL;
}
tankDesignScreen::~tankDesignScreen()
{

}
tankDesignScreen::tankDesignScreen(Texture* gameImage,Texture* gameSprite,Texture* fontImage,  Point pos):DrawScreen(image,pos)
{

    choseTurret=false;

    typeTa=5;
    position = pos;

    frame = 0;             //ANIMATION FRAME

    display = new Background(gameImage,position,0);                     //BACKDROP OBJECT
    tank = new Tank(gameSprite, position.shift(-154,0),0.0,1,false);    //PLAYER TANK

    turret[0] = new LaserTurret(gameSprite, this->position.shift(-25,-50),0.0,0.0,2);
    turret[1] = new MachineTurret(gameSprite, this->position.shift(-25,0),0.0,0.0,2);
    turret[2] = new BomberTurret(gameSprite, this->position.shift(-25,+50),0.0,0.0,2);

//    as = new Button(fontImage,(this->position.shift(113,-50)), "my test");
//    as->setButWidth(9);

    //NG->setButWidth(10);
//    word[2] = new Word(fontImage,pos.shift(113,+50), "BOMBER TURRET");

    /*DEFINE INITIAL POSITIONS*/
    base[0]=31.0;height[0]=3;
    base[1]=31.0;height[1]=3;
    base[2]=31.0;height[2]=25.0;
    base[3]=31.0;height[3]=25.0;
    base[4]=31.0;height[4]=43.0;
    base[5]=31.0;height[5]=43.0;
    base[6]=31.0;height[6]=87.0;
    base[7]=31.0;height[7]=87.0;
    base[8]=0.0;height[8]=120.0;

    for(int i=0; i<8; i++){
        if(i==0 || i==2 || i==4 || i==6){
            buttonRect[i].x = (tank->returnPosition().shift(-base[i],height[i])).x-8;
            buttonRect[i].y = (tank->returnPosition().shift(-base[i],height[i])).y-8;
        }
        else{
            buttonRect[i].x = (tank->returnPosition().shift(base[i],height[i])).x-8;
            buttonRect[i].y = (tank->returnPosition().shift(base[i],height[i])).y-8;
        }
        buttonRect[i].w = 16;
        buttonRect[i].h = 16;
        tankType[i]=5;
    }
    for(int i=0; i<3; i++){
        turretRect[i].x = (turret[i]->returnPosition().x)-10;
        turretRect[i].y = (turret[i]->returnPosition().y)-10;
        turretRect[i].w = 220;
        turretRect[i].h = 20;
    }

}
int* tankDesignScreen::Event(SDL_Event e,const Uint8* currentKeyStates,bool* mouseClicked,int* state)
{
    if( e.type == SDL_MOUSEBUTTONDOWN && *mouseClicked == false)
    {
        Point p;
        int x,y;
        SDL_GetMouseState( &x, &y );
        p.x=x;
        p.y=y;

        if (e.button.button == SDL_BUTTON_LEFT){

            *mouseClicked = true;
            for(int i=0; i<3; i++){
                if(choseTurret==false && checkClick(turretRect[i],p)){
                    typeTa=i;
                    choseTurret=true;
                }
            }
            for(int i=0; i<8; i++){
                if(choseTurret==true && checkClick(buttonRect[i],p))
                {
                    tankType[i]=typeTa;
                    choseTurret=false;
                    tank->loadTurret(i,typeTa);
                }
            }
        }
    }
    if( e.type == SDL_MOUSEBUTTONUP && *mouseClicked == true)
    {
        *mouseClicked=false;
    }
    if(currentKeyStates[ SDL_SCANCODE_SPACE ])
    {
        *state = 3;

    }
//
    return tankType;
}

void tankDesignScreen::Play(){

}

void tankDesignScreen::Render(SDL_Renderer* gRenderer)
{
    display->Render(gRenderer);         // RENDER BACKGROUND.
    tank->Render(frame,gRenderer);      // RENDER TANK.
//    word->Render(gRenderer);
//    as->Render(gRenderer,9);
    for(int i=0; i<3; i++){
        turret[i]->Render(frame, gRenderer,0.0);
    }
}


#include "ExplosionP.h"
#include "cmath"
#include "math.h"



ExplosionP::~ExplosionP()
{
    cout<<"ExplosionP Deallocated"<<endl;
    delete ObjRectangle;
    ObjRectangle = NULL;
}

ExplosionP::ExplosionP(LTexture* image, float x, float y, float angle):Explosion(image, x, y, angle)
{
    ObjRectangle = new SDL_Rect;
    Type = "ExplosionP";
    health = -1;
    spriteSheetTexture = image;
    rotation = angle;

    spriteClips[ 0 ].x = 209;
    spriteClips[ 0 ].y = 47;
    spriteClips[ 0 ].w = 30;
    spriteClips[ 0 ].h = 31;

    spriteClips[ 1 ].x = 248;
    spriteClips[ 1 ].y = 47;
    spriteClips[ 1 ].w = 30;
    spriteClips[ 1 ].h = 31;

    spriteClips[ 2 ].x = 289;
    spriteClips[ 2 ].y = 47;
    spriteClips[ 2 ].w = 30;
    spriteClips[ 2 ].h = 31;

    spriteClips[ 3 ].x = 328;
    spriteClips[ 3 ].y = 47;
    spriteClips[ 3 ].w = 30;
    spriteClips[ 3 ].h = 31;


    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    alive  = true;
    rotation = 0.0;

    ObjRectangle->x = x;
    ObjRectangle->y = y;
    ObjRectangle->h = height;
    ObjRectangle->w = width;



    //rotation = 360
    //speed


}

void ExplosionP::Move(int SCREEN_HEIGHT)
{


}

void ExplosionP::Render(long int& frame, SDL_Renderer* gRenderer)
{
    ObjRectangle->x = x;
    ObjRectangle->y = y;

    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame/10 % 4 ], rotation, NULL, SDL_FLIP_NONE, gRenderer );
    if (frame/10 % 4 == 3 )
    {
        SetAlive(false);
    }
}

#include "ExplosionH.h"
#include "cmath"
#include "math.h"



ExplosionH::~ExplosionH()
{
    cout<<"ExplosionH Deallocated"<<endl;
    delete ObjRectangle;
    ObjRectangle = NULL;
}

ExplosionH::ExplosionH(LTexture* image, float x, float y, float angle):Explosion(image, x, y, angle)
{
        ObjRectangle = new SDL_Rect;
        Type = "ExplosionH";
    health = -1;
    spriteSheetTexture = image;
    rotation = angle;

    spriteClips[ 0 ].x = 224.0;  //224 -> 209
    spriteClips[ 0 ].y = 102.0;
    spriteClips[ 0 ].w = 15.0;   //15 ->45
    spriteClips[ 0 ].h = 1.0;

    spriteClips[ 1 ].x = 280.0;
    spriteClips[ 1 ].y = 102.0;
    spriteClips[ 1 ].w = 15.0;
    spriteClips[ 1 ].h = 1.0;

    spriteClips[ 2 ].x = 336.0;
    spriteClips[ 2 ].y = 102.0;
    spriteClips[ 2 ].w = 15.0;
    spriteClips[ 2 ].h = 1.0;


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

void ExplosionH::Move(int SCREEN_HEIGHT)
{


}

void ExplosionH::Render(long int& frame, SDL_Renderer* gRenderer)
{
    ObjRectangle->x = x;
    ObjRectangle->y = y;


    if (ObjTime < 80)
    {
        xtemp = x - (ObjTime/2);
    }

    spriteSheetTexture->Render( xtemp , y , &spriteClips[ frame/10 % 3 ], rotation, NULL, SDL_FLIP_NONE, gRenderer );
    if (ObjTime < 80)
    {

        spriteClips[0].h += 1.0;
        spriteClips[1].h += 1.0;
        spriteClips[2].h += 1.0;
        if (ObjTime%2 == 0)
        {
            spriteClips[0].w += 1.0;
            spriteClips[1].w += 1.0;
            spriteClips[2].w += 1.0;
        }
        if (ObjTime%5 == 0)
        {
            spriteClips[0].x -= 1.0;
            spriteClips[1].x -= 1.0;
            spriteClips[2].x -= 1.0;

        }


    }
    else if (ObjTime>=161 && ObjTime <250)
    {
        spriteClips[0].h -= 1.0;
        spriteClips[1].h -= 1.0;
        spriteClips[2].h -= 1.0;
        if (ObjTime%3 == 0)
        {
            spriteClips[0].w -= 1.0;
            spriteClips[1].w -= 1.0;
            spriteClips[2].w -= 1.0;

        }
        if (ObjTime%5 == 0)
        {
            spriteClips[0].x += 1.0;
            spriteClips[1].x += 1.0;
            spriteClips[2].x += 1.0;

        }
    }
    else if (ObjTime == 250)
    {
        SetAlive(false);
    }
        ObjTime++;






//    if (frame/10 % 3 == 2 )
//    {
//        SetAlive(false);
//    }
}

#include "Explosion.h"

Explosion::Explosion()
{

}
Explosion::~Explosion()
{
    image = NULL;
    cout<<"d";
}

Explosion::Explosion(Texture* image, Point pos,int id):Unit(image, pos,id)
{
    setSpriteClips();

    this->wid = spriteClips[ 0 ].w;
    this->hei = spriteClips[ 0 ].h;

    sprite=0;
}

void Explosion::setSpriteClips(){

    spriteClips[ 0 ].y = spriteClips[ 1 ].y = spriteClips[ 2 ].y = spriteClips[ 3 ].y = 600;
    spriteClips[ 4 ].y = spriteClips[ 5 ].y = spriteClips[ 6 ].y = spriteClips[ 7 ].y = 670;
    spriteClips[ 8 ].y = spriteClips[ 9 ].y = spriteClips[ 10 ].y = spriteClips[ 11 ].y = 670+70;
    spriteClips[ 8 ].x = spriteClips[ 4 ].x = spriteClips[ 0 ].x = 249;
    spriteClips[ 9 ].x = spriteClips[ 5 ].x = spriteClips[ 1 ].x = 249+58;
    spriteClips[ 10 ].x = spriteClips[ 6 ].x = spriteClips[ 2 ].x = 249+58+58;
    spriteClips[ 11 ].x = spriteClips[ 7 ].x = spriteClips[ 3 ].x = 249+58+(58*2);

    spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = spriteClips[ 3 ].w = spriteClips[ 4 ].w = spriteClips[ 5 ].w = spriteClips[ 6 ].w = spriteClips[ 7 ].w = spriteClips[ 8 ].w = spriteClips[ 9 ].w = spriteClips[ 10 ].w = spriteClips[ 11 ].w = 58 ;
    spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = spriteClips[ 3 ].h = spriteClips[ 4 ].h = spriteClips[ 5 ].h = spriteClips[ 6 ].h = spriteClips[ 7 ].h = spriteClips[ 8 ].h = spriteClips[ 9 ].h = spriteClips[ 10 ].h = spriteClips[ 11 ].h = 70;
}

void Explosion::Render(long int& frame, SDL_Renderer* gRenderer)
{
    image->Render( position.x -wid/2, position.y-hei/2 , &spriteClips[ sprite ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

    sprite++;
    if (sprite >= 12)
    {
        alive =false;
    }
}




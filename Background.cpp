#include "Backgound.h"

Background::Background()
{

}

Background::Background(Texture* image, Point pos,int id):Unit(image, pos,id)
{
    setSpriteClips();
}
Background::~Background()
{

}


void Background::setSpriteClips(){

    spriteClips[ 0 ].x = 0;                 //coordinates calculated through the select option in paint.
    spriteClips[ 0 ].y = 0;                  //y coordinate and width,height remains same. x changes.
    spriteClips[ 0 ].w = 800;
    spriteClips[ 0 ].h = 600;

}

void Background::Render(SDL_Renderer* gRenderer)
{
    image->Render( spriteClips[ 0 ].x, spriteClips[ 0 ].y, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

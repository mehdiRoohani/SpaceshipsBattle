#include "DrawScreen.h"
#include "Texture.h"

DrawScreen::DrawScreen()
{
}

DrawScreen::DrawScreen(Texture* image, Point pos)
{
    this->image = image;

    spriteClips.x =   0;
    spriteClips.y =   0;
    spriteClips.w = 800;
    spriteClips.h = 600;

    position.x=pos.x;
    position.y=pos.y;

    width=spriteClips.w;
    height=spriteClips.h;
}
DrawScreen::~DrawScreen()
{
    image = NULL;
}
//void DrawScreen::SetPosition(Texture* image, int x, int y)
//{
//    gSpriteSheetTexture = image;
//
//    spriteClips.x =   0;
//    spriteClips.y =   0;
//    spriteClips.w = 800;
//    spriteClips.h = 600;
//
//    position.x=x;
//    position.y=y;
//}

bool DrawScreen::checkClick(SDL_Rect a,Point p){

    /*BOUNDARIES OF THE BUTTON*/
    int left;
    int right;
    int top;
    int bottom;

    /*CALCULATE THE SIZE OF RECTANGEL*/
    left = a.x;
    right = a.x + a.w;
    top = a.y;
    bottom = a.y + a.h;

    if(p.x>left && p.x<right && p.y>top && p.y<bottom){
        return true;
    }
    else{
        return false;
    }
}
void DrawScreen::Render(SDL_Renderer* gRenderer)
{
    image->Render( position.x, position.y, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

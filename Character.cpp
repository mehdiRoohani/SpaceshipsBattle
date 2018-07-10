#include "Character.h"
#include <iostream>

using namespace std;

Character::Character()
{
    charWidth=20;
    charHeight=30;
    letter=0;
}

void Character::generateCharacter(Texture* image, Point pos, char text)
{
    capital = toupper(text);
    letter = int(capital)-65;
    this->image = image;

    if(letter>=0 && letter <12)
    {
        spriteClips.x =   charWidth*letter;
        spriteClips.y =   0;
        spriteClips.w = charWidth;
        spriteClips.h = charHeight;
    }
    if(letter>=12 && letter <24)
    {
        spriteClips.x =   charWidth*(letter-12);
        spriteClips.y =   charHeight;
        spriteClips.w = charWidth;
        spriteClips.h = charHeight;
    }
    if(letter>=24 && letter <=36)
    {
        spriteClips.x = charWidth*(letter-24);
        spriteClips.y =   96;
        spriteClips.w = charWidth;
        spriteClips.h = charHeight;
    }
//    if(letter>=-17 && letter<=-15)    // first line of numbers
//    {
//        letter = letter +17;
//        spriteClips.x = charWidth*(letter) +(charWidth*8);
//        spriteClips.y =   charHeight*4;
//        spriteClips.w = charWidth;
//        spriteClips.h = charHeight;
//    }
//    if(letter>=-15 && letter<=-8)    // second line of numbers
//    {
//        letter = letter +17;
//        spriteClips.x = charWidth*(letter-3);
//        spriteClips.y =   charHeight*5;
//        spriteClips.w = charWidth;
//        spriteClips.h = charHeight;
//    }

    position.x=pos.x;
    position.y=pos.y;

}


Character::~Character()
{
    image = NULL;
}

float Character::characterWidth(){
    return charWidth;
}

float Character::characterHeight(){
    return charHeight;
}

void Character::Render(SDL_Renderer* gRenderer)
{
    image->Render( position.x-charWidth/2, position.y-charHeight/2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}




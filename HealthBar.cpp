#pragma once
#include "HealthBar.h"


HealthBar::HealthBar(Texture* image, Point pos,float angle, float healthV):Unit(image,pos,0){

    this->image = image;
    position=pos;
    this->health=healthV;

    //Frame 0
    spriteClips[ 0 ].x = 172;
    spriteClips[ 0 ].y = 600;
    spriteClips[ 0 ].w = 77;
    spriteClips[ 0 ].h = 6;

    //Frame 1
    spriteClips[ 1 ].x = 172;
    spriteClips[ 1 ].y = 606;
    spriteClips[ 1 ].w = 77;
    spriteClips[ 1 ].h = 6;
}

void HealthBar::updateHealth(float healthValue){
    if(health>=healthValue)
        health-=0.001;
    spriteClips[ 1 ].w = (spriteClips[ 0 ].w)*health;
}

void HealthBar::Render(long int& frame, SDL_Renderer* gRenderer){

    pointOfRotation.x=(spriteClips[0].w)/2;
    pointOfRotation.y=(spriteClips[0].h)/2;

    image->Render(position.x-(spriteClips[0].w)/2, position.y-(spriteClips[0].h)/2, &spriteClips[0], angle, NULL, SDL_FLIP_NONE, gRenderer );
    image->Render(position.x-(spriteClips[0].w)/2, position.y-(spriteClips[0].h)/2, &spriteClips[1], angle, &pointOfRotation, SDL_FLIP_NONE, gRenderer );
}

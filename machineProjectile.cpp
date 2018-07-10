#pragma once
#include "machineProjectile.h"


MachineProjectile::MachineProjectile(){

}

MachineProjectile::~MachineProjectile(){

}

MachineProjectile::MachineProjectile(Texture* image, Point pos, float angle,float tAngle,int id):Projectile(image,pos,angle,tAngle,id){

    //Frame 0
    spriteClips[ 0 ].x = 130;
    spriteClips[ 0 ].y = 641;
    spriteClips[ 0 ].w = 14;
    spriteClips[ 0 ].h = 10;

    //Frame 1
    spriteClips[ 1 ].x = 144;
    spriteClips[ 1 ].y = 641;
    spriteClips[ 1 ].w = 14;
    spriteClips[ 1 ].h = 10;

    //Frame 2
    spriteClips[ 2 ].x = 158;
    spriteClips[ 2 ].y = 641;
    spriteClips[ 2 ].w = 14;
    spriteClips[ 2 ].h = 10;

    speedy = 5;

    damageValue=0.005;

    this->wid = spriteClips[ 0 ].w;
    this->hei = spriteClips[ 0 ].h;

    collider.x=position.x-wid/2;
    collider.y=position.y-hei/2;
    collider.w=this->wid;
    collider.h=this->hei;
}

void MachineProjectile::Render(long int& frame, SDL_Renderer* gRenderer){
    image->Render(position.x-(spriteClips[0].w)/2, position.y-(spriteClips[0].h)/2, &spriteClips[frame%3], angle, NULL, SDL_FLIP_NONE, gRenderer );
}


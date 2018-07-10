#pragma once
#include "LaserProjectile.h"


LaserProjectile::LaserProjectile(){

}

LaserProjectile::~LaserProjectile(){

}

LaserProjectile::LaserProjectile(Texture* image, Point pos, float angle,float tAngle,int id):Projectile(image,pos,angle,tAngle,id){

    //Frame 0
    spriteClips[ 0 ].x = 130;
    spriteClips[ 0 ].y = 600;
    spriteClips[ 0 ].w = 14;
    spriteClips[ 0 ].h = 10;

    speedy = 2.5;

    damageValue=0.01;

    this->wid = spriteClips[ 0 ].w;
    this->hei = spriteClips[ 0 ].h;

    collider.x=position.x-wid/2;
    collider.y=position.y-hei/2;
    collider.w=this->wid;
    collider.h=this->hei;
}

void LaserProjectile::Render(long int& frame, SDL_Renderer* gRenderer){
    image->Render(position.x-(spriteClips[0].w)/2, position.y-(spriteClips[0].h)/2, &spriteClips[0], angle, NULL, SDL_FLIP_NONE, gRenderer );
}




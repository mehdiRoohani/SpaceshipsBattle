#pragma once
#include "BomberProjectile.h"


BomberProjectile::BomberProjectile(){

}

BomberProjectile::~BomberProjectile(){

}

BomberProjectile::BomberProjectile(Texture* image, Point pos, float angle,float tAngle,int id):Projectile(image,pos,angle,tAngle,id){

    //Frame 0
    spriteClips[ 0 ].x = 130;
    spriteClips[ 0 ].y = 666;
    spriteClips[ 0 ].w = 23;
    spriteClips[ 0 ].h = 10;

    speedy = 1;

    damageValue=0.025;

    this->wid = spriteClips[ 0 ].w;
    this->hei = spriteClips[ 0 ].h;

    collider.x=position.x-wid/2;
    collider.y=position.y-hei/2;
    collider.w=this->wid;
    collider.h=this->hei;
}

void BomberProjectile::Render(long int& frame, SDL_Renderer* gRenderer){
    image->Render(position.x-(spriteClips[0].w)/2, position.y-(spriteClips[0].h)/2, &spriteClips[0], angle, NULL, SDL_FLIP_NONE, gRenderer );
}



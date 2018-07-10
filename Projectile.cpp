#pragma once
#include "Projectile.h"



Projectile::Projectile(Texture* image, Point pos, float angle,float tAngle,int id):Unit(image,pos,id){

    this->angle=angle;
    turretAngle=tAngle;

}

Projectile::Projectile(){

}

Projectile::~Projectile(){
}

void Projectile::Move(){
    position.y = position.y + ((cos(turretAngle*(PI/180)))*(speedy));
    position.x = position.x + ((sin(turretAngle*(PI/180)))*(-speedy));

    collider.x=position.x-wid/2;
    collider.y=position.y-hei/2;

}

void Projectile::Rotate(int direction){

}

void Projectile::Render(long int& frame, SDL_Renderer* gRenderer){
    image->Render(position.x-(spriteClips[0].w)/2, position.y-(spriteClips[0].h)/2, &spriteClips[frame%3], angle, NULL, SDL_FLIP_NONE, gRenderer );
}

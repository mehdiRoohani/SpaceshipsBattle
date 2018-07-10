#pragma once
#include"machineTurret.h"

MachineTurret::MachineTurret(Texture* image, Point pos,float tAngle,float tpAngle,int id):Turret(image,pos,tAngle,tpAngle,id)
{
    //Frame 0
    spriteClips[ 0 ].x =   100;
    spriteClips[ 0 ].y =   641;
    spriteClips[ 0 ].w = 30;
    spriteClips[ 0 ].h = 25;

    range=500.0;
    rotationLimit=360.0;
    type=2;

    collider.x=position.x-wid/2;
    collider.y=position.y-hei/2;
    collider.w=this->wid;
    collider.h=this->hei;

    pointOfRotation.x=(spriteClips[0].w)/2;
    pointOfRotation.y=(spriteClips[0].h)/2+3;
}

Unit** MachineTurret::fire(long int& frame,int id){
    if(frame%100==0){
        projectile[0] = new MachineProjectile(this->image,this->position,this->angle-90,this->angle+180,id);
        return projectile;
    }
    else{
        projectile[0] = NULL;
        return projectile;
    }
}

void MachineTurret::Render(long int& frame, SDL_Renderer* gRenderer, float tAngle){
    image->Render(position.x-(spriteClips[0].w)/2, position.y-(spriteClips[0].h)/2-6, &spriteClips[0], angle, &pointOfRotation, SDL_FLIP_NONE, gRenderer );
}


#pragma once
#include "Turret.h"



Turret::Turret(Texture* image, Point pos, float angle,float tAngle,int id):Unit(image,pos,id){


    this->angle=angle;
    turretPosAngle=angle;
    tankAngle=tAngle;

    this->wid = spriteClips[ 0 ].w;
    this->hei = spriteClips[ 0 ].h;

    range=800.0;

    pointOfRotation.x=0;
    pointOfRotation.y=0;
    Target=NULL;

}

Turret::Turret(){

}

Turret::~Turret(){

}

bool Turret::checkRange(Unit* enemy){

    float tempBase=enemy->returnPosition().x-position.x;
    float tempPerp=enemy->returnPosition().y-position.y;
    float tempHyp=sqrt(float(pow(tempBase,2.0)+pow(tempPerp,2.0)));

    if(tempHyp<=range)
        return true;
    else
        return false;
}

Unit* Turret::switchTarget(Unit* enemy){
    Point p=enemy->returnPosition();
    if(Target==NULL){
        Target=enemy;
        targetBase=Target->returnPosition().x-position.x;
        targetPerp=Target->returnPosition().y-position.y;
        targetHyp=sqrt(float(pow(targetBase,2.0)+pow(targetBase,2.0)));
    }
    else{

        /*CALCULATE THE CURRENT DISTANCE WITH TARGET*/
        targetBase=Target->returnPosition().x-position.x;
        targetPerp=Target->returnPosition().y-position.y;
        targetHyp=sqrt(float(pow(targetBase,2.0)+pow(targetBase,2.0)));

        /*CALCULATE THE CURRENT DISTANCE WITH GIVEN SPACESHIP*/
        float tempBase=p.x-position.x;
        float tempPerp=p.y-position.y;
        float tempHyp=sqrt(float(pow(tempBase,2.0)+pow(tempPerp,2.0)));
//        cout<<tempHyp<<endl;

        /*COMPARE THEM*/
        if(tempBase*tempBase<targetBase*targetBase){
            Target=enemy;
            targetBase=tempBase;
            targetPerp=tempPerp;
            targetHyp=tempHyp;
        }
    }
    return Target;
}
void Turret::Rotate(int direction){
    if(direction==LEFT)
    {
        speedx=(-2.0);
    }
    if(direction==RIGHT)
    {
        speedx=2.0;
    }
    angle+=speedx;
    tankAngle+=speedx;
    turretPosAngle+=speedx;
}

void Turret::updatePosition(Point pos){
    this->position=pos;
}

bool Turret::selectTarget(Unit* enemy){

    if(checkRange(enemy)){

        Target=switchTarget(enemy);
        targetAngle=((atan(-targetPerp/targetBase))*(180/PI));

        if((enemy->returnPosition().x)>=position.x){
            if(angle < 90-targetAngle)
            {
                angle++;
            }
            else if(angle > 90-targetAngle)
            {
                angle--;
            }
            if(angle < 90-targetAngle+1 && angle > 90-targetAngle-1){
                return true;
            }
            else{
                return false;
            }
        }
        else if((enemy->returnPosition().x)<position.x){
            if(angle < 270-targetAngle)
            {
                angle++;
            }
            else if(angle > 270-targetAngle)
            {
                angle--;
            }
            if(angle < 270-targetAngle+1 && angle > 270-targetAngle-1){
                return true;
            }
            else{
                return false;
            }

        }
    }
    else{
        return false;
    }
}

Unit** Turret::fire(long int& frame,int id){
    return projectile;
}

void Turret::Render(long int& frame, SDL_Renderer* gRenderer, float tAngle){
    image->Render(position.x-(spriteClips[0].w)/2, position.y-(spriteClips[0].h)/2-3, &spriteClips[0], angle, &pointOfRotation, SDL_FLIP_NONE, gRenderer );
}


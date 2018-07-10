#pragma once
#include <iostream>
#include "Unit.h"
#include "Tank.h"



Tank::Tank(Texture* image, Point pos, float ang,int id,bool hB):Unit(image,pos,id){

    //Frame 0
    spriteClips[ 0 ].x = 0;
    spriteClips[ 0 ].y = 600;
    spriteClips[ 0 ].w = 100;
    spriteClips[ 0 ].h = 219;


    this->wid = spriteClips[ 0 ].w;
    this->hei = spriteClips[ 0 ].h;

    /*DRAW A RECTANGLE AROUND FOR DETECTING COLLISIONS*/
    collider.x=position.x-wid/2;
    collider.y=position.y-hei/2;
    collider.w=this->wid;
    collider.h=this->hei;

    angle=ang;

    /*DEFINE INITIAL POSITIONS*/
    base[0]=31.0;height[0]=3;
    base[1]=31.0;height[1]=3;
    base[2]=31.0;height[2]=25.0;
    base[3]=31.0;height[3]=25.0;
    base[4]=31.0;height[4]=43.0;
    base[5]=31.0;height[5]=43.0;
    base[6]=31.0;height[6]=87.0;
    base[7]=31.0;height[7]=87.0;
    base[8]=0.0;height[8]=120.0;

    for(int i=0; i<8; i++){
            if(i==0 || i==2 || i==4 || i==6){
                angleVariation[i]=(atan(-height[i]/base[i]))*(180/PI);
            }
            else
                angleVariation[i]=(atan(height[i]/base[i]))*(180/PI);

            hypoteneous[i]=sqrt(float(pow((base[i]),2.0)+pow((height[i]),2.0)));
            turretPosition[i]=false;
            turretFire[i]=false;
            turretType[i]=5;
    }

    /*HEALTH BAR*/
    angleVariation[8]=(atan(height[8]/base[8]))*(180/PI);
    hypoteneous[8]=sqrt(float(pow((base[8]),2.0)+pow((height[8]),2.0)));
    hBar = new HealthBar(image,this->position.shift(base[8],height[8]),angle,health);

    healthBar=hB;
}

Tank::Tank(){

}

Tank::~Tank(){

}

void Tank::loadTurret(int index,int type){
    if(!turretPosition[index]){
        switch(index){
            case 0:{
                switch(type){
                    case 0:
                    {
                        turret[index] = new LaserTurret(this->image, this->position.shift(-base[index],height[index]),angle,angle,2);
                        break;
                    }
                    case 1:
                    {
                        turret[index] = new MachineTurret(this->image, this->position.shift(-base[index],height[index]),angle,angle,2);
                        break;
                    }
                    case 2:
                    {
                        turret[index] = new BomberTurret(this->image, this->position.shift(-base[index],height[index]),angle,angle,2);
                        break;
                    }
                }
                break;
            }
            case 1:{
                switch(type){
                    case 0:
                    {
                        turret[index] = new LaserTurret(this->image, this->position.shift(base[index],height[index]),angle,angle,2);
                        break;
                    }
                    case 1:
                    {
                        turret[index] = new MachineTurret(this->image, this->position.shift(base[index],height[index]),angle,angle,2);
                        break;
                    }
                    case 2:
                    {
                        turret[index] = new BomberTurret(this->image, this->position.shift(base[index],height[index]),angle,angle,2);
                        break;
                    }
                }
                break;
            }
            case 2:{
                switch(type){
                    case 0:
                    {
                        turret[index] = new LaserTurret(this->image, this->position.shift(-base[index],height[index]),angle-90.0,angle,2);
                        break;
                    }
                    case 1:
                    {
                        turret[index] = new MachineTurret(this->image, this->position.shift(-base[index],height[index]),angle-90.0,angle,2);
                        break;
                    }
                    case 2:
                    {
                        turret[index] = new BomberTurret(this->image, this->position.shift(-base[index],height[index]),angle-90.0,angle,2);
                        break;
                    }
                }
                break;
            }
            case 3:{
                switch(type){
                    case 0:
                    {
                        turret[index] = new LaserTurret(this->image, this->position.shift(base[index],height[index]),angle+90.0,angle,2);
                        break;
                    }
                    case 1:
                    {
                        turret[index] = new MachineTurret(this->image, this->position.shift(base[index],height[index]),angle+90.0,angle,2);
                        break;
                    }
                    case 2:
                    {
                        turret[index] = new BomberTurret(this->image, this->position.shift(base[index],height[index]),angle+90.0,angle,2);
                        break;
                    }
                }
                break;
            }
            case 4:{
                switch(type){
                    case 0:
                    {
                        turret[index] = new LaserTurret(this->image, this->position.shift(-base[index],height[index]),angle-90.0,angle,2);
                        break;
                    }
                    case 1:
                    {
                        turret[index] = new MachineTurret(this->image, this->position.shift(-base[index],height[index]),angle-90.0,angle,2);
                        break;
                    }
                    case 2:
                    {
                        turret[index] = new BomberTurret(this->image, this->position.shift(-base[index],height[index]),angle-90.0,angle,2);
                        break;
                    }
                }
                break;
            }
            case 5:{
                switch(type){
                    case 0:
                    {
                        turret[index] = new LaserTurret(this->image, this->position.shift(base[index],height[index]),angle+90.0,angle,2);
                        break;
                    }
                    case 1:
                    {
                        turret[index] = new MachineTurret(this->image, this->position.shift(base[index],height[index]),angle+90.0,angle,2);
                        break;
                    }
                    case 2:
                    {
                        turret[index] = new BomberTurret(this->image, this->position.shift(base[index],height[index]),angle+90.0,angle,2);
                        break;
                    }
                }
                break;
            }
            case 6:{
                switch(type){
                    case 0:
                    {
                        turret[index] = new LaserTurret(this->image, this->position.shift(-base[index],height[index]),angle+180.0,angle,2);
                        break;
                    }
                    case 1:
                    {
                        turret[index] = new MachineTurret(this->image, this->position.shift(-base[index],height[index]),angle+180.0,angle,2);
                        break;
                    }
                    case 2:
                    {
                        turret[index] = new BomberTurret(this->image, this->position.shift(-base[index],height[index]),angle+180.0,angle,2);
                        break;
                    }
                }
                break;
            }
            case 7:{
                switch(type){
                    case 0:
                    {
                        turret[index] = new LaserTurret(this->image, this->position.shift(base[index],height[index]),angle+180.0,angle,2);
                        break;
                    }
                    case 1:
                    {
                        turret[index] = new MachineTurret(this->image, this->position.shift(base[index],height[index]),angle+180.0,angle,2);
                        break;
                    }
                    case 2:
                    {
                        turret[index] = new BomberTurret(this->image, this->position.shift(base[index],height[index]),angle+180.0,angle,2);
                        break;
                    }
                }
                break;
            }
        }
        turretType[index]=type;
        turretPosition[index]=true;
    }
}

void Tank::Rotate(int direction){
    Unit::Rotate(direction);
    hBar->updatePosition(this->position.shift((cos((angle+angleVariation[8])*(PI/180))*hypoteneous[8]),(sin((angle+angleVariation[8])*(PI/180))*hypoteneous[8])));
    hBar->Rotate(direction);
    for(int i=0; i<8; i++)
    {
        if(turretPosition[i])
        {
            if(i%2==0)
                turret[i]->updatePosition(this->position.shift(-(cos((angle+angleVariation[i])*(PI/180))*hypoteneous[i]),-(sin((angle+angleVariation[i])*(PI/180))*hypoteneous[i])));
            else
                turret[i]->updatePosition(this->position.shift((cos((angle+angleVariation[i])*(PI/180))*hypoteneous[i]),(sin((angle+angleVariation[i])*(PI/180))*hypoteneous[i])));
            turret[i]->Rotate(direction);
        }
    }
}

void Tank::Move(int direction){
    Unit::Move(direction);
    hBar->updatePosition(this->position.shift((cos((angle+angleVariation[8])*(PI/180))*hypoteneous[8]),(sin((angle+angleVariation[8])*(PI/180))*hypoteneous[8])));
    for(int i=0; i<8; i++){
        if(turretPosition[i])
        {
            if(i%2==0)
                turret[i]->updatePosition(this->position.shift(-(cos((angle+angleVariation[i])*(PI/180))*hypoteneous[i]),-(sin((angle+angleVariation[i])*(PI/180))*hypoteneous[i])));
            else
                turret[i]->updatePosition(this->position.shift((cos((angle+angleVariation[i])*(PI/180))*hypoteneous[i]),(sin((angle+angleVariation[i])*(PI/180))*hypoteneous[i])));
        }
    }
}

void Tank::Move(){
    speedy = speedy * friction;
    position.y = position.y + ((cos(angle*(PI/180)))*(speedy));
    position.x = position.x + ((sin(angle*(PI/180)))*(-speedy));
    collider.x=position.x-wid/2;
    collider.y=position.y-hei/2;
    if((collider.y+collider.h)>600 || collider.y<0 || (collider.x+collider.w)>800 || collider.x<0){
        position.y = position.y - ((cos(angle*(PI/180)))*(speedy));
        position.x = position.x - ((sin(angle*(PI/180)))*(-speedy));
        collider.x = position.x-wid/2;
        collider.y = position.y-hei/2;
    }
    else{
        speedy = speedy * friction;
        position.y = position.y + ((cos(angle*(PI/180)))*(speedy));
        position.x = position.x + ((sin(angle*(PI/180)))*(-speedy));
        hBar->updatePosition(this->position.shift((cos((angle+angleVariation[8])*(PI/180))*hypoteneous[8]),(sin((angle+angleVariation[8])*(PI/180))*hypoteneous[8])));
        for(int i=0; i<8; i++){
            if(turretPosition[i])
            {
                if(i%2==0)
                    turret[i]->updatePosition(this->position.shift(-(cos((angle+angleVariation[i])*(PI/180))*hypoteneous[i]),-(sin((angle+angleVariation[i])*(PI/180))*hypoteneous[i])));
                else
                    turret[i]->updatePosition(this->position.shift((cos((angle+angleVariation[i])*(PI/180))*hypoteneous[i]),(sin((angle+angleVariation[i])*(PI/180))*hypoteneous[i])));
            }
        }
    }
}

void Tank::updateHealth(float healthValue){
    health=healthValue;
    hBar->updateHealth(health);
}

bool Tank::selectTarget(Unit* enemy){
    for(int i=0; i<8; i++){
        if(turretPosition[i])
        {
            turretFire[i]=turret[i]->selectTarget(enemy);
        }
    }
    return true;
}

Unit** Tank::fire(long int& frame,int id){
    for(int i=0; i<8; i++){
        if(turretPosition[i] && turretFire[i])
        {
            projectile[i]=*turret[i]->fire(frame,id);
        }
        else{
            projectile[i]=NULL;
        }

    }
    return projectile;
}

void Tank::Render(long int& frame, SDL_Renderer* gRenderer){
    image->Render(position.x-(spriteClips[0].w)/2, position.y-(spriteClips[0].h)/2, &spriteClips[0], angle, NULL, SDL_FLIP_NONE, gRenderer );
    if(healthBar)
        hBar->Render(frame,gRenderer);
    for(int i=0; i<8; i++){
        if(turretPosition[i])
        {
            turret[i]->Render(frame, gRenderer,angle);
        }
    }
}

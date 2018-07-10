#include "Unit.h"

Unit::Unit()
{

}

Unit::Unit(Texture* image, Point pos,int id)
{
    this->id=id;
    this->image = image;
    position=pos;
    alive=true;
    friction=0.995f;
    health=1;
}

Unit::~Unit()
{
    this->image = NULL;
}

int Unit::getId()
{
    return this->id;
}

float Unit::getAngle()
{
    return this->angle;
}

SDL_Rect Unit::getRect()
{
    return collider;
}

void Unit::Rotate(int direction)
{
    if(direction==LEFT)
    {
        speedx=-1.0;
        angle+=speedx;
    }
    if(direction==RIGHT)
    {
        speedx=1.0;
        angle+=speedx;
    }

    collider.x=(position.x-wid/2) - ((sin(angle*(PI/180)))*((hei-wid)/2));
    collider.y=position.y-hei/2 + ((sin(angle*(PI/180)))*((hei-wid)/2));
    collider.w=wid+((hei-wid)*(sin(angle*(PI/180))));
    collider.h=hei-((hei-wid)*(sin(angle*(PI/180))));
}

void Unit::Move(int direction)
{
    speedy=-1;

    if(direction==UP)
    {
        position.y+=((cos(angle*(PI/180)))*(speedy));
        position.x+=((sin(angle*(PI/180)))*(-speedy));
    }

    collider.x=position.x-wid/2;
    collider.y=position.y-hei/2;
    if((collider.y+collider.h)>600 || collider.y<0 || (collider.x+collider.w)>800 || collider.x<0){
        position.y-=((cos(angle*(PI/180)))*(speedy));
        position.x-=((sin(angle*(PI/180)))*(-speedy));
    }
}

void Unit::Move()
{

}

void Unit::updateHealth(float healthValue)
{
    health=healthValue;
}

float Unit::getHealth()
{
    return health;
}

float Unit::getDamageValue()
{
    return damageValue;
}

bool Unit::selectTarget(Unit* enemy)
{
    return true;
}

Unit** Unit::fire(long int& frame,int id)
{
    return &Target;
}

bool Unit::checkCollision(SDL_Rect a, SDL_Rect b)
{

    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if(rightA>=leftB && bottomA>=topB && topA<=bottomB)
    {
        return false;
    }
    else
        return true;
}

void Unit::setAlive(bool al)
{
    alive=al;
}

bool Unit::getAlive()
{
    return alive;
}

void Unit::updatePosition(Point pos)
{
    this->position=pos;
}

Point Unit::returnPosition()
{
    return position;
}

int* Unit::returnTType(){
    return turretType;
}

void Unit::Render(long int& frame, SDL_Renderer* gRenderer)
{
    image->Render(position.x-(spriteClips[0].w)/2, position.y-(spriteClips[0].h)/2, &spriteClips[0], angle, NULL, SDL_FLIP_NONE, gRenderer );
}



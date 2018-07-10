#pragma once
#include"Node.h"
#include <stdlib.h>
#include <time.h>
#include "Explosion.h"

class Queue
{
private:
    Node* head;
    Node* tail;
    int random=0;
    Explosion* explode;
public:
    Queue();
    ~Queue();
    void Enqueue(Unit*);
    void Clean(int);
    void collision(Texture* image);
    bool checkWin();
    void selectTarget(long int& frame);
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void Move();
    void Move(int direction,int id);
    void Rotate(int direction,int id);
};

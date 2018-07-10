#include"Queue.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
    head = NULL;
    tail = NULL;
    srand(time(NULL));
}

Queue::~Queue()
{
     while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        cout<<"Deallocating value: "<<temp->unit<<endl;
        delete temp;
    }
}

void Queue::Enqueue(Unit* unit)
{
    if(head == NULL)
    {
        head = new Node;
        head->unit = unit;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->unit = unit;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

void Queue::Clean(int Wid)
{
    Node* temp = head;
    while(temp!=NULL){
         if((temp->unit->returnPosition().x)>Wid+28 || (temp->unit->returnPosition().x)<-50){
            Node* del=temp;
            temp=temp->next;
            if((del->prev)!=NULL)
            {
                del->prev->next = del->next;
            }
            else
                head=del->next;
            if((del->next)!=NULL){
                del->next->prev = del->prev;
            }
            else
                tail=del->prev;
            delete del;
        }
        else if(temp->unit->getAlive()==false){
            Node* del=temp;
            temp=temp->next;
            if((del->prev)!=NULL)
            {
                del->prev->next = del->next;
            }
            else
                head=del->next;
            if((del->next)!=NULL){
                del->next->prev = del->prev;
            }
            else
                tail=del->prev;
            delete del;
        }
        else
            temp=temp->next;
    }
    delete temp;

}

void Queue::collision(Texture* image)
{
    Node* temp1 = head;
    Node* temp2 = head;
    while(temp1!=NULL){
        while(temp2!=NULL){
            if((temp1->unit->getId()==3 && temp2->unit->getId()==4)){
                if(!temp1->unit->checkCollision(temp1->unit->getRect(),temp2->unit->getRect())){

                        explode = new Explosion(image, temp1->unit->returnPosition(),11);
                        Enqueue(explode);

                        temp2->unit->updateHealth(temp2->unit->getHealth()-temp1->unit->getDamageValue());

                        /* DELETE BULLET */
                        Node* del=temp1;
                        temp1=temp1->next;
                        if((del->prev)!=NULL)
                        {
                            del->prev->next = del->next;
                        }
                        else
                            head=del->next;
                        if((del->next)!=NULL){
                            del->next->prev = del->prev;
                        }
                        else
                            tail=del->prev;
                        delete del;

                        temp1=head;

                        /* DELETE TANK */
                        if(temp2->unit->getHealth()<=0){
                            Node * del1=temp2;
                            temp2=temp2->next;
                            if((del1->prev)!=NULL)
                            {
                                del1->prev->next = del1->next;
                            }
                            else
                                head=del1->next;
                            if((del1->next)!=NULL){
                                del1->next->prev = del1->prev;
                            }
                            else
                                tail=del1->prev;
                            delete del1;
                        }
                        temp1=head;
                        temp2=head;
                }
            }

            else if((temp1->unit->getId()==1 && temp2->unit->getId()==5)){
                if(!temp1->unit->checkCollision(temp1->unit->getRect(),temp2->unit->getRect())){

                        explode = new Explosion(image, temp2->unit->returnPosition(),11);
                        Enqueue(explode);

                        temp1->unit->updateHealth(temp1->unit->getHealth()-temp2->unit->getDamageValue());

                        /* DELETE BULLET */
                        Node * del1=temp2;
                        temp2=temp2->next;
                        if((del1->prev)!=NULL)
                        {
                            del1->prev->next = del1->next;
                        }
                        else
                            head=del1->next;
                        if((del1->next)!=NULL){
                            del1->next->prev = del1->prev;
                        }
                        else
                            tail=del1->prev;
                        delete del1;

                        temp2=head;

                        /* DELETE TANK */
                        if(temp1->unit->getHealth()<=0){
//                            ExplosionE* explode = new ExplosionE(Texture, temp1->unit->returnPosition(), 6);
//                            this->Enqueue(explode);
                            Node* del=temp1;
                            temp1=temp1->next;
                            if((del->prev)!=NULL)
                            {
                                del->prev->next = del->next;
                            }
                            else
                                head=del->next;
                            if((del->next)!=NULL){
                                del->next->prev = del->prev;
                            }
                            else
                                tail=del->prev;
                            temp1->unit->setAlive(false);
                            delete del;
                        }

                        temp1=head;
                        temp2=head;
                }
            }
//            if((temp1->unit->getId()==2) && !temp1->unit->checkCollision(temp1->unit->getRect(),pla->getRect())){
//                pla->SetAlive(false);
//            }
            if(temp2!=NULL)
                temp2=temp2->next;
        }
        if(temp1!=NULL)
            temp1=temp1->next;
        temp2=head;
    }
}

void Queue::Move()
{
    Node* temp=head;
    while(temp!=NULL){
        temp->unit->Move();
        temp->unit->updateHealth(temp->unit->getHealth());
        temp=temp->next;
    }
    delete temp;
}

void Queue::Move(int direction,int id)
{
    Node* temp=head;

    while(temp!=NULL){
        if(temp->unit->getId()==1 && temp->unit->getId()==id)
            temp->unit->Move(direction);
        else if(temp->unit->getId()==4 && temp->unit->getId()==id)
        {
            random=rand()%3;
            temp->unit->Move(random);
        }
        temp=temp->next;
    }
    delete temp;
}

void Queue::Rotate(int direction,int id)
{
    Node* temp=head;
    while(temp!=NULL){
        if(temp->unit->getId()==1 && temp->unit->getId()==id)
            temp->unit->Rotate(direction);
        else if(temp->unit->getId()==4 && temp->unit->getId()==id)
        {
            random=rand()%3;
            temp->unit->Rotate(random);
        }
        temp=temp->next;
    }
}

void Queue::selectTarget(long int& frame)
{
    Node* temp1 = head;
    Node* temp2;
    Unit** projectile;
    if(head!=NULL)
        temp2 = head->next;
    else
        temp2=NULL;
    while(temp1!=NULL){
        if(temp1->unit->getId()==1){
            while(temp2!=NULL){
                if((temp2->unit->getId()==4)){
                        temp1->unit->selectTarget(temp2->unit);
                        projectile=temp1->unit->fire(frame,3);
                        for(int i=0; i<8; i++){
                            if(projectile[i]!=0)
                                this->Enqueue(projectile[i]);
                        }
                }
                temp2=temp2->next;
            }
        }
        else if(temp1->unit->getId()==4 && head->unit->getId()==1){
            temp1->unit->selectTarget(head->unit);
            projectile=temp1->unit->fire(frame,5);
            for(int i=0; i<8; i++){
                if(projectile[i]!=0)
                    this->Enqueue(projectile[i]);
            }
        }
        temp1=temp1->next;
        temp2=head;
    }
//    delete temp1;
//    delete temp2;
}

bool Queue::checkWin()
{
    Node* temp=head;
    bool win=true;
    while(temp!=NULL){
        if(temp->unit->getId()==4)
            win=false;
        temp=temp->next;
    }
    delete temp;
    return win;
}

void Queue::Render(long int& frame, SDL_Renderer* gRenderer)
{
    Node* temp=head;
    while(temp!=NULL){
        temp->unit->Render(frame, gRenderer);
        temp=temp->next;
    }
    delete temp;
}


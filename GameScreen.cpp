#include "GameScreen.h"

GameScreen::GameScreen() : DrawScreen()
{

}

GameScreen::~GameScreen()
{

}

GameScreen::GameScreen(Texture* gameImage,Texture* fontImg, Point pos,int* type,int isFile):DrawScreen(gameImage,pos)
{
    cout<<isFile;
    position = pos;
    this->type=type;

    frame = 0;             //ANIMATION FRAME
    bulletInterval = 0;    //BULLETS INTERVAL

    srand (time(NULL));     //RANDOM SEED

    random = 0;
    display = new Background(gameImage,position,0);                        //BACKDROP OBJECT

    saveButton = new Button(fontImg,pos.shift(0,250), "Save Game");
    saveButton->setButWidth(9);

    if(isFile==0){
        tank = new Tank(gameImage, position.shift(0,120),0.0,1,true);           //PLAYER TANK
        enemyTank=new Enemy*[1];
        enemyTank[0] = new Enemy(gameImage, position.shift(100,-100),180.0,4);        //ENEMY TANK


        for(int i= 0; i<8; i++){
            if(type[i]!=5)
                tank->loadTurret(i,type[i]);
        }
        for(int i= 0; i<1; i++){
            enemyTank[0]->loadTurret(i,1);
        }
        q.Enqueue(tank);
        q.Enqueue(enemyTank[0]);
    }

    else if(isFile==1){
        filePointer = fopen("lastgame.txt", "r");    //Opening file as read only

        if (filePointer == NULL)
        {
            perror ("ERROR OPENING FILE");
        }

        Point tempP;
        tempP.x=0;
        tempP.y=0;
        noOfLines=LineCounter();
        enemyTank=new Enemy*[(noOfLines/13)-1];
        for (int j=0; j<13; j++){
            fgets(buff[j], 32, (FILE*)filePointer);
        }
        tank = new Tank(gameImage, tempP.shift(atoi(buff[2]),atoi(buff[3])),atof(buff[1]),atoi(buff[0]),true);
        tank->updateHealth(atof(buff[4]));
        for(int i= 0; i<8; i++){
            if(atoi(buff[i+5])!=5)
                tank->loadTurret(i,atoi(buff[i+5]));
        }
        q.Enqueue(tank);
        for (int i=0; i<(noOfLines/13); i++){
            if(i>0){
                for (int j=0; j<13; j++){
                    fgets(buff[j], 32, (FILE*)filePointer);
                }
                enemyTank[i-1] = new Enemy(gameImage, tempP.shift(atoi(buff[2]),atoi(buff[3])),atof(buff[1]),atoi(buff[0]));
                enemyTank[i-1]->updateHealth(atof(buff[4]));
                for(int k= 0; k<8; k++){
                    if(atoi(buff[k+5])!=5)
                        enemyTank[i-1]->loadTurret(k,atoi(buff[k+5]));
                }
                q.Enqueue(enemyTank[i-1]);
            }
        }
        fclose(filePointer);
    }

    else if(isFile==2){

        Point tempP;
        tempP.x=0;
        tempP.y=0;
        noOfLines=LineCounter();

        tank = new Tank(gameImage, position.shift(0,120),0.0,1,true);           //PLAYER TANK

        for(int i= 0; i<8; i++){
            if(type[i]!=5)
                tank->loadTurret(i,type[i]);
        }

        q.Enqueue(tank);

        //
        filePointer = fopen("lastgame.txt", "r");    //Opening file as read only

        if (filePointer == NULL)
        {
            perror ("ERROR OPENING FILE");
        }

        enemyTank=new Enemy*[(noOfLines/13)];

        for (int i=0; i<(noOfLines/13); i++){
            for (int j=0; j<13; j++){
                fgets(buff[j], 32, (FILE*)filePointer);
            }
            enemyTank[i] = new Enemy(gameImage, tempP.shift(atoi(buff[2]),atoi(buff[3])),atof(buff[1]),4);
            enemyTank[i]->updateHealth(atof(buff[4]));
            for(int k= 0; k<8; k++){
                if(atoi(buff[k+5])!=5)
                    enemyTank[i]->loadTurret(k,atoi(buff[k+5]));
            }
            q.Enqueue(enemyTank[i]);
        }
        fclose(filePointer);
    }
}


int GameScreen::LineCounter()
{
    FILE* filePointerT;
    filePointerT = fopen("lastgame.txt","r");
    char buff[32];                              //Declaring a character array to store a line

    int counter = 0;                            //Counts the lines in file

    while(fgets(buff, 32, (FILE*)filePointerT) !=NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointerT);                                //close file when done
    return counter;                                     //return line count
}

void GameScreen::saveGame()
{
    myfile.open ("lastgame.txt");
    myfile<<tank->getId()<<endl;
    myfile<<tank->getAngle()<<endl;
    myfile<<tank->returnPosition().x<<endl;
    myfile<<tank->returnPosition().y<<endl;
    myfile<<tank->getHealth()<<endl;
    type=tank->returnTType();
    for(int i=0; i<8; i++){
        myfile<<type[i]<<endl;
    }
    for(int i=0; i<(sizeof(enemyTank)/sizeof(*enemyTank)); i++){
        myfile<<enemyTank[i]->getId()<<endl;
        myfile<<enemyTank[i]->getAngle()<<endl;
        myfile<<enemyTank[i]->returnPosition().x<<endl;
        myfile<<enemyTank[i]->returnPosition().y<<endl;
        myfile<<enemyTank[i]->getHealth()<<endl;
        type=enemyTank[i]->returnTType();
        for(int i=0; i<8; i++){
            myfile<<type[i]<<endl;
        }
    }
}

void GameScreen::Event(SDL_Event e,const Uint8* currentKeyStates,bool* mouseClicked,int* state)
{
    if(currentKeyStates[ SDL_SCANCODE_ESCAPE ])
    {
        *state = 1;
    }
    if(currentKeyStates[ SDL_SCANCODE_RIGHT ])
    {
        q.Rotate(RIGHT,1);
    }

    if(currentKeyStates[ SDL_SCANCODE_LEFT ])
    {
        q.Rotate(LEFT,1);
    }

    if(currentKeyStates[ SDL_SCANCODE_UP ])
    {
        q.Move(UP,1);
    }
    if( e.type == SDL_MOUSEBUTTONDOWN && *mouseClicked == false)
    {
        Point p;
        int x,y;
        SDL_GetMouseState( &x, &y );
        p.x=x;
        p.y=y;

        if (e.button.button == SDL_BUTTON_LEFT){

            *mouseClicked = true;
            if(checkClick(saveButton->returnButtonRect(),p))
            {
                saveGame();
                *state=1;
            }

        }
    }
    if( e.type == SDL_MOUSEBUTTONUP && *mouseClicked == true)
    {
        *mouseClicked=false;
    }
}

void GameScreen::Play(int* state,int* isFile)
{

    q.selectTarget(bulletInterval);     // PERFORM AI TO SELECT THE NEAREST TARGET
    q.Move();
    q.collision(this->image);
    q.Clean(800);

    if(frame%250==0){
        q.Move(0,4);                    // MOVE OBJECTS IN RANDOM DIRECTIONS
        q.Rotate(0,4);                  // ROTATE OBJECTS IN RANDOM DIRECTIONS
    }

    if(bulletInterval==1000)
    {
        bulletInterval=-1000;
    }
    if(q.checkWin()){
        myfile.open ("lastgame.txt");
        myfile<<4<<endl;
        myfile<<180.0<<endl;
        myfile<<200.0<<endl;
        myfile<<100.0<<endl;
        myfile<<1<<endl;
        type=tank->returnTType();
        for(int i=0; i<8; i++){
            myfile<<type[i]<<endl;
        }
//        for(int i=0; i<(sizeof(enemyTank)/sizeof(*enemyTank)); i++){
//            myfile<<4<<endl;
//            myfile<<180.0<<endl;
//            myfile<<i*100<<endl;
//            myfile<<150<<endl;
//            myfile<<1<<endl;
//            type=enemyTank[i]->returnTType();
//            for(int i=0; i<8; i++){
//                myfile<<type[i]<<endl;
//            }
//        }
        *state=2;
        *isFile=2;
    }
    ++frame;
    ++bulletInterval;
}

void GameScreen::Render(SDL_Renderer* gRenderer)
{
    display->Render(gRenderer);     // RENDER BACKGROUND.
    q.Render(frame,gRenderer);      // RENDER ALL THE OBJECTS IN QUEUE.
    saveButton->Render(gRenderer,9);
}

#include "MainMenu.h"




MainMenu::MainMenu() : DrawScreen()
{


}

MainMenu::MainMenu(Texture* image,Texture* image1, Point pos):DrawScreen(image,pos)
{

    NG = new Button(image1,pos.shift((spriteClips.w/2),(spriteClips.h/2)-50), "New Game");
    LG = new Button(image1,pos.shift((spriteClips.w/2),(spriteClips.h/2)), "load Game");
    Qut = new Button(image1,pos.shift((spriteClips.w/2),(spriteClips.h/2)+50), "Quit");

    if(NG->returnNoOfLetter()>LG->returnNoOfLetter() && NG->returnNoOfLetter()>Qut->returnNoOfLetter())
        maxNoOfL=NG->returnNoOfLetter();
    else if(LG->returnNoOfLetter()>NG->returnNoOfLetter() && LG->returnNoOfLetter()>Qut->returnNoOfLetter())
        maxNoOfL=LG->returnNoOfLetter();
    else if(Qut->returnNoOfLetter()>LG->returnNoOfLetter() && Qut->returnNoOfLetter()>NG->returnNoOfLetter())
        maxNoOfL=Qut->returnNoOfLetter();
    NG->setButWidth(maxNoOfL);
    LG->setButWidth(maxNoOfL);
    Qut->setButWidth(maxNoOfL);

    isFile=false;
}

MainMenu::~MainMenu()
{
//    delete NG;
//    NG = NULL;
//    delete LG;
//    LG = NULL;
//    delete Qut;
//    Qut = NULL;
//    delete welcome;
//    LG = NULL;

}

int MainMenu::Event(SDL_Event e,const Uint8* currentKeyStates,bool* mouseClicked,int* state,bool* quit)
{

    if( e.type == SDL_MOUSEBUTTONDOWN && *mouseClicked == false)
    {
        Point p;
        int x,y;
        SDL_GetMouseState( &x, &y );
        p.x=x;
        p.y=y;


        if (e.button.button == SDL_BUTTON_LEFT){

            *mouseClicked = true;
            if(checkClick(NG->returnButtonRect(),p))
            {
                *state = 2;
            }
            if (checkClick(LG->returnButtonRect(),p))
            {
                filePointer = fopen("lastgame.txt", "r");    //Opening file as read only

                if (filePointer == NULL)
                {
                    perror ("ERROR OPENING FILE");
                }
                else{
                    isFile=1;
                    *state=3;
                }
                fclose(filePointer);
            }
            if (checkClick(Qut->returnButtonRect(),p))
            {
                *quit = true;
            }
        }
    }
    if( e.type == SDL_MOUSEBUTTONUP && *mouseClicked == true)
    {
        *mouseClicked=false;
    }
    return isFile;
}

void MainMenu::Render(SDL_Renderer* gRenderer)
{
    image->Render( position.x, position.y, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    NG->Render(gRenderer,maxNoOfL);
    LG->Render(gRenderer,maxNoOfL);
    Qut->Render(gRenderer,maxNoOfL);

}

int MainMenu::Play( Texture* image, SDL_Renderer* gRenderer,int state)
{
    return state;
}

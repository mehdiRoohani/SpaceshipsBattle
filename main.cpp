//#include <SDL.h>
//#include <SDL_image.h>
//#include <stdio.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//#include "Texture.h"
//#include "Unit.h"
//#include "Point.h"
//#include "Tank.h"
//#include "Enemy.h"
//#include "Backgound.h"
//#include "Queue.h"
//
////SCREEN DIMENSIONS
//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 600;
//
//bool init();
//bool loadMedia();
//void close();
//
//SDL_Window* gWindow = NULL;
//SDL_Renderer* gRenderer = NULL;
//Texture gameImage;
//
//int main( int argc, char* args[] )
//{
//	//Start up SDL and create window
//	if( !init() )
//	{
//		printf( "Failed to initialize!\n" );
//	}
//	else
//	{
//		//Load media
//		if( !loadMedia() )
//		{
//			printf( "Failed to load media!\n" );
//		}
//		else
//		{
//		    /*---------------------------VARIABLE DECLARATIONS---------------------------*/
//
//			bool quit = false;
//
//            Point position;                 //DETERMINIG CENTER OF THE SCREEN, ALL OBJECTS WILL BE DRAWN WITH RESPECT TO.
//            position.x=SCREEN_WIDTH/2;
//            position.y=SCREEN_HEIGHT/2;
//
//			SDL_Event e;                    //EVENT HANDLER
//
//			long int frame = 0;             //ANIMATION FRAME
//			long int bulletInterval = 0;    //BULLETS INTERVAL
//
//            srand (time(NULL));             //RANDOM SEED
//            int random = 0;
//		    Queue q;                        //QUEUE
//            const Uint8* currentKeyStates;  //KEYSTATE DETECTOR
//
//		    Background* display = new Background(&gameImage,position,0);                //BACKDROP OBJECT
//			Tank* tank = new Tank(&gameImage, position.shift(0,120),0.0,1);             //PLAYER TANK
//			Enemy* tank1 = new Enemy(&gameImage, position.shift(100,-100),180.0,4);     //ENEMY TANK
//			Enemy* tank2 = new Enemy(&gameImage, position.shift(-200,-25),180.0,4);     //ENEMY TANK
//			Unit* tank3 = new Enemy(&gameImage, position.shift(-300,50),180.0,4);       //ENEMY TANK
//
//			for(int i= 0; i<8; i++){
//                tank->loadTurret(i,2);
//            }
//			for(int i= 0; i<8; i++){
//                tank1->loadTurret(i,2);
//            }
//			for(int i= 0; i<1; i++){
//                tank2->loadTurret(i,1);
//            }
//
//            q.Enqueue(tank);
//			q.Enqueue(tank1);
////			q.Enqueue(tank2);
////			q.Enqueue(tank3);
//
//            /*---------------------------GAME LOOP---------------------------*/
//
//			while( !quit )
//			{
//				while( SDL_PollEvent( &e ) != 0 )
//				{
//					if( e.type == SDL_QUIT )
//					{
//						quit = true;
//					}
//					currentKeyStates = SDL_GetKeyboardState( NULL );
//				}
//
//                if(currentKeyStates[ SDL_SCANCODE_RIGHT ])
//                {
//                    q.Rotate(RIGHT,1);
//                }
//
//                if(currentKeyStates[ SDL_SCANCODE_LEFT ])
//                {
//                    q.Rotate(LEFT,1);
//                }
//
//                if(currentKeyStates[ SDL_SCANCODE_UP ])
//                {
//                    q.Move(UP,1);
//                }
//
//                if(currentKeyStates[ SDL_SCANCODE_DOWN ])
//                {
//                    q.Move(DOWN,1);
//                }
//
//                /*---------------------------RENDERING OF OBJECTS---------------------------*/
//
//                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
//                SDL_RenderClear( gRenderer );
//
//                display->Render(frame, gRenderer);      // Render Background.
//
//                q.selectTarget(bulletInterval);         // Perform AI to select nearest enemy as target.
//                q.Move();
//                q.collision();
//                if(frame%250==0){
//                    q.Move(0,4);                    //Move Objects In Random Directions.
//                    q.Rotate(0,4);                  //Rotate Objects In Random Directions.
//                }
//
//                q.Render(frame,gRenderer);          //Render All Objects
//                q.Clean(SCREEN_WIDTH);
//                SDL_RenderPresent( gRenderer );     //Update screen
//
//                if(bulletInterval==1000)
//                {
//                    bulletInterval=-1000;
//                }
//
//                ++frame;
//                ++bulletInterval;
//            }
//		}
//	}
//
//	//Free resources and close SDL
//	close();
//
//	return 0;
//}
//
//bool init()
//{
//	//Initialization flag
//	bool success = true;
//
//	//Initialize SDL
//	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
//	{
//		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
//		success = false;
//	}
//	else
//	{
//		//Set texture filtering to linear
//		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
//		{
//			printf( "Warning: Linear texture filtering not enabled!" );
//		}
//
//		//Create window
//		gWindow = SDL_CreateWindow( "Oops", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
//		if( gWindow == NULL )
//		{
//			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
//			success = false;
//		}
//		else
//		{
//			//Create renderer for window
//			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
//            if( gRenderer == NULL )
//            {
//                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
//                success = false;
//            }
//			else
//			{
//				//Initialize renderer color
//				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
//
//				//Initialize PNG loading
//				int imgFlags = IMG_INIT_PNG;
//				if( !( IMG_Init( imgFlags ) & imgFlags ) )
//				{
//					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
//					success = false;
//				}
//			}
//		}
//	}
//
//	return success;
//}
//
//bool loadMedia()
//{
//	//Loading success flag
//	bool success = true;
//
//	//Load sprite sheet texture
//	if( !gameImage.LoadFromFile( "Images/bg.png", gRenderer  ) )
//	{
//		printf( "Failed to load sprite sheet texture!\n" );
//		success = false;
//	}
//
//	return success;
//}
//
//void close()
//{
//	//Free loaded images
//	gameImage.Free();
//
//	//Destroy window
//	SDL_DestroyRenderer( gRenderer );
//	SDL_DestroyWindow( gWindow );
//	gWindow = NULL;
//	gRenderer = NULL;
//
//	//Quit SDL subsystems
//	IMG_Quit();
//	SDL_Quit();
//}
#include <SDL.h>
#include <stdio.h>
#include "Character.h"
#include "Word.h"
#include "Button.h"
#include "DrawScreen.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "GameScreen.h"
#include "tankDesignScreen.h"
#include "Point.h"

#include <iostream>

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool init();                            //Starts up SDL and creates window
bool loadMedia();                       //Loads media
void close();                           //Frees media and shuts down SDL

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;     //The surface contained by the window

Texture fontImage;
Texture gameSprite;
Texture tankDesignImage;

//SDL_Surface* gScreenSurface = NULL;
//SDL_Surface* MainBackground = NULL;

//SDL_Surface* menuInit1 = NULL;
//SDL_Surface* menuInit2 = NULL;

//void Render(SDL_Surface* image,SDL_Renderer* gRenderer))
//{
//    image->Render( 0,0, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
//}

int main(int argc, char* args[])
{

    //Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
            Point position;                 //DETERMINIG CENTER OF THE SCREEN, ALL OBJECTS WILL BE DRAWN WITH RESPECT TO.
            position.x=0;
            position.y=0;
		    bool quit = false;
		    bool mouseClicked = false;
		    int state = 0;
			SDL_Event e;
			const Uint8* currentKeyStates;
			int* tankType=new int[8];
			bool gameWon=false;

            int isFile=0;              //DECLARING FILE POINTER
//            char buff[13][32];              //CHARACTER 2D ARRAY TO STORE LINES

            SplashScreen* splashScreen=NULL;
			MainMenu* menu=NULL;
			GameScreen* gameScreen=NULL;
			tankDesignScreen* tankScreen=NULL;

			while( !quit )   // Main game runs in this while loop
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
						//e.type = SDL_QUIT;     Hasan after doing that remove this!
                    }
                    currentKeyStates = SDL_GetKeyboardState( NULL );
				}
                switch(state)
                {

                    case 0:
                    {
                        if(splashScreen == NULL)
                            splashScreen = new SplashScreen(&gameSprite,position);
                        break;
                    }
                    case 1:
                    {
                        if(menu == NULL)
                            menu = new  MainMenu(&gameSprite,&fontImage,position);
                        isFile=menu->Event(e,currentKeyStates,&mouseClicked,&state,&quit);

                        break;
                    }
                    case 2:
                    {
                        if(tankScreen == NULL)
                            tankScreen = new  tankDesignScreen(&tankDesignImage,&gameSprite,&fontImage,position.shift(SCREEN_WIDTH/2,SCREEN_HEIGHT/2));
                        tankType=tankScreen->Event(e,currentKeyStates,&mouseClicked,&state);

                        break;
                    }
                    case 3:
                    {
                        if(isFile==2){

                            delete gameScreen;
                            gameScreen=NULL;
                        }
                        if(gameScreen == NULL)
                            gameScreen = new  GameScreen(&gameSprite,&fontImage,position.shift(SCREEN_WIDTH/2,SCREEN_HEIGHT/2),tankType,isFile);
                        gameScreen->Event(e,currentKeyStates,&mouseClicked,&state);
                        break;
                        break;
                    }

                }
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);
                switch(state){
                    case 0:{
                        splashScreen->Render(gRenderer);
                        SDL_RenderPresent(gRenderer);
                        SDL_Delay(1000);
                        state=1;
                        break;
                    }
                    case 1:{
                        if(menu!=NULL)
                            menu->Render(gRenderer);
                        break;
                    }
                    case 2:{
                        if(tankScreen!=NULL){
                            tankScreen->Play();
                            tankScreen->Render(gRenderer);
                        }
                        break;
                    }
                    case 3:{
                        if(gameScreen!=NULL){
                            gameScreen->Play(&state,&isFile);
                            gameScreen->Render(gRenderer);
                        }
                        if(isFile==2){

//                            delete gameScreen;
                            gameScreen=NULL;
                        }
                        break;
                    }
                }
                SDL_RenderPresent(gRenderer);
			}
			delete splashScreen;
			delete menu;
			delete gameScreen;
			delete tankScreen;
			close();
		}
	}
    return 0;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "FLASH GAMES", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	if( !fontImage.LoadFromFile( "Images/fontSprite1.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !gameSprite.LoadFromFile( "Images/bg.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet 2 texture!\n" );
		success = false;
	}
	if( !tankDesignImage.LoadFromFile( "Images/bgT.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet 3 texture!\n" );
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	fontImage.Free();
	gameSprite.Free();
	tankDesignImage.Free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	//SDL_DestroyTexture(&fontImage);
	gWindow = NULL;
	gRenderer = NULL;


	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

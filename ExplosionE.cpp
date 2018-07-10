//#include "ExplosionE.h"
//#include "cmath"
//#include "math.h"
//
//
//
//ExplosionE::~ExplosionE()
//{
//    cout<<"ExplosionE Deallocated"<<endl;
//    delete ObjRectangle;
//    ObjRectangle = NULL;
//}
//
//ExplosionE::ExplosionE(Texture* image, Point pos, float angle):Explosion(image, pos, angle)
//{
//    ObjRectangle = new SDL_Rect;
//    Type = "ExplosionE";
//
//    health = -1;
//    rotation = angle;
//
//    spriteClips[ 0 ].x = 199;
//    spriteClips[ 0 ].y = 191;
//    spriteClips[ 0 ].w = 30;
//    spriteClips[ 0 ].h = 32;
//
//    spriteClips[ 1 ].x = 224;
//    spriteClips[ 1 ].y = 191;
//    spriteClips[ 1 ].w = 30;
//    spriteClips[ 1 ].h = 32;
//
//    spriteClips[ 2 ].x = 249;
//    spriteClips[ 2 ].y = 191;
//    spriteClips[ 2 ].w = 30;
//    spriteClips[ 2 ].h = 32;
//
//    spriteClips[ 3 ].x = 281;
//    spriteClips[ 3 ].y = 191;
//    spriteClips[ 3 ].w = 30;
//    spriteClips[ 3 ].h = 32;
//
//    spriteClips[ 4 ].x = 321;
//    spriteClips[ 4 ].y = 191;
//    spriteClips[ 4 ].w = 30;
//    spriteClips[ 4 ].h = 32;
//
//
//    this->x = x;
//    this->y = y;
//
//    this->width = spriteClips[ 0 ].w;
//    this->height = spriteClips[ 0 ].h;
//
//    alive  = true;
//    rotation = 45.0;
//    ObjRectangle->x = x;
//    ObjRectangle->y = y;
//    ObjRectangle->h = height;
//    ObjRectangle->w = width;
//
//
//}
//
//void ExplosionE::Move(int SCREEN_HEIGHT)
//{
//    if (y <0 || y>SCREEN_HEIGHT+30 )
//    {
//        SetAlive(false);
//    }
//
//}
//
//void ExplosionE::Render(long int& frame, SDL_Renderer* gRenderer)
//{
//    ObjRectangle->x = x;
//    ObjRectangle->y = y;
//
//    spriteSheetTexture->Render( x, y , &spriteClips[ frame/4 % 5 ], rotation, NULL, SDL_FLIP_NONE, gRenderer );
//    if (frame/4 % 5 ==4)
//    {
//        SetAlive(false);
//    }
//}

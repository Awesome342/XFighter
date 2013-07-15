#include "Enemy.h"

Enemy::Enemy()
{
    Img = IMG_Load("data/trev-ftr.png");
    Pos.x = 64;
    Pos.y = 336;
    Pos.w = 32;
    Pos.h = 32;
    Clip.x = 0;
    Clip.y = 8;
    Clip.w = 32;
    Clip.h = 48;
    Health = 100;
    Attacking = false;
    colorKey = SDL_MapRGB( Img->format, 0xFF, 0, 0xFF );
    SDL_SetColorKey( Img, SDL_SRCCOLORKEY, colorKey );
}

void Enemy::draw( SDL_Surface *Screen )
{
    SDL_BlitSurface( Img, &Clip, Screen, &Pos );
}

void Enemy::getInput()
{
    key = SDL_GetKeyState( NULL );
    if ( key[SDLK_d] )
    {
        Pos.x += 5;
        Direction = 3;
    }
    if ( key[SDLK_a] )
    {
        Pos.x -= 5;
        Direction = 2;
    }
    if ( key[SDLK_s] )
    {
        Attacking = true;
        Clip.x = 108;
        Clip.y = 8;
    }
    else
    {
        Attacking = false;
        Clip.x = 0;
        Clip.y = 8;
    }
}

void Enemy::checkHealth( SDL_Rect POS, bool IsAttacking )
{

    if ( IsAttacking == true )
    {
        if ( POS.x < Pos.x + Pos.w &&
            POS.x + POS.w > Pos.w &&
            POS.y < Pos.y + Pos.h &&
            POS.y + POS.h > Pos.y )
        {
            Health -= 1;
        }
/*
        if ( Direction == 3 )
        {
            Pos.x -= 10;
        }
        else if ( Direction == 2 )
        {
            Pos.x += 10;
        }
*/
    }
}

SDL_Rect Enemy::returnPos()
{
    return Pos;
}

int Enemy::returnHealth()
{
    return Health;
}

bool Enemy::returnAttacking()
{
    return Attacking;
}

Enemy::~Enemy()
{
    SDL_FreeSurface( Img );
}

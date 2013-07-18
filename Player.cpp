#include "Player.h"

Player::Player()
{
    //Image Properties
    Img = IMG_Load("data/star-sm2.png");
    Pos.x = 512;
    Pos.y = 336;
    Pos.w = 32;
    Pos.h = 48;
    Clip.x = 0;
    Clip.y = 0;
    Clip.w = 32;
    Clip.h = 48;
    colorKey = SDL_MapRGB( Img->format, 0xFF, 0, 0xFF );
    SDL_SetColorKey( Img, SDL_SRCCOLORKEY, colorKey );

    //Stats
    frame = 0;
    Special = 0;
    Power = 1;
    Health = 100;
}

void Player::draw( SDL_Surface *Screen )
{
    SDL_BlitSurface( Img, &Clip, Screen, &Pos );
    if ( Special >= 5 )
    {
        std::cout << "You Have A Special.\n";
    }
}

void Player::getInput()
{
    key = SDL_GetKeyState(NULL);
    if ( key[SDLK_SPACE] )
    {
        Attacking = true;
        frame = 2;
        Special += 1;
    }
    else
    {
        Attacking = false;
        Clip.x = 0;
    }
/*
    if ( key[SDLK_x] && Special >= 5 )
    {
        Attacking = true;
        frame = 2;
        Power = 1;
    }
    else
    {
        Attacking = false;
        Clip.x = 0;
        Power = 1;
    }
*/

    if ( key[SDLK_RIGHT] )
    {
        Pos.x += 5;
        Direction = 3;
        Clip.y = 48;
        frame += 1;
    }
    if ( key[SDLK_LEFT] )
    {
        Pos.x -= 5;
        Direction = 2;
        Clip.y = 0;
        frame += 1;
    }
    if ( frame > 1 && Attacking == false )
    {
        frame = 0;
    }
    Clip.x = frame * 32;
}

void Player::checkHealth( SDL_Rect POS, bool IsAttacking )
{
    if ( IsAttacking == true )
    {
        if ( Pos.x < POS.x + POS.w &&
            Pos.x + Pos.w > POS.w &&
            Pos.y < POS.y + POS.h &&
            Pos.y + Pos.h > POS.y )
        {
            Health -= 1;
        }
    }
}

int Player::returnHealth()
{
    return Health;
}

SDL_Rect Player::returnPos()
{
    return Pos;
}

bool Player::returnAttacking()
{
    return Attacking;
}

int Player::returnSpecial()
{
    return Special;
}

int Player::returnPower()
{
    return Power;
}

Player::~Player()
{
    SDL_FreeSurface( Img );
}

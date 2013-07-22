#include "Graphics.h"

Graphics::Graphics()
{
    Screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
    bg = IMG_Load("data/Map1.png");
}

void Graphics::draw()
{
    Hero.getInput();
    Hero.checkHealth( Baddy.returnPos(), Baddy.returnAttacking() );
    Hero.UpdateY( Health.Level.returnCollY(), Health.Level.returnCurrentLevel() );
    Hero.updateAlt( Health.Level.returnAltStart(), Health.Level.returnAltEnd(), Health.Level.returnAltChange() );
    Health.Update( Hero.returnHealth(), Baddy.returnHealth(), Hero.returnSpecial() );
    Baddy.checkHealth( Hero.returnPos(), Hero.returnAttacking(), Hero.returnPower() );
    Baddy.UpdateY( Health.Level.returnCollY(), Health.Level.returnCurrentLevel() );
    Baddy.updateAltChange( Health.Level.returnAltStart(), Health.Level.returnAltEnd() );
    Baddy.getInput();

    Health.draw( Screen );
    Baddy.draw( Screen, Health.IsInMenu );
    Hero.draw( Screen, Health.IsInMenu );
    SDL_Flip( Screen );
}

Graphics::~Graphics()
{
    SDL_FreeSurface( Screen );
}

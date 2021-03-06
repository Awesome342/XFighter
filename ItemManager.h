#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Item.h"
#include <iostream>

class ItemManager
{
    public:
        ItemManager();
        void draw( SDL_Surface *Screen, bool IsInMenu );
        void Update( SDL_Rect PlayerPos, SDL_Rect EnemyPos, int CollY, int currentLevel );
        void UpdateAlt( int AltChangeStart, int AltChangeEnd, int AltChange );
        int returnAffectedObj();
        int returnType();
        int returnTimesCollected();

    private:
        Item Item1;
        int currentItem;
};

#endif

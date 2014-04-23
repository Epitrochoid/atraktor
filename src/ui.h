#ifndef UI_H
#define UI_H

#include <SDL/SDL.h>
#include "state.h"

class UIElement {
    public:
        virtual ~UIElement();
	virtual void render(SDL_Surface*) = 0;
	virtual void update(State*) = 0;
}

#endif

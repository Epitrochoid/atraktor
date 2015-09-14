#ifndef UI_H
#define UI_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include "state.h"

enum Input {Up, Down};

// Product type of text settings available for render 
class TextSpec {
    public:
        TTF_Font* bigFont;
        TTF_Font* smallFont;
        SDL_Color textColor;
        SDL_Color bgActive;
        SDL_Color bgInactive;
        SDL_Color bgEmph;
};

// Interface for all ui elements
class UIElement {
    public:
        virtual ~UIElement();
        virtual void render(SDL_Surface*, TextSpec*) = 0;
        virtual void update(State*) = 0;
        virtual void giveFocus() = 0;
        virtual void takeFocus() = 0;
        virtual void input(Input) = 0;
};

class UIPlayback: public UIElement {
    public:
        UIPlayback();
        ~UIPlayback();
        void render(SDL_Surface*, TextSpec*);
        void update(State*);
        void giveFocus();
        void takeFocus();
        void input(Input);
    private:
        Playback playState;
        string name;
        SDL_Surface* nameSurface;
        SDL_Surface* playbackSurface;
};

#endif

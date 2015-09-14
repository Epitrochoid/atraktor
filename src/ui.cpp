#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include <iostream>

#include "state.h"
#include "ui.h"
#include "util.h"

// Needed for the interface
UIElement::~UIElement() = default;

UIPlayback::UIPlayback() {
    playState = Stop;
    name = "Test_0000";
    nameSurface = NULL;
    playbackSurface = NULL;
}

UIPlayback::~UIPlayback() {
}


void UIPlayback::render(SDL_Surface* screen, TextSpec* textSpec) {
    if (nameSurface == NULL) {
        nameSurface = TTF_RenderText_Shaded(textSpec->bigFont, name.c_str(), textSpec->textColor, textSpec->bgInactive);
    }
    applySurface(0, 0, nameSurface, screen);
}

void UIPlayback::update(State* state) {
    playState = state->playback;
    name = state->name;
}

void UIPlayback::giveFocus() {
}

void UIPlayback::takeFocus() {
}

void UIPlayback::input(Input action) {
}


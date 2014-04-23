#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>

#include "state.h"
#include "ui.h"

// Needed for the interface
UIElement::~UIElement() = default;

UIPlayback::UIPlayback() {
    playState = Stop;
    name = "";
}

UIPlayback::~UIPlayback() {
}


void UIPlayback::render(SDL_Surface* screen, TextSpec& textSpec) {
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


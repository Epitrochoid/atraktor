#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include "state.h"
#include "ui.h"

UIPlayback::UIPlayback() {
    playState = Stop;
    name = "";
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

void input(Input action) {
}

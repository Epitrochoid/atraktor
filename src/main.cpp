#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <iostream>

#include "ui.h"

using namespace std;

// Function prototypes
bool init();
bool load(TextSpec*);

// Globals are bad, m'kay
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

SDL_Surface *screen = NULL;
SDL_Event event;

// Program entry point
int main(int argc, char* argv[]) {
	if (init() == false) {
		return 1;
	}

	TextSpec* textspec = new TextSpec;
	if (load(textspec) == false) {
		return 1;
	}

	// Main event loop
	bool quit = false;

	while (quit == false) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_UP) {
					quit = true;
				}
			}
		}

		// Wait 5ms
		SDL_Delay(5);
	}

	delete textspec;
	SDL_FreeSurface(screen);
    SDL_Quit();
    return 0;
}

// Initializes SDL and subsystems
bool init() {
	// Try to initialize all SDL subsystems
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		cout << "Could not initialize SDL" << endl;
		return false;
	}

	// The primary drawing surface that gets flipped
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_FULLSCREEN);

	// Check that `screen` was created correctly
	if (screen == NULL) {
		cout << "Primary screen surface could not be created" << endl;
		return false;
	}
	
	// Initialize SDL_TTF
	if (TTF_Init() == -1) {
		cout << "Could not load SDL_ttf" << endl;
		return false;
	}

	// If we got here, everything worked
	return true;
}

bool load(TextSpec* textspec) {
	textspec->bigFont = TTF_OpenFont("Anonymous_Pro.ttf", 16);
	textspec->smallFont = TTF_OpenFont("Anonymous_Pro.ttf", 14);

	if (textspec->bigFont == NULL && textspec->smallFont == NULL) {
		cout << "Could not load font" << endl;
		return false;
	}

	textspec->textColor = {255, 255, 255};
	textspec->bgActive = {80, 80, 80};
	textspec->bgInactive = {0, 0, 0};
	textspec->bgEmph = {60, 60, 60};
	return true;
}


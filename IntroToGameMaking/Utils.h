#pragma once

#include <SDL.h>


const int SCREEN_WIDTH = 1270;
const int SCREEN_HEIGHT = 800;

struct Vec2 {
	float x;
	float y;
};

const Uint32 GAME_OVER_EVENT = SDL_USEREVENT + 1;
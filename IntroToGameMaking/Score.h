#pragma once

#include "Utils.h"
#include <SDL.h>
#include <SDL_ttf.h>

class Score
{
public:
	Score(SDL_Renderer* renderer, int xLoc, int yLoc);
	void Update();
	void Draw();

private:
	int score = 0;
	Vec2 pos;
	SDL_Renderer* renderer;
	SDL_Color color = { 255, 255, 255 };
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect* rect;
	
	TTF_Font* font = TTF_OpenFont("Library/Fonts/ScoreFont.ttf", 24);
	
};


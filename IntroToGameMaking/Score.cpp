#include "Score.h"
#include <iostream>
#include <string>


using namespace std;

Score::Score(SDL_Renderer* renderer, int xLoc, int yLoc)
{
	surface = TTF_RenderText_Solid(font, to_string(score).c_str(), color);
	
	this->renderer = renderer;
	
	if (!font) {
		cout << "Failed to load font: " << TTF_GetError() << endl;
	}
	pos.x = xLoc;
	pos.y = yLoc;
	
	rect = new SDL_Rect{ (int)pos.x, (int)pos.y, 50, 50 };
}

void Score::Update() {
	
	score++;

	surface = TTF_RenderText_Solid(font, to_string(score).c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);

}

void Score::Draw() {
	SDL_RenderCopy(renderer, texture, NULL, rect);
}


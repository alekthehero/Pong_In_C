#include "Score.h"
#include <iostream>
#include <string>


using namespace std;

Score::Score(SDL_Renderer* renderer, int xLoc, int yLoc)
{
	//have the text of the rendertext to be "Score: " + score
	scoreTxt = "Score: " + to_string(score);
	surface = TTF_RenderText_Solid(font, scoreTxt.c_str(), color);
	
	this->renderer = renderer;
	
	if (!font) {
		cout << "Failed to load font: " << TTF_GetError() << endl;
	}
	pos.x = xLoc;
	pos.y = yLoc;
	
	rect = new SDL_Rect{ (int)pos.x, (int)pos.y, 100, 50 };

}

void Score::Update() {
	score++;
	scoreTxt = "Score: " + to_string(score);
}

void Score::Draw() {
	surface = TTF_RenderText_Solid(font, scoreTxt.c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, texture, NULL, rect);
}


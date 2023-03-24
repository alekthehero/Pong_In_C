#pragma once

#include "Utils.h"

class Paddle
{
public:
	Paddle(int i);
	void Update();
	void SetDir(int d) { dir = d; }

	Vec2 GetPos() { return pos; }
	SDL_Rect* GetRect() { return &rect; }
	int GetId() { return id; }

private:
	int id;
	int dir = 0;
	int width = 20;
	int height = 100;
	Vec2 pos;
	float speed;
	SDL_Rect rect;
};


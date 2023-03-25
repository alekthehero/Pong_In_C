#pragma once

#include "Paddle.h"

class Ball
{
public:
	Ball();
	void Update(Paddle* leftPaddle, Paddle* rightPaddle);
	bool CollisionCheck(Paddle* paddle);
	void SetVelocity(float x, float y) { vel.x = x; vel.y = y; }

	SDL_Rect* GetRect() { return &rect; }

private:
	Vec2 pos, vel;
	int size = 20;
	float x, y, speed;
	SDL_Rect rect;
	SDL_Event gameOverEvent;
};


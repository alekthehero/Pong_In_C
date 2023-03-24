#pragma once

#include "Paddle.h"
#include "Ball.h"

class Game
{
public:
	bool Init();
	void GameLoop();
	void Shutdown();

private:
	bool isRunning = true;

	void HandleEvents();
	void Update();
	void Draw();

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	class Paddle* leftPaddle, * rightPaddle;
	class Ball* ball;
};


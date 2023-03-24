#include "Game.h"

bool Game::Init() {
	//Init SDL Check
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	//Create window and check if created
	window = SDL_CreateWindow("PONG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (!window) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	//Create Renderer and check if created
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	/// Init of Paddles
	leftPaddle = new Paddle(0);
	rightPaddle = new Paddle(1);

	/// Init Ball
	ball = new Ball();

	return true;
}

void Game::GameLoop() {
	while (isRunning) {
		HandleEvents();
		Update();
		Draw();
	}
}

void Game::HandleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}

	const Uint8* keyStates = SDL_GetKeyboardState(NULL);

	if (keyStates[SDL_SCANCODE_ESCAPE]) {
		isRunning = false;
	}

	///Paddle movement
	leftPaddle->SetDir(0);
	rightPaddle->SetDir(0);
	//Left
	if (keyStates[SDL_SCANCODE_W]) {
		leftPaddle->SetDir(-1);
	}
	if (keyStates[SDL_SCANCODE_S]) {
		leftPaddle->SetDir(1);
	}
	//Right
	if (keyStates[SDL_SCANCODE_UP]) {
		rightPaddle->SetDir(-1);
	}
	if (keyStates[SDL_SCANCODE_DOWN]) {
		rightPaddle->SetDir(1);
	}
}

void Game::Update() {
	leftPaddle->Update();
	rightPaddle->Update();

	ball->Update(leftPaddle, rightPaddle);
}

void Game::Draw() {
	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
	SDL_RenderClear(renderer);

	///Draw Paddles
	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	SDL_RenderFillRect(renderer, leftPaddle->GetRect());
	SDL_RenderFillRect(renderer, rightPaddle->GetRect());

	///Draw Ball
	SDL_SetRenderDrawColor(renderer, 200, 100, 100, 255);
	SDL_RenderFillRect(renderer, ball->GetRect());


	SDL_RenderPresent(renderer);
}

void Game::Shutdown() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
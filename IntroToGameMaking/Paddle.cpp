#include "Paddle.h"

Paddle::Paddle(int i) {
	id = i;
	speed = 10.0f;
	
	if (id == 0) {
		pos.x = 20;
		pos.y = SCREEN_HEIGHT / 2 - height / 2;
	}
	else if (id == 1) {
		pos.x = SCREEN_WIDTH - width - 20;
		pos.y = SCREEN_HEIGHT / 2 - height / 2;
	}

	rect.x = (int)pos.x;
	rect.y = (int)pos.y;
	rect.w = width;
	rect.h = height;
}

void Paddle::Update() {
	//set init y
	pos.y += speed * dir;

	//set bounds 
	if (pos.y < 0) {
		pos.y = 0;
	}
	else if (pos.y + height > SCREEN_HEIGHT) {
		pos.y = SCREEN_HEIGHT - height;
	}

	rect.y = pos.y;
}
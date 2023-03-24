#include "Ball.h"
#include <iostream>
using namespace::std;

Ball::Ball() {
	speed = 6.5f;

	pos.x = SCREEN_WIDTH / 2 - size / 2;
	pos.y = SCREEN_HEIGHT / 2 - size / 2;

	vel.x = 1;
	vel.y = 1;

	rect.x = (int)pos.x;
	rect.y = (int)pos.y;
	rect.w = size;
	rect.h = size;
}

void Ball::Update(Paddle* leftPaddle, Paddle* rightPaddle) {
	//Set init pos related to vel
	pos.x += vel.x * speed;
	pos.y += vel.y * speed;

	//Constrain the ball
	if (pos.y < 0) {
		pos.y = 0;
		vel.y *= -1;
	}
	else if (pos.y + size > SCREEN_HEIGHT) {
		pos.y = SCREEN_HEIGHT - size;
		vel.y *= -1;
	}

	//Check if collision with paddle
	if (CollisionCheck(leftPaddle)) {
		vel.x *= -1;
	}
	else if (CollisionCheck(rightPaddle)) {
		vel.x *= -1;
	}
	
	rect.x = (int)pos.x;
	rect.y = (int)pos.y;
}

bool Ball::CollisionCheck(Paddle* paddle) {
	//!!!!!Error here !!!!! The collision detection dups when ball hits end of paddle and not the face.
	if (pos.x + size >= paddle->GetPos().x && //Right ball -> left paddle
		pos.x <= paddle->GetPos().x + paddle->GetRect()->w && //Left ball -> right paddle
		pos.y + size >= paddle->GetPos().y && //Bottom ball -> top paddle
		pos.y <= paddle->GetPos().y + paddle->GetRect()->h) {//Top ball -> bottom paddle
		//Collistion
		cout << "Collision" << endl;
		return true;
	}
	else {
		return false;
	}
}

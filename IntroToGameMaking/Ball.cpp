#include "Ball.h"
#include <iostream>
using namespace::std;

Ball::Ball() {
	speed = 7.f;

	pos.x = SCREEN_WIDTH / 2 - size / 2;
	pos.y = SCREEN_HEIGHT / 2 - size / 2;

	vel.x = 1;
	vel.y = 1;

	rect.x = (int)pos.x;
	rect.y = (int)pos.y;
	rect.w = size;
	rect.h = size;

	//Events
	
}

void Ball::Update(Paddle* leftPaddle, Paddle* rightPaddle) {
	//Set the init win state
	winState = 0;
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
	
	//Check if the ball is out of bounds on the x axis
	if (pos.x < 0) {
		//Send the game over event for right side player win
		winState = 2;
		ResetBall();
	}
	else if (pos.x + size > SCREEN_WIDTH) {
		//Send the game over event left side player win
		winState = 1;
		ResetBall();
		
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
		//Keep the ball outside the collider
		if (paddle->GetId() == 0) {
			pos.x = paddle->GetPos().x + paddle->GetRect()->w;
		}
		else if (paddle->GetId() == 1) {
			pos.x = paddle->GetPos().x - size;
		}
		return true;
	}
	else {
		return false;
	}
}

void Ball::ResetBall() {
	pos.x = SCREEN_WIDTH / 2 - size / 2;
	pos.y = SCREEN_HEIGHT / 2 - size / 2;

	vel.x = rand() % 2 == 0 ? 1 : -1;
	vel.y = rand() % 2 == 0 ? 1 : -1;

	rect.x = (int)pos.x;
	rect.y = (int)pos.y;
}

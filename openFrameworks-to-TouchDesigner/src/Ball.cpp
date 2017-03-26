#include "Ball.h"
#include <vector>

// define movement parameters
#define SPRING 0.05
#define GRAVITY 0.03
#define FRICTION  -0.9


Ball::Ball() {
}

// ball setup function
void Ball::setup(int idin, vector<Ball> *oin)
{
	x = ofRandom(RES_X);
	y = ofRandom(RES_Y);
	diameter = ofRandom(30, 70);
	id = idin;
	others = oin;
}

// function to check for ball collisions against other balls
void Ball::collide() {
	for (int i = id + 1; i < NUM_BALLS; i++) {
		float dx = others->at(i).x - x;
		float dy = others->at(i).y - y;
		float distance = sqrt(dx*dx + dy*dy);
		float minDist = others->at(i).diameter / 2 + diameter / 2;
		if (distance < minDist) {
			float angle = atan2(dy, dx);
			float targetX = x + cos(angle) * minDist;
			float targetY = y + sin(angle) * minDist;
			float ax = (targetX - others->at(i).x) * SPRING;
			float ay = (targetY - others->at(i).y) * SPRING;
			vx -= ax;
			vy -= ay;
			others->at(i).vx += ax;
			others->at(i).vy += ay;
		}
	}
}

// function to move the ball every frame
void Ball::move() {
	float gravity = 0.03;
	float friction = -0.9;

	int resX = RES_X;
	int resY = RES_Y;

	vy += gravity;
	x += vx;
	y += vy;
	if (x + diameter/2 > resX) {
		x = resX - diameter/2;
		vx *= friction;
	}
	else if (x - diameter/2 < 0) {
		x = diameter/2;
		vx *= friction;
	}
	if (y + diameter/2 > resY) {
		y = resY - diameter/2;
		vy *= friction;
	}
	else if (y - diameter/2 < 0) {
		y = diameter/2;
		vy *= friction;
	}
}





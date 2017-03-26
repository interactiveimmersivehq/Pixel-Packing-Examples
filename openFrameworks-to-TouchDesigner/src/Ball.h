#pragma once
#include "ofMain.h"
#include <vector>

using namespace std;

// define the number of balls and screen size
#define NUM_BALLS 12
#define RES_X 1280
#define RES_Y 720

class Ball
{
public:
	Ball();

	// variables needed per ball
	float x, y;
	float diameter;
	float vx;
	float vy;
	int id;
	std::vector<Ball> *others;

	// variables needed for collision detection
	float dx;
	float dy;
	float distance;
	float minDist;
	float angle;
	float targetX;
	float targetY;

	// ball functions
	void collide();
	void setup(int idin, vector<Ball> *oin);
	void move();

};


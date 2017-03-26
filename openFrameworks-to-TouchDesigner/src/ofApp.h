#pragma once

#include "ofMain.h"
#include "ofxSpout.h"
#include "Ball.h"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void draw();
	void exit();

	// function to create a vec4 from a 32bit value
	ofVec4f pixelPacker(float val);

	// list of balls and a temp ball for setup
	std::vector <Ball> ball_vec;
	Ball tempBall;

	// textures for writing data to
	ofTexture screen_tex;

	// variables to navigate the ofPixels
	int i;
	int spoutX;
	int spoutY;
	int row;
	int col;

	// vec4s that get written to before data transmission
	ofVec4f ballX;
	ofVec4f ballY;
	ofVec4f ballD;

};

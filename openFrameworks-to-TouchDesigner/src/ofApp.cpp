#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowTitle("nVoid oF to TouchDesigner");
	ofSetFrameRate(60);

	// disables the blending, or multiplication, of alpha with the r,g, and b channels
	ofDisableAlphaBlending();

	// background set to transparent
	ofBackground(0,0,0,0);

	// set size of spout texture
	spoutX = 16;
	spoutY = 4;

	// allocate memory and initialize the vector of ball objects
	ball_vec.reserve(NUM_BALLS);
	for (int i = 0; i < NUM_BALLS; i++) {
		tempBall.setup(i, &ball_vec);
		ball_vec.push_back(tempBall);
	}


	// initialize Spout with a sender name, and a texture size
	ofxSpout::init("oF to TouchDesigner", screen_tex, ofGetWidth(), ofGetHeight(), true);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	
	// init sender if it's not already initialized
	ofxSpout::initSender();

	// iterate through balls to check for collisions and move accordingly, and draw the data for spout
	for (int i = 0; i < NUM_BALLS; i++) {
		ball_vec[i].collide();
		ball_vec[i].move();

		// set up data to be written to spout texture
		// balls x values
		row = 0;
		col = ball_vec[i].id;
		ballX = pixelPacker(ball_vec[i].x);
		ofSetColor(ballX.x, ballX.y, ballX.z, ballX.w);
		ofFill();
		ofDrawRectangle(col, row, 1, 1);

		// balls y values
		row = 1;
		col = ball_vec[i].id;
		ballY = pixelPacker(ball_vec[i].y);
		ofSetColor(ballY.x, ballY.y, ballY.z, ballY.w);
		ofFill();
		ofDrawRectangle(col, row, 1, 1);

		// balls diameter
		row = 2;
		col = ball_vec[i].id;
		ballD = pixelPacker(ball_vec[i].diameter);
		ofSetColor(ballD.x, ballD.y, ballD.z, ballD.w);
		ofFill();
		ofDrawRectangle(col, row, 1, 1);

	}

	// send screen to Spout
	ofxSpout::sendTexture();

}

//--------------------------------------------------------------
// this helper function uses bit shifting to take a single 32-bit float
// and convert it into four 8-bit values and returned as an ofVec4f

ofVec4f ofApp::pixelPacker(float val) {
	// bit shift val into 4 8-bit values
	int num = int(val);
	int r = (num >> 0) & 255;
	int g = (num >> 8) & 255;
	int b = (num >> 16) & 255;
	int a = (num >> 24) & 255;

	// the RGBA chans are used to return a color for the fill
	return ofVec4f(r, g, b, a);
}

//--------------------------------------------------------------
void ofApp::exit()
{
	// exit spout
	ofxSpout::exit();
}


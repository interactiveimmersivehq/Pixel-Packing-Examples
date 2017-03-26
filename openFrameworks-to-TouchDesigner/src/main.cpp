#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main()
{
	// set window size to be same as spout texture
	ofSetupOpenGL(114, 4, OF_WINDOW);
	ofRunApp(new ofApp());
}

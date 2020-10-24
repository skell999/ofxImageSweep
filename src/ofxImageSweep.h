#pragma once

#include "ofMain.h"
#include <math.h> 

class ofxImageSweep
{
public:
	ofxImageSweep();
	~ofxImageSweep();

	void allocate(int width, int height);
	void update(const ofTexture& texture, float width, float pos);
	void draw(int x, int y);
	ofFbo& getFbo();
	ofShader& getShader();
	bool copyShaderToBin(); // Make bin folder portable


private:
	ofShader shader;
	ofFbo fbo;
};

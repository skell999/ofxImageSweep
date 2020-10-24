#include "ofxImageSweep.h"

ofxImageSweep::ofxImageSweep()
{
}

ofxImageSweep::~ofxImageSweep()
{
}

void ofxImageSweep::allocate(int width, int height)
{
	fbo.allocate(width, height);
	shader.load("../../../../../addons/ofxImageSweep/src/shader/ImageSweep");
}

void ofxImageSweep::update(const ofTexture& texture, float width, float pos)
{
	fbo.begin();

	shader.begin();
	shader.setUniformTexture("image", texture, 1);
	shader.setUniform2f("resolution", fbo.getWidth(), fbo.getHeight());
	shader.setUniform1f("width", width);
	shader.setUniform1f("pos", pos);

	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawPlane(ofGetWidth(), ofGetHeight());
	ofPopMatrix();

	shader.end();

	fbo.end();
}

void ofxImageSweep::draw(int x, int y)
{
	fbo.draw(x, y);
}

ofFbo& ofxImageSweep::getFbo()
{
	return fbo;
}

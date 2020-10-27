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

	copyShaderToBin();

	shader.load("ofxImageSweepShader/ImageSweep");

}

void ofxImageSweep::update(const ofTexture& texture, const ofTexture& posMap, float divX, float divY, float posX, float posY, bool flipX, bool flipY, bool sliceX, bool sliceY)
{
	fbo.begin();

	shader.begin();
	shader.setUniformTexture("image", texture, 1);
	shader.setUniformTexture("posMap", posMap, 2);
	shader.setUniform2f("resolution", fbo.getWidth(), fbo.getHeight());
	shader.setUniform1f("divX", divX);
	shader.setUniform1f("posX", posX);
	shader.setUniform1f("divY", divY);
	shader.setUniform1f("posY", posY);
	shader.setUniform1i("flipX", flipX);
	shader.setUniform1i("flipY", flipY);
	shader.setUniform1i("sliceX", sliceX);
	shader.setUniform1i("sliceY", sliceY);

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

ofShader& ofxImageSweep::getShader()
{
	return shader;
}

bool ofxImageSweep::copyShaderToBin()
{
	ofDirectory dir;

	bool result = true;
	if (!dir.doesDirectoryExist("ofxImageSweepShader")) {
		if (!dir.createDirectory("ofxImageSweepShader"))
		{
			cout << "Create Directory ofxImageSweepShader FAILED" << endl;
			result = false;
		}
	}

	if (!ofFile::copyFromTo("../../../../../addons/ofxImageSweep/src/shader/ImageSweep.vert", "ofxImageSweepShader/ImageSweep.vert",true,true) && !result)
	{
		cout << "Copy ImageSweep.vert FAILED" << endl;
		result = false;
	}

	if (!ofFile::copyFromTo("../../../../../addons/ofxImageSweep/src/shader/ImageSweep.frag", "ofxImageSweepShader/ImageSweep.frag",true,true) && !result)
	{
		cout << "Copy ImageSweep.frag FAILED" << endl;
		result = false;
	};

	return result;
}

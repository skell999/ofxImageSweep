#pragma once

#include "ofMain.h"
#include <math.h> 

class ofxImageSweep
{
public:
	ofxImageSweep();
	~ofxImageSweep();

	void allocate(int width, int height);
	/**
	 * @brief Applies the image sweep effect to an image
	 * @param texture: The image that will be sliced
	 * @param posMap: A black and white image that controls the position in the x direction
	 * @param divX: Number of slices in the x direction 
	 * @param divY: Number of slices in the y direction  
	 * @param posX: Scan position in the x direction 
	 * @param posY: Scan position in the y direction 
	 * @param bool flipX: Create symmetry in the x direction by flipping every second slice 
	 * @param bool flipY: Create symmetry in the y direction by flipping every second slice 
	 * @param bool sliceX: Enable slices in the x direction 
	 * @param bool sliceY: Enable slices in the y direction 
	*/
	void update(const ofTexture& texture, const ofTexture& posMap, float divX, float divY, float posX, float posY, bool flipX, bool flipY, bool sliceX, bool sliceY);
	/**
	 * @brief Draws the internal fbo
	*/
	void draw(int x, int y);
	ofFbo& getFbo();
	ofShader& getShader();
	bool copyShaderToBin(); // Make bin folder portable


private:
	ofShader shader;
	ofFbo fbo;
};

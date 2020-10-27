# ofxImageSweep
Image sweep takes an image as input and slices it into a small strip with repeating symmetry. 

<img src="https://github.com/skell999/ofxImageSweep/blob/main/images/0.png" width="512" height="384" />

<img src="https://github.com/skell999/ofxImageSweep/blob/main/images/3.png" width="512" height="384" />

<img src="https://github.com/skell999/ofxImageSweep/blob/main/images/4.png" width="512" height="384" />

<img src="https://github.com/skell999/ofxImageSweep/blob/main/images/5.png" width="512" height="384" />

<img src="https://github.com/skell999/ofxImageSweep/blob/main/images/6.png" width="512" height="384" />

<img src="https://github.com/skell999/ofxImageSweep/blob/main/images/7.png" width="512" height="384" />

<img src="https://github.com/skell999/ofxImageSweep/blob/main/images/8.png" width="512" height="384" />

<img src="https://github.com/skell999/ofxImageSweep/blob/main/images/9.png" width="512" height="384" />

<img src="https://github.com/skell999/ofxImageSweep/blob/main/images/10.png" width="512" height="384" />

## Basic usage

Create an instance of ofImage and ofxImageSweep
```cpp
ofImage image;
ofImage positionMap;
ofxImageSweep sweep;
```

Load an image and initialize ofxImageSweep
```cpp
void ofApp::setup(){
  image.load("yourPic.jpg");
  positionMap.load("map.jpg"); // A black and white image that controls the position in the x direction
  sweep.allocate(ofGetWidth(),ofGetHeight());
}
```

In your update function
```cpp
void ofApp::update(){
  float divX = 6; // Amount of x slices
  float divY = 6; // Amount of y slices
  float posX = 100; // Scan position x
  float posY = 100; // Scan position y
  bool flipX = true; // Enable x symmetry
  bool flipY = true; // Enable y symmetry
  bool sliceX = true; // Enable x slice
  bool sliceY = true; // Enable y slice
  sweep.update(image.getTexture(), positionMap.getTexture(), divX, divY, posX, posY, flipX, flipY, sliceX, sliceY);
}
```

Draw the image
```cpp
void ofApp::draw(){
  sweep.draw(0, 0);
}
```

## Animation

```cpp
void ofApp::update(){
  float speed = 6;
  float position = ofGetElapsedTimef() * speed;

  float divX = 6; // Amount of x slices
  float divY = 6; // Amount of y slices

  float posX = position; // Scan position x
  float posY = position; // Scan position y

  bool flipX = true; // Enable x symmetry
  bool flipY = true; // Enable y symmetry

  bool sliceX = true; // Enable x slice
  bool sliceY = true; // Enable y slice

  sweep.update(image.getTexture(), positionMap.getTexture(), divX, divY, posX, posY, flipX, flipY, sliceX, sliceY);
```

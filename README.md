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
ofxImageSweep sweep;
```

Load an image and initialize ofxImageSweep
```cpp
void ofApp::setup(){
  image.load("yourPic.jpg");
  sweep.allocate(ofGetWidth(),ofGetHeight());
}
```

In your update function
```cpp
void ofApp::update(){
  float width = 64; // Slice width
  float pos = 400; // Slice position
  sweep.update(image.getTexture(), width, pos);
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
  float width = 64;
  float speed = 6;
  sweep.update(image.getTexture(), width, ofGetElapsedTimef() * speed);
}
```

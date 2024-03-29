#pragma once

#include "ofMain.h"
#include "Defines.h"
#include "ofxOsc.h"
#include "ofxUI.h"
#include "ofxSyphon.h"
#include "Tracker.h"

class ofxContentScene {
    
public:
    
    ofxContentScene(){}
    virtual ~ofxContentScene(){};
    
    ofxSyphonClient * syphonIn;
    ofxUICanvas* gui;
    ofxSyphonServer syphonOut;
    
    TTracker * tracker;
    
    vector<ofxOscSender *> oscClients;
    
    int index;
    string name;
    string oscAddress = "/default";
    
    ofFbo fbo;
    bool enabled;
    bool solo = true;
    float opacity;
    float speed;
    
    int width;
    int height;
    int numSamples = 4;
    
    virtual void init();
    virtual void setup();
    virtual void update();
    virtual void draw();
    virtual void exit();
    virtual void setGui();
    virtual void parseOscMessage(ofxOscMessage * m);
    
    void guiEvent(ofxUIEventArgs &e);
    void setSceneGui();
    void addSlider();
    void checkMsg();
    void parseSceneOscMessage(ofxOscMessage * m);
    void setupScene(int _width, int _height, int _i);
    void updateScene();
    void drawScene();
    
    void publishSyphonTexture(bool force=false);
    
};

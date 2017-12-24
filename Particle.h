#pragma once
#include "ofMain.h"

class Particle {
public:
	Particle(ofVec3f center, float r, ofColor color);
	~Particle() {};
	void update();
	void draw();
	ofVec3f getLocation();
	bool isDead();
	ofColor getColor();
private:
	ofVec3f location;
	ofVec3f velocity;
	ofVec3f mycenter;
	float myradius;
	float myweight;
	ofColor mycolor;
	float myalp;
	float phi;
	float vphi;
	float unitz;
	float vunitz;
	bool plus;
	float mynoise;
};
#include "Particle.h"

Particle::Particle(ofVec3f center, float r, ofColor color) {
	this->mycenter = center;
	this->myradius = r;
	this->mycolor = color;
	//todo
	this->myalp = 255;
	this->plus = ofRandom(100) > 49 ? true : false;
	this->myweight = ofRandom(1, 3);
	this->phi = ofRandom(TWO_PI);
	this->unitz = ofRandom(-1.0, 1.0);
	float x = this->mycenter.x + this->myradius * sqrt(1 - this->unitz * this->unitz) * cos(this->phi);
	float y = this->mycenter.y + this->myradius * sqrt(1 - this->unitz * this->unitz) * sin(this->phi);
	float z = this->mycenter.z + this->myradius * this->unitz;
	this->location = ofVec3f(x, y, z);
	//todo
	this->mynoise = ofNoise(ofRandom(255));
}
void Particle::update() {
	int pm = this->plus ? 1 : -1;
	this->phi += ofGetFrameNum() * 0.0001 * pm;
	if (this->phi > TWO_PI) {
		this->phi = 0;
	}
	else if (this->phi < 0) {
		this->phi = TWO_PI;
	}
	this->unitz += ofGetFrameNum() * 0.00001 * pm;
	if (unitz > 1.0) {
		unitz = -1.0;
	}
	else if (unitz < -1.0) {
		unitz = 1.0;
	}
	float x = this->mycenter.x + this->myradius * sqrt(1 - this->unitz * this->unitz) * cos(this->phi);
	float y = this->mycenter.y + this->myradius * sqrt(1 - this->unitz * this->unitz) * sin(this->phi);
	float z = this->mycenter.z + this->myradius * this->unitz;
	this->location = ofVec3f(x, y, z);
	//todo
	this->myalp -= 0.001;
}
void Particle::draw() {
	ofSetColor(this->mycolor, this->myalp);
	ofPushMatrix();
	ofTranslate(this->location);
	ofDrawSphere(this->myweight);
	ofPopMatrix();
}
ofVec3f Particle::getLocation() {
	return this->location;
}
bool Particle::isDead() {
	return this->myalp < 0;
}
ofColor Particle::getColor() {
	return this->mycolor;
}
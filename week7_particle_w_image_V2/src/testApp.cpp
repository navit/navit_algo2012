#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    spot.loadImage("HAZE.png");
	
	for (int i = 0; i < 200; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		myParticle.img = &spot;
        //myParticle.img1 = &spot1;
		particles.push_back(myParticle);	
	}


	bRepel		= true;
	radius		= 40;
	strength	= 0.05f;
      	

		
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		
		particles[i].addAttractionForce(mouseX, mouseY, 1000, 0.4);
		
	
		for (int j = 0; j < i; j++){
			if (bRepel){
				particles[i].addRepulsionForce(particles[j], radius, strength);
			} else {
				particles[i].addAttractionForce(particles[j], radius, strength);
			}
		}
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addDampingForce();
		particles[i].update();
	}
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	ofSetRectMode(OF_RECTMODE_CENTER);
	

    
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	ofSetRectMode(OF_RECTMODE_CORNER);
	//drawing interactions
	string reportString =	"(space) = reset\n(a/s) strength = " + ofToString(strength) + 
							"\n(z/x) radius = " + ofToString(radius) +
							"\n(r) toggle mode = " + (bRepel ? "repelling" : "attracting" );
	
	ofSetColor(90,65,255);
    ofSetLineWidth(1);
	ofRect(10,10,300,80);
	ofSetColor(56,65,255);
	ofDrawBitmapString(reportString, 30, 30);
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	//creating interactions
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
		case 'a':
			strength += 0.02f;
			break;
		case 's':
			strength -= 0.02f;
			if (strength <= 0) strength = 0.02f;
			break;
		case 'z':
			radius += 5.0f;
			break;
		case 'x':
			radius -= 5.0f;
			if (radius <= 0) radius = 5.0f;
			break;
		case 'r':
			bRepel = !bRepel;
			break;
    
	}
	
    if(key=='f' || key=='F'){
        ofToggleFullscreen();
    }
    
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	particles.erase(particles.begin());
	particle myParticle;
	myParticle.img = &spot;
    //myParticle.img1 = &spot1; //pass the reference of the second image
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}

#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(20);
	n=1;
    
	bRepel		= true;
	radius		= 20;
	strength	= 0.5f;
    
    //panel
//	panel.setup("control", 770, 0, 300, 400);
//	panel.addPanel("color", 1, false);
//	
//	panel.addPanel("geometry", 1, false);
//	
//	panel.setWhichPanel("color");
//	panel.setWhichColumn(0);
//	panel.addSlider("red", "VAL_RED", 0,0,255, false);
//	panel.addSlider("green", "VAL_GREEN", 0,0,255, false);
//	panel.addSlider("blue", "VAL_BLUE",0,0,255, false);
//	
//	panel.setWhichPanel("geometry");
//	
//	panel.addToggle("rect", "VAL_RECT", true);
//	
//	panel.loadSettings("settings.xml");
	
	
}

//--------------------------------------------------------------
void testApp::update(){
    
    n++;
    
    if(n<100)
    {
     
//    for (int i = 0; i < n; i++){
//		particle myParticle;
//		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
//		particles.push_back(myParticle);
//	}
    
                   for (int y = 0; y < n; y++){
                       particle myParticle;
                       myParticle.setInitialCondition(ofRandom(ofGetWidth()/2-40,ofGetWidth()/2+40),ofRandom(ofGetHeight()/2-40,ofGetHeight()/2+40),0,0);
                       particles.push_back(myParticle);
                   }
    }
    else{
        n=0;
       
    }

	// on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		
		particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.02);//the bigger the number the bigger the repulsion.
		
		for (int j = 0; j < i; j++){
			particles[i].addRepulsionForce(particles[j], 50, 0.4);
			particles[i].addAttractionForce(particles[j], 500, 0.005);
		}
		for (int j = 0; j < i; j++){
			if (bRepel){
				particles[i].addRepulsionForce(particles[j], radius, strength);
			} else {
				particles[i].addAttractionForce(particles[j], radius, strength);
			}		}
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addDampingForce();
		particles[i].update();
	}
    
    //panel.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	
	ofSetColor(0x000000);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	string reportString =	"(space) = reset\n(a/s) strength = " + ofToString(strength) + 
							"\n(z/x) radius = " + ofToString(radius) + 
							"\n(r) toggle mode = " + (bRepel ? "repelling" : "attracting");
	
	ofSetColor(40,40,0);
	ofRect(10,10,300,80);
	ofSetColor(255,255,255);
	ofDrawBitmapString(reportString, 30, 30);
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
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
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);
    
    //panel.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    particles.clear();
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
    //panel.mouseReleased();
}

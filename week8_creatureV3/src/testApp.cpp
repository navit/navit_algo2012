#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	particle p0;
	p0.setInitialCondition(400,400,0,0);
	particles.push_back(p0);
	
    particle p1;
	p1.setInitialCondition(500,400,0,0);
	particles.push_back(p1);
	
    particle p2;
	p2.setInitialCondition(400,500,0,0);
	particles.push_back(p2);

    particle p3;
	p3.setInitialCondition(500,500,0,0);
	particles.push_back(p3);
    
    particle p4;
	p4.setInitialCondition(600,500,0,0);
	particles.push_back(p4);
	

	
	spring mySpring;
		

    mySpring.distance		= (particles[0].pos-particles[1].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (particles[1]);
	springs.push_back(mySpring);
    
    mySpring.distance		= (particles[1].pos-particles[2].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (particles[2]);
	springs.push_back(mySpring);  
    
    mySpring.distance		= (particles[2].pos-particles[3].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[2]);
	mySpring.particleB = & (particles[3]);
	springs.push_back(mySpring);
    
    mySpring.distance		= (particles[3].pos-particles[4].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[3]);
	mySpring.particleB = & (particles[4]);
	springs.push_back(mySpring);
    
    //-------------------
	mySpring.distance		= (particles[0].pos-particles[2].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (particles[2]);
	springs.push_back(mySpring);
	
	mySpring.distance		= (particles[1].pos-particles[3].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (particles[3]);
	springs.push_back(mySpring);

	
    mySpring.distance		= (particles[3].pos-particles[4].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[3]);
	mySpring.particleB = & (particles[4]);
	springs.push_back(mySpring);

	
}

//--------------------------------------------------------------
void testApp::update(){
    
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
    
	springs[1].distance = 50+100 * sin(ofGetElapsedTimef());
	springs[2].distance = 50+100 * sin(ofGetElapsedTimef()+ PI);
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addForce(0,0.1f);
		particles[i].addRepulsionForce(mouseX, mouseY, 300, 0.7f);
        
        for(int j = 0; j<particles.size(); j++){
            particles[3].addAttractionForce(mouseX, mouseY, 800, 3);
            particles[0].addRepulsionForce(particles[0], 800, 2);
            //particles[1].addRepulsionForce(mouseX, ofGetHeight(), 800, 2);
           
        }
	}
    
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
//    for(int i=0; i<particles.size(); i++){
//        particles[i].draw();
//    }
    
    ofSetColor(255,173,0);
    ofBeginShape();
    ofVertex(particles[0].pos.x, particles[0].pos.y);
    ofCircle(particles[0].pos.x, particles[0].pos.y, 2);
    ofVertex(particles[1].pos.x, particles[1].pos.y);
    ofCircle(particles[1].pos.x, particles[1].pos.y, 2);
    ofVertex(particles[2].pos.x, particles[2].pos.y);
    ofCircle(particles[2].pos.x, particles[2].pos.y, 2);
    ofEndShape();
    ofBeginShape();
    ofVertex(particles[4].pos.x, particles[4].pos.y);
    ofCircle(particles[4].pos.x, particles[4].pos.y, 2);
    ofVertex(particles[3].pos.x, particles[3].pos.y);
    ofCircle(particles[3].pos.x, particles[3].pos.y, 2);
    ofVertex(particles[2].pos.x, particles[2].pos.y);
    ofCircle(particles[2].pos.x, particles[2].pos.y, 2);
    ofEndShape();
    ofEndShape();

    ofSetColor(255,173,0);
    ofCircle(particles[2].pos.x, particles[2].pos.y, 6);

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
	particles[0].pos.set(mouseX, mouseY);
	/*particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);*/
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
	particles[0].bFixed = false;
}


#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
    //size = 5;
    lead = 6;
    color.set(255,255,255);
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 8; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(500,550),ofRandom(500,550),0,0);
		particles.push_back(myParticle);
	}
    
    //creating more points
//    particle *p1 = new particle();
//    particle *p2 = new particle();
//    particle *p3 = new particle();
//    particle *p4 = new particle();
//     
	
	
	for (int i = 0; i < (particles.size()); i++){//the last one has no attachment -1
		spring mySpring;
		mySpring.distance		= 80;
		mySpring.springiness	= 0.2f;
		mySpring.particleA = & (particles[i]);
		mySpring.particleB = & (particles[(i+1)%particles.size()]);
		springs.push_back(mySpring);
	}
   
	//particles[particles.size()-1].bFixed = true;
    
   
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
	
	
	//for (int i = 0; i < particles.size(); i++){ //gravity force
		//particles[i].addForce(0,0.1);
	//}
	 
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
        particles[i].bounceOffWalls();
		particles[i].addDampingForce();
        //particles[i].addAttractionForce(mouseX, mouseY, lead, 0.1);
		particles[i].update();
	}
	
	trail.push_back(particles[50].pos);
	if (trail.size() > 150){
		trail.erase(trail.begin());	
	}

    
}


//--------------------------------------------------------------
void testApp::draw(){
	//color variables
//    
//    float distance = ofDist(pos.x,pos.y,ofGetWidth()/2,ofGetHeight()/2);
//    float sat = ofMap(distance,0,ofGetWidth()/4,100,250,true);
//    float brightness = ofMap(distance,ofGetWidth()/2,ofGetWidth()/2,100,180,true);
//    color = ofColor::fromHsb(sat,brightness,250);

    
    float Nx = pos.x - prevPos.x;
    float Ny = pos.y - prevPos.y;
    
    float angle = atan2(Nx, Ny)+ PI;
    
	for (int i = 0; i < particles.size(); i++){
		//particles[i].draw();
        ofPushMatrix();
        ofBeginShape();
        //ofSetColor(35,35,35);
        ofTranslate(0,0);
        ofRotateZ(angle * RAD_TO_DEG);
        ofVertex(particles[0].pos.x, particles[0].pos.y);
        ofVertex(particles[1].pos.x, particles[1].pos.y);
        ofVertex(particles[2].pos.x, particles[2].pos.y);
        ofVertex(particles[3].pos.x, particles[3].pos.y);
        ofVertex(particles[4].pos.x, particles[4].pos.y);
        ofVertex(particles[5].pos.x, particles[5].pos.y);
        ofEndShape();
        ofPopMatrix();
        //eyes
        ofPopMatrix();
        ofBeginShape();
        ofSetColor(10,207,0);
        ofTranslate(0,0);
        ofCircle(particles[0].pos.x, particles[0].pos.y, 8);
        ofCircle(particles[1].pos.x, particles[1].pos.y, 8);
        ofEndShape();
        ofPopMatrix();
        //eye balls
        ofPushMatrix();
        ofSetColor(20,20,20);
        ofBeginShape();
        ofTranslate(0, 0);
        ofCircle(particles[0].pos.x, particles[0].pos.y, 4);
        ofCircle(particles[1].pos.x, particles[1].pos.y,4);
        ofEndShape();
        ofPopMatrix();
        //tail
        ofPushMatrix();
        ofSetColor(50,30,120);
        ofBeginShape();
        ofTranslate(0,0);
        ofEllipse(particles[4].pos.x, particles[4].pos.y,10,10);
        ofEndShape();
        ofPopMatrix();
    
    }
    
    
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}
    
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

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	particles[0].bFixed = false;
}


#include "testApp.h"
//creating a new spring.
void testApp::makeSpring(particle * P1, particle * P2){
    
    spring mySpring;
    mySpring.distance = (P1->pos - P2->pos).length();//distance
    mySpring.springiness = 0.13;//the force of the spring
    mySpring.particleA = P1;
    mySpring.particleB = P2;
    
    mySpring.PrevDistance = mySpring.distance;
    
    springs.push_back(mySpring);
   
    
    
    
    
    
}
//--------------------------------------------------------------
void testApp::setup(){	
    ofBackground(0,0,0);
	ofSetVerticalSync(true);
	ofSetFrameRate(150);
	ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    
    ofSetBackgroundAuto(false);
  
	
    radius = 80;
    secRadius = radius + 0.1;
    
    float xorig = ofGetMouseX();
	float yorig = ofGetMouseY();
    
    angle = ofGetElapsedTimef() *40;
    
    particle * P1 = new particle();
    P1->setInitialCondition(pos.x, pos.y, 0, 0);
    particles.push_back(P1);
    
    particle * P2 = new particle();
    P2->setInitialCondition(pos.x, pos.y, 0, 0);
    particles.push_back(P2);
    
    for(int i = 0; i < 30; i++){
        particle * firstParticle = new particle();
        float x = pos.x + radius * -cos(angle);
        float y = pos.y + radius * sin(angle);
        firstParticle->setInitialCondition(x,y,0,0);
        particles.push_back(firstParticle);
        
        makeSpring(P1, firstParticle);
     

        
//        for(int i=0; i <10; i++){
//            particle * secParticle = new particle();
//            float x1 = pos.x + radius * -cos(angle);
//            float y1 = pos.y + radius * sin(angle);
//            firstParticle->setInitialCondition(x1,y1,0,0);
//            particles.push_back(secParticle);
//            
//            makeSpring(P2, secParticle);
//
//        }
    }
}



//--------------------------------------------------------------
void testApp::update(){
    
    float muscleLength = size < 75 ? 7 : 15;
  
	for (int i = 0; i < springs.size(); i++){  //float ofMap(float value, float inputMin, float inputMax, float outputMin, float outputMax, bool clamp) {
        springs[i].distance =  springs[i].PrevDistance * 3 * ofMap(sin(ofGetElapsedTimef() + i/0.9), -1,1,0,1);
                                                                       
    }
    
    
    for (int i = 0; i < particles.size(); i++){
		particles[i]->resetForce();
	}
    
	
	for (int i = 0; i < particles.size(); i++){
		
		particles[i]->addRepulsionForce(mouseX, mouseY, 100, 0.05f); //x,  y,  radius, scale
       
        for (int j = 0; j < i; j++){
            particles[j]->addRepulsionForce(*particles[i], 20, 0.05f);
            particles[j]->addAttractionForce(*particles[i], 30, 0.7f);

		}
	}
    
    for (int i = 0; i < springs.size(); i++){
        springs[i].update();
    }
    
    for (int i = 0; i < particles.size(); i++){
		particles[i]->addDampingForce();
		particles[i]->update();
	}
    
}


//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();
	ofBackground(0,0,0,255);
   
    for (int i = 0; i < particles.size(); i++){
        ofSetColor(242,93,7,ofMap(i, 0, particles.size(), 20, 255, true));
        particles[i]->draw();
//        ofBeginShape();
//        ofVertex(particles[0]->pos.x, particles[0]->pos.y);
//        ofVertex(particles[1]->pos.x, particles[1]->pos.y);
//        ofVertex(particles[2]->pos.x, particles[2]->pos.y);
//        ofEndShape();
       
    }

    
    for (int i = 0; i < springs.size(); i++){
        float alpha = ofMap(100, 0, 0.1, 0.0, 0.8);
        ofSetColor(88,167,42,alpha);
		//springs[i].draw();
	}
}
//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i]->setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
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
	particles[0]->pos.set(mouseX, mouseY);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0]->bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	particles[0]->bFixed = false;
}


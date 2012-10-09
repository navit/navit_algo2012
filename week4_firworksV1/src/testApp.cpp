#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	ofEnableAlphaBlending();
	ofSetVerticalSync(true);
	ofSetFrameRate(50);
	
	ofBackground(0, 0, 0);
    timer =0;
	
	for (int i = 0; i < 100; i++){
		particle myParticle;
		myParticle.setInitialCondition(300,300,ofRandom(-10,10), ofRandom(-10,10));//positioning  xy and vel
		// more interesting with diversity :)
		myParticle.damping = 0.010;//ofRandom(0.001, 0.05);
		particles.push_back(myParticle);
	}
	
    hue = 0;
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
        particles[i].addForce(0.0, 0.40);
		particles[i].addDampingForce();
		//particles[i].bounceOffWalls();
		particles[i].update();
	}
    
    if ( timer > 1){ //5 sec
        ofPoint pos = ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        
        for (int i = 0; i < particles.size(); i++){
            particles[i].setInitialCondition(pos.x,pos.y,ofRandom(-10,10), ofRandom(-10,10));
            particles[i].color.setHue(hue + ofRandom(-10,10));
        }
        timer = 0;
    }
    
    timer += 1.0/ofGetFrameRate();// increament by sec.

}

//--------------------------------------------------------------
void testApp::draw(){

	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
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
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    hue = (hue + 10)%255;
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}

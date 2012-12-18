#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    //ofSetBackgroundAuto(false);
    ofBackground(0,0,0);
	ofSetVerticalSync(true);
	ofSetFrameRate(20);
	//n=1;
    
	bRepel		= true;
	radius		= 40;
	strength	= 0.5f;
    
    petri.loadImage("petridish.png");

    //starting with just one particle on the screen
    particle myParticle;
    myParticle.setInitialCondition(ofRandom(ofGetWidth()/2-40,ofGetWidth()/2+40),ofRandom(ofGetHeight()/2-40,ofGetHeight()/2+40),0,0);
    particles.push_back(myParticle);
}

//--------------------------------------------------------------
void testApp::update(){
    

//    if (timer%30==0){
//        for (int y = 0; y < life; y++){
//            particle myParticle;
//            myParticle.setInitialCondition(ofRandom(ofGetWidth()/2-40,ofGetWidth()/2+40),ofRandom(ofGetHeight()/2-40,ofGetHeight()/2+40),0,0);
//            particles.push_back(myParticle);
//        }
//    }
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
//		particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.02);//the bigger the number the bigger the repulsion.
		
		for (int j = 0; j < i; j++){
			particles[i].addRepulsionForce(particles[j], 20, 0.4);
			particles[i].addAttractionForce(particles[j], 10, 0.05);
		}
        
    }
//		for (int j = 0; j < i; j++){
//			if (bRepel){
//				particles[i].addRepulsionForce(particles[j], radius, strength);
//			} else {
//				particles[i].addAttractionForce(particles[j], radius, strength);
//			}		}
     
    for (int i = 0; i < particles.size(); i++){
        particles[i].addDampingForce();
		particles[i].update();
        
        if (particles[i].bRepro) {
            particle myParticle;
            myParticle.setInitialCondition(particles[i].pos.x,particles[i].pos.y,ofRandom(-1,1),ofRandom(-1,1));
            particles.push_back(myParticle);
        }
	}
	
    for (int i = particles.size()-1; i > 0 ; i--){
        if (!particles[i].bAlive){
            particles.erase(particles.begin()+i);
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

	ofEnableAlphaBlending();
    
    //petri.draw(0,0, 1024,836);
    	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
//	
//	string reportString =	"(space) = reset\n(a/s) strength = " + ofToString(strength) + 
//							"\n(z/x) radius = " + ofToString(radius) + 
//							"\n(r) toggle mode = " + (bRepel ? "repelling" : "attracting");
//	
//	ofSetColor(40,40,0);
//	ofRect(10,10,300,80);
//	ofSetColor(255,255,255);
//	ofDrawBitmapString(reportString, 30, 30);
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),ofRandom(-1,1),ofRandom(-1,1));
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
//	particles.erase(particles.begin());
//	particle myParticle;
//	myParticle.setInitialCondition(x,y,0,0);
//	particles.push_back(myParticle);
    
 
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //particles.clear();
}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}

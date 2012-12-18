#include "testApp.h"

// comparison routine for sort...
bool comparisonFunction(  particle * a, particle * b ) {
	return a->pos.x < b->pos.x;
}

//--------------------------------------------------------------
void testApp::setup(){
    //ofSetBackgroundAuto(false);
    //ofBackground(0,0,0);
	ofSetVerticalSync(true);
	ofSetFrameRate(20);
    
    ofTrueTypeFont::setGlobalDpi(72);
    
	Dosis.loadFont("Dosis-Book.otf", 30, true, true);
    Dosis1.loadFont("Dosis-Book.otf", 20, true, true);
	Dosis.setLineHeight(18.0f);
	Dosis.setLetterSpacing(1.037);

	
    
	bRepel		= true;
	radius		= 40;
	strength	= 0.5f;
    
    petri.loadImage("petridish.png");
    bacteria.loadImage("bacteria2.png");
   
    //starting with just one particle on the screen
    particle *myParticle = new particle();
    myParticle->setInitialCondition(ofRandom(ofGetWidth()/2-40,ofGetWidth()/2+40),ofRandom(ofGetHeight()/2,ofGetHeight()/2),0,0);
    particles.push_back(myParticle);;

    
    //using an image for a particle
    particles.push_back(myParticle);
	
    //drawingMode = 0;
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
    
    sort( particles.begin(), particles.end(), comparisonFunction );
	
	for (int i = 0; i < particles.size(); i++){
		particles[i]->resetForce();
//		particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.02);//the bigger the number the bigger the repulsion.
		
		for (int j = 0; j < i; j++){
			particles[i]->addRepulsionForce(particles[j], 15, 0.4);
			particles[i]->addAttractionForce(particles[j], 10, 0.05);
		}
        
    }
     
    for (int i = 0; i < particles.size(); i++){
        particles[i]->addDampingForce();
		particles[i]->update();
        
        if ( particles[i]->bRepro) {
            particle *myParticle = new particle();
            myParticle->setInitialCondition(particles[i]->pos.x,particles[i]->pos.y,ofRandom(-1,1),ofRandom(-1,1));
            particles.push_back(myParticle);
        }
	}
	
    for (int i = particles.size()-1; i > 0 ; i--){
        if (!particles[i]->bAlive){
            particles.erase(particles.begin()+i);
        }
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

	ofEnableAlphaBlending();
    ofSetColor(255);
    petri.draw(0,0, 1024,836);
    ofSetColor(0,175,100);
	Dosis.drawString("Bacteria Samples", 405, 90);
    Dosis1.drawString("Staphylococcus",448,120);
    //Dosis1.drawString("Bacillus typhi",448,120);
    //Dosis1.drawString("Micrococcus",450,120);
    
    	
	ofSetColor(255);
	for (int i = 0; i < particles.size(); i++){
        //if (drawingMode == 0)
        //particles[i]->draw(&bacteria);
        particles[i]->drawOne();
        //else if (drawingMode == 1)
           // particles[i]->drawOne();
	}
	
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
        case ' ':
            drawingMode = (drawingMode+1)%3;
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

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}

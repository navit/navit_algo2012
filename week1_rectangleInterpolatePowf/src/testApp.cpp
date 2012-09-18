#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(30,30,30);
	
	
	// set the "a" and "b" positions of the rectangle...
	
	myRectangle.posa.x = 50;
	myRectangle.posa.y = 50;
	myRectangle.posb.x = 600;
	myRectangle.posb.y = 50;
	myRectangle.interpolateByPct(0);	// start at 0 pct
    rectanglePct = 0;							// a variable we can alter...
    
    
    myCirlce.posa.x = 50;
    myCirlce.posa.y = 150;
    myCirlce.posb.x = 600;
    myCirlce.posb.y = 150;
    myCirlce.interpolateByPct(0);	// start at 0 pct
    circlePct = 0;
}
//--------------------------------------------------------------
void testApp::update(){
	    
    
    //circle speed
    circlePct += 0.0001f;
	
    if (circlePct > 1) {
		circlePct = 0;						// just between 0 and 1 (0% and 100%)
	}
	myCirlce.interpolateByPct(circlePct);		// go between pta and ptb
    
	//rect speed
    rectanglePct += 0.03f;
	
    if (rectanglePct > 1) {
		rectanglePct = 0;						
	}
	myRectangle.interpolateByPct(rectanglePct);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    myRectangle.draw();
    ofDrawBitmapString("The Rectangle is moving at _ feet per second",100, 50);
    
    myCirlce.draw();
    ofDrawBitmapString("The Cirlce is moving at _ feet per second", 100, 150);
    
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
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

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
	
	myRectangle.posa.x = 0;
	myRectangle.posa.y = 50;
	myRectangle.posb.x = 600;
	myRectangle.posb.y = 50;
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter...
    
    
     myCirlce.posa.x = 0;
	 myCirlce.posa.y = 150;
	 myCirlce.posb.x = 600;
	 myCirlce.posb.y = 150;
	 myCirlce.interpolateByPct(0);	// start at 0 pct
     pct = 0;
} 

//--------------------------------------------------------------
void testApp::update(){
	
	pct += 0.006f;							// increase by a certain amount
	if (pct > 1) pct = 0;					// just between 0 and 1 (0% and 100%)
	myRectangle.interpolateByPct(pct);		// go between pta and ptb
	 myCirlce.interpolateByPct(pct);
}

//--------------------------------------------------------------
void testApp::draw(){
    myRectangle.draw();
    myCirlce.draw();
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

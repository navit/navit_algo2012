#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(0,0,0);
	
	
	// set the "a" and "b" positions of the rectangle...
	
	myRectangle.color.set(44,44,90);
    myRectangle.posa.x = 0;
	myRectangle.posa.y = 0;
	myRectangle.posb.x = 600;
	myRectangle.posb.y = 600;
	
	
	myRectangle.radiusa = 10;
	myRectangle.radiusb = 200;
	
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0.001;							// a variable we can alter...
    
    
    
    myNewRectangle.posa.x = 600;
	myNewRectangle.posa.y = 0;
	myNewRectangle.posb.x = 0;
	myNewRectangle.posb.y = 600;
	
	
	myNewRectangle.radiusa = 10;
	myNewRectangle.radiusb = 200;
	
	myNewRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0.001;
}


//--------------------------------------------------------------
void testApp::update(){
	
	
	pct = (float) mouseY / (float) ofGetHeight();
	
	//printf("%f \n", pct);
	
	pct = pct + 0.01;
		if (pct > 1){ //if pct is biiger then 1 then it = 0
		pct = 0;	
}
	
	myRectangle.interpolateByPct(pct);
    myNewRectangle.interpolateByPct(pct);
	
}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
    myNewRectangle.draw();
	
	ofSetColor(255,255,255);
	ofDrawBitmapString("mouse height controls interpolation (pct = " + ofToString(pct) + ")", 20, 20);//drawing txt
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
 //set pct based on mouseY....
//    pct = (float)  y /  (float) ofGetHeight();
//    if (pct < 0) pct = 0;
//	if (pct > 1) pct = 1;
//    myRectangle.interpolateByPct(pct);		// go between pta and ptb
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

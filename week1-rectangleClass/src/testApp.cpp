#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);//synced with the speed of the screen
	
	// set background: 
	
	ofBackground(30,30,30);
	
	
	// set the position of the rectangle:
	
	myRectangle.pos.x = 120;
	myRectangle.pos.y = 120;
    
    newRectangle.pos.x= 200;
    newRectangle.pos.y=200;
	
}

//--------------------------------------------------------------
void testApp::update(){

	myRectangle.update();
    newRectangle.update();
	
}



//--------------------------------------------------------------
void testApp::draw(){
    
	ofSetColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
	myRectangle.draw();
    newRectangle.draw();
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
	// in class we looked at this -- click = new position
	//myRectangle.pos.x = ofRandom(0,ofGetWidth());
	//myRectangle.pos.y =  ofRandom(0,ofGetHeight());
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}

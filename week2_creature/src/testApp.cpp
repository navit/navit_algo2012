#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofEnableAlphaBlending();
	ofBackground(35,35,35);
	
	
	// set the position of the snake

	//mySnake.pos.x = 0;
    //mySnake.pos.y = 0;
	
}

//--------------------------------------------------------------
void testApp::update(){
        
	mySnake.xenoToPoint(mouseX/6, mouseY/6);
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

	mySnake.draw();
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

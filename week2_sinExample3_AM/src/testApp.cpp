#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	//ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
    // regulates the carrier change its behaviour  To vary the frequency, amplitude, phase, or other characteristic
	float modulator = ofMap( sin(ofGetElapsedTimef()*10), -1, 1, 0, 1); //mapping -1 & 1 to 0 & 1
	
    //carriers
    float ypos= ofMap( cos(ofGetElapsedTimef()*100) * modulator, -1, 1, 5, ofGetHeight()-20);
	float xpos= ofMap( sin (ofGetElapsedTimef()*100) * modulator, -1, 1, 5, ofGetWidth()-50);
	
    ofSetColor(64,255,64);
	ofCircle(xpos, ypos,10);
    
    
    //drawing and storing the points
    ofPoint temp;
	temp.x = xpos;
	temp.y = ypos;
	points.push_back(temp);
	if (points.size() > 1000){//how many points to store
		points.erase(points.begin());
	}
    ofSetColor(1,92,101);
    ofBeginShape();
	for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x, points[i].y);
//        ofCurve(points[i].x, points[i].y, points[i].x/2, points[i].y/2, points[i].x/5, points[i].y/5, points[i].x/10, points[i].y/10);
    }
	ofEndShape();
	
	
	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

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
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}


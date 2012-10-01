#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
    ofEnableAlphaBlending();
	ofEnableSmoothing();
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
    radius=300;
    SecRadius= 270;
    ThirdRadius = 220;
    FourthRadius =370;
	
	

}

//--------------------------------------------------------------
void testApp::update(){
    
//    radius = radius + 0.1;
//    SecRadius= SecRadius + 0.2;
//    ThirdRadius =ThirdRadius + 0.3;
//
}

//--------------------------------------------------------------
void testApp::draw(){
    //ofBackgroundGradient(ofColor::blue, ofColor::gray);

	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;

    
    
    ofNoFill();
    ofSetLineWidth(5);
    ofBeginShape();
	for (int i = 0; i < 100; i++){
		//radius = 20 + i * 2;
		float angle = ofGetElapsedTimef() * (1 + i / 5.0);
		float x = xorig + FourthRadius * -cos( GOLDEN_RATIO * angle);
		float y = yorig + FourthRadius * sin( GOLDEN_RATIO * angle);
        ofSetRectMode(OF_RECTMODE_CENTER);
        float alpha = ofMap(i, 0, 100, 0.0, 0.4);
        ofSetColor(ofFloatColor(255.0/255.0, 73.0/225.0, 0/255.0, alpha));
        //ofSetColor(113,9,170);
        ofVertex(x, y);
	}
    ofEndShape();
    
    ofNoFill();
    ofSetLineWidth(5);
    ofBeginShape();
	for (int i = 0; i < 100; i++){
		//radius = 20 + i * 2;
		float angle = ofGetElapsedTimef() * (2 + i / 10.0);
		float x = xorig + radius * -cos( GOLDEN_RATIO * angle);
		float y = yorig + radius * sin( GOLDEN_RATIO * angle);
        ofSetRectMode(OF_RECTMODE_CENTER);
        float alpha = ofMap(i, 0, 100, 0.0, 0.4);
        ofSetColor(ofFloatColor(92.0/255.0, 204.0/225.0, 204.0/255.0, alpha));
        //ofSetColor(92,204,204);
        ofVertex(x, y);
	}
    ofEndShape();
    
    ofNoFill();
    ofBeginShape();
	for (int i = 0; i < 100; i++){
		//float secRadius = 10 + i * 2;
		float angle = ofGetElapsedTimef() * (3+ i /20.0);//*100 + i;
		float x = xorig + SecRadius * -cos( GOLDEN_RATIO * angle);
		float y = yorig + SecRadius * sin( GOLDEN_RATIO * angle);
		ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(0,153,153);
        ofVertex(x, y);
	}
    ofEndShape();
    
    
    ofFill();
    ofBeginShape();
	for (int i = 0; i < 100; i++){
		//float secRadius = 10 + i * 2;
		float angle = ofGetElapsedTimef() * ( 4+ i / 30.0);
		float x = xorig + ThirdRadius * -cos( GOLDEN_RATIO * angle);
		float y = yorig + ThirdRadius * sin( GOLDEN_RATIO * angle);
		ofSetRectMode(OF_RECTMODE_CENTER);
        float alpha = ofMap(i, 0, 100, 0.0, 0.9);
        ofSetColor(ofFloatColor(0/255.0, 160.0/225.0, 138.0/255.0, alpha));
        ofVertex(x, y);
	}
    ofEndShape();
   

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key=='f' || key=='F'){
        ofToggleFullscreen();
    }
    if(key=='s' || key=='S'){
        radius=0;
        SecRadius= 0;
        ThirdRadius = 0;
    }
    

    


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


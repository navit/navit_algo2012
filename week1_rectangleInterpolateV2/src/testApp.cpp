#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofEnableAlphaBlending();
	ofSetVerticalSync(true);
   	
	  	
//	// set the "a" and "b" positions of the rectangle...
//	
//	myRectangle.posa.x = 0;
//	myRectangle.posa.y = 0;
//	myRectangle.posb.x = 300;
//	myRectangle.posb.y = 300;
//	myRectangle.interpolateByPct(0);	
//	pct = 1;							
//	myRectangle.color.set(120,156,166); //defining the color of my first instance
//    
//        
//    mySecondRectangle.posa.x = 600;
//	mySecondRectangle.posa.y = 0;
//	mySecondRectangle.posb.x = 300;
//	mySecondRectangle.posb.y = 300;
//	mySecondRectangle.interpolateByPct(0);
//    pct = 1;							
//	mySecondRectangle.color.set(106,152,200); //defining the color of my second instance
//	
//    
//    myThirdRectangle.posa.x = 0;
//    myThirdRectangle.posa.y = 600;
//    myThirdRectangle.posb.x = 300;
//    myThirdRectangle.posb.y = 300;
//    myThirdRectangle.interpolateByPct(0);	
//	pct = 1;							
//	myThirdRectangle.color.set(235,231,148); //defining the color of my third instance
//	
//    
//    myFourthRectangle.posa.x = 600;
//    myFourthRectangle.posa.y = 600;
//    myFourthRectangle.posb.x = 300;
//    myFourthRectangle.posb.y = 300;
//    myFourthRectangle.interpolateByPct(0);
//    pct = 1;
//	myFourthRectangle.color.set(176,214,216); //defining the color of my fourth instance
	
    

}

//--------------------------------------------------------------
void testApp::update(){
	
	// to see pct in the console
	//printf("%f \n", pct);
	 
	pct += 0.004f;							// increase by a certain amount- floating numnber.
	if (pct > 1) {
		pct = 0;							// just between 0 and 1 (0% and 100%)
	}	
    
    vertex.interpolateByPct(pct);		// go between pta and ptb

    ofSetWindowTitle( ofToString( ofGetFrameRate() ));
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackgroundGradient(ofColor(0,255,255), ofColor(30,30,30));//center and conrners
    
    float xPct = (float)(mouseX) / (float)(ofGetWidth());
	float yPct = (float)(mouseY) / (float)(ofGetHeight());
	int nTips = 5 + xPct * 60;
	int nStarPts = nTips * 2;
	float angleChangePerPt = TWO_PI / (float)nStarPts;
	float innerRadius = 0 + yPct*100;
	float outerRadius = 100;
	float origx = 300;
	float origy = 300;
	float angle = 0;
	
	ofSetColor(0xa16bca);
	ofBeginShape();
	for (int i = 0; i < nStarPts; i++){
		if (i % 2 == 0) {
			// inside point:
			float x = origx + innerRadius * cos(angle);
			float y = origy + innerRadius * sin(angle);
			ofVertex(x,y);
		} else {
			// outside point
			float x = origx + outerRadius * cos(angle);
			float y = origy + outerRadius * sin(angle);
			ofVertex(x,y);
		}
		angle += angleChangePerPt;
	}
	ofEndShape();
 
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
	
	//myRectangle.posa.x = x;
	//myRectangle.posa.y = y;
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}

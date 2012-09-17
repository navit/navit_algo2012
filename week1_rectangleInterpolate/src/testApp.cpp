#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofEnableAlphaBlending();
	ofSetVerticalSync(true);
    windows.loadImage("windows.jpg");
	
	// set background: 
	  	
	// set the "a" and "b" positions of the rectangle...
	
	myRectangle.posa.x = 0;
	myRectangle.posa.y = 0;
	myRectangle.posb.x = 300;
	myRectangle.posb.y = 300;
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 1;							// a variable we can alter...
	
	myRectangle.color.set(255,0,0); //defining the color of my first instance
    
    
    
    mySecondRectangle.posa.x = 600;
	mySecondRectangle.posa.y = 0;
	mySecondRectangle.posb.x = 300;
	mySecondRectangle.posb.y = 300;
	mySecondRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 1;							// a variable we can alter...
	
	mySecondRectangle.color.set(90,170,0); //defining the color of my second instance
	
    
    myThirdRectangle.posa.x = 0;
    myThirdRectangle.posa.y = 600;
    myThirdRectangle.posb.x = 300;
    myThirdRectangle.posb.y = 300;
    myThirdRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 1;							// a variable we can alter...
	
	myThirdRectangle.color.set(250,200,0); //defining the color of my third instance
	
    myFourthRectangle.posa.x = 600;
    myFourthRectangle.posa.y = 600;
    myFourthRectangle.posb.x = 300;
    myFourthRectangle.posb.y = 300;
    myFourthRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 1;							// a variable we can alter...
	
	myFourthRectangle.color.set(20,50,250); //defining the color of my fourth instance
	
    
    


}

//--------------------------------------------------------------
void testApp::update(){
	
	// to see pct in the console
	//printf("%f \n", pct);
    
    pct += 0.2f;//very very fast
	//pct += 0.00001f;	//very very slow						// increase by a certain amount- floating numnber.
	if (pct > 1) {
		pct = 0;							 // just between 0 and 1 (0% and 100%)
	}
	
	myRectangle.interpolateByPct(pct);		 // go between pta and ptb
    mySecondRectangle.interpolateByPct(pct);
    myThirdRectangle.interpolateByPct(pct);
    myFourthRectangle.interpolateByPct(pct);
    
    ofSetWindowTitle( ofToString( ofGetFrameRate() ));
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //ofBackgroundGradient(ofColor(0,255,255), ofColor(30,30,30));//center and conrners
    ofSetColor(255,255,255);
    windows.draw(0,0 , 600, 600);
	
    myRectangle.draw();
    mySecondRectangle.draw();
    myThirdRectangle.draw();
    myFourthRectangle.draw();
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

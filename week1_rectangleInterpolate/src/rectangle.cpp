#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
    color = ofColor(198,246,55);
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	//ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(color, 55 + pct * 200 );//mapping the alpha using pct
    //cout << pct * 255 << endl;
    //ofRect(pos.x, pos.y, 40,40);
    
    ofSetCircleResolution(100);
    ofCircle(pos.x, pos.y, pct * 50);
}


//------------------------------------------------------------------
void rectangle::interpolateByPct(float myPct){
    
	pct = myPct;
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;
	
	// this is an alternative way to write above..
	// differe style, but the same mathematically.
	//pos.x = posa.x + (pct) * (posb.x-posa.x);
}
#include "circle.h"



//------------------------------------------------------------------
    circle::circle(){
	shaper = 5;
}

//------------------------------------------------------------------
void circle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(60,240,40);
    ofSetCircleResolution(10);
    ofCircle(pos.x,pos.y, 30);
    
}


//------------------------------------------------------------------
void circle::interpolateByPct(float myPct){
	
	
	// powf (2, 3) = 8
	
	pct = powf(myPct, shaper);
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;
}
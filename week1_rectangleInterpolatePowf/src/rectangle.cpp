#include "rectangle.h"



//------------------------------------------------------------------
rectangle::rectangle(){
	shaper = 5;
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(200,26,55);
    ofRect(pos.x, pos.y, 50,50);
    
}


//------------------------------------------------------------------
void rectangle::interpolateByPct(float myPct){
	
	
	// powf (2, 3) = 8
	
	pct = powf(myPct, shaper);
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;
}
#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
  
}

void rectangle::update(){

	pos.x = pos.x + ofRandom(-2,2); //the range
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    //ofSetColor(56,246,55);
    ofRect(pos.x, pos.y, 200,200);

}

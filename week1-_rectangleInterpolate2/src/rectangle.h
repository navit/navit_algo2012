#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle {

	public:
	
        rectangle();
	
		void draw();
		void interpolateByPct(float myPct);
		
		ofPoint		pos;
		ofPoint		posa;
		ofPoint		posb;
		float		pct;	// what pct are we between "a" and "b"
	
	
		float		radius;
	
		float		radiusa; //radius for pos a
		float		radiusb; //radius for pos b
    
        ofColor     color;//creating a variable

	

};

#endif // RECTANGLE_H

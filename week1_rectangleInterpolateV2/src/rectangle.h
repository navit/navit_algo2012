#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle {
public:
	
    rectangle();
	
    void draw();
    void interpolateByPct(float myPct);
    
    ofColor     color;//creating a variable
    ofPoint		pos;
    
    ofPoint		posa;
    ofPoint		posb;
    
    float		pct;	// what pct (%) are we between "a" and "b"
   	
	

};

#endif // RECTANGLE_H

#ifndef CIRCLE_H
#define CIRCLE_H

#include "ofMain.h"

class circle {
    
public:
	
    circle();
	
    void draw();
    void interpolateByPct(float myPct);
    
    ofPoint		pos;
    ofPoint		posa;
    ofPoint		posb;
    float		pct;	// what pct are we between "a" and "b"
    float		shaper;
	
	
    
};

#endif 

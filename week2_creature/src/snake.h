#ifndef SNANKE_H
#define SNANKE_H

#include "ofMain.h"

class snake {

	public:
	
        snake();
	
        void draw();
		void	xenoToPoint(float catchX, float catchY);
	
		ofPoint		pos;
		ofPoint		prevPos;
			
		float		angle;
        float       radius;
        float       dx,dy;
        ofColor     light;
        ofColor     dark;
        ofColor     lighter;
        float       alpha;
    
	
	
		float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
        vector < ofPoint > points;
		    
    //body
    float   scales;
    float   scales1;
    float   scales2;
    float   scales3;
    
    

 
	
	
	
};

#endif // RECTANGLE_H

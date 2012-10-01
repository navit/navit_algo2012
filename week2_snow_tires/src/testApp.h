#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#define GOLDEN_RATIO 1.61803398874989484820

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
    
	
		vector < ofPoint > points;
        vector < ofPoint > SecPoints;
        vector < ofPoint > ThirdPoints;
        vector< ofPoint > FourthPoints;

    
	float x;
    float y;
		float radius;
        float SecRadius;
        float ThirdRadius;
        float FourthRadius;
	

};

#endif

#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "rectangle.h" //include the class i made which is a seperate file

class testApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased (int key);

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();

		rectangle myRectangle; //making an instance of that class/object
        rectangle newRectangle;
};

#endif


#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:
        
        particle();
		virtual ~particle(){};

        void resetForce();
        void addForce(float x, float y);
        void addDampingForce();
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
	
        void bounceOffWalls();
        
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
        ofColor color;
        float radius;
        float alpha;
    
	
		float damping;

        protected:
        private:
    
        vector <ofPoint> trail; //another vector > each particle has its own vector of prev position
};  

#endif // PARTICLE_H
    
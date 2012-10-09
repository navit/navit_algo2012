#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
#define GOLDEN_RATIO 1.61803398874989484820

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
        
	
        
        ofPoint pos;
        ofPoint vel;
        ofPoint frc;   // frc is also know as acceleration (newton says "f=ma")
        ofColor color;
        
        float radius;
        float alpha;
        float timer;
        
        
		float damping;

        protected:
        private:
    
        vector <ofPoint> trail; //another vector > each particle has its own vector of prev position
};  

#endif // PARTICLE_H
    
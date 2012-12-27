#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   
        ofVec2f currentPos;
        ofVec2f prevPos;

    
        ofImage * img; //pointer
        //ofImage * img1;
    
	
	
        particle();
		virtual ~particle(){};
        //functions
        void resetForce();
		void addForce(float x, float y);
		void addRepulsionForce(float x, float y, float radius, float scale);
		void addAttractionForce(float x, float y, float radius, float scale);
		void addRepulsionForce(particle &p, float radius, float scale);
		void addAttractionForce(particle &p, float radius, float scale);
		
		void addDampingForce();
        
		void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
	
		void bounceOffWalls();
	
        //variables
    
		float damping;
        ofFloatColor color;
        float radius;
        float tail;
    
     ofPoint temp;
    
        vector <ofVec2f> trail;

    protected:
    private:
};

#endif // PARTICLE_H

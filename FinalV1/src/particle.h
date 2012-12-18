#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
        
        particle();
		virtual ~particle(){};

        void resetForce();
		void addForce(float x, float y);
		void addRepulsionForce(float x, float y, float radius, float scale);
		void addAttractionForce(float x, float y, float radius, float scale);
		void addRepulsionForce(particle *p, float radius, float scale);
		void addAttractionForce(particle *p, float radius, float scale);
		
		void addDampingForce();
        
		void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void drawOne();
        void draw(ofImage *img);
        //void draw(2);
        
		void bounceOffWalls();
	
	
		float damping;
        
        int life;
        int death;
        int reproAge;
    
        int reproFactor;
    
        vector <ofPoint> points;
        
        bool bRepro;
        bool bAlive;
    
        ofPoint p1,p2,p3,p4;
        
        float	angle;
    
        
    protected:
    private:
};

#endif // PARTICLE_H

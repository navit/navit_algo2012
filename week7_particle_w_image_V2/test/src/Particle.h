//
//  Particle.h
//  emptyExample
//
//  Created by Navit Keren on 12/4/12.
//
//

#ifndef emptyExample_Particle_h
#define emptyExample_Particle_h

#include "ofMain.h"

class Particle {
public:
    
    void setup();
    void draw();
    void update();
    
    ofVec2f pos,vel,acc,oldpos;
    float angle;
    ofColor color;
    int age;
};

#endif

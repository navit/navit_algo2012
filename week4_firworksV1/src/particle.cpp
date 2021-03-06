#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.01f;
    color.set(255,0,255);
    color.setHue(ofRandom(200));

}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
   
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);//position
	vel.set(vx*2,vy*2);//velocity
    //radius=1;
    alpha=(255);
    trail.clear();
}

//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel;
    //radius += 0.1;
    alpha -= 3;
    
    trail.push_back(pos);//ofpoint

    if (trail.size() > 100){//how many points to store
		trail.erase(trail.begin());
	}
    
    
}

//------------------------------------------------------------
void particle::draw(){
    ofFill();
    ofSetColor(color,alpha);
    ofCircle(pos.x, pos.y, 1);
    
    ofFill();
    ofBeginShape();
    for (int i = 0; i < trail.size(); i++) {
        ofVertex(trail[i].x, trail[i].y);//draw a shape with the prev
    }
    ofEndShape();
    
}


//------------------------------------------------------------
	


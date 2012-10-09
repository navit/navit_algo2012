#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.01f;
    color.set(0,0,255);
    color.setHue(ofRandom(20));
    //radius =1;
    timer = 0;

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
    vel.set(ofRandom(-10,10), ofRandom(-10,10));
    //radius =1;
    trail.clear();
    
}


//------------------------------------------------------------
void particle::update(){	

    vel += frc;
    vel *= 1.0f;
    pos += vel;
    //radius += 0.1;
    timer =+0.1;
   // alpha -= 2;

    

   	trail.push_back(pos);
  
	if (trail.size() > 10){
		trail.erase(trail.begin());
	}
}

//------------------------------------------------------------
void particle::draw(){
   
 
    ofMesh lineMesh;
    ofNoFill();
    lineMesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    for (int i = 0 ; i < trail.size() ; i++){
        float angle = atan2(vel.y,vel.x);
        alpha = ofMap(i+1, 1,trail.size(), 0.0,1.0);
        lineMesh.addColor( ofFloatColor( color, alpha * 0.4) );
        lineMesh.addVertex(trail[i]);
        lineMesh.draw();
        ofSetColor(color);
       ofCircle(pos.x, pos.y, 1 *angle);
}
    
//    ofFill();
//    ofBeginShape();
//	for (int i = 0; i < 100; i++){
//        float alpha = ofMap(i+1, 1,trail.size(), 0.0,1.0);
//        float angle = ofGetElapsedTimef() * (3+ i /20.0);//*100 + i;
//		float x = radius * -cos( GOLDEN_RATIO * angle);
//		float y =  radius * sin( GOLDEN_RATIO * angle);
//		ofSetRectMode(OF_RECTMODE_CENTER);
//        ofSetColor(color,alpha);
//        ofCircle(pos.x, pos.y, 1 * angle);
//	}
//       

}






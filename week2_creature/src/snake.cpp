#include "snake.h"


//------------------------------------------------------------------
snake::snake(){

        catchUpSpeed = 0.03f;
        
        pos.set(0,0);
        prevPos.set(0,0);
        
        scales = 80;
        lighter.set(166,45,0);
        light.set(191,87,48);
        dark.set(0,0,0);
        //alpha = (ofRandom(255));
}

//------------------------------------------------------------------
    void snake::draw(){ 
      
     //my epileptic snake
    

        ofPushMatrix();
        ofTranslate(ofGetMouseX(), ofGetMouseY());
        ofRotateZ(angle * RAD_TO_DEG);
        for (int i = 0; i < scales; i++){
            scales1 = 15 * sin(ofGetElapsedTimef()* 3 + i);//the speed
            ofSetColor(dark);
            ofCircle(pos.x/6.0+5*i+scales1, pos.y/10*i-scales1, 5-i*0.5);
            
        }
        
        for (int i = 0; i < scales; i++){
            scales2 = 10 * sin(ofGetElapsedTimef()* 3 + i);//the speed
            ofSetColor(light);
            ofCircle(pos.x/6.0+5*i+scales2, pos.y/10*i-scales2, 5-i*0.5);
        }
        
        for (int i = 0; i < scales; i++){
            scales3 = 5 * sin(ofGetElapsedTimef()* 3 + i);//the speed
            ofSetColor(lighter);
            ofCircle(pos.x/6.0+5*i+scales3, pos.y/10*i-scales3, 5-i*0.5);
        }
        
        ofSetColor(0,0,0);
        ofCircle(pos.x/6.0+5*79+scales3, pos.y/10*79-scales3,6);
        ofCircle(pos.x/6.0+5*79+scales3, pos.y/11*79-scales3,6);
        ofPopMatrix();

	
}

//------------------------------------------------------------------
void snake::xenoToPoint(float catchX, float catchY){
	
	
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 

	float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
	
	angle = atan2(dy, dx);

	prevPos.x = pos.x;
	prevPos.y = pos.y;
    
    
	

}

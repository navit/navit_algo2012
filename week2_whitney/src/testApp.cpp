#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
    ofEnableAlphaBlending();
	ofEnableSmoothing();
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
	
	
	radius = 150;
    SecRadius = 100;
    ThirdRadius =50 ;
    FourthRadius = 200;
    

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	radius = radius + 0.1;
    SecRadius = SecRadius  + 0.1;
    ThirdRadius = ThirdRadius  + 0.1;
    FourthRadius = FourthRadius + 0.1;
    

}

//--------------------------------------------------------------
void testApp::draw(){
	//ofMap(ofGetMouseX(),0, ofGetWidth(), 0.0,1.0); the vlaue i want to map, min & max of the value, the min & max of the value i want to map to

	float xorig = ofGetMouseX();
	float yorig = ofGetMouseY();

    float SecXorig = ofGetMouseX(); //new postions
    float SecYorig  = ofGetMouseY();
    
    float ThirdXorig = ofGetMouseX(); //new postions
    float ThirdYorig  = ofGetMouseY();
    
    float FourthXorig = ofGetMouseX(); //new postions
    float FourthYorig  = ofGetMouseY();
    
	float angle = ofGetElapsedTimef() *10;
    float SecAngle = ofGetElapsedTimef() *100;
    float ThirdAngle = ofGetElapsedTimef() *1000;
    float FourthAngle = ofGetElapsedTimef() *20;
	
    
	float x = xorig  + radius * -cos(angle);//position the shape
	float y = yorig + radius * sin(angle);//make a  new x,y float to draw a new shape
    
    float x2 = SecXorig  + SecRadius * cos(SecAngle);
    float y2 = SecYorig  + SecRadius * sin(SecAngle);

    float x3 = ThirdXorig  + ThirdRadius * cos(ThirdAngle);
    float y3 = ThirdYorig  + ThirdRadius * sin(ThirdAngle);
    
    float x4 = FourthXorig  + FourthRadius * -cos(FourthAngle);
    float y4 = FourthYorig  + FourthRadius * sin(FourthAngle);
    
    
    
    // 1 shape
    //storing the points in the vector
	ofPoint temp;
	temp.x = x;
	temp.y = y;
    
	points.push_back(temp);
	if (points.size() > 1000){
		points.erase(points.begin());
	}

   
	//drawing the circle leading the line
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(128,0,83);
    ofFill();
	ofCircle(x,y,5);
    
    ofMesh lineMesh1;
    lineMesh1.setMode(OF_PRIMITIVE_LINE_STRIP);
    for (int i = 0 ; i < points.size() ; i++){
        float alpha = ofMap(i, 0, points.size(), 0.0, 0.3);
        
        lineMesh1.addColor( ofFloatColor(255.0/255.0, 0/225.0, 127.0/255.0, alpha));
        lineMesh1.addVertex(points[i]);
    }
    
    lineMesh1.draw();
    
    

    
    
    
    //2 shape
    temp.x = x2;
    temp.y = y2;
    
    SecPoints.push_back(temp);
	if (SecPoints.size() > 150){
		SecPoints.erase(SecPoints.begin());
	}
    
    ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(62,4,112);
    ofFill();
	ofCircle(x2,y2,5);
    
    ofMesh lineMesh2;
    lineMesh2.setMode(OF_PRIMITIVE_LINE_STRIP);
    for (int i = 0 ; i < SecPoints.size() ; i++){
        float alpha = ofMap(i, 0, SecPoints.size(), 0.0, 0.4);
        
        lineMesh2.addColor( ofFloatColor(52.0/255.0, 57.0/225.0, 153.0/255.0, alpha));
        lineMesh2.addVertex(SecPoints[i]);
    }
    
    lineMesh2.draw(); 
    

    
    
    //3 shape
    temp.x = x3;
    temp.y = y3;
    
    ThirdPoints.push_back(temp);
	if (ThirdPoints.size() > 100){
		ThirdPoints.erase(ThirdPoints.begin());
	}
     
    ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(166,70,0);
    ofFill();
	ofCircle(x3,y3,5);
    
    ofMesh lineMesh3;
    lineMesh3.setMode(OF_PRIMITIVE_LINE_STRIP);
    for (int i = 0 ; i < ThirdPoints.size() ; i++){
        float alpha = ofMap(i, 0, ThirdPoints.size(), 0.0, 0.4);
        
        lineMesh3.addColor( ofFloatColor(198.0/255.0,92.0/255.0,015.0/255.0, alpha) );
        
        lineMesh3.addVertex(ThirdPoints[i]);
    }

    lineMesh3.draw();
    


    //4 shape
    temp.x = x4;
    temp.y = y4;
    
    FourthPoints.push_back(temp);
	if (FourthPoints.size() > 250){
		FourthPoints.erase(FourthPoints.begin());
	}
    
    ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(0,123,37,80);
    ofFill();
	ofCircle(ofGetMouseX(),ofGetMouseY(),6);
    
    ofMesh lineMesh4;
    lineMesh4.setMode(OF_PRIMITIVE_LINE_STRIP);
    for (int i = 0 ; i < FourthPoints.size() ; i++){
        float alpha = ofMap(i, 0, FourthPoints.size(), 0.0, 0.4);
        
        lineMesh4.addColor( ofFloatColor(70.0/255.0, 114.0/255.0, 153.0/255.0, alpha));
        
        lineMesh4.addVertex(FourthPoints[i]);
    }
    
    lineMesh4.draw();
    



	
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    //resetting the radius when mouse moves
    radius = 50;
    SecRadius = 30;
    ThirdRadius =10 ;
    FourthRadius = 70;
    


}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    radius = 50 * 2;
    SecRadius = 30 * 2;
    ThirdRadius =10 * 2 ;
    FourthRadius = 70 * 2;
   

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}


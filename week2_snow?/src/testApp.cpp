#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
    ofEnableAlphaBlending();
	ofEnableSmoothing();
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
	
	
	radius = 15;
   
    
}

//--------------------------------------------------------------
void testApp::update(){
	
	//radius = radius + 0.1;
}
   
//--------------------------------------------------------------
void testApp::draw(){
	ofBackgroundGradient(ofColor::blue, ofColor::black);
    
    
	
    float angle = ofGetElapsedTimef() *100;
    float x = ofGetMouseX() + radius * cos(GOLDEN_RATIO * angle);//position the shape
    float y = ofGetMouseY() + radius * sin(GOLDEN_RATIO * angle);//make a  new x,y float to draw a new shape
    
    
    // 1 shape
    //storing the points in the vector
	ofPoint temp;
	temp.x = x;
	temp.y = y;
    
	points.push_back(temp);
	if (points.size() > 80){
		points.erase(points.begin());
	}
    

    ofPushMatrix();
    ofTranslate(60,60);
    ofMesh lineMesh1;
    lineMesh1.setMode(OF_PRIMITIVE_LINE_STRIP);
    for (int i = 0 ; i < points.size() ; i++){
        float alpha = ofMap(i, 0, points.size(), 0.0, 0.5);
        lineMesh1.addColor( ofFloatColor(255.0/255.0, 255.0/225.0,255.0/255.0, alpha));
        lineMesh1.addVertex(points[i]);
    }
    
    lineMesh1.draw();
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofTranslate(100,100);
    ofMesh lineMesh2;
    lineMesh2.setMode(OF_PRIMITIVE_LINE_STRIP);
    for (int i = 0 ; i < points.size() ; i++){
        float alpha = ofMap(i, 0, points.size(), 0.0, 0.5);
        lineMesh2.addColor( ofFloatColor(255.0/255.0, 255.0/225.0,255.0/255.0, alpha));
        lineMesh2.addVertex(points[i]);
    }
    
    lineMesh2.draw();
    ofPopMatrix();
    
    
    
    ofPushMatrix();
    ofTranslate(140,140);
    ofMesh lineMesh3;
    lineMesh3.setMode(OF_PRIMITIVE_LINE_STRIP);
    for (int i = 0 ; i < points.size() ; i++){
        float alpha = ofMap(i, 0, points.size(), 0.0, 0.5);
        lineMesh3.addColor( ofFloatColor(255.0/255.0, 255.0/225.0,255.0/255.0, alpha));
        lineMesh3.addVertex(points[i]);
    }
    
    lineMesh3.draw();
    ofPopMatrix();

    
    ofPushMatrix();
    ofTranslate(180,180);
    ofMesh lineMesh4;
    lineMesh4.setMode(OF_PRIMITIVE_LINE_STRIP);
    for (int i = 0 ; i < points.size() ; i++){
        float alpha = ofMap(i, 0, points.size(), 0.0, 0.5);
        lineMesh4.addColor( ofFloatColor(255.0/255.0, 255.0/225.0,255.0/255.0, alpha));
        lineMesh4.addVertex(points[i]);
    }
    
    lineMesh4.draw();
    ofPopMatrix();


    
    
    
    
    
    
    
    
    
    
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){


}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

   

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


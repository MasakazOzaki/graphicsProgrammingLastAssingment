#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    backgroundImage.load("space.jpg");
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
//    ofToggleFullscreen();
    
    boxSize = 15;
    
    for (int i=0; i<NUM; i++) {
        pos[i].x = ofRandom(-500, 500);
        pos[i].y = ofRandom(-500, 500);
        pos[i].z = ofRandom(-500, 500);
        vel[i].x = ofRandom(-10, 10);
        vel[i].y = ofRandom(-10, 10);
        vel[i].z = ofRandom(-10, 10);
        mbox[i].set(boxSize);
        
    }
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<NUM; i++) {
        ofVec3f tmp = pos[i];
        pos[i].x +=  vel[i].x ;
        pos[i].y +=  vel[i].y ;
        pos[i].z +=  vel[i].z ;
        
        if (pos[i].x > ofGetWidth() || pos[i].x < -ofGetWidth())
        {
            pos[i].x = tmp.x;
            vel[i].x *= -1;
        }

        if (pos[i].y > ofGetHeight() || pos[i].y < -ofGetHeight())
        {
            
            pos[i].y = tmp.y;
            vel[i].y *= -1;

        }

        if (pos[i].z > ofGetWidth() || pos[i].z <  -ofGetWidth())
        {
            pos[i].z = tmp.z;
            vel[i].z *= -1;
        }
        mbox[i].setPosition(pos[i].x, pos[i].y, pos[i].z);
        
    }

    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    backgroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    vec.set(mouseX-p.x, mouseY-p.y);
    
    
    cam.begin();
    
    int alpha = abs(vec.x) + abs(vec.y);
    ofSetColor(100, 200, 255, 255 - alpha);
    for (int i=0; i<NUM; i++) {
        mbox[i].draw();
    }
    
   // ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255, 255, 255, (ofGetFrameNum()*6)%120);
    box.setPosition(0, 0, 0);
    box.set(150);
    box.draw();
    
    ofSetColor(255, 255, 255, 255);
    box.drawWireframe();
    
    for (int i=0; i<NUM; i++) {
        for (int j=0; j<NUM; j++) {
            if (i != j && distance(mbox[i].getPosition(), mbox[j].getPosition()) < 350 ) {
                ofDrawLine(mbox[i].getPosition(), mbox[j].getPosition());
//                ofMesh line = ofMesh();
//                line.setMode(OF_PRIMITIVE_LINES);
//                line.addVertex(mbox[i].getPosition());
//                line.addVertex(mbox[j].getPosition());
//                line.drawWireframe();
                
            }
            
        }
    }
    
    cam.end();
    p.x = mouseX;
    p.y = mouseY;

   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gifs.init();
}

//--------------------------------------------------------------
void ofApp::update(){
    bpmTapper.update();
    gifs.update(abs(bpmTapper.beatPerc()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient( ofColor( 128 ), ofColor( 0 ) );
    
    gifs.draw();
    ofPushStyle();
    ofSetColor(0);
    bpmTapper.draw(10, ofGetHeight()-60, 10);

    ofFill();
    ofSetColor(0);
    /*
    ofRect(ofGetWidth()/2, ofGetHeight()*abs(bpmTapper.sin4), 10, 10);
    ofRect(ofGetWidth()/2 + 100, ofGetHeight()*abs(bpmTapper.beatPerc()), 50, 10);
    ofRect(ofGetWidth()/2 + 200, ofGetHeight()*abs(bpmTapper.beatCosU(4)), 100, 10);
    ofRect(ofGetWidth()/2 + 300, ofGetHeight()*abs(bpmTapper.beatCosS(4)), 150, 10);
     */

    ofDrawBitmapString("FPS: "+ofToString(ofGetFrameRate(), 2)+
                       "BPM: " + ofToString(bpmTapper.bpm()), 10, ofGetHeight()-10);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 't') {
        bpmTapper.tap();
        bpmTapper.startFresh();
    }
    if(key == 's') {
        gifs.stop();
    }
    
    if(key == 'f') {
        ofToggleFullscreen();
        gifs.setRandom();
    }
    if(key == 'a') {

    }
    
    bool gifsFlag = true;
    if(gifsFlag
       && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')){
        if( key == '1' ){ gifs.setPattern(1); }
        else if( key == '2'){ gifs.setPattern(2); }
        else if( key == '3'){ gifs.setPattern(3); }
        else if( key == '4'){ gifs.setPattern(4); }
        else if( key == '5'){ gifs.setPattern(5); }
        else if( key == '6'){ gifs.setPattern(6); }
        else if( key == '7'){ gifs.setPattern(7); }
        else if( key == '8'){ gifs.setPattern(8); }
        else if( key == '9'){ gifs.setPattern(9); }
        else if( key == '0'){ gifs.setPattern(0); }
    }
    if(gifsFlag && key == OF_KEY_LEFT){
        gifs.addColumn(false);
    }else if(gifsFlag && key == OF_KEY_RIGHT){
        gifs.addColumn(true);
    }
    
    if(gifsFlag && key == OF_KEY_UP){
        gifs.addRow(true);
    }else if(gifsFlag && key == OF_KEY_DOWN){
        gifs.addRow(false);
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

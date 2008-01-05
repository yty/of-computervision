#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	 
    ofBackground(255,255,255);	
	
    cw = 320; ch = 240;
    
    vidGrabber.initGrabber(cw,ch);
    
    cameraImg.allocate(cw, ch);
    grayImg.allocate(cw, ch);
    pastImg.allocate(cw, ch);
    
    // grayImg.set(0);
    // pastImg.set(0);
    
    block_size = 10;
    shift_size = 1;
    
    rows = int(ceil(double(ch) / block_size));
    cols = int(ceil(double(cw) / block_size));
    
    velx = cvCreateMat (rows, cols, CV_32FC1);
    vely = cvCreateMat (rows, cols, CV_32FC1);
    
    cvSetZero(velx);
    cvSetZero(vely);
    
    block = cvSize (block_size, block_size);
    shift = cvSize (shift_size, shift_size);
    max_range = cvSize (10, 10);
}

//--------------------------------------------------------------
void testApp::update(){
    
    vidGrabber.grabFrame();
    
    if(vidGrabber.isFrameNew()){
        pastImg = grayImg;
        
        cameraImg.setFromPixels(vidGrabber.getPixels(), cw, ch);
        grayImg.setFromColorImage(cameraImg);
        
        grayImg.threshold(100);
        grayImg.blurHeavily();
        
        /*
        grayImg.dilate_3x3();
        grayImg.threshold(230);
        grayImg.blurHeavily();
        */
        
        // printf("%p %p\n", pastImg.getCvImage(), grayImg.getCvImage());
        cvCalcOpticalFlowBM(pastImg.getCvImage(), grayImg.getCvImage(), 
            block, shift, max_range, 0, velx, vely);
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    cameraImg.draw(0,0);
    grayImg.draw(320,0);
    pastImg.draw(0,240);
    
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            int dx = (int) cvGetReal2D (velx, y, x);
            int dy = (int) cvGetReal2D (vely, y, x);
            int xx = x * block_size;
            int yy = y * block_size;
            ofLine(xx, yy, xx + dx, yy + dy);
        }
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){ 
	if(key == 's'){
        vidGrabber.videoSettings();
    }
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
void testApp::mouseReleased(){
}

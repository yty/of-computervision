#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofCvMain.h"


class testApp : public ofSimpleApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
        
        ofCvColorImage cameraImg;
        ofCvGrayscaleImage grayImg;
        ofCvGrayscaleImage pastImg;
        
        int rows, cols;
        int block_size;
        int shift_size;
        int cw, ch;
        
        CvMat *velx, *vely;
        CvSize block;
        CvSize shift;
        CvSize max_range;
        
        ofVideoGrabber vidGrabber;
};

#endif	


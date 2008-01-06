#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofCvMain.h"

class testApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();

		ofVideoGrabber 		vidGrabber;
		ofCvGrayscaleImage 	grayImage;
		ofCvGrayscaleImage 	grayLastImage;
		ofCvGrayscaleImage 	grayBg;
		ofCvGrayscaleImage 	grayDiff;
		ofCvColorImage		colorImg;

		ofCvOpticalFlowLK	opticalFlow;

		int 				threshold;
		bool				bLearnBakground;


};

#endif

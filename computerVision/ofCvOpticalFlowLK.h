#pragma once

#include "ofMain.h"
#include "ofCvConstants.h"
#include "ofCvGrayscaleImage.h"

class ofCvOpticalFlowLK
{
public:
	ofCvOpticalFlowLK(void);
	~ofCvOpticalFlowLK(void);
		
	void allocate(int _w, int _h);

	void calc( ofCvGrayscaleImage & pastImage,
			   ofCvGrayscaleImage & currentImage,					   
			   int size
			  );

	void setCalcStep(int _cols, int _rows);
		
	void reset();
	void draw();

private:

	static const int DEFAULT_CAPTURE_WIDTH = 320;
	static const int DEFAULT_CAPTURE_HEIGHT = 240;

	int captureWidth;
	int captureHeight;

	static const int DEFAULT_CAPTURE_COLS_STEP = 4;
	static const int DEFAULT_CAPTURE_ROWS_STEP = 4;

	int captureColsStep;
	int captureRowsStep;

	IplImage* vel_x;
	IplImage* vel_y;

};

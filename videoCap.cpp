#include <string>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <opencv/cv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/tracking.hpp>

using namespace std;
using namespace cv;
using namespace cv::gpu;

int theObject[2] = {0,0};
Rect objectBoundingRectangle = Rect(0,0,0,0);


void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

string intToString(int num){
	ostringstream convert;
	convert << num;
	string s = convert.str();;
	return s;
}

void drawBox(vector< vector<Point> > contours, Mat &cameraFeed){

	vector<vector<Point> > contours_poly( contours.size() );
	vector<Rect> boundRect( contours.size() );
	vector<Point2f>center( contours.size() );
	vector<float>radius( contours.size() );

	// int area;
	// int prev_area = 0;
	// int max_area_index = 0;
	
	#pragma omp parallel for
	for( int i = 0; i < contours.size(); i++ ) {
		approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
		boundRect[i] = boundingRect( Mat(contours_poly[i]) );
		// if (area > prev_area){
		// 	max_area_index = i;
		// 	prev_area = area;
		// }
	}


	/// Draw polygonal contour + bonding rects
	#pragma omp parallel for
	for( int i = 0; i< contours.size(); i++ ) {
		Scalar color = Scalar(255,0,255);
		drawContours( cameraFeed, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
		rectangle( cameraFeed, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
	}
	
	
}

void searchForMovement(Mat thresholdImage, Mat &cameraFeed){
	//notice how we use the '&' operator for objectDetected and cameraFeed. This is because we wish
	//to take the values passed into the function and manipulate them, rather than just working with a copy.
	//eg. we draw to the cameraFeed to be displayed in the main() function.
	bool objectDetected = false;
	Mat temp;
	thresholdImage.copyTo(temp);
	//these two vectors needed for output of findContours
	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	//find contours of filtered image using openCV findContours function
	//findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );// retrieves all contours
	findContours(temp,contours,hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE );// retrieves external contours


	int THRESH = 100;

	//if contours vector is not empty, we have found some objects
	if(contours.size()>0)objectDetected=true;
	else objectDetected = false;

	//vector< vector<int> > theObject(contours.size(), vector<int>(2));

	int prev_xpos = theObject[0];
	int prev_ypos = theObject[1];

	if(objectDetected){
		//the largest contour is found at the end of the contours vector
		//we will simply assume that the biggest contour is the object we are looking for.
		//vector< vector<Point> > largestContourVec;
		//largestContourVec.push_back(contours.at(contours.size()-1));
		//make a bounding rectangle around the largest contour then find its centroid
		//this will be the object's final estimated position.
		//objectBoundingRectangle = boundingRect(largestContourVec.at(0));
		//int xpos = objectBoundingRectangle.x+objectBoundingRectangle.width/2;
		//int ypos = objectBoundingRectangle.y+objectBoundingRectangle.height/2;



		//theObject[0] = xpos;
		//theObject[1] = ypos;
		drawBox( contours, cameraFeed);

		
		//for(int i = 0; i < contours.size(); i++){	
		//	objectBoundingRectangle = boundingRect(contours.at(i));
		//	int xpos = objectBoundingRectangle.x + objectBoundingRectangle.width/2;
		//	int ypos = objectBoundingRectangle.y + objectBoundingRectangle.height/2;
			
		//	theObject[i][0] = xpos;
		//	theObject[i][1] = ypos;
		//}

		//update the objects positions by changing the 'theObject' array values
		//theObject[0] = xpos , theObject[1] = ypos;
	}
	
	//make some temp x and y variables so we dont have to type out so much
	//int x = theObject[0];
	//int y = theObject[1];

	//if(x - prev_xpos > THRESH){
	//	cout << "Left" << endl;
	//}
	//else if(abs(x - prev_xpos) > THRESH) {
	//	cout << "Right" << endl;
	//}
	
	//if(y - prev_ypos > THRESH) {
	//	cout << "Up" << endl;
	//}
	//else if(abs(y - prev_ypos) > THRESH) {
	//	cout << "Down" << endl;
	//}

	//circle(cameraFeed,Point(x,y),20,Scalar(0,255,0),2);
	//line(cameraFeed,Point(x,y),Point(x,y-25),Scalar(0,255,0),2);
	//line(cameraFeed,Point(x,y),Point(x,y+25),Scalar(0,255,0),2);
	//line(cameraFeed,Point(x,y),Point(x-25,y),Scalar(0,255,0),2);
	//line(cameraFeed,Point(x,y),Point(x+25,y),Scalar(0,255,0),2);

	//write the position of the object to the screen
	//putText(cameraFeed,"Tracking object at (" + intToString(x)+","+intToString(y)+")",Point(x,y),1,1,Scalar(255,0,0),2);
	
	

}


int main(int argc, char* argv[]){
	VideoCapture cap(0);
	Mat frame1, frame2, frame3;
	Mat grayImage1, grayImage2, grayImage3;
	Mat blurframe1, blurframe2, blurframe3;
	Mat difference1, difference2;
	Mat finalImg;

	if(!cap.isOpened()){
		cout << "Video Cam cannot be opened" << endl;
		return -1;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	cout << "Frame size: " << dWidth << "x" << dHeight << endl;

	namedWindow("MyVideo", WINDOW_OPENGL);
	namedWindow("test", WINDOW_OPENGL);
	
	float total = 0;
	float count = 0;

	while(true){
		//Mat frame;
		clock_t t1, t2;
		t1 = clock();
		
		//reads first frame
		bool bSuccess = cap.read(frame1);
		blur(frame1, blurframe1, Size(4,4));

		if(!bSuccess){
			cout << "Cannot read from video stream" << endl;
			break;
		}
		//converts 1st frame to gray
		cvtColor(blurframe1, grayImage1, COLOR_BGR2GRAY);
		//reads 2nd frame
		cap.read(frame2);
		blur(frame2, blurframe2, Size(6,6));
		//converts 2nd frame to gray
		cvtColor(blurframe2, grayImage2, COLOR_BGR2GRAY);
		//frame3
		cap.read(frame3);
		blur(frame3, blurframe3, Size(6,6));
		cvtColor(blurframe3, grayImage3, COLOR_BGR2GRAY);


		
		//absdiff(grayImage1, grayImage2, difference1);
		absdiff(grayImage1, grayImage3, difference1);
		absdiff(grayImage2, grayImage3, difference2);
		bitwise_or(difference1, difference2, finalImg);
		threshold(finalImg, finalImg, 35, 255, CV_THRESH_BINARY);
		// fastNlMeansDenoisingMulti(finalImg, finalImg);
		// threshold(difference, finalImg, 20, 255, THRESH_BINARY);

		blur(finalImg, finalImg, Size(6,6));
		threshold(finalImg, finalImg, 20, 255, THRESH_BINARY);

		Mat kernel;

		getStructuringElement(MORPH_RECT, Size(10,10));
		morphologyEx(finalImg, finalImg, MORPH_CLOSE, kernel , Point(-1,-1));

		//int b;
		//int g;
		//int r;
		//unsigned char *data = (unsigned char*)(frame.data);
		//for (int i = 0; i < frame.rows - 4; i++) {
		//	for (int j = 0; j < frame.cols - 1000; j++) { //segmentation fault?
		//		printf("%d\n", i);
		//		printf("%d\n", j);
		//		b = data[frame.step * j + i];
		//		g = data[frame.step * j + i + 1];
		//		r = data[frame.step * j + i + 2];
		//		cout << r << g << b << endl;
		//	}
		//}
		//int b = data[frame.step*50 + 50];
		//cout << r << g << b << endl;


		//Mat finalImg(finalImg);
		
		vector< vector<Point> > contours;
		vector<Vec4i> hierarchy;
		//find contours of filtered image using openCV findContours function
		// findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );// retrieves all contours
		findContours(finalImg ,contours,hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE );// retrieves external contours

		vector<Point> approxShape;
		#pragma omp parallel for
		for (int i = 0; i < contours.size(); i++) {
			approxPolyDP(contours[i], approxShape, arcLength(Mat(contours[i]), true)*0.04, true);
			drawContours(finalImg, contours, i, Scalar(255,255,255), CV_FILLED); 
		}

		// flip(finalImg, finalImg, 1);
		// flip(frame3, frame3, 1);

		searchForMovement(finalImg, frame3);

		imshow("test", frame3);
		imshow("MyVideo", finalImg);
		
		t2 = clock();
		
		float diff = ((float)t2 - (float)t1);
		total += diff/CLOCKS_PER_SEC;
		count += 1;

		if(waitKey(30) >= 0){
			cout << "Avg time: " << total / count << endl;
			cout << "Terminating Video" << endl;
			break;
		}
	}
	
	return 0;
}

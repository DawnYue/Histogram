#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main()
{

	Mat dispMat = Mat::zeros(700, 700, CV_8UC3);
	cv::Point pt;
	pt.x = 10;
	pt.y = 10;
	circle(dispMat, pt, 5, CV_RGB(255, 0, 0), 1, 8, 0);
	imshow("dispMat", dispMat);
	waitKey(0);//等待用户按键

	//draw line
	Point pt1, pt2;
	pt1.x = 20;
	pt1.y = 20;
	pt2.x = 200;
	pt2.y = 200;
	line(dispMat, pt1, pt2, CV_RGB(255, 0, 0), 1, 8, 0);
	imshow("dispMat", dispMat);
	waitKey(0);//等待用户按键

	//draw rectangle  
	cv::Rect rect;
	rect.x = 350;
	rect.y = 350;
	rect.height=120;
	rect.width=100;
	rectangle(dispMat, rect, CV_RGB(255, 0, 0), 1, 8, 0);
	imshow("dispMat", dispMat);
	waitKey(0);//等待用户按键
	return 0;
}
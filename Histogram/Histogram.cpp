#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat src_colar = imread("E:\\4.png");

	std::vector<cv::Mat>channels;//声明vector，作为分离后3个通道图像的保存容器
	split(src_colar, channels);//分离rgb三通道

	cv::Mat B = channels.at(0);//获得3个通道的分离结果
	cv::Mat G = channels.at(1);//三个通道的排列
	cv::Mat R = channels.at(2);//顺序是B,G,R


	imshow("red", R);
	waitKey(0);
	imshow("blue", B);
	waitKey(0);
	imshow("green", G);
	waitKey(0);
	imshow("original Mat", src_colar);
	waitKey(0);//等待用户按键
	return 0;
}
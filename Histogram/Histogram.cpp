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

	Mat  dst;
	//转换成灰度图像，使原图成为单通道图像
	cvtColor(src_colar, dst, CV_BGR2GRAY);
	//查看图像通道数
	int c = dst.channels();
	cout << "=" << endl << c << endl;

	float histgram[256]= { 0 };
		for (int j = 0; j < dst.rows; j++) {
			uchar* data = src_colar.ptr <uchar>(j);
			for (int i = 0; i < dst.cols; i++) {
				//data[i] = j;
				histgram[data[i]] = histgram[data[i]] + 1;
			}
		}
	float total;
	total = src_colar.rows*src_colar.cols;
	for (int i = 0; i < 256; i++) {
		histgram[i] = histgram[i] / ;
    cout << "histgram" << histgram [i]<< endl;
	}

	imshow("src_colar", src_colar);
	waitKey(0);//等待用户按键
	return 0;
}
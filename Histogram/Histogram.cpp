#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat src_colar = imread("E:\\4.png");//读取 图片 存入名为 src_color的Mat容器中


	vector<Mat>bgr_planes;
	split(src_colar, bgr_planes);

	//步骤二：计算直方图
	int histsize = 256;
	float range[] = { 0,256 };
	const float*histRanges = { range };
	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histsize, &histRanges, true, false);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histsize, &histRanges, true, false);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histsize, &histRanges, true, false);

	//归一化
	int hist_h = 400;//直方图的图像的高
	int hist_w = 512;////直方图的图像的宽
	int bin_w = hist_w / histsize;//直方图的等级
	Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(0, 0, 0));//绘制直方图显示的图像
	normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX, -1, Mat());//归一化
	normalize(g_hist, g_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, hist_h, NORM_MINMAX, -1, Mat());

	//步骤三：绘制直方图（render histogram chart）
	for (int i = 1; i < histsize; i++)
	{
		//绘制蓝色分量直方图
		line(histImage, Point((i - 1)*bin_w, hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, CV_AA);
		//绘制绿色分量直方图
		line(histImage, Point((i - 1)*bin_w, hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, CV_AA);
		//绘制红色分量直方图
		line(histImage, Point((i - 1)*bin_w, hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, CV_AA);
	}
	imshow("src", histImage);
	waitKey(0);//等待用户按键
	return 0;
}
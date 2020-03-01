//equalizeHist(直方图均衡化)；提高图像对比度

  
#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;


static Scalar randomColor(RNG& rng)
{
	int iColor = unsigned(rng);
	//255 = 0xFF  
	return Scalar(iColor & 255, (iColor >> 8) & 255, (iColor >> 16) & 255);    //产生一种颜色  
}

int main()
{

	char wndName[] = "Drawing Demo";
	const int randomNumber = 100;
	const int DELAY = 10;
	int lineType = CV_AA;
	int height1 = 700;
	int width1 = 1000;
	int x1 = -width1 / 2;      //-500  
	int x2 = 3 * width1 / 2;    //1500  
	int y1 = -height1 / 2;     //-350  
	int y2 = 3 * height1 / 2;   //1050  
	RNG rng(0xFFFFFFFF);


	Mat image = Mat::zeros(height1, width1, CV_8UC3);
	imshow(wndName, image);
	waitKey(DELAY);

	//draw line  
	for (int i = 0; i < randomNumber; i++)
	{
		Point pt1, pt2;
		pt1.x = rng.uniform(x1, x2);
		pt1.y = rng.uniform(y1, y2);
		pt2.x = rng.uniform(x1, x2);
		pt2.y = rng.uniform(y1, y2);
		line(image, pt1, pt2, randomColor(rng), rng.uniform(1, 10), lineType);
		imshow(wndName, image);
		if (waitKey(DELAY) >= 0)
			return 0;
	}

	//draw rectangle  
	for (int i = 0; i < randomNumber; i++)
	{
		Point pt1, pt2;
		pt1.x = rng.uniform(x1, x2);
		pt1.y = rng.uniform(y1, y2);
		pt2.x = rng.uniform(x1, x2);
		pt2.y = rng.uniform(y1, y2);
		int thickness = rng.uniform(-3, 10);

		/*----------------------draws a simple, thick, or filled up-right rectangle-----------
		*   C++: void rectangle(Mat& img, Point pt1, Point pt2, const Scalar& color,
								int thickness=1, int lineType=8,int shift=0)
		*   C++: void rectangle(Mat& img, Rect rec, const Scalar& color, int thickness=1,
								int lineType=8, int shift=0)
		*   img – image
		*   pt1 – Vertex of the rectangle                    矩形的一个顶点p1
		*   pt2 – Vertex of the rectangle opposite to pt1    矩形的另一个顶点，与p1相对
		*   rec – Alternative specification of the drawn rectangle
		*   color – Rectangle color or brightness (grayscale image)      线条颜色，对于灰度图是亮度
		*   thickness – Thickness of lines that make up the rectangle. Negative values,   线条粗细
			like CV_FILLED, mean that the function has to draw a filled rectangle
		*   lineType – Type of the line. See the line() description       线条类型
		*   shift – Number of fractional bits in the point coordinates
		-----------------------------------------------------------------------------*/
		rectangle(image, pt1, pt2, randomColor(rng), MAX(thickness, -1), lineType);
		imshow(wndName, image);
		if (waitKey(DELAY) >= 0)
			return 0;
	}




	//draw ellipse  
	for (int i = 0; i < randomNumber; i++)
	{
		Point center;
		center.x = rng.uniform(x1, x2);
		center.y = rng.uniform(y1, y2);
		Size axes;
		axes.width = rng.uniform(0, 200);
		axes.height = rng.uniform(0, 200);
		double angle = rng.uniform(0, 180);

		/*---------draws a simple or thick elliptic arc or fills an ellipse sector---------
		*   C++: void ellipse(Mat& img, Point center, Size axes, double angle,
								double startAngle,double endAngle,const Scalar& color,
								int thickness=1, int lineType=8, int shift=0)
		*   C++: void ellipse(Mat& img, const RotatedRect& box, const Scalar& color,
								int thickness=1, int lineType=8)
		*   img – image
		*   center – Center of the ellipse 椭圆中心
		*   axes – Half of the size of the ellipse main axes 椭圆长轴的一半
		*   angle – Ellipse rotation angle in degrees 椭圆旋转的角度
		*   startAngle – Starting angle of the elliptic arc in degrees 弧度开始的角度
		*   endAngle – Ending angle of the elliptic arc in degrees 弧度结束的角度
		*   box – Alternative ellipse representation via RotatedRect or CvBox2D
			This means that the function draws an ellipse inscribed in the rotated rectangle
		*   color – Ellipse color
		*   thickness – Thickness of the ellipse arc outline, if positive. Otherwise, this indicates that a
			filled ellipse sector is to be drawn
		*   lineType – Type of the ellipse boundary. See the line() description
		*   shift – Number of fractional bits in the coordinates of the center and values of axes
		-----------------------------------------------------------------------------*/
		ellipse(image, center, axes, angle, angle - 100, angle + 200, randomColor(rng), rng.uniform(1, 8), lineType);
		imshow(wndName, image);
		if (waitKey(DELAY) >= 0)
			return 0;
	}

	
	//draw polygons with filled area  
	for (int i = 0; i < randomNumber; i++)
	{
		Point pt[2][3];
		pt[0][0].x = rng.uniform(x1, x2);
		pt[0][0].y = rng.uniform(y1, y2);
		pt[0][1].x = rng.uniform(x1, x2);
		pt[0][1].y = rng.uniform(y1, y2);
		pt[0][2].x = rng.uniform(x1, x2);
		pt[0][2].y = rng.uniform(y1, y2);
		pt[1][0].x = rng.uniform(x1, x2);
		pt[1][0].y = rng.uniform(y1, y2);
		pt[1][1].x = rng.uniform(x1, x2);
		pt[1][1].y = rng.uniform(y1, y2);
		pt[1][2].x = rng.uniform(x1, x2);
		pt[1][2].y = rng.uniform(y1, y2);
		const Point* ppt[2] = { pt[0], pt[1] };
		int npt[] = { 3, 3 };

		/*--------------fills the area bounded by one or more polygons---------------
		*   C++: void fillPoly( Mat& img, const Point** pts, const int* npts, int ncontours,
						const Scalar& color, int lineType=8, int shift=0, Point offset=Point() )
		*   img – image
		*   pts – Array of polygons where each polygon is represented as an array of points
		*   npts – Array of polygon vertex counters
		*   ncontours – Number of contours that bind the filled region
		*   color – Polygon color
		*   lineType – Type of the polygon boundaries. See the line() description
		*   shift – Number of fractional bits in the vertex coordinates
		*   offset – Optional offset of all points of the contours
		-----------------------------------------------------------------------------*/
		fillPoly(image, ppt, npt, 2, randomColor(rng), lineType);
		imshow(wndName, image);
		if (waitKey(DELAY) >= 0)
			return 0;
	}

	//draw circle  
	for (int i = 0; i < randomNumber; i++)
	{
		Point center;
		center.x = rng.uniform(x1, x2);
		center.y = rng.uniform(y1, y2);

		/*-----------------------------draw a circle----------------------------------
		*   C++: void circle(Mat& img, Point center, int radius, const Scalar& color,
								int thickness=1, int lineType=8,int shift=0)
		*   img – Image where the circle is drawn
		*   center – Center of the circle
		*   radius – Radius of the circle
		*   color – Circle color
		*   thickness – Thickness of the circle outline, if positive.
						Negative thickness means that a
		*   filled circle is to be drawn
		*   lineType – Type of the circle boundary. See the line() description
		*   shift – Number of fractional bits in the coordinates of the center and
			in the radius value
		-----------------------------------------------------------------------------*/
		circle(image, center, rng.uniform(0, 300), randomColor(rng), rng.uniform(-1, 9), lineType);
		imshow(wndName, image);
		if (waitKey(DELAY) >= 0)
			return 0;
	}

	//put text on the image  
	for (int i = 0; i < randomNumber; i++)
	{
		Point org;
		org.x = rng.uniform(x1, x2);
		org.y = rng.uniform(y1, y2);
		putText(image, "Testing text rendering", org, rng.uniform(0, 8)/*font type*/,
			rng.uniform(0, 100)*0.05 + 0.1/*font scale*/,
			randomColor(rng), rng.uniform(1, 10)/*thickness*/, lineType);
		imshow(wndName, image);
		if (waitKey(DELAY) >= 0)
			return 0;
	}

	/*------------------calculates the width and height of a text string--------------
	*   C++: Size getTextSize( const string& text, int fontFace, double fontScale,
								int thickness, int* baseLine)
	*   text – Input text string
	*   fontFace – Font to use. See the putText() for details
	*   fontScale – Font scale. See the putText() for details
	*   thickness – Thickness of lines used to render the text
	*   baseLine – Output parameter - y-coordinate of the baseline relative
					to the bottom-most text point.
	--------------------------------------------------------------------------------------*/
	//string text = " OpenCV Forever!" ;  
	//int fontFace = FONT_HERSHEY_COMPLEX;  
	//double fontScale = 2;  
	//int thickness = 3;  
	//int baseline=0;  
	//baseline += thickness;  
	//Size textSize = getTextSize(text, fontFace,  
	//                      fontScale, thickness, &baseline);  

	Size textSize = getTextSize("OpenCV Forever!", FONT_HERSHEY_COMPLEX, 3, 5, 0);
	Point org((width1 - textSize.width) / 2, (height1 - textSize.height) / 2);

	Mat image2;
	for (int i = 0; i < 255; i += 2)
	{
		image2 = image - Scalar::all(i);
		putText(image2, "OpenCV Forever!", org, FONT_HERSHEY_COMPLEX,
			3, Scalar(i, i, 255), 5, lineType);

		imshow(wndName, image2);
		if (waitKey(DELAY) >= 0)
			return 0;
	}

	waitKey();



    Mat  dst, dst1, dst2;
	cv::Mat srcMat = imread("E:\\3.png");
	cv::Mat deepMat;
	cv::Mat shallowMat;

    //转换成灰度图像，使原图成为单通道图像
	cvtColor(srcMat, dst, CV_BGR2GRAY);
	//查看图像通道数
	int c = dst.channels();
	cout << "=" << endl << c << endl;
	//直方图均衡化
	equalizeHist(dst, dst1);
	imshow("src", dst);// 
    //等待用户按键
	waitKey(0);

	imshow("src", dst1);// 
	//等待用户按键
	waitKey(0);



	//分割通道，彩色
	vector<Mat>channels;
	split(srcMat, channels);

	Mat blue, green, red;
	blue = channels.at(0);
	green = channels.at(1);
	red = channels.at(2);
	//分别对BGR通道做直方图均衡化
	equalizeHist(blue, blue);
	equalizeHist(green, green);
	equalizeHist(red, red);
	//合并通道
	merge(channels, dst2);

	imshow("src", dst2);
	//等待用户按键
	waitKey(0);




	//步骤一：分通道显示  绘制直方图
	vector<Mat>bgr_planes;
	split(srcMat, bgr_planes);
	//split(// 把多通道图像分为多个单通道图像 const Mat &src, //输入图像 Mat* mvbegin）// 输出的通道图像数组

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
	waitKey(0);



	shallowMat = srcMat;
	srcMat.copyTo(deepMat);
	int height = srcMat.rows; //行数
	int width = srcMat.cols; //每行元素的总元素数量
	uchar threshold = 100;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++)
		{
			//处理每个像素
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] +
				srcMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold) {
				average = 255;
			}
			else {
				average = 0;
			}
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
			//结束像素处理
		} //单行处理结束
	}



	imshow("src", shallowMat);//浅拷贝
	//等待用户按键
	waitKey(0);

	imshow("src", deepMat);//深拷贝
	//等待用户按键
	waitKey(0);
	return 0;
}
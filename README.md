# Histogram第二周
 opencv简单实践2：分离rgb三通道、调摄像头、绘图操作、直方图计算与绘制

https://www.bilibili.com/video/BV1UE411c7zL/

练习1
读取一张图片，存入名为src_color的Mat容器中
声明vector，作为分离后3个通道图像的保存容器
调用split函数，分离src_color的rgb三通道
定义3个Mat容器获得3个通道的分离结果，注意
opencv中三个通道的排列顺序是B,G,R。
显示3个通道的图像，以及原图

练习2 调用本机的摄像头。
实例化一个VideoCapture类，名称为cap
cap(0)表示打开本机的第一个摄像头，()中如果是本地视频地址如cap(“D:\\1.avi”)则可以打开本地视频。
isOpened()检查视频是否开启，正常开启返回1
通过get()及不同参数可以获得视频的不同参数，如本例获得视频的fps
声明Mat类型图片，名称为frame，并通过read()获得视频的当前帧
通过imshow显示当前帧
waitKey延时，如缺少，无法显示

练习3 opencv的基本绘图功能
画圆：
画圆的目标图像圆心的点圆的半径圆的颜色圆的线条粗细，取-1为绘制实心圆领接关系和偏移，一般设置默认值，8和0

画线段：
画线的目标图像线段的起点和终点线段的颜色线段的粗细领接关系和偏移，一般设置默认值，8和0

画矩形框：
Opencv中定义一个矩形语句，定义完成后首先对x,y的坐标值赋值，然后对宽度和高度赋值画矩形的目标图像被绘制的矩形矩形的颜色 矩形的粗细，-1则为实心矩形领接关系和偏移，一般设置默认值，8和0

练习4 直方图计算   （先转成灰度图）
定义一个容量为256的float型数组，遍历图像的每个像素，并计算直方图，将结果存入数组中。数组声明方式Float histgram[256]；

练习5 直方图绘制
利用练习4的结果，以及画线或者画圆的函数，绘制一副直方图

ps：练习都在分支中
课前准备为3个通道的直方图

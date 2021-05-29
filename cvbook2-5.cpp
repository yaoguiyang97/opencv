#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
/*
//颜色缩减的其中一种方法，（函数）
void colorreduce(Mat& image, int div = 64) {
	int n1 = image.rows;
	int nc = image.cols * image.channels();//获取每行像素值
	//for (int j = 0; j < n1; j++) {
	//	uchar* data = image.ptr<uchar>(j);//ptr函数得到图像任意首地址，ptr返回第J行的首地址
	//	//for (int i = 0; i < nc; i++) {//可提前计算的变量，提高运算速度
	//	for (int i = 0; i < image.cols * image.channels(); i++) {
	//		data[i] = data[i] / div * div + div / 2;//使用指针从一列移到下一列（颜色缩减函数公式1）
	//	//*data++ = *data / div * div + div/2;//颜色缩减函数公式2
	//	//data[i] = data[i] - data[i] % div + div / 2; //颜色缩减函数公式3,这个方法比较慢

	//	////用位运算(非常高效)，限制缩减因子为2^n,（运用掩模???）
	//	//uchar mask = OxFF << n;//e.g.for div=16,mask=OxFo;
	//	//data[i] = (data[i] & mask) + div / 2;

	//	}
	//}
	for (int j = 0; j < n1; j++) {
		for (int i = 0; i < nc; i++) {
			image.at<Vec3b>(j, i)[0] =
				image.at<Vec3b>(j, i)[0] / div * div + div / 2;
			image.at<Vec3b>(j, i)[1] =
				image.at<Vec3b>(j, i)[1] / div * div + div / 2;
			image.at<Vec3b>(j, i)[2] =
				image.at<Vec3b>(j, i)[2] / div * div + div / 2;
		}
	}
}
*/
void colorreduce(Mat& image, int div = 64) {
	int n1 = image.rows;
	int nc = image.cols;
	if (image.isContinuous()) {
		nc = nc * n1;
		n1 = 1;
	}
	int n = static_cast<int>(
		log(static_cast<double>(div)) / log(2.0));
	uchar mask = 0xFF << n;
	for (int j = 0; j < nc; j++) {
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; i++) {
			*data++ = *data & mask + div / 2;
			*data++ = *data & mask + div / 2;
			*data++ = *data & mask + div / 2;
		}
	}
}
int main() {
	Mat img;
	img = imread("D:/opencvcode/img/13.png");

	//colorreduce(img);//调用颜色缩减函数

	double duration;//count the run time
	duration = static_cast<double>(cv::getTickCount());
	colorreduce(img);
	duration = static_cast<double>(cv::getTickCount()) - duration;
	duration /= cv::getTickFrequency();




	namedWindow("input");
	imshow("input", img);
	waitKey(0);

	return 0;
}
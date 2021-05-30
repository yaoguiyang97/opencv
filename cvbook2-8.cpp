
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
int main() {
	Mat image = imread("D:/opencvcode/img/13.png");
	Mat logo = imread("D:/opencvcode/img/13-2.png");
	cv::Mat imageROI;
	imageROI = image(cv::Rect(385, 270,logo.cols.logo.rows));
	cv::addWeighted(imageROI, 1.0, logo, 0.3, 0., imageROI);

	namedWindow("input1");
	imshow("input1", image);

	//sharpen(image, image);
	//sharpen2D(image, image);

	waitKey(0);
	return 0;
}
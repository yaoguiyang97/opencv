//Í¼ÏñµÄÔËËã
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
void sharpen2D(const cv::Mat& image, cv::Mat& result) {
	cv::Mat kernel(3, 3, CV_32F, cv::Scalar(0));
	kernel.at<float>(1, 1) = 5.0;
	kernel.at<float>(0, 1) = -1.0;
	kernel.at<float>(2, 1) = -1.0;
	kernel.at<float>(1, 0) = -1.0;
	kernel.at<float>(1, 2) = -1.0;
	cv::filter2D(image, result, image.depth(), kernel);
	}

int main() {
	Mat image = imread("D:/opencvcode/img/13.png");
	Mat image2 = imread("D:/opencvcode/img/13-1png");
	cv::addWeighted(image, 0.7, image2, 0.9, 0., result);
	sharpen2D(image, image);
	namedWindow("input");
	imshow("input", image);
	waitKey(0);
	return 0;
}
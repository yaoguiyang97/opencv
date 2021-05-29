//锐化//基于拉普拉斯算子//公式sharpened_pixel=5*current-left-right-up-down;
//三个指针，当前行，上一行，下一行
//用黑白图像效果更明显，彩色：cv::Scalar(a,b,c)
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;//method1
/*
void sharpen(const Mat& image, Mat& result) {
	result.create(image.size(), image.type());
	for (int j = 1; j < image.rows - 1; j++) {
		const uchar* previous =
			image.ptr<const uchar>(j - 1);
		const uchar* current =
			image.ptr<const uchar>(j);
		const uchar* next =
			image.ptr<const uchar>(j + 1);
		uchar* output = result.ptr<uchar>(j);
		for (int i = 0; i < image.cols - 1; i++) {
			*output++ = saturate_cast<uchar>(
				5 * current[i] - current[i - 1]
				- current[i + 1] - previous[i] - next[i]);
		}
	}
	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows - 1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols - 1).setTo(cv::Scalar(0));
}*/
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
	namedWindow("input1");
	imshow("input1", image);
	//sharpen(image, image);
	sharpen2D(image, image);

	namedWindow("input2");
	imshow("input2", image);

	waitKey(0);
	return 0;
}
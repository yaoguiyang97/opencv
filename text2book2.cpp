#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
int main() {
	Mat src = imread("D:/opencvcode/img/13.png",IMREAD_COLOR);//IMREAD_UNCHANGED/��������//�������ر���IMREAD_GRAYSCALE
	if (src.empty()) {
		printf("could not load.");
		return -1;
	}

	namedWindow("opencv img1", WINDOW_AUTOSIZE);//������ʾ����
	imshow("opencv img1", src);//��ʾ����

	namedWindow("outputwindow", WINDOW_AUTOSIZE);
	Mat output_image;
	cvtColor(src, output_image, COLOR_BGR2HLS);//COLOR_BGR2GRAY
	imshow("output window", output_image);

	waitKey(5000);
	
	//Mat result;
	//flip(src, result, 1);//��ת����
	//namedWindow("opencv img2");
	//imshow("opencv img2", result);
	//waitKey(5000);

	//Mat output;
	//cvtColor(src, output, COLOR_BGR2HLS);//�ı�����
	//imshow("output windows", output);

	//imwrite("13-2.png", output);//����

	//waitKey(5000);
	return 0;
}
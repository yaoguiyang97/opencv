#include<opencv2/opencv.hpp>
#include<iostream>
//#include<math.h>

using namespace cv;
int main() {
	Mat src = imread("D:/opencvcode/img/12.png");//载入像素//声明像素变量
	if (src.empty()) {
		printf("could not load.");
		return -1;
	}

	namedWindow("opencv img1",WINDOW_AUTOSIZE);//定义显示窗口
	imshow("opencv img1", src);//显示像素
	waitKey(5000);

	//Mat result;
	//flip(src, result, 1);//反转像素
	//namedWindow("opencv img2");
	//imshow("opencv img2", result);
	//waitKey(5000);

	//Mat output;
	//cvtColor(src, output, COLOR_BGR2HLS);//改变像素
	//imshow("output windows", output);

	//imwrite("13-2.png", output);//保存

	//waitKey(5000);
	return 0;
}
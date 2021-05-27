#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
//Mat Iterator_<Vec3b>it;//创建一个迭代器特化版本1
//Mat_<Vec3b>::iterator it;//创建一个迭代器特化版本2

void colorreduce(Mat& img, int div = 64) {
	Mat_<Vec3b>::iterator it = img.begin<Vec3b>();//处理彩色图像3b,用begin方法获得初始位置，得到左上角位置的迭代器
	//img.begin<Vec3b>() + img.rows;//从图像的第二行开始
	Mat_<Vec3b>::iterator itend = img.end<Vec3b>();//终止迭代的运算
	//img.end<Vec3b>() - img.rows;//希望在迭代过程的图像最后一行之前停止
	for (; it != itend; ++it) {
		(*it)[0] = (*it)[0] / div * div + div / 2;
		(*it)[1] = (*it)[1] / div * div + div / 2;
		(*it)[2] = (*it)[2] / div * div + div / 2;
	}

}
int main() {
	Mat img = imread("D:/opencvcode/img/13.png");
	if (img.empty()) {
		printf("not img!");
		return -1;
	}
	colorreduce(img);//函数调用
	namedWindow("input");
	imshow("input", img);

	waitKey(0);
	return 0;
}


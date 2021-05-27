#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
//颜色缩减的其中一种方法，（函数）
void colorreduce(Mat& image, int div = 64) {
	int n1 = image.rows;
	int nc = image.cols * image.channels();//获取每行像素值
	for (int j = 0; j < n1; j++) {
		uchar* data = image.ptr<uchar>(j);//ptr函数得到图像任意首地址，ptr返回第J行的首地址
		for (int i = 0; i < nc; i++) {
			data[i] = data[i] / div * div + div / 2;//使用指针从一列移到下一列（颜色缩减函数公式1）
		//*data++ = *data / div * div + div/2;//颜色缩减函数公式2
		//data[i] = data[i] - data[i] % div + div / 2; //颜色缩减函数公式3,这个方法比较慢

		////用位运算(非常高效)，限制缩减因子为2^n,（运用掩模???）
		//uchar mask = OxFF << n;//e.g.for div=16,mask=OxFo;
		//data[i] = (data[i] & mask) + div / 2;

		}
	}
}

////result.creatr(image.rows, image.cows, image.tye());
//	for (int j = 0; j < n1; j++) {
//		const uchar* data_in = image.ptr<uchar>(j);
//		uchar* data_out = result.ptr<uchar>(j);
//		for (int i = 0; i < nc; i++) {
//			data_out[i] = data_in[i] / div * div + div / 2;
//		}
//	}

int main() {
	Mat img;
	img = imread("D:/opencvcode/img/13.png");

	colorreduce(img);//调用颜色缩减函数
	namedWindow("input");
	imshow("input", img);

	Mat imageClone = img.clone();//clone函数的使用//处理克隆的图像
	colorreduce(imageClone);//原始图像不变

	void colorReduce(const Mat & image,//输入图像
		Mat & resul,                  //输出图像
		int div = 64);
	//colorreduce(img,img);//不能用，mat->int

	//////另一个实列
	//cv::Mat result;
	//colorreduce(img,result);

	void colorreduce(Mat & img, int div = 64) {
		int n1 = img.rows;
		int nc = img.cols * img.channels();
		if (img.isContinuous())//函数
		{
			nc = nc * n1;
			n1 = 1;
		}
		for (int j = 0; j < n1; j++) {
			uchar* data = img.ptr<uchar>(j);
			data[i] = data[i] / div * div + div / 2;
		}
	}

	if (img.isContinuous())
	{
		img.reshape(1,img.cols * img.rows);
	}
	int n1 = img.rows;
	int nc = img.cols * img.channels();

	/*namedWindow("output");
	imshow("output", imageClone);*/


	namedWindow("input");
	imshow("input", img);
	waitKey(0);
	return 0;
}
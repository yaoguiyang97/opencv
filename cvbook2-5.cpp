#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
/*
//��ɫ����������һ�ַ�������������
void colorreduce(Mat& image, int div = 64) {
	int n1 = image.rows;
	int nc = image.cols * image.channels();//��ȡÿ������ֵ
	//for (int j = 0; j < n1; j++) {
	//	uchar* data = image.ptr<uchar>(j);//ptr�����õ�ͼ�������׵�ַ��ptr���ص�J�е��׵�ַ
	//	//for (int i = 0; i < nc; i++) {//����ǰ����ı�������������ٶ�
	//	for (int i = 0; i < image.cols * image.channels(); i++) {
	//		data[i] = data[i] / div * div + div / 2;//ʹ��ָ���һ���Ƶ���һ�У���ɫ����������ʽ1��
	//	//*data++ = *data / div * div + div/2;//��ɫ����������ʽ2
	//	//data[i] = data[i] - data[i] % div + div / 2; //��ɫ����������ʽ3,��������Ƚ���

	//	////��λ����(�ǳ���Ч)��������������Ϊ2^n,��������ģ???��
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

	//colorreduce(img);//������ɫ��������

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
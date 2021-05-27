#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
//Mat Iterator_<Vec3b>it;//����һ���������ػ��汾1
//Mat_<Vec3b>::iterator it;//����һ���������ػ��汾2

void colorreduce(Mat& img, int div = 64) {
	Mat_<Vec3b>::iterator it = img.begin<Vec3b>();//�����ɫͼ��3b,��begin������ó�ʼλ�ã��õ����Ͻ�λ�õĵ�����
	//img.begin<Vec3b>() + img.rows;//��ͼ��ĵڶ��п�ʼ
	Mat_<Vec3b>::iterator itend = img.end<Vec3b>();//��ֹ����������
	//img.end<Vec3b>() - img.rows;//ϣ���ڵ������̵�ͼ�����һ��֮ǰֹͣ
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
	colorreduce(img);//��������
	namedWindow("input");
	imshow("input", img);

	waitKey(0);
	return 0;
}


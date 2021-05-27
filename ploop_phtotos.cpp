#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
//��ɫ����������һ�ַ�������������
void colorreduce(Mat& image, int div = 64) {
	int n1 = image.rows;
	int nc = image.cols * image.channels();//��ȡÿ������ֵ
	for (int j = 0; j < n1; j++) {
		uchar* data = image.ptr<uchar>(j);//ptr�����õ�ͼ�������׵�ַ��ptr���ص�J�е��׵�ַ
		for (int i = 0; i < nc; i++) {
			data[i] = data[i] / div * div + div / 2;//ʹ��ָ���һ���Ƶ���һ�У���ɫ����������ʽ1��
		//*data++ = *data / div * div + div/2;//��ɫ����������ʽ2
		//data[i] = data[i] - data[i] % div + div / 2; //��ɫ����������ʽ3,��������Ƚ���

		////��λ����(�ǳ���Ч)��������������Ϊ2^n,��������ģ???��
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

	colorreduce(img);//������ɫ��������
	namedWindow("input");
	imshow("input", img);

	Mat imageClone = img.clone();//clone������ʹ��//�����¡��ͼ��
	colorreduce(imageClone);//ԭʼͼ�񲻱�

	void colorReduce(const Mat & image,//����ͼ��
		Mat & resul,                  //���ͼ��
		int div = 64);
	//colorreduce(img,img);//�����ã�mat->int

	//////��һ��ʵ��
	//cv::Mat result;
	//colorreduce(img,result);

	void colorreduce(Mat & img, int div = 64) {
		int n1 = img.rows;
		int nc = img.cols * img.channels();
		if (img.isContinuous())//����
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
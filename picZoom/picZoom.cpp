#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
using namespace cv;

// ȫ�ֱ���
Mat src, dst, tmp;
char* window_name = "Zoom Demo";
bool flag = false;

void picZoom1();//ͼ�������
void picZoom2(int);//Resize����

int main()
{
	char n, m;
	// ָʾ˵��
	cout << "select Zoom mod " << endl;
	cout << "------------------ " << endl;
	cout << " * [1] -> Image Pyramid  " << endl;
	cout << " * [2] -> Resize " << endl;
	cout << " * [OTHER] -> Close program " << endl << endl;
	cin >> n;
	flag = true;
	if ('1' == n)
		picZoom1();
	else if ('2' == n)
	{
		// ָʾ˵��
		cout << "select Zoom mod " << endl;
		cout << "------------------ " << endl;
		cout << " * [1] -> INTER_NEAREST  " << endl;
		cout << " * [2] -> INTER_LINEAR " << endl;
		cout << " * [3] -> INTER_AREA  " << endl;
		cout << " * [4] -> INTER_CUBIC " << endl;
		cout << " * [5] -> INTER_LANCZOS4  " << endl;
		cout << " * [OTHER] -> Again " << endl << endl;
		cin >> m;
		while (m > '5' || m < '1')
			cin >> m;
		picZoom2(m - 1);
	}
	return 0;
}

void picZoom1()
{
	// ָʾ˵��
	cout << "Zoom In-Out demo (Image Pyramid)" << endl;
	cout << "------------------ " << endl;
	cout << " * [u] -> Zoom in  " << endl;
	cout << " * [d] -> Zoom out " << endl;
	cout << " * [ESC] -> Close program " << endl << endl;
	// ����ͼ�� - �ߴ�����ܱ� 2^{n} ����
	src = imread("cat.jpg");
	if (!src.data)
	{
		cout << " No data! -- Exiting the program " << endl;
		return;
	}

	tmp = src;
	dst = tmp;

	// ������ʾ����
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	imshow(window_name, dst);

	// ѭ��
	while (true)
	{
		int c;
		c = waitKey(10);

		if ((char)c == 27)
		{
			break;
		}
		if ((char)c == 'u')
		{
			pyrUp(tmp, dst, Size(tmp.cols * 2, tmp.rows * 2));
			cout << "** Zoom In: Image x 2 " << endl;
		}
		else if ((char)c == 'd')
		{
			pyrDown(tmp, dst, Size(tmp.cols / 2, tmp.rows / 2));
			cout << "** Zoom Out: Image / 2 " << endl;
		}

		imshow(window_name, dst);
		tmp = dst;
	}
}

void picZoom2(int interpolation)
{
	// ָʾ˵��
	cout << "Zoom In-Out demo (Resize)" << endl;
	cout << "------------------ " << endl;
	cout << " * [u] -> Zoom in  " << endl;
	cout << " * [d] -> Zoom out " << endl;
	cout << " * [ESC] -> Close program " << endl << endl;
	// ����ͼ�� - �ߴ�����ܱ� 2^{n} ����
	src = imread("cat.jpg");
	if (!src.data)
	{
		cout << " No data! -- Exiting the program " << endl;
		return;
	}

	tmp = src;
	dst = tmp;

	// ������ʾ����
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	imshow(window_name, dst);

	// ѭ��
	while (true)
	{
		int c;
		c = waitKey(10);

		if ((char)c == 27)
		{
			break;
		}
		if ((char)c == 'u')
		{
			resize(tmp, dst, Size(tmp.cols * 2, tmp.rows * 2), interpolation);
			cout << "** Zoom In: Image x 2 " << endl;
		}
		else if ((char)c == 'd')
		{
			resize(tmp, dst, Size(tmp.cols / 2, tmp.rows / 2), interpolation);
			cout << "** Zoom Out: Image / 2 " << endl;
		}

		imshow(window_name, dst);
		tmp = dst;
	}
}
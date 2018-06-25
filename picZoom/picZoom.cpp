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


int main()
{
	// ָʾ˵��
	cout << "\n Zoom In-Out demo   " << endl;
	cout << "------------------ " << endl;
	cout << " * [u] -> Zoom in  " << endl;
	cout << " * [d] -> Zoom out " << endl;
	cout << " * [ESC] -> Close program " << endl << endl;
	// ����ͼ�� - �ߴ�����ܱ� 2^{n} ����
	src = imread("cat.jpg");
	if (!src.data)
	{
		cout << " No data! -- Exiting the program " << endl;
		return -1;
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
	return 0;
}
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
using namespace cv;

// 全局变量
Mat src, dst, tmp;
char* window_name = "Zoom Demo";


int main()
{
	// 指示说明
	cout << "\n Zoom In-Out demo   " << endl;
	cout << "------------------ " << endl;
	cout << " * [u] -> Zoom in  " << endl;
	cout << " * [d] -> Zoom out " << endl;
	cout << " * [ESC] -> Close program " << endl << endl;
	// 测试图像 - 尺寸必须能被 2^{n} 整除
	src = imread("cat.jpg");
	if (!src.data)
	{
		cout << " No data! -- Exiting the program " << endl;
		return -1;
	}

	tmp = src;
	dst = tmp;

	// 创建显示窗口
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	imshow(window_name, dst);

	// 循环
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
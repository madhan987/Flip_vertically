
//flip the image vertically
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;

int main()
{
	//Reading input image
	Mat image = imread("C:\\Users\\HP\\Pictures\\Download\\p1.jpg");

	//Displaying input image
	imshow("1", image);

	Mat grey_image(image.rows, image.cols, CV_8UC1);

	Mat vertical_flip(image.cols, image.rows, CV_8UC1);

	//converting RGB to gray scale
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			grey_image.at<uchar>(i, j) = (image.at<Vec3b>(i, j)[0] + image.at<Vec3b>(i, j)[1] + image.at<Vec3b>(i, j)[2]) / 3;
		}
	}



	//Displaying grey image
	imshow("2", grey_image);


	int m = image.rows;
	for (int i = 0; i < image.rows; i++)
	{

		m--;

		for (int j = 0; j < image.cols; j++)
		{
			vertical_flip.at<uchar>(i, j) = grey_image.at<uchar>(m, j);

		}

	}

	//Displaying vertically flipped image
	imshow("3", vertical_flip);

	waitKey(0);

	return 1;
}
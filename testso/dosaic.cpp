#include "dosaic.h"
#include <opencv2/core/types_c.h>

#include <opencv2/imgcodecs.hpp>

CDosaic::CDosaic(const wchar_t* file)
{
	std::wstring t(file);
	mFile = cv::String(t.begin(), t.end());
}
void CDosaic::setFile(string file)
{
	//std::wstring t(file);
	mFile = cv::String(file);
	ReadImage();
}
void CDosaic::Dot(int type, int x, int y, int r)
{
	
	x += 3;
	y += 3;
	//type = 7;
	switch (type)
	{

	case 7:
		SetPixel(x - 1, y - 3);
		SetPixel(x + 2, y - 3);
		SetPixel(x + 3, y - 2);
		SetPixel(x + 4, y - 1);
		SetPixel(x + 4, y + 2);
		SetPixel(x + 3, y + 3);
		SetPixel(x + 2, y + 4);
		SetPixel(x - 1, y + 4);
		SetPixel(x - 2, y + 3);
		SetPixel(x - 3, y + 2);
		SetPixel(x - 3, y - 1);
		SetPixel(x - 2, y - 2);
	case 6:
		SetPixel(x, y - 3);
		SetPixel(x + 1, y - 3);

		SetPixel(x + 4, y);
		SetPixel(x + 4, y + 1);

		SetPixel(x + 1, y + 4);
		SetPixel(x, y + 4);
		SetPixel(x - 3, y);
		SetPixel(x - 2, y - 1);
	case 5:
		SetPixel(x + 2, y - 2);
		SetPixel(x + 3, y - 1);

		SetPixel(x + 3, y + 2);
		SetPixel(x + 2, y + 3);

		SetPixel(x - 1, y + 3);
		SetPixel(x - 2, y + 2);
		SetPixel(x - 3, y + 1);
		SetPixel(x - 1, y - 2);


	case 4:

		SetPixel(x, y - 2);
		SetPixel(x + 1, y - 2);

		SetPixel(x + 3, y);
		SetPixel(x + 3, y + 1);

		SetPixel(x + 1, y + 3);
		SetPixel(x, y + 3);

		SetPixel(x - 2, y + 1);
		SetPixel(x - 2, y);

	case 3:	
		SetPixel(x + 2, y - 1);
		SetPixel(x + 2, y + 2);
		SetPixel(x - 1, y + 2);	
		SetPixel(x - 1, y - 1);	

	case 2:

		SetPixel(x, y - 1);
		SetPixel(x + 1, y - 1);
		SetPixel(x + 2, y);
		SetPixel(x + 2, y + 1);
	case 1:
		SetPixel(x + 1, y + 2);
		SetPixel(x, y + 2);
		SetPixel(x - 1, y + 1);
		SetPixel(x - 1, y);
	default:
		SetPixel(x, y);
		SetPixel(x, y + 1);
		SetPixel(x + 1, y);
		SetPixel(x + 1, y + 1);
		break;
	}

}

void CDosaic::ReadImage() 
{
	if (!mFile.empty())
	{
		double ratio;
		Mat mat;
	
		mat = imread(mFile);
		if (!mat.empty())
		{
			ratio = ((double)1280) / mat.cols;
			resize(mat, mmatOrigin, Size(), ratio, ratio);
			mat.release();
			mmatDosaic.create(mmatOrigin.rows, mmatOrigin.cols / 8 * 8, CV_8UC3);
		}
	}
}

void CDosaic::implement() 
{
	// TODO: Add your implementation code here.
	int rate = 8; //mmatDosaic.rows * 8 / 1280; 

	Vec3b bgr;
	int sum;
	for (size_t row = 0; row < (int)mmatOrigin.rows - rate; row += rate)
	{
		for (size_t col = 0; col < (int)mmatOrigin.cols - rate; col += rate)
		{
			sum = 0;
			for (int ii = row; ii < row + rate; ii++)
			{
				for (int jj = col; jj < col + rate; jj++)
				{
					bgr = mmatOrigin.at<Vec3b>(ii, jj); //用Vec3b也行
					sum += bgr.val[0] + bgr.val[1] + bgr.val[2];

				}
			}
			//sum = col / 160;
			sum += rate * rate * 3 * 16;
			sum /= (rate * rate * 3 * 32);
			Dot(sum, row, col, 8);

		}
	}
}

void CDosaic::SetPixel(int x, int y)
{
	size_t start = (x * mmatDosaic.cols + y);
	mmatDosaic.at<Vec3b>(start).val[0] = 220;
	mmatDosaic.at<Vec3b>(start).val[1] = 220;
	mmatDosaic.at<Vec3b>(start).val[2] = 220;
}


void CDosaic::Save() const
{
	// TODO: Add your implementation code here.
	if (!mmatDosaic.empty())
	{
		imwrite(mFile + ".jpg", mmatDosaic);  //偷个懒
	}
}
#pragma once
#include <iostream>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

class CDosaic{
public:
    CDosaic(){}
	CDosaic(const wchar_t* file);     
    void implement();
	void setFile(string str);
	void ReadImage();
	void Save()const;
private:
	Mat mmatOrigin;
	Mat mmatDosaic;
	void Dot(int type, int x, int y, int r);
	void SetPixel(int x, int y);
	
	cv::String mFile;

};

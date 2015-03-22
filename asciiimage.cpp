#include <iostream>
#include "asciiimage.h"

using namespace std;

const char AsciiImage::seventyShadesOfGrey[70] = {' ','.','\'','`','^','"',',',':',';','I','l','!','i','>','<','~','+','_','-','?',']','[','}','{','1',')','(','|','\\','/','t','f','j','r','x','n','u','v','c','z','X','Y','U','J','C','L','Q','0','O','Z','m','w','q','p','d','b','k','h','a','o','*','#','M','W','&','8','%','B','@','$'};


AsciiImage::AsciiImage(int width,int height)
{
	int i = 0;

	this->height = height;
	this->width = width;
	image = new char[height*width];

	for(i=0;i<height*width;i++)
	{
		image[i] = ' ';
	}

}


void AsciiImage::setPix(int x, int y, int color)
{
	image[width*y+x] = seventyShadesOfGrey[color];
}

void AsciiImage::show()
{
	int i = 0;
	int j = 0;
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			cout << image[(width*i+j)];
		}
		cout  << endl;
	}
}

AsciiImage::~AsciiImage()
	{
			delete[] image;
	}

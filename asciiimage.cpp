#include <iostream>
#include "asciiimage.h"

using namespace std;

static const char shadeChars[] = {'$','@','B','%','8','&','W','M','#','*','o','a','h','k','b','d','p','q','w','m','Z','O','0','Q','L','C','J','U','Y','X','z','c','v','u','n','x','r','j','f','t','/','\\','|','(',')','1','{','}','[',']','?','-','_','+','~','<','>','i','!','l','I',';',':',',','"','^','`','\'','.',' '};;
const char * AsciiImage::seventyShadesOfGrey = shadeChars;

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
	int revert = 70 - color;
	char a = seventyShadesOfGrey[revert];

	image[width*y+x] = a;
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

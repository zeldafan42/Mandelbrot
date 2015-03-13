#include <iostream>
#include "asciiimage.h"

using namespace std;

static const char shadeChars[] = {'$','@','B','%','8','&','W','M','#','*','o','a','h','k','b','d','p','q','w','m','Z','O','0','Q','L','C','J','U','Y','X','z','c','v','u','n','x','r','j','f','t','/','\\','|','(',')','1','{','}','[',']','?','-','_','+','~','<','>','i','!','l','I',';',':',',','"','^','`','\'','.',' '};;
const char * AsciiImage::seventyShadesOfGrey = shadeChars;

AsciiImage::AsciiImage(int height,int width)
{
	this->height = height;
	this->width = width;
	image = new char[height*width];
}


void AsciiImage::setPix(int x, int y, int color)
{
	if(color>69)
	{
		color = 69;
	}
	if(color<0)
	{
		color = 0;
	}
	char a = seventyShadesOfGrey[color];

	image[(height-1)*(y-1)+x] = a;
}

void AsciiImage::show()
{
	int i = 0;
	int j = 0;
	for(i=0;i<width;i++)
	{
		for(j=0;j<height;j++)
		{
			cout << image[(i*(height-1)+j)];
		}
		cout  << endl;
	}
}

AsciiImage::~AsciiImage()
	{
			delete[] image;
	}

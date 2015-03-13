#include <iostream>
#include "asciiimage.h"

using namespace std;


AsciiImage::AsciiImage(int height,int width)
{
	this->height = height;
	this->width = width;
	image = new char[height*width];
}


void AsciiImage::setPix(int x, int y, int color)
{
	if(color>70)
	{
		color = 70;
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

void AsciiImage::print()
{
	for(int i = 0; i<70; i++)
	{
		cout << seventyShadesOfGrey[i]<< endl;


	}
}


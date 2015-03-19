/*
 * mandelbrot.cpp
 *
 *  Created on: 13.03.2015
 *      Author: Christoph Majcen
 *      		Arthur Bouz
 */

#include <iostream>
#include "asciiimage.h"

using namespace std;

void calculateAndWriteToImage(AsciiImage * img,double x0,double y0,double x1,double y1,int width,int height,int max);
bool evaluateInputs(double x0, double y0, double x1, double y1, int width, int height, int max);

int main()
{
	AsciiImage * myImage;
	int width;
	int height;
	double x0;
	double y0;
	double x1;
	double y1;
	int max;

	do
	{
	cout << "Enter Width: ";
	cin >> width;
	cout << "Enter Height: ";
	cin >> height;
	cout << "Enter x0: ";
	cin >> x0;
	cout << "Enter y0: ";
	cin >> y0;
	cout << "Enter x1: ";
	cin >> x1;
	cout << "Enter y1: ";
	cin >> y1;
	cout << "Enter max: ";
	cin >> max;
	}
	while(evaluateInput(x0,y0,x1,y1,width,height,max));

	myImage = new AsciiImage(width, height);
	
	calculateAndWriteToImage(myImage,x0,y0,x1,y1,width,height,max);

	myImage->show();

	delete myImage;

	return 0;
}

bool evaluateInputs(double x0, double y0, double x1, double y1, int width, int height, int max)
{
	bool correct = true;
	
	if(x0 > x1)
	{
		cerr << "Incorrect coordinates: x0 > x1" << endl;
		correct = false;
	}

	if(y0 > y1)
	{
		cerr << "Incorrect coordinates: y0 > y1" << endl;
		correct = false;
	}
	
	if(width < 1)
	{
		cerr << "Incorrect width input: zero or negative value" << endl;
		correct = false;
	}
	
	if(height < 1)
	{
		cerr << "Incorrect height input: zero or negative value" << endl;
		correct = false;
	}
	
	if(max < 1)
	{
		cerr << "Incorrect maximum iterations: zero or negative value";
		correct = false;
	}
	
	return correct;
}

void calculateAndWriteToImage(AsciiImage* img, double x0,double y0,double x1,double y1,int width,int height,int max)
{
	double stepX = 0;
	double stepY = 0;

	if(width == 1)
	{
		stepX = x1-x0;
	}
	else
	{
		stepX = (x1-x0)/(width-1);
	}

	if(height == 1)
	{
		stepY = y1-y0;
	}
	else
	{
		stepY = (y1-y0)/(height-1);
	}

	double zr = 0.;
	double zi = 0.;
	double nextzr = 0;
	double nextzi = 0;
	int i = 0;
	int j = 0;
	int k = 0;


	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{

			for(k=0;k<max;k++)
				{
					nextzr = zr * zr - zi * zi + (x0 + stepX*j);
					nextzi = 2 * zr * zi + (y0 + stepY*i);

					if( (nextzr*nextzr + nextzi*nextzi) > 4)
					{
						k = k % 70;
						break;
					}
					zr = nextzr;
					zi = nextzi;
				}
			zr = 0;
			zi = 0;

			img->setPix(j,i,k);
		}
	}
}

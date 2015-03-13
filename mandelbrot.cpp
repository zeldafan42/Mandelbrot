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

	myImage = new AsciiImage(width, height);

	myImage->print();

	calculateAndWriteToImage(myImage,x0,y0,x1,y1,width,height,max);



	return 0;
}

void calculateAndWriteToImage(AsciiImage* img, double x0,double y0,double x1,double y1,int width,int height,int max)
{
	double stepX = (x1-x0)/width;
	double stepY = (y1-y0)/height;

	double zr = 0.;
	double zi = 0.;
	int i = 0;
	int j = 0;
	int k = 0;


	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{

			for(k=0;k<max;k++)
				{
					double nextzr = zr * zr - zi * zi + (x0 + stepX*j);
					double nextzi = 2 * zr * zi + (y0 + stepY*i);

					if(nextzr*nextzr + nextzi*nextzi > 4)
					{
						k = k % 70;
						break;
					}
					zr = nextzr;
					zi = nextzi;

				}


			img->setPix(j,i,k);
		}
	}

	img->show();


}

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

void calculateAndWriteToImage(AsciiImage * img,int x0,int y0,int x1,int y1,int max);

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

	//calculateAndWriteToImage(myImage,x0,y0,x1,y1,max);



	return 0;
}

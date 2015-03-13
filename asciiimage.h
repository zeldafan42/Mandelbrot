/*
 * asciiimage.h
 *
 *  Created on: 13.03.2015
 *      Author: Christoph Majcen
 *      		Arthur Bouz
 */

#ifndef ASCIIIMAGE_H_
#define ASCIIIMAGE_H_

class AsciiImage
{
public:
	void setPix(int x, int y, int color);
	void show();
	AsciiImage(int width, int height);
	~AsciiImage();
	void print();

private:
	int width;
	int height;
	static const char * seventyShadesOfGrey; //It is the same for every AsciiImage
	char * image;
};



#endif /* ASCIIIMAGE_H_ */

#include <iostream>

class AsciiImage
{
	private:
		int length;
		int width;
		char* image;

	public:
		AsciiImage(int length,int width)
		{
			this->length = length;
			this->width = width;
			char* image = new char[length*width];
		}

		~AsciiImage()
		{
			delete image;
		}


		void setPix(int x, int y, int color)
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

			image[(length-1)*(y-1)+x] = a;
		}

		void show()
		{
			int i = 0;
			int j = 0;
			for(i=0;i<width;i++)
			{
				for(j=0;j<length;j++)
				{
					std::cout << image[(i*(length-1)+j)];
				}
				std::cout  << std::endl;
			}
		}


};


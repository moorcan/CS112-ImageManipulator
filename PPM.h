#pragma once
#include <string>
#include <vector>
#include "Pixel.hpp"
#include <fstream>
#include <iostream>

using namespace std;

class PPM
{
private:
	string header_format = "";
	int width = 0;
	int height = 0;
	int max_color_val = 0;
	vector<vector<Pixel*>> pixel_data;

public:
	PPM();
	~PPM();
	void open(ifstream&);
	void negateRed();
	void flipVertical();
	void flipHorizontal();
	bool save(ofstream&);

	int getHeight()
	{
		return height;
	}

	int getWidth()
	{
		return width;
	}

	Pixel* getPixel(int height, int width)
	{
		if (height < pixel_data.size())
		{
			if (width < pixel_data[height].size())
			{
				return pixel_data[height][width];
			}
		}
		return NULL;
	}

	
	void ImageEditor(int option_chosen)
	{
		switch (option_chosen)
		{
			//Remove Red in RGB
			//(starting with element 0) in the data component 
			//to a zero. (Data Changed)
		case 1:
			for (int i = 0; i < pixel_data.size(); i++)
			{
				//pixel_data[i] = 0;
				for (int j = 0; j < pixel_data[i].size(); j++)
				{
					pixel_data[i][j]->setRed(0);
				}
			}
			break;

			//Remove Green in RGB
			//(starting with element 0) in the data component 
			//to a zero. (Data Changed)
		case 2:
			for (int i = 0; i < pixel_data.size(); i++)
			{
				//pixel_data[i] = 0;
				for (int j = 0; j < pixel_data[i].size(); j++)
				{
					pixel_data[i][j]->setGreen(0);
				}
			}
			break;

			//Remove Blue - turn every 4th number
			//(starting with element 0) in the data component 
			//to a zero. (Data Changed)
		case 3:
			for (int i = 0; i < pixel_data.size(); i++)
			{
				//pixel_data[i] = 0;
				for (int j = 0; j < pixel_data[i].size(); j++)
				{
					pixel_data[i][j]->setBlue(0);
				}
			}
			break;

			// If user selects 4, Negate Red starting at element [0]
		case 4:
			for (int i = 0; i < pixel_data.size(); i++)
			{
				//pixel_data[i] = 255 - pixel_data[i];
				for (int j = 0; j < pixel_data[i].size(); j++)
				{
					pixel_data[i][j]->setRed(255 - pixel_data[i][j]->getRed());
				}
			}
			break;

			//If user selects 5, Negate green starting at element [0]
		case 5:
			for (int i = 0; i < pixel_data.size(); i++)
			{
				//pixel_data[i] = 255 - pixel_data[i];
				for (int j = 0; j < pixel_data[i].size(); j++)
				{
					pixel_data[i][j]->setGreen(255 - pixel_data[i][j]->getGreen());
				}
			}
			break;

			//If user selects 6, Negate blue starting at element [0]
		case 6:
			for (int i = 0; i < pixel_data.size(); i++)
			{
				//pixel_data[i] = 255 - pixel_data[i];
				for (int j = 0; j < pixel_data[i].size(); j++)
				{
					pixel_data[i][j]->setBlue(255 - pixel_data[i][j]->getBlue());
				}
			}
			break;

			//If user selects 7, return image in grayscale.
		case 7:
			for (int i = 0; i < pixel_data.size(); i++)
			{
				for (int j = 0; j < pixel_data[i].size(); j++)
				{
					Pixel* pixel = pixel_data[i][j];

					if (pixel->getRed() != pixel->getAverage() || pixel->getBlue() != pixel->getAverage() || pixel->getGreen() != pixel->getAverage())
					{
						int avg = pixel->getAverage();
						pixel->setRed(avg);
						pixel->setBlue(avg);
						pixel->setGreen(avg);
					}
				}
			}
			break;
			//Random Noise (Generates random number and adds it to current value of each RGB value.
		case 8:
			for (int i = 0; i < pixel_data.size() - 1; i++)
			{
				for (int j = 0; j < pixel_data[i].size(); j++)
				{
					Pixel* pixel = pixel_data[i][j];
					int randomNum = rand() % (10 - (-10 + 1)) + (-10);

					pixel->setRed(pixel->getRed() + randomNum);
					pixel->setBlue(pixel->getRed() + randomNum);
					pixel->setGreen(pixel->getRed() + randomNum);

					if (pixel->getRed() < 0)
					{
						pixel->setRed(0);
					}
					else if (pixel->getRed() > 255)
					{
						pixel->setRed(255);
					}

					if (pixel->getBlue() < 0)
					{
						pixel->setBlue(0);
					}
					else if (pixel->getBlue() > 255)
					{
						pixel->setBlue(255);
					}

					if (pixel->getGreen() < 0)
					{
						pixel->setGreen(0);
					}
					else if (pixel->getGreen() > 255)
					{
						pixel->setGreen(255);
					}
				}
			}
			break;
			//High Contrast 
		case 9:
			for (int i = 0; i < pixel_data.size(); i++)
			{
				for (int j = 0; j < pixel_data[i].size(); j++)
				{
					Pixel* pixel = pixel_data[i][j];

					if (pixel->getRed() > 255 / 2)
					{
						pixel->setRed(255);
					}
					else
					{
						pixel->setRed(0);
					}

					if (pixel->getBlue() > 255 / 2)
					{
						pixel->setBlue(255);
					}
					else
					{
						pixel->setBlue(0);
					}

					if (pixel->getGreen() > 255 / 2)
					{
						pixel->setGreen(255);
					}
					else
					{
						pixel->setGreen(0);
					}
				}
			}
			break;
			//Horizontal Flip
		case 10:
			flipHorizontal();
			break;
			//Vertical Flip
		case 11:
			flipVertical();
			break;
		}
	}
};
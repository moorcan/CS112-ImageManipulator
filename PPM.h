#pragma once
#include<string>
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
	bool open(ifstream&);
	//bool save(ofstream&);
	//void negateRed();
	//Remove Red in RGB
			//(starting with element 0) in the data component 
			//to a zero. (Data Changed)
	
	
	void ImageEditor(int option_chosen)
	{
		switch (option_chosen)
		{
			//Remove Red in RGB
			//(starting with element 0) in the data component 
			//to a zero. (Data Changed)
		case 1:
			for (int i = 0; i < pixel_data.size(); i += 3)
			{
				pixel_data[i] = 0;
			}
			break;

			//Remove Green in RGB
			//(starting with element 0) in the data component 
			//to a zero. (Data Changed)
		case 2:
			for (int i = 1; i < pixel_data.size(); i += 3)
			{
				pixel_data[i] = 0;
			}
			break;

			//Remove Blue - turn every 4th number
			//(starting with element 0) in the data component 
			//to a zero. (Data Changed)
		case 3:
			for (int i = 2; i < pixel_data.size(); i += 3)
			{
				pixel_data[i] = 0;
			}
			break;

			// If user selects 4, Negate Red starting at element [0]
		case 4:
			for (int i = 0; i < pixel_data.size(); i += 3)
			{
				pixel_data[i] = 255 - pixel_data[i];
			}
			break;

			//If user selects 5, Negate green starting at element [0]
		case 5:
			for (int i = 1; i < pixel_data.size(); i += 3)
			{
				pixel_data[i] = 255 - pixel_data[i];
			}
			break;

			//If user selects 6, Negate blue starting at element [0]
		case 6:
			for (int i = 2; i < pixel_data.size(); i += 3)
			{
				pixel_data[i] = 255 - pixel_data[i];
			}
			break;

			//If user selects 7, return image in grayscale.
		case 7:
			for (int i = 0; i < pixel_data.size() - 2; i += 3)
			{
				int red = i;
				int green = i + 1;
				int blue = i + 2;
				int average = (pixel_data[red] + pixel_data[green] + pixel_data[blue]) / 3;
				pixel_data[i];

				if (pixel_data[red] != average || pixel_data[blue] != average || pixel_data[green] != average)
				{
					pixel_data[red] = average;
					pixel_data[blue] = average;
					pixel_data[green] = average;
				}
			}
			break;
			//Random Noise (Generates random number and adds it to current value of each RGB value.
		case 8:
			for (int i = 0; i < pixel_data.size() - 1; i += 3)
			{
				int randomNum = rand() % (10 - (-10 + 1)) + (-10);
				pixel_data[i] += randomNum;
				pixel_data[i + 1] += randomNum;
				pixel_data[i + 2] += randomNum;
				for (int j = 0; j < 3; j++)
				{
					if (pixel_data[i + j] < 0)
					{
						pixel_data[i + j] = 0;
					}
					else if (pixel_data[i + j] > 255)
					{
						pixel_data[i + j] = 255;
					}
				}
			}
			break;
			//High Contrast 
		case 9:
			for (int i = 0; i < pixel_data.size() - 1; i += 3)
			{
				for (int j = 0; j < 3; j++)
				{
					if (pixel_data[i + j] > (255 / 2))
					{
						pixel_data[i + j] = 255;
					}
					else
					{
						pixel_data[i + j] = 0;

					}
				}
			}
			break;
		}
	};
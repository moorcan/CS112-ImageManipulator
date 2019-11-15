#pragma once
#ifndef PIXEL_H
#define PIXEL_H

#include <istream>
#include <exception>
using namespace std;

class Pixel
{
private:
	
	int _red = -1;
	int _green = -1;
	int _blue = -1;

public:
	void setRed(int red)
	{
		_red = red;
	}

	int getRed()
	{
		return _red;
	}
	
	void setGreen(int green)
	{
		_green = green;
	}

	int getGreen()
	{
		return _green;
	}

	void setBlue(int blue)
	{
		_blue = blue;

	}

	int getBlue()
	{
		return _green;
	}

	Pixel(int red, int green, int blue)
	{
		this->red = red;
		this->green = green;
		this->blue = blue;
	}
	
	Pixel(vector<int>values)
	{
		if (values.size() == 3)
		{
			this->red = values[0];
			this->green = values[1];
			this->blue = values[2];

		}
		else
		{
			cout << "Pixel Constructor called with wrong number of values!";
			this->red = 0;
			this->green = 0;
			this->blue = 0;
		}
		
}
};
/*
istream& operator>>(istream& stream, Pixel& pixel)
{
	stream >> pixel.red >> pixel.green >> pixel.blue;
	return stream;
}

ostream& operator<<(ostream& stream, Pixel& pixel)
{
	stream << pixel.red << " " << pixel.green << " " << pixel.blue;
	return stream;
}
*/
#endif // !PIXEL_H

#pragma once
#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
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
		this->_red = red;
		this->_green = green;
		this->_blue = blue;
	}
	
	Pixel(vector<int>values)
	{
		if (values.size() == 3)
		{
			this->_red = values[0];
			this->_green = values[1];
			this->_blue = values[2];

		}
		else
		{
			cout << "Pixel Constructor called with wrong number of values!";
			this->_red = 0;
			this->_green = 0;
			this->_blue = 0;
		}
	}

	string toString()
	{
		string result;
		result = to_string(_red) + " " + to_string(_green) +  " " + to_string(_blue);
		return result;
	}

	int getAverage()
	{
		return (_red + _green + _blue) / 3;
	}

	void swap(Pixel* other) {
		int other_red = other->getRed();
		int other_green = other->getGreen();
		int other_blue = other->getBlue();
		other->setRed(this->_red);
		other->setGreen(this->_green);
		other->setBlue(this->_blue);
		this->_red = other_red;
		this->_green = other_green;
		this->_blue = other_blue;
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

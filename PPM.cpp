#pragma once
#include "PPM.h"
#include "Pixel.hpp"

PPM::PPM()
{
	header_format = "";
	width = 0;
	height = 0;
	max_color_val = 0;
}

PPM::~PPM()
{
	for (int i = 0; i < pixel_data.size(); i++)
	{
		for (int j = 0; j < pixel_data[i].size(); j++)
		{
			delete pixel_data[i][j];
		}
	}
}

void PPM::open(ifstream& input_stream)
{
	string line_to_read;

	if (!input_stream.good()) {
		cout << "Input stream not good" << endl;
		return;
	}

	// Parses header information
	getline(input_stream, line_to_read);
	header_format = line_to_read;
	getline(input_stream, line_to_read, ' ');
	width = stoi(line_to_read);
	getline(input_stream, line_to_read);
	height = stoi(line_to_read);
	getline(input_stream, line_to_read);
	max_color_val = stoi(line_to_read);

	// Read the body
	for (int i = 0; i < height; i++)
	{
		vector<Pixel*> row;
		int next_value;
		int counter = 0;
		vector<int> single_pixel;

		while (row.size() < width)
		{
			input_stream >> next_value;
			if (counter == 3)
			{
				counter = 0;
				Pixel* temp = new Pixel(single_pixel);
				row.push_back(temp);
				single_pixel.clear();
			}
			single_pixel.push_back(next_value);
			counter++;
		}
		pixel_data.push_back(row);
	}

	// Testing dimensions
	int i = 0;
	for (auto row : pixel_data) {
		if (row.size() != width) {
			cout << "Row size incorrect: " << i++ << endl;
		}
	}
}

void PPM::negateRed() {
	for (auto row : pixel_data) {
		for (auto pixel : row) {
			pixel->setRed(0);
		}
	}
}

void swap(Pixel& pixel_one, Pixel& pixel_two)
{
	Pixel pixel_pointer_a = pixel_one;
	pixel_one = pixel_two;
	pixel_two = pixel_pointer_a;
}

void PPM::flipHorizontal() {
	for (auto row : pixel_data) {
		int i = 0;
		int j = width - 1;
		while (i < j) {
			row[i]->swap(row[j]);
			i++;
			j--;
		}
	}
}

void PPM::flipVertical()
{
	for (int j = 0; j < width - 1; j++)
	{
		int i = 0;
		int k = height - 1;
		while (i < k)
		{
			swap(pixel_data[i][j], pixel_data[k][j]);
			i++;
			k--;	
		}
	}
}

bool PPM::save(ofstream& output_stream) {
	if (output_stream.good())
	{
	output_stream << header_format << endl;
	output_stream << width << " " << height << endl;
	output_stream << max_color_val << endl;
	for (auto row : pixel_data)
	{
		for (auto pixel : row)
		{
			output_stream << pixel->toString() << " ";
		}
		output_stream << endl;
	}
		return true;
	}
	else
	{
		return false;
	}
}
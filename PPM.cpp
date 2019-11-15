#pragma once
#include "PPM.h";

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

bool PPM::open(ifstream& input_stream)
{
	string line_to_read;

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
	for (int j = 0; j < height; j++)
	{
		
		for (int i = 0; i < width; i++)
		{
			vector<Pixel*> row;
			int next_value;
			int counter = 0;
			vector<int> single_pixel;
			while ((input_stream >> next_value) && (row.size() < width))
			{
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
	}
	return true;
}

ostream& operator << (ostream& stream, PPM& ppm_doc)
{
	stream << PPM
}
PPM::close()

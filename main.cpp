
/*PA 4
Candace Moore
CS112 - pa4
2019-09-30
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <time.h>
using namespace std;

/*
signature: what_file: ifstream ofstream -> void
purpose: Expects an ifstream and an ofstream with a side effect
of prompting the user for the file names.
*/

void what_file(ifstream& input_stream, ofstream& output_stream); //declaring function

const int NUM_HEADER_LINES = 3;

int main(void)
{
	ifstream input_stream;
	ofstream output_stream;
	string line_to_read;
	vector<string> header_info;
	vector<int> pixel_data;
	vector<int> converted_data;
	int option_chosen;
	srand(time(NULL));


	what_file(input_stream, output_stream);

	//Reading the first 3 lines of the File
	if (input_stream.good() == true)
	{
		for (int i = 0; i < NUM_HEADER_LINES; i++)
		{
			getline(input_stream, line_to_read);
			header_info.push_back(line_to_read);
		}
	}

	//Reading the body of the file
	while (input_stream.good() == true)
	{
		int value = 0;
		input_stream >> value;
		pixel_data.push_back(value);
	}

	cout << "What would you like to do? 1. Remove Red, 2. Remove Green, 3. Remove Blue, 4. Negate Red\n";
	cout << "5. Negate Green, 6. Negate Blue, 7. Grayscale. 8. Add Noise 9. High Contrast\n";
	cout << "Q. Quit Select Option" << endl;

	cin >> option_chosen;

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
	default:
		cout << "Error! Must enter number 1-8";
	}


	//Write out to file (header).
	for (int i = 0; i < header_info.size(); i++)
	{
		output_stream << header_info[i] << endl;
	}

	//Write out to file (body).
	for (int i = 0; i < pixel_data.size(); i++)
	{
		{
			output_stream << pixel_data[i] << ' ';
		}
	}

	while (input_stream.good())
	{
		getline(input_stream, line_to_read);
	}
	//cleaning up:
	input_stream.close();
	output_stream.close();
	return 0;
}


void what_file(ifstream& input_stream, ofstream& output_stream)
{
	string file_name;

	// Error Checking to see if file is open
	if ((input_stream.is_open() == true) || (output_stream.is_open() == true))
	{
		cout << "Error: File Already Opened. Closing file to proceed. " << endl;
		input_stream.close();
		output_stream.close();
	}

	// Prompt user for file name they want to open.
	cout << "Enter the name of the file you wish to open: " << endl;
	getline(cin, file_name);
	input_stream.open(file_name);
	while (input_stream.good() == false)
	{
		cout << "This file does not exist! Please re-enter file name: " << endl;
		getline(cin, file_name);
		input_stream.open(file_name);
	}

	// Prompt user for the file name they want to write to.
	cout << "Enter the name of the file you wish to write to: " << endl;
	getline(cin, file_name);
	output_stream.open(file_name);
	// Error checking to make sure file ext can open.
	while (output_stream.good() == false)
	{
		cout << "This file name is not compatible! Please re-enter file name: " << endl;
		getline(cin, file_name);
		output_stream.open(file_name);
	}
}


#include <iostream>

using namespace std;

void getData(double array[][2]);
double averageHigh(const double array[][2]);
double averageLow(const double array[][2]);
int indexHighTemp(const double array[][2]);
int indexLowTemp(const double array[][2]);

int main()
{
	double temperatures[12][2];
	getData(temperatures);

	cout << "The average high temperature of the year is: " << averageHigh(temperatures) << endl;
	cout << "The average low temperature of the year is: " << averageLow(temperatures) << endl;

	cout << "The highest temperature of the year is: " << temperatures[indexHighTemp(temperatures)][1] << endl;
	cout << "The lowest temperature of the year is: " << temperatures[indexLowTemp(temperatures)][0] << endl;


	return 0;
}

void getData(double array[][2])
{
	for (int i = 0; i < 12; i++)
	{
		cout << "Enter the highest and lowest temperatures of the month " << i + 1 << endl;
		for (int j = 0; j < 2; j++)
			cin >> array[i][j];
	}
}

double averageHigh(const double array[][2])
{
	double sum = 0;

	int col = 1;
	for (int i = 0; i < 12; i++)
		sum = sum + array[i][col];
	return sum / 12.0;
}

double averageLow(const double array[][2])
{
	double sum = 0;

	int col = 0;
	for (int i = 0; i < 12; i++)
		sum = sum + array[i][col];
	return sum / 12.0;
}

int indexHighTemp(const double array[][2])
{
	int col = 1;

	double maxTemp = array[0][col];
	int index = 0;
	for (int row = 1; row < 12; row++)
	{
		if (array[row][col] > maxTemp)
		{
			maxTemp = array[row][col];
			index = row;
		}
	}

	return index;
}

int indexLowTemp(const double array[][2])
{
	int col = 0;

	double minTemp = array[0][col];
	int index = 0;
	for (int row = 1; row < 12; row++)
	{
		if (array[row][col] < minTemp)
		{
			minTemp = array[row][col];
			index = row;
		}
	}

	return index;
}
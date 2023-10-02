// Exercise 3

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("C:\\inData.txt");
	if (!inFile)
	{
		cout << "The file does not exist!!" << endl;
		cout << "The program terminates!!" << endl;
		return 1;
	}

	int ranges[100] = { 0 };
	int score;

	inFile >> score;
	while (inFile)
	{
		//cout << score << endl;
		ranges[score / 25]++;

		if (score / 25 == 8)
			ranges[7]++;

		inFile >> score;
	}


	int j = 0;
	for (int i = 0; i < 8; i++)
	{
		if (i == 7)
		{
			cout << "The number of students with scores in the range " << j << "-" << j + 25 << " is: " << ranges[i]
				<< endl;
			break;
		}

		cout << "The number of students with scores in the range " << j << "-" << j + 24 << " is: " << ranges[i]
			<< endl;

		j = j + 25;

	}

	inFile.close();



	return 0;
}
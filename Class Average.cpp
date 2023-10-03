
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int N = 50;

int main()
{
	ifstream inFile;
	inFile.open("C:\\inData.txt");
	if (!inFile)
	{
		cout << "The file does not exist!!" << endl;
		cout << "Program terminates!!" << endl;
		return 1;
	}

	string students[N];
	double testScore[N];

	double avg = 0;

	inFile >> students[0];

	int i = 0;
	while (inFile)
	{
		inFile >> testScore[i];
		avg = avg + testScore[i];
		i++;
		inFile >> students[i];

	}
	avg = avg / i;
	cout << i << endl;
	cout << "The class average is: " << avg << endl;

	double maxScore = testScore[0];
	cout << "The names of students whose test scores are below the average: " << endl;
	for (int i = 0; i < N; i++)
	{
		if (testScore[i] < avg)
			cout << students[i] << endl;
		if (testScore[i] > maxScore)
			maxScore = testScore[i];
	}

	cout << endl;
	cout << "The names of students having the highest score: " << endl;
	for (int i = 0; i < N; i++)
	{
		if (testScore[i] == maxScore)
			cout << students[i] << endl;
	}

	inFile.close();




	return 0;
}

// Code detection

#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_LENGTH = 250;

void readCode(ifstream& inFile, int code[], int l);
void compareCodes(ifstream& inFile, ofstream& outFile, const int code[], int l);

int main()
{
	ifstream inFile;
	ofstream outFile;

	inFile.open("C:\\inData.txt");
	if (!inFile)
	{
		cout << "The file does not exist!!" << endl;
		cout << "Program terminates!!" << endl;
		return 1;
	}

	outFile.open("C:\\outData.txt");

	int length;
	inFile >> length;
	if (length > 250)
	{
		cout << "The length of the code exeeds the max length allowed!!" << endl;
		cout << "Program terminates!!" << endl;
		return 1;
	}

	int code[MAX_LENGTH];
	readCode(inFile, code, length);

	int copyLength;
	inFile >> copyLength;

	if (copyLength != length)
	{
		cout << "The message and its copy are not of the same length." << endl;
		return 1;
	}
	compareCodes(inFile, outFile, code, length);

	inFile.close();
	outFile.close();

	return 0;
}

void readCode(ifstream& inFile, int code[], int l)
{
	for (int i = 0; i < l; i++)
	{
		inFile >> code[i];
	}


}

void compareCodes(ifstream& inFile, ofstream& outFile, const int code[], int l)
{
	outFile << left << setw(13) << "Code digit"
		<< setw(15) << "Code digit copy" << endl;



	int digit;
	bool identical = true;
	for (int i = 0; i < l; i++)
	{
		outFile << right << setw(5) << code[i];
		inFile >> digit;
		outFile << right << setw(11) << digit;
		if (digit != code[i])
		{
			outFile << "   Message digits are not the same";
			identical = false;
		}
		outFile << endl;

	}
	if (identical == true)
		outFile << left << "Message transmited OK." << endl;
	else
		outFile << "Error in transmission!! Retransmit." << endl;

}

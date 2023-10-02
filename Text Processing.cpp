
//Text Processing (Line and letter count)

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void initialize(int array[], int s);
void characterCount(char ch, int array[]);
void copyLine(ifstream& inFile, ofstream& outFile, char& ch, int array[]);
void writeTotal(ofstream& outFile, const int array[], int lineCount);

int main()
{
	ifstream inFile;
	ofstream outFile;

	inFile.open("C:\\inData.txt");
	if (!inFile)
	{
		cout << "The file does not exist!!" << endl;
		cout << "The program terminates!!" << endl;
		return 1;
	}

	outFile.open("C:\\outData.txt");



	int letterCount[26]; // to store 26 characters counts
	initialize(letterCount, 26);
	char letter;
	inFile.get(letter);

	int lineCount = 0;

	while (inFile)
	{
		copyLine(inFile, outFile, letter, letterCount);
		lineCount++;
		inFile.get(letter);
	}

	writeTotal(outFile, letterCount, lineCount);

	inFile.close();
	outFile.close();



	return 0;

}

void initialize(int array[], int s)
{
	for (int i = 0; i < s; i++)
		array[i] = 0;

}

void characterCount(char ch, int array[])
{
	int index;
	ch = toupper(ch);

	index = static_cast <int>(ch) - static_cast<int> ('A');

	if (index >= 0 && index <= 26)
		array[index]++;

}

void copyLine(ifstream& inFile, ofstream& outFile, char& ch, int array[])
{
	while (ch != '\n')
	{
		outFile << ch;
		characterCount(ch, array);
		inFile.get(ch);
	}
	outFile << ch; // output the new line character



}

void writeTotal(ofstream& outFile, const int array[], int lineCount)
{
	outFile << endl;
	outFile << "The number of lines = " << lineCount << endl;
	for (int i = 0; i < 26; i++)
	{
		outFile << static_cast<char> (i + static_cast<int> ('A')) << " count = " << array[i]
			<< endl;
	}

}
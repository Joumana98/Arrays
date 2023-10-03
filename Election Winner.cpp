#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int N = 5;

int findMax(double array[]);
void printData(const string names[], const int votes[], const double percent[]);

int main()
{
	cout << fixed << showpoint << setprecision(2);

	string names[N];
	int votes[N];

	double totalVotes = 0;

	for (int i = 0; i < N; i++)
	{
		cout << "Enter the name of the candidate: " << endl;
		cin >> names[i];
		cout << "Enter the number of votes recived by " << names[i] << " :" << endl;
		cin >> votes[i];
		totalVotes = totalVotes + votes[i];
	}

	double percentage[N];
	for (int i = 0; i < N; i++)
		percentage[i] = (static_cast<double>(votes[i]) / totalVotes) * 100;

	cout << endl;
	cout << left << setw(17) << "Candidate"
		<< left << setw(17) << "Votes Received"
		<< left << setw(17) << "% of Total Votes" << endl;

	printData(names, votes, percentage);
	cout << left << setw(17) << "Total"
		<< left << setw(17) << totalVotes << endl;

	cout << endl;
	cout << "The Winner of the Election is " << names[findMax(percentage)] << endl;

	return 0;
}

int findMax(double array[])
{
	int max = array[0];
	int index = 0;
	for (int i = 1; i < N; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
			index = i;
		}
	}
	return index;
}

void printData(const string names[], const int votes[], const double percent[])
{
	for (int i = 0; i < N; i++)

		cout << setw(17) << names[i]
		<< left << setw(17) << votes[i]
		<< left << setw(17) << percent[i] << endl;
}
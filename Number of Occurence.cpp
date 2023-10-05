#include <iostream>

using namespace std;

const int N = 100;

int calculateLength(const int array[]);
void sortArray(int array[], int l);
void printOccurence(int array[], int l);

int main()
{
	int numbers[N];

	int n;
	int index = 0;
	cout << "Enter a set of positive integers. Mark the end of the list by -99." << endl;
	cin >> n;
	while (n != -99)
	{
		numbers[index] = n;
		index++;
		cin >> n;
	}
	numbers[index] = n;

	int l = calculateLength(numbers);
	cout << l << endl;

	sortArray(numbers, l);
	cout << endl;
	for (int i = 0; i < l; i++)
		cout << numbers[i] << " ";
	cout << endl;

	cout << endl;
	printOccurence(numbers, l);

	return 0;
}

int calculateLength(const int array[])
{
	int length = 0;
	while (array[length] != -99)
		length++;
	return length;
}

void sortArray(int array[], int l)
{
	int temp;
	for (int i = 0; i < l; i++)
	{
		temp = array[i];
		for (int j = i + 1; j < l; j++)
		{
			if (array[j] < array[i])
			{
				array[i] = array[j];
				array[j] = temp;
				temp = array[i];

			}
		}
	}
}

void printOccurence(int array[], int l)
{
	cout << "Number     Count" << endl;
	int count;
	int i = 0;
	while (i < l)
	{
		count = 1;
		while (array[i + 1] == array[i])
		{
			count++;
			i++;
		}
		cout << array[i] << "       " << count << endl;
		i++;
	}
}
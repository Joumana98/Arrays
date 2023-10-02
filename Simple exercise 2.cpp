// Exercise 2

#include <iostream>

using namespace std;

int smallestIndex(int list[], int length);

int main()
{
	int list[10] = { 1,5,4,7,0,4,7,9,3,-1 };
	int index = smallestIndex(list, 10);

	cout << "The index of the smallest element in the array is: " << index << endl;


	return 0;
}

int smallestIndex(int list[], int length)
{
	int minIndex = 0;
	int min = list[0];
	for (int i = 1; i < length; i++)
	{
		if (list[i] < min)
		{
			min = list[i];
			minIndex = i;
		}
	}

	return minIndex;
}
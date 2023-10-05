// Exercise 13

#include <iostream>

using namespace std;

const int N = 16;

const int M = 4;

void createArithmeticSeq(int seq[]);
void matricise(const int array[], int matrix[][4]);
void reverseDiagonal(int array[][M]);
void magicCheck(int array[], int matrix[][4]);

int main()
{
	int list[N];
	createArithmeticSeq(list);
	cout << endl;

	int matrix[M][M];
	matricise(list, matrix);

	cout << endl;
	reverseDiagonal(matrix);

	cout << endl;
	magicCheck(list, matrix);

	return 0;
}

void createArithmeticSeq(int seq[])
{
	int first, diff;
	cout << "Enter tow integers: " << endl;
	cin >> first >> diff;

	seq[0] = first;
	cout << seq[0] << " ";
	for (int i = 1; i < N; i++)
	{
		seq[i] = seq[i - 1] + diff;
		cout << seq[i] << " ";

	}
	cout << endl;


}

void matricise(const int array[], int matrix[][4])
{
	int index = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			matrix[i][j] = array[index];
			index++;
			cout << matrix[i][j] << " ";
		}
		cout << endl;

	}

}

void reverseDiagonal(int array[][M])
{
	int temp;
	for (int i = 0; i < M / 2; i++)
	{
		temp = array[i][i];
		array[i][i] = array[M - i - 1][M - i - 1];
		array[M - i - 1][M - i - 1] = temp;
	}

	for (int i = 0; i < M / 2; i++)
	{
		temp = array[i][M - i - 1];
		array[i][M - i - 1] = array[M - i - 1][i];
		array[M - i - 1][i] = temp;
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			cout << array[i][j] << " ";
		cout << endl;
	}

}

void magicCheck(int array[], int matrix[][4])
{
	double magicNumber = 0;
	for (int i = 0; i < N; i++)
		magicNumber = magicNumber + array[i];
	magicNumber = magicNumber / 4.0;

	double rowSum = 0;
	double colSum = 0;
	double d1Sum = 0;
	double d2Sum = 0;

	bool isMagic = true;

	for (int i = 0; i < M; i++)
	{
		rowSum = 0;
		colSum = 0;
		for (int j = 0; j < M; j++)
		{
			rowSum = rowSum + matrix[i][j];
			colSum = colSum + matrix[j][i];
		}
		if ((rowSum != magicNumber) || (colSum != magicNumber))
			isMagic = false;
	}


	if (isMagic == true)
	{
		for (int i = 0; i < M; i++)
		{
			d1Sum = d1Sum + matrix[i][i];
			d2Sum = d2Sum + matrix[i][M - i - 1];
		}
		if (d1Sum != magicNumber || d2Sum != magicNumber)
			isMagic = false;
	}


	if (isMagic == true)
		cout << "This is a magic square!" << endl;
	else
		cout << "This is not a magic square!!" << endl;
}
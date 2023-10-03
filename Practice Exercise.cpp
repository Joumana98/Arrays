// Exercise 9

#include <iostream>

using namespace std;

void setZero(int array[], int length);
void inputArray(int array[], int length);
void doubleArray(const int alpha[], int beta[], int length);
void copyGamma(const int gamma[], int array[][4]);
void copyAlphaBeta(const int alpha[], const int beta[], int array[][4]);
void printArray(const int array[], int length);
void setInStock(const int delta[], int array[][4]);
void print2D(int array[][4]);

int main()
{
	int inStock[10][4];
	int alpha[20];
	int beta[20];
	int gamma[4] = { 11,13,15,17 };
	int delta[10] = { 3,5,2,6,10,9,7,11,1,8 };

	inputArray(alpha, 20);
	doubleArray(alpha, beta, 20);
	printArray(beta, 20);
	cout << endl;

	copyGamma(gamma, inStock);
	print2D(inStock);
	cout << endl;

	copyAlphaBeta(alpha, beta, inStock);
	print2D(inStock);
	cout << endl;

	setInStock(delta, inStock);
	print2D(inStock);

	return 0;
}

void setZero(int array[], int length)
{
	for (int i = 0; i < length; i++)
		array[i] = 0;
}

void inputArray(int array[], int length)
{
	cout << "Enter " << length << " integers: " << endl;
	for (int i = 0; i < length; i++)
		cin >> array[i];
}

void doubleArray(const int alpha[], int beta[], int length)
{
	for (int i = 0; i < length; i++)
		beta[i] = 2 * alpha[i];

}

void copyGamma(const int gamma[], int array[][4])
{
	int row = 0;
	for (int col = 0; col < 4; col++)
		array[row][col] = gamma[col];
	for (int row = 1; row < 10; row++)
	{
		for (int col = 0; col < 4; col++)
			array[row][col] = 3 * array[row - 1][col];
	}
}

void copyAlphaBeta(const int alpha[], const int beta[], int array[][4])
{
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 4; col++)
			array[row][col] = alpha[col];
	}

	for (int row = 5; row < 10; row++)
	{
		for (int col = 0; col < 4; col++)
			array[row][col] = beta[col];
	}


}

void printArray(const int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (i % 15 == 0)
			cout << endl;
		cout << array[i] << " ";

	}

}

void setInStock(const int delta[], int array[][4])
{
	cout << "Enter " << 10 << " integers: " << endl;
	int col = 0;
	for (int row = 0; row < 10; row++)
		cin >> array[row][col];

	for (int col = 1; col < 4; col++)
	{
		for (int row = 0; row < 10; row++)
			array[row][col] = 2 * array[row][col - 1] - delta[col];

	}

}

void print2D(int array[][4])
{
	for (int row = 0; row < 10; row++)
	{
		for (int col = 0; col < 4; col++)
			cout << array[row][col] << " ";
		cout << endl;
	}
}
#include <iostream>
#include <iomanip>

using namespace std;

const int N = 8;

void readScores(double array[]);
void sortArray(double array[]);
void removeMinMax(const double array[], double final[]);
double addScores(const double array[]);

int main()
{
	cout << fixed << showpoint << setprecision(2);

	double scores[N];
	readScores(scores);
	for (int i = 0; i < N; i++)
		cout << scores[i] << " ";
	cout << endl << endl;
	sortArray(scores);
	for (int i = 0; i < N; i++)
		cout << scores[i] << " ";
	cout << endl;
	double scoresConsidered[N - 2];
	removeMinMax(scores, scoresConsidered);

	double sum = addScores(scoresConsidered);

	cout << "The contestant received at total of " << sum << " points" << endl;


	return 0;
}

void readScores(double array[])
{
	double score;
	cout << "Enter the scores of " << N << " judges: " << endl;
	for (int i = 0; i < N; i++) {
		cin >> score;
		if (score >= 1 && score <= 10)
			array[i] = score;
		else
		{
			cout << "The scores should be bewteen 1 and 10. Enter scores again. " << endl;
			readScores(array);
		}

	}

}

void sortArray(double array[])
{
	double temp;
	for (int i = 0; i < N; i++)
	{
		temp = array[i];
		for (int j = i + 1; j < N; j++)
		{
			if (array[j] < temp)
			{
				array[i] = array[j];
				array[j] = temp;
				temp = array[i];
			}
		}
	}
}

void removeMinMax(const double array[], double final[])
{
	for (int i = 1; i < N - 1; i++)
		final[i - 1] = array[i];
}

double addScores(const double array[])
{
	double sum = 0;
	for (int i = 0; i < N - 2; i++)
		sum = sum + array[i];
	return sum;
}
#include <iostream>
const int MAX_SIZE = 50;

//1
int minElement(const int arr[][MAX_SIZE], int rows, int cols) {
	int min = arr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] < min)
				min = arr[i][j];
		}
	}
	return min;
}

//2
void printSum(const int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		int sum = 0;
		for (int j = 0; j < cols; j++)
		{
			sum += arr[i][j];
		}
		std::cout << sum << std::endl;
	}
}

//3
bool MagicEl(const int arr[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == i * j)
				return true;
		}
	}
	return false;
}

//5??
void indexSum(const int arr[][MAX_SIZE], int size, int x) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i + j == x)
				sum += arr[i][j];
		}
	}
	std::cout << sum << std::endl;
}

//6
void PrintDiagonals(const int arr[][MAX_SIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i][i] << ' ';
	}
	std::cout << std::endl;
	for (int i = size - 1; i >= 0; i--)
	{
		std::cout << arr[i][size - i - 1] << ' ';
	}
}

//7
bool isSymetrical(const int arr[][MAX_SIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i][j] != arr[j][i])
				return false;
		}
	}
	return true;
}

//8
bool isTriangle(const int arr[][MAX_SIZE], int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; i < i; i++)
		{
			if (arr[i][j] != 0)
				return false;
		}
	}
	return true;
}

//9
int ProductOfElementsNotInSecondaryDiagonal(const int arr[][MAX_SIZE], int size) {
	int result = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i + j != size - 1)
				result *= arr[i][j];
		}
	}
	return result;
}

//10
bool isPrime(int n) {
	for (int i = 0; i <= n / 2; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

bool CheckForPrime(const int arr[][MAX_SIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (isPrime(arr[i][j]))
				return true;
		}
	}
	return false;
}

//11
bool isMagic(const int arr[][MAX_SIZE], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i][i];
	}
	int tempsum = 0;
	for (int i = 0; i < size; i++)
	{
		tempsum += arr[i][size - i - 1];
	}
	if (sum != tempsum)
		return false;
	for (int i = 0; i < size; i++)
	{
		tempsum = 0;
		for (int j = 0; j < size; j++)
		{
			tempsum += arr[i][j];
		}
		if (sum != tempsum)
			return false;
		tempsum = 0;
		for (int j = 0; j < size; j++)
		{
			tempsum += arr[j][i];
		}
		if (sum != tempsum)
			return false;
	}
	return true;
}


int main() {
	//1
	int mat[MAX_SIZE][MAX_SIZE] =
	{
		{1, 2, 3, 5},
	{ 4, 5, 6, 5 },
	{ 7, 8, 9, 5 }
	};
	std::cout << minElement(mat, 3, 3);

	//11
	/*int mat[MAX_SIZE][MAX_SIZE] =
	{ {8, 1, 6},
		{3, 5, 7},
		{4, 9, 2} };
	std::cout << isMagic(mat, 3);*/

	return 0;
}
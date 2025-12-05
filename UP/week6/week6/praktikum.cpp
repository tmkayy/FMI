#include<iostream>

const int MAX_SIZE = 100;

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

int Absolute(int n) {
	return (n > 0 ? n : -n);
}

int Max(int n1, int n2) {
	return (n1 >= n2) * n1 + (n1 < n2) * n2;
}

void removeElement(int arr[], int& size, int pos) {
	for (int i = pos; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = 0;
	size--;
}

void addElement(int arr[], int& size, int pos, int el) {
	for (int i = size; i >= pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos] = el;
	size++;
}

//1
int ResultOfPosDivisibleBy3(const int arr[], int size)
{
	int result = 1;
	for (int i = 0; i < size; i++)
	{
		if (i % 3 == 0)
			result *= arr[i];
	}
	return result;
}

//2
bool AnalyzeArr(const int arr[], int size)
{
	int count = 0;
	if (size <= 0)
		return false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == i)
			count++;
	}
	if (count >= 2)
		return true;
	else
		return false;
}

//3
void CreateThirdArray(const int arr1[], int size1, const int arr2[], int size2, int arr3[]) {
	int size3 = Max(size1, size2);
	for (int i = 0; i < size3; i++)
	{
		if (i < size1 && i < size2)
			arr3[i] = arr1[i] * arr2[i];
		else
			arr3[i] = arr1[i] + arr2[i];
	}
	printArray(arr3, size3);
}

//4
bool SymbolsArray(const char arr[], int size)
{
	int countCapitalCase = 0;
	int countLowerCase = 0;
	int countDigits = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
			countDigits++;
		else if (arr[i] >= 'a' && arr[i] <= 'z')
			countLowerCase++;
		else if (arr[i] >= 'A' && arr[i] <= 'Z')
			countCapitalCase++;
	}
	return (countDigits == Absolute(countLowerCase - countCapitalCase));
}

//5
bool SubArray(const int arr1[], int size1, const int arr2[], int size2) {
	int end = size1 - size2;
	for (int i = 0; i <= end; i++)
	{
		if (arr1[i] == arr2[0])
		{
			if (size2 == 1)
				return true;
			int arr2Index = 0;
			int newI = i;
			while (arr2[arr2Index] == arr1[newI])
			{
				if (arr2Index == size2 - 1)
					return true;
				arr2Index++;
				newI++;
				if (newI > size1 - size2 + 1)
					return false;
			}
		}
	}
	return false;
}

//6
bool contains(int el, const int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		if (el == arr[i])
			return true;
	}
	return false;
}

void PrintInterSection(const int arr1[], int size1, const int arr2[], int size2)
{
	int helper[MAX_SIZE] = {};
	int size = 0;
	for (int i = 0; i < size1; i++)
	{
		if (contains(arr1[i], arr2, size2) && !contains(arr1[i], helper , size))
		{
			helper[size] = arr1[i];
			size++;
		}
	}
	printArray(helper, size);
}

//7
int RepeatingElement(const int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size -1; j++)
		{
			if (arr[i] == arr[j])
				return arr[i];
		}
	}
	return -1;
}

//8
int AnalyzeArray(const int arr[], int l) {
	return 0;
}

//14
void countArr(const int arr[], int size, int counter[])
{
	for (int i = 0; i < size; i++)
	{
		int curr = arr[i];
		counter[curr]++;
	}
}

bool isPermutation(const int arr1[], int size1, const int arr2[], int size2) {
	int count[10] = {};
	int count2[10] = {};
	countArr(arr1, size1, count);
	countArr(arr2, size2, count2);
	for (int i = 0; i < 10; i++)
	{
		if (count[i] != count2[i])
		{
			return false;
		}
	}

	return true;
}


int main() {
	//1
	/*int arr[MAX_SIZE] = {2, 4, 5, 6, 4, 8, 5, 1, 2};
	std::cout << ResultOfPosDivisibleBy3(arr, 9);*/

	//2
	/*int arr[MAX_SIZE] = { 0, 5, 7, 8, 4, 1, 5, 70, -9 };
	std::cout << AnalyzeArr(arr, 9);*/

	//3
	/*int arr1[MAX_SIZE] = { 2, 4, 2, 3, 6, 5, 4, 7 };
	int arr2[MAX_SIZE] = { 8, 6, 9, 1, 0 };
	int arr3[MAX_SIZE];
	CreateThirdArray(arr1, 8, arr2, 5, arr3);*/

	//4
	/*char arr[MAX_SIZE] = { 'a', 'C', '$', 'B', 'D', '1', '2' };
	std::cout << SymbolsArray(arr, 7);*/

	//5
	/*int arr1[] = { 4, 6, 6, 8, 8, 9 };
	int arr2[] = { 8, 9 };
	std::cout << SubArray(arr1, 6, arr2, 2);*/

	//6
	/*int arr1[] = { 7, 8, 4, 5, 65, 9, 12, 32 };
	int arr2[] = { 65, 12, 9, 5, 4, 56, 88 };
	PrintInterSection(arr1, 8, arr2, 7);*/

	//7
	/*int arr[] = { 78, 8, 7, 68, 8, 7, 7, 7 };
	std::cout << RepeatingElement(arr, 8);*/

	//14
	/*int arr[] = { 8, 8, 7, 8, 8, 7, 7, 7 };
	int arr2[] = { 8, 7, 8, 8, 8, 7, 7, 7 };
	std::cout << isPermutation(arr, 8, arr2, 8);*/


	return 0;
}
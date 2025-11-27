#include <iostream>

int* createArray(const int* oldArr, const int size, int& size2) {
	int count = 0;
	for (size_t i = 1; i < size - 1; i++)
	{
		if (oldArr[i] % oldArr[i - 1] == 0 || oldArr[i] % oldArr[i + 1] == 0)
			count++;
	}
	int* arr = new int[count];
	count = 0;
	for (size_t i = 1; i < size - 1; i++)
	{
		if (oldArr[i] % oldArr[i - 1] == 0 || oldArr[i] % oldArr[i + 1] == 0) {
			arr[count] = oldArr[i];
			count++;
		}
	}
	size2 = count;
	return arr;
}



int main() {
	int arr[] = { 5, 1, 3, 6, 7 };
	int size2 = 0;
	int* arr2 = createArray(arr, 5, size2);
	for (size_t i = 0; i < size2; i++)
	{
		std::cout << arr2[i];
	}
}
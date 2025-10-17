#include <iostream>

void printArr(int* arr, size_t len) {
	std::cout << "{ ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "}";
}

void insertionSort(int* arr, size_t len) {
	for (size_t i = 1; i < len; i++)
	{
		int current = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > current)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = current;
	}
}

int main() {
	int arr[10] = { 3, 4, 1, 2, 4, 5, 0, 2, 7, 6 };
	insertionSort(arr, 10);
	printArr(arr, 10);
	return 0;
}
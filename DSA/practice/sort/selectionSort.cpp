#include <iostream>

void printArr(int* arr, size_t len) {
	std::cout << "{ ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "}";
}

void selectionSort(int* arr, size_t len) {
	for (size_t i = 0; i < len - 1; i++)
	{
		int minIdx = i;
		for (size_t j = i + 1; j < len; j++)
		{
			if (arr[minIdx] > arr[j])
				minIdx = j;
		}
		if (minIdx != i)
			std::swap(arr[minIdx], arr[i]);
	}
}

int main() {
	int arr[10] = { 3, 4, 1, 2, 4, 5, 0, 2, 7, 6 };
	selectionSort(arr, 10);
	printArr(arr, 10);
	return 0;
}
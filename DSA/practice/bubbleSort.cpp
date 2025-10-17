#include <iostream>

void printArr(int* arr, size_t len) {
	std::cout << "{ ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "}";
}

void bubbleSort(int* arr, size_t len) {
	for (size_t i = 0; i < len; i++)
	{
		bool swapped = false;
		for (size_t j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

int main() {
	int arr[10] = { 3, 4, 1, 2, 4, 5, 0, 2, 7, 6 };
	bubbleSort(arr, 10);
	printArr(arr, 10);
	return 0;
}
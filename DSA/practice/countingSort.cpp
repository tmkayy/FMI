#include <iostream>

void printArr(int* arr, size_t len) {
	std::cout << "{ ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "}" << std::endl;
}

void countingSort(int* arr, size_t arrLength) {
	constexpr int MAX_SIZE = 1e5;
	int copyArr[MAX_SIZE];
	int count[MAX_SIZE];

	int max = arr[0];
	for (size_t i = 0; i < arrLength; i++) {
		copyArr[i] = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	for (size_t i = 0; i <= max; i++) {
		count[i] = 0;
	}

	for (size_t i = 0; i < arrLength; i++) {
		count[copyArr[i]]++;
	}

	for (size_t i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	for (int i = arrLength - 1; i >= 0; i--) {
		arr[count[copyArr[i]] - 1] = copyArr[i];
		count[copyArr[i]]--;
	}
}

int main() {
	int arr[10] = { 3, 4, 1, 2, 4, 5, 0, 2, 7, 6 };
	countingSort(arr, 10);
	printArr(arr, 10);
	return 0;
}
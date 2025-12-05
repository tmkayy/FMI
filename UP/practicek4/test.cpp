#include <iostream>

//haralampy slavkov 2MI0600476

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int numLength(int n) {
	int count = 0;
	do
	{
		count++;
		n /= 10;
	} while (n != 0);
	return count;
}

bool isValid(int n, int length) {
	return n >= 0 && n < length;
}

void reverseArr(int* arr, int length) {
	if (!arr)
	{
		std::cerr << "nullptr";
		return;
	}
	int end = length / 2;
	for (int i = 0; i < end; i++)
	{
		swap(arr[i], arr[length - 1 - i]);
	}
}

int* ExtractNums(int n) {
	int length = numLength(n);
	int* digits = new int[length];
	for (int i = 0; i < length; i++)
	{
		digits[i] = n % 10;
		n /= 10;
	}
	reverseArr(digits, length);
	return digits;
}

int arrToNum(const int* arr, int length) {
	int result = 0;
	for (size_t i = 0; i < length; i++)
	{
		result += arr[i];
		result *= 10;
	}
	return result;
}

int checkForDivisibleBy4(int n, int m, int l) {
	int digit1Pos = m - 1;
	int digit2Pos = l - 1;
	int length = numLength(n);

	if (!(isValid(digit1Pos, length) && (isValid(digit2Pos, length))))
		return -1;

	int* digits = ExtractNums(n);
	swap(digits[digit1Pos], digits[digit2Pos]);
	int newNum = arrToNum(digits, length);

	delete[] digits;

	if (newNum % 4 == 0)
		std::cout << "divisible by 4";
	else
		std::cout << "not divisible by 4";
	return 0;
}

int main() {
	int n, l, m;
	std::cout << "N = ";
	std::cin >> n;
	std::cout << std::endl << "M = ";
	std::cin >> m;
	std::cout << std::endl << "L = ";
	std::cin >> l;
	checkForDivisibleBy4(n, m, l);
}
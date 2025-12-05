#include <iostream>

//1
int NumberOfDividers(int n) {
	int count = 1;
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
			count++;
	}
	return count;
}

//2
int SumOfDigits(int n) {
	int sum = 0;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

//3
void Grade(double n)
{
	if (n >= 2 && n < 3)
		std::cout << "Poor 2";
	else if (n >= 3 && n < 3.5)
		std::cout << "Average 3";
	else if (n >= 3.5 && n < 4.5)
		std::cout << "Good 4";
	else if (n >= 4.5 && n < 5.5)
		std::cout << "Very good 5";
	else if (n >= 5.5 && n <= 6)
		std::cout << "Excellent 6";
	else
		std::cout << "wrong input";
}

//4
int NumberOfDigits(int n) {
	int count = 0;
	do
	{
		count++;
		n /= 10;
	} while (n != 0);
	return count;
}

//5
int ReverseNumber(int n) {
	int rev = 0;
	while (n != 0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev;
}

//6
void EnterSum() {
	int sum = 0;
	int n = 0;
	while (true)
	{
		std::cin >> n;
		if (n == sum)
			break;
		sum += n;
	}
}

//7
void geometricProgression(int start, int ratio, unsigned int n)
{
	for (int i = 1; i <= n; i++)
	{
		std::cout << start << std::endl;
		start *= ratio;
	}
}

//8
void Sdvoeni(int p, int q) {
	for (int i = p; i <= q - 2; i++)
	{
		std::cout << i << ' ' << i + 2 << std::endl;
	}
}

//9
int Concat(int a, int b) {
	int result = 0, revA = 0, revB = 0;
	while (a != 0)
	{
		revA = revA * 10 + a % 10;
		a /= 10;
	}
	while (b != 0)
	{
		revB = revB * 10 + b % 10;
		b /= 10;
	}
	while (revA != 0)
	{
		result = result * 10 + revA % 10;
		revA /= 10;
	}
	while (revB != 0)
	{
		result = result * 10 + revB % 10;
		revB /= 10;
	}
	return result;
}

//10
int AnalyzeNum(int n) {
	int M = -1;
	int tempNum = n;
	while (tempNum != 0)
	{
		int biggerCount = 0;
		int smallerCount = 0;
		int current = tempNum % 10;
		tempNum /= 10;
		int temp = n;
		while (temp != 0)
		{
			if (temp % 10 > current)
				biggerCount++;
			else if (temp % 10 < current)
				smallerCount++;
			temp /= 10;
		}
		if (biggerCount == smallerCount)
		{
			M = current;
			break;
		}
	}
	return M;
}

//11-1
bool isPerfect(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
			sum += i;
	}
	return n == sum;
}

//11-2
void GeneratePerfectNums(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		if (isPerfect(i))
		{
			std::cout << i;
		}
	}
}

//12
bool permutationNumbers(int a, int b)
{
	if (a == b)
		return false;
	int countOfDigitInA = 0;
	int countOfDigitInB = 0;
	for (int i = 0; i < 9; i++)
	{
		int copyA = a;
		int copyB = b;
		while (copyA != 0)
		{
			if (copyA % 10 == i)
				countOfDigitInA++;
			copyA /= 10;
		}
		while (copyB != 0)
		{
			if (copyB % 10 == i)
				countOfDigitInB++;
			copyB /= 10;
		}
		if (countOfDigitInA != countOfDigitInB)
			return false;
	}
	return true;
}

//13
int TransferDigits(int a, int b, int k)
{
	int result = 0;
	for (int i = 0; i < k; i++)
	{
		result = result * 10 + a % 10;
		a /= 10;
	}
	while (b != 0)
	{
		result = result * 10 + b % 10;
		b /= 10;
	}
	return result;
}

//14
int getRemainder(int first, int second)
{
	return first - second * (first / second);
}

//15
int removeDigitAt(unsigned& num, unsigned index)
{
	int rev = 0, count = 1, digits = 0, copy = num;
	while (copy != 0)
	{
		digits++;
		copy /= 10;
	}
	while (num != 0)
	{
		if ((digits - count + 1) != index)
			rev = rev * 10 + num % 10;
		count++;
		num /= 10;
	}
	while (rev != 0)
	{
		num = num * 10 + rev % 10;
		rev /= 10;
	}
	return num;
}



int main() {
	//1
	/*std::cout << NumberOfDividers(4);*/

	//2
	/*std::cout << SumOfDigits(28);*/

	//3
	/*Grade(1.9);*/

	//4
	/*std::cout << NumberOfDigits(345);*/

	//5
	/*std::cout << ReverseNumber(3456);*/

	//6
	/*EnterSum();*/

	//7
	/*geometricProgression(3, 3, 3);*/

	//8
	/*Sdvoeni(9, 20);*/

	//9
	/*std::cout << Concat(15, 24);*/

	//10
	/*std::cout << AnalyzeNum(6666);*/

	//11
	/*GeneratePerfectNums(1, 3);*/

	//12
	/*std::cout << permutationNumbers(2434, 4324);*/

	//13
	/*std::cout << TransferDigits(23311, 54, 3);*/

	//14
	/*std::cout << getRemainder(13, 4);*/

	//15
	/*unsigned num = 12345;
	std::cout << removeDigitAt(num, 2);*/


	return 0;
}
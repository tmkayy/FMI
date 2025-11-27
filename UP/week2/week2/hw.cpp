#include <iostream>

int main() {
	//1
	/*int a, b, c;
	std::cin >> a >> b >> c;
	if (a+b>c&&a+c>b&&b+c>a)
	{
		std::cout << "Exists";
		if (a == b && a == c && b == c)
		{
			std::cout << " Equilateral";
		}
		else if (a == b || a == c || b == c) {
			std::cout << " Isosceles";
		}
		else {
			std::cout << " Scalene";
		}
	}
	else
	{
		std::cout << "Does not exist";
	}*/

	//2
	/*int n;
	std::cin >> n;
	int digit1 = n % 10;
	int digit2 = n /10% 10;
	int digit3 = n / 100;
	if (digit1==digit2||digit1==digit3||digit2==digit3)
	{
		std::cout << "no " << digit1 << digit2 << digit3;
	}
	else
	{
		std::cout << "yes " << digit1 * digit3;
	}*/

	//3
	/*int a, b, c;
	std::cin >> a >> b >> c;
	int maxEven = INT_MIN;
	int minUneven = INT_MAX;
	if (a % 2 == 0)
	{
		if (a>maxEven)
		{
			maxEven = a;
		}
	}
	else
	{
		if (a<minUneven)
		{
			minUneven = a;
		}
	}

	if (b % 2 == 0)
	{
		if (b > maxEven)
		{
			maxEven = b;
		}
	}
	else
	{
		if (b < minUneven)
		{
			minUneven = b;
		}
	}
	if (c % 2 == 0)
	{
		if (c > maxEven)
		{
			maxEven = c;
		}
	}
	else
	{
		if (c < minUneven)
		{
			minUneven = c;
		}
	}

	std::cout << ((maxEven != INT_MIN && minUneven != INT_MAX) ? maxEven - minUneven : (maxEven == INT_MIN ? minUneven : maxEven));*/

	//4
	/*int month, year;
	std::cin >> month >> year;
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		std::cout << 31;
		break;
	case 2:
		if (isLeapYear)
			std::cout << 29;
		else
			std::cout << 28;
		break;
	default:
		std::cout << 30;
		break;
	}*/

	return 0;
}
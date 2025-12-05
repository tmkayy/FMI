#include <iostream>

int main()
{
	//1
	/*int day;
	std::cin >> day;
	bool inJanuary = (day >= 1 && day <= 31);
	std::cout << (inJanuary * day);*/

	//2
	/*int num;
	std::cin >> num;
	bool isDivisible = (num % 2 == 0 && num % 3 != 0);
	std::cout << isDivisible;*/

	//3
	/*int divident, divisor;
	std::cout << "Enter Divident : ";
	std::cin >> divident;
	std::cout << "Enter Divisor : ";
	std::cin >> divisor;
	std::cout << "Quotient : " << (divident / divisor) << std::endl;
	std::cout << "Remainder : " << (divident % divisor) << std::endl;*/

	//4
	/*int num, thousands, hundreds, tens, ones;
	std::cin >> num;
	ones = (num % 10)*1000;
	tens = (num / 10 % 10)*100;
	hundreds = (num / 10 / 10 % 10)*10;
	thousands = num / 1000;
	std::cout << ones + tens + hundreds + thousands;*/

	//5
	/*int num;
	std::cin >> num;
	bool isPalindrome = (num % 10 == num / 100);
	(isPalindrome == true && std::cout << "True") || (isPalindrome == false && std::cout << "False");*/

	//6
	//(1km = 0.621371 miles)
	/*double km;
	double mileModifier = 0.621371;
	std::cin >> km;
	std::cout << km * mileModifier;*/

	//7
	/*int n1, n2, n3, n4;
	std::cin >> n1 >> n2 >> n3 >> n4;
	bool isProgression = (n2 / n1 == n3 / n2 && n4 / n3 == n2 / n1);
	std::cout << isProgression;*/

	//8
	/*int n1, n2, n3;
	std::cin >> n1 >> n2 >> n3;
	bool isNegative = !(n1 > 0 && n2 > 0 && n3 > 0);
	std::cout << isNegative;*/

	//9
	//int lowerLimit, n, upperLimit;
	//std::cin >> lowerLimit >> n >> upperLimit;
	//bool toSwap = (lowerLimit > upperLimit);
	//(toSwap && (lowerLimit += upperLimit) && (upperLimit = lowerLimit - upperLimit) && (lowerLimit -= upperLimit));
	////swap without promenliva if the interval is wrong

	//bool inRange = (lowerLimit <= n && n <= upperLimit);
	//std::cout << inRange;

	//10
	/*int num, thousands, hundreds, tens, ones;
	std::cin >> num;
	ones = num % 10;
	tens = num / 10 % 10;
	hundreds = num / 10 / 10 % 10;
	thousands = num / 1000;
	int sum = ones + tens + hundreds + thousands;
	int product = ones * tens * hundreds * thousands;
	double average = (ones + tens + hundreds + thousands) / 4.00;
	std::cout << sum << " " << product << " " << average;*/

	//11
	/*int a, b, c, x;
	std::cin >> a >> b >> c >> x;
	std::cout << a * x * x + b * x + c;*/

	//12
	/*int a, b, c;
	std::cin >> a >> b >> c;
	bool exists = (a + b > c && a + c > b && b + c > a);
	std::cout << exists;*/

	//13
	/*double a, b, c;
	std::cin >> a >> b >> c;
	double perimeter = a + b + c;
	double halfPerimeter = perimeter / 2;
	double area = halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c);
	std::cout << "Area = " << area;
	std::cout << "Perimeter = " << perimeter;*/

	//14
	/*int seconds, days, hours, minutes;
	std::cin >> seconds;
	int const MINUTE_SECS = 60;
	int const HOUR_SECS = 60 * MINUTE_SECS;
	int const DAY_SECS = 24 * HOUR_SECS;
	days = seconds / DAY_SECS;
	seconds -= days* DAY_SECS;
	hours = seconds / HOUR_SECS;
	seconds -= hours * HOUR_SECS;
	minutes = seconds / MINUTE_SECS;
	seconds -= minutes * MINUTE_SECS;
	std::cout << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";*/

	//15
	/*int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	bool crossNot1 = a <= b && b <= c && c <= d;
	bool crossNot2 = c <= d && d <= a && a <= b;
	if (crossNot1||crossNot2)
		std::cout << 0;
	else
		std::cout << 1;*/

		//16
		/*int a, b;
		std::cin >> a >> b;
		a += b;
		b = a - b;
		a -= b;
		std::cout << a << " " << b;*/

	//17
	/*int a, b, c, d;
	int evenSum = 0;
	std::cin >> a >> b >> c >> d;
	if (a%2==0)
	{
		evenSum += a;
	}
	if (b % 2 == 0)
	{
		evenSum += b;
	}
	if (c % 2 == 0)
	{
		evenSum += c;
	}
	if (d % 2 == 0)
	{
		evenSum += d;
	}
	std::cout << evenSum;*/


	return 0;
}
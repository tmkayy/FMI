#include <iostream>
int main() {
	//1
	/*int year;
	std::cin >> year;
	bool isLeap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	std::cout << year << (isLeap ? " is a leap year" : " isn't a leap year");*/

	//2
	/*int num;
	std::cin >> num;
	if (num == 0)
		std::cout << 0;
	else
		std::cout << (num % 2 == 0 ? "Even" : "Odd");*/

		//3
		/*char c;
		std::cin >> c;
		std::cout << (c >= 'a' && c <= 'z' ? "true" : "false");*/

		//4
	/*int const GAP = 32;
	char c;
	std::cin >> c;
	bool isLower = c >= 'a' && c <= 'z';
	bool isUpper = c >= 'A' && c <= 'Z';
	if (isUpper)
		std::cout << (char)(c + 32) << std::endl;
	else if (isLower)
		std::cout << (char)(c - 32) << std::endl;
	else {
		std::cout << "not a letter" << std::endl;
		return 0;
	}

	switch (c)
	{
	case 'A':
	case 'a':
	case 'U':
	case 'u':
	case 'O':
	case 'o':
	case 'E':
	case 'e':
		std::cout << "Vowel";
		break;
	default:
		std::cout << "Consonant";
	}*/

	//5
	/*int day;
	std::cin >> day; day %= 7;
	switch (day)
	{
	case 0:
		std::cout << "Monday";
		break;
	case 1:
		std::cout << "Tuesday";
		break;
	case 2:
		std::cout << "Wednesday";
		break;
	case 3:
		std::cout << "Thursday";
		break;
	case 4:
		std::cout << "Friday";
		break;
	case 5:
		std::cout << "Saturday";
		break;
	case 6:
		std::cout << "Sunday";
		break;
	}*/

	//6
	//int num;
	//std::cin >> num;
	//switch (num)
	//{
	//case 1: std::cout << "I";  break;
	//case 2: std::cout << "II";  break;
	//case 3: std::cout << "III";  break;
	//case 4: std::cout << "IV";  break;
	//case 5: std::cout << "V";  break;
	//case 6: std::cout << "VI";  break;
	//case 7: std::cout << "VII";  break;
	//case 8: std::cout << "VII";  break;
	//case 9: std::cout << "IX";  break;
	//case 10: std::cout << "X";  break;
	//default: std::cout << "invalid number";  break;
	//}

	//7
	/*int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;
	bool bCheck = (b > a && b > c) || (b < a && b < c);
	bool cCheck = (c > b && c > d) || (c < d && c < b);
	bool dCheck = (d > c && d > e) || (d < c && d < e);
	if (bCheck && cCheck && dCheck)
		std::cout << "True";
	else
		std::cout << "False";*/

		//8
	/*int r, a, b, x, y;
	std::cin >> r >> a >> b >> x >> y;
	int result = (x - a) * (x - a) + (y - b) * (y - b);
	if (result == r * r)
		std::cout << "on the circle";
	else if (result < r * r)
		std::cout << "inside";
	else
		std::cout << "outside";*/

		//9
	//int temp;
	//std::cin >> temp;
	//if (temp >= 35)
	//	std::cout << "very hot";
	//else if (temp >= 25 && temp < 35)
	//	std::cout << "hot";
	//else if (temp >= 15 && temp < 25)
	//	std::cout << "warm";
	//else if (temp >= 5 && temp < 15)
	//	std::cout << "cool";
	//else
	//	std::cout << "cold";


	//10
	/*double a, b, c;
	std::cin >> a >> b >> c;
	double d = b * b - 4 * a * c;
	if (d == 0)
		std::cout << -b / (2 * a);
	else if (d < 0)

		std::cout << "no real roots";
	else
	{
		std::cout << (-b + sqrt(d)) / (2 * a) << " ";
		std::cout << (-b - sqrt(d)) / (2 * a);
	}*/

	//11
	/*int n;
	std::cin >> n;
	std::cout << ((n / 1000 + n / 10 / 10 % 10 == n / 10 % 10 + n % 10) ? "Yes" : "No");*/

	//12
	/*int n, numberToFind;
	std::cin >> n >> numberToFind;
	std::cout << ((n % 10 == numberToFind || n / 10 % 10 == numberToFind || n / 100 == numberToFind) ? "Yes" : "No");*/

	//13
	/*int n;
	std::cin >> n;
	if ((n % 2 != 0 && n < 15) ||
		!(n % 2 == 0 && n >= 15 && n <= 30) ||
		(n >30 && n % 4 == 0))
	{
		std::cout << "Strange";
	}
	else
		std::cout << "Not strange";*/

		//14
		/*int seconds, hours, minutes;
		std::cin >> seconds;
		int const MINUTE_SECS = 60;
		int const HOUR_SECS = 60 * MINUTE_SECS;
		hours = seconds / HOUR_SECS;
		seconds -= hours * HOUR_SECS;
		minutes = seconds / MINUTE_SECS;
		seconds -= minutes * MINUTE_SECS;
		if (hours < 10)
			std::cout << '0' << hours << " hours, ";
		else
			std::cout << hours << " hours, ";
		if (minutes < 10)
			std::cout << '0' << minutes << " minutes, ";
		else
			std::cout << minutes << " minutes, ";
		if (seconds < 10)
			std::cout << '0' << seconds << " seconds";
		else
			std::cout << seconds << " seconds";*/

			//15
			/*int hours, minutes;
			std::cin >> hours >> minutes;
			minutes += 5;
			if (minutes>=60)
			{
				minutes %= 60;
				hours += 1;
			}
			hours %= 24;
			if (hours < 10)
				std::cout << '0' << hours;
			else
				std::cout << hours;
			std::cout << ':';
			if (minutes<10)
				std::cout << '0' << minutes;
			else
				std::cout << minutes;*/

				//16
				/*int day, month;
				std::cin >> day >> month;
				switch (month)
				{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					if (day != 31)
					{
						day++;
					}
					else
					{
						day = 1;
						if (month == 12)
							month = 1;
						else
							month++;
					}break;
				case 2:
					if (day != 28)
					{
						day++;
					}
					else
					{
						day = 1;
						month++;
					}break;
				case 4:
				case 6:
				case 9:
				case 11:
					if (day != 30)
					{
						day++;
					}
					else
					{
						day = 1;
						month++;
					}break;
				default:
					std::cout << "invalid data";
					return 0;
				}
				std::cout << day << ' ' << month;*/

				//17
	/*double a, b, result = 0;
	char c;
	std::cin >> a >> b >> c;
	switch (c)
	{
	case '+':
		result = a + b;
	case '-':
		result = a - b;
	case '*':
		result = a * b;
	case '/':
		if (b>0.000000001)
		{
			result = a / b;
		}
		else
		{
			std::cout << "Cannot divide by 0!";
			return 0;
		}
	}
	std::cout << result;*/

	//18
	/*int a, b, c;
	std::cin >> a >> b >> c;
	if (b>a)
	{
		a += b;
		b = a - b;
		a -= b;
	}
	if (c > a)
	{
		a += c;
		c = a - c;
		a -= c;
	}
	if (c > b)
	{
		b += c;
		c = b - c;
		b -= c;
	}
	std::cout << a << b << c;*/

	//19
	/*double n;
	std::cin >> n;
	int check = n + 1;
	if (check-n==1)
		std::cout << "integer number";
	else
		std::cout << "floating point number";*/

		//20
	/*char a1, b1, a2, b2, x;
	const int LETTER_DIFF = 'a' - 'A';
	std::cin >> a1 >> b1 >> a2 >> b2 >> x;
	a2 -= LETTER_DIFF;
	b2 -= LETTER_DIFF;
	if (x > 'Z')
	{
		x -= LETTER_DIFF;
	}
	bool isUnion = (x >= a1 && x <= b1) || (x >= a2 && x <= b2);
	bool isIntersection = (x >= a1 && x <= b1) && (x >= a2 && x <= b2);
	bool isDifference = (x >= a1 && x <= b1) && !(x >= a2 && x <= b2);
	bool isOnlyInOne = !isIntersection && isUnion;
	std::cout << isUnion << std::endl << isIntersection << std::endl <<
		isDifference << std::endl << isDifference;*/

	return 0;
}
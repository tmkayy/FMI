#include <iostream>

int main()
{
	//1
	/*int number;
	std::cin >> number;
	if (number > 0)
		std::cout << "positive";
	else if(number < 0)
		std::cout << "negative";
	else
		std::cout << "0";*/

		//2
		/*int number;
		std::cin >> number;
		switch (number)
		{
		case 1: std::cout << "I"; break;
		case 2: std::cout << "II"; break;
		case 3: std::cout << "III"; break;
		case 4: std::cout << "IV"; break;
		case 5: std::cout << "V"; break;
		case 6: std::cout << "VI"; break;
		case 7: std::cout << "VII"; break;
		case 8: std::cout << "VIII"; break;
		case 9: std::cout << "IX"; break;
		default:
			break;
		}*/

		//3
		/*int year;
		std::cin >> year;
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (isLeap)
			std::cout << "Leap Year";
		else
			std::cout << "Not Leap Year";*/

			//4
			/*int day;
			std::cin >> day;
			switch (day)
			{
			case 1: std::cout << "Monday"; break;
			case 2: std::cout << "Tuesday"; break;
			case 3: std::cout << "Wednesday"; break;
			case 4: std::cout << "Thursday"; break;
			case 5: std::cout << "Friday"; break;
			case 6: std::cout << "Saturday"; break;
			case 7: std::cout << "Sunday"; break;
			default:break;
			}*/

			//5
			/*int num1, num2;
			std::cin >> num1 >> num2;
			std::cout << ((num1 > num2) ? num1 : num2);*/

			//6
			/*char letter;
			std::cin >> letter;
			const int difference = 32;
			bool isUpper = (letter >= 'A' && letter <= 'Z');
			bool isLower = (letter >= 'a' && letter <= 'z');
			bool isVowel = letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter == 'i' || letter == 'I' ||
				letter == 'o' || letter == 'O' || letter == 'u' || letter == 'U';
			if (isUpper)
			{
				std::cout << (char)(letter + difference) << std::endl;
				std::cout << (isVowel ? "Vowel" : "Not Vowel");

			}
			else if (isLower) {
				std::cout << (char)(letter - difference) << std::endl;
				std::cout << (isVowel ? "Vowel" : "Not Vowel");
			}
			else {
				std::cout << "Invalid Character";
			}*/

			//7
			/*int a, b, c, temp;
			std::cin >> a >> b >> c;
			if (c<b)
			{
				temp = c;
				c = b;
				b = temp;
			}
			if (b < a) {
				temp = a;
				a = b;
				b = temp;
			}
			if (c<a)
			{
				temp = c;
				c = a;
				a = temp;
			}
			std::cout << a << " " << b << " " << c;*/

			//8
	/*int r, x, y;
	std::cin >> r >> x >> y;
	if (x * x + y * y == r * r)
	{
		std::cout << "on the circle";
	}
	else if (x * x + y * y < r * r)
	{
		std::cout << "in the circle";
	}
	else {
		std::cout << "outside the circle";
	}*/

	double a, b, c, epsilon;
	std::cin >> a >> b >> c;
	epsilon = 0.0001;
	if (abs(c-a)>=epsilon)
	{
		//cant be bothered to finish this shit
	}
}
//#include <iostream>
//
//int main() {
//	//1
//	/*int n, result = 1;
//	std::cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		result *= i;
//	}
//	std::cout << result;*/
//
//	//2
//	/*int a, b, result = 1;
//	std::cin >> a >> b;
//	for (int i = 0; i < b; i++)
//	{
//		result *= a;
//	}
//	std::cout << result;*/
//
//	//3
//	/*int n;
//	std::cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			std::cout << j;
//		}
//		std::cout << std::endl;
//	}*/
//
//	//4
//	/*int temp, count = 0;
//	while (true)
//	{
//		std::cin >> temp;
//		if (temp%7==0)
//		{
//			count++;
//			if (count==3)
//			{
//				break;
//			}
//		}
//	}*/
//
//	//5
//	/*int count, num;
//	std::cin >> count;
//	for (int i = 0; i < count; i++)
//	{
//		std::cin >> num;
//		for (int j = num; j > 0; j--)
//		{
//			if (num%j==0)
//			{
//				std::cout << j << ' ';
//			}
//		}
//		std::cout << std::endl;
//	}*/
//
//	//6
//	/*int n, smallerSum = 0, temp;
//	std::cin >> n;
//	int sum = (n * (1 + n)) / 2;
//	for (int i = 0; i < n - 1; i++)
//	{
//		std::cin >> temp;
//		smallerSum += temp;
//	}
//	std::cout << sum - smallerSum;*/
//
//	//7
//	/*int n, sum = 0, currentNum = 9;
//	std::cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += currentNum;
//		currentNum = currentNum * 10 + 9;
//	}
//	std::cout << sum;*/
//
//	//8
//	/*int firstNum = 0, secondNum = 1, newNum = 0, n;
//	std::cin >> n;
//	if (n==1)
//	{
//		std::cout << 0;
//	}
//	else if (n == 2)
//	{
//		std::cout << 1;
//	}
//	for (int i = 3; i <= n; i++)
//	{
//		newNum = firstNum + secondNum;
//		firstNum = secondNum;
//		secondNum = newNum;
//	}
//	std::cout << newNum;*/
//
//	//9
//	/*int n, temp;
//	std::cin >> n;
//	bool allEven = true;
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> temp;
//		if (temp % 2 != 0)
//		{
//			allEven = false;
//		}
//	}
//	std::cout << (allEven ? "all are even" : "not all");*/
//
//	//10
//	/*int n, k, counter = 0;
//	std::cin >> n >> k;
//	while (true)
//	{
//		if (n % 10 == k)
//		{
//			counter++;
//		}
//		n /= 10;
//		if (n==0)
//		{
//			std::cout << counter;
//			break;
//		}
//	}*/
//
//	//11
//	/*int n;
//	std::cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (j == 1 || j == n)
//			{
//				if (i == 1 || i == n)
//				{
//					std::cout << '+';
//				}
//				else
//				{
//					std::cout << '|';
//				}
//			}
//			else
//			{
//				std::cout << " - ";
//			}
//		}
//		std::cout << std::endl;
//	}*/
//
//	//12
//	/*int n;
//	std::cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = n-i; j > 0; j--)
//		{
//			std::cout << ' ';
//		}
//		for (int j = 1; j <= i; j++)
//		{
//			std::cout << j;
//		}
//		for (int j = i - 1; j > 0; j--)
//		{
//			std::cout << j;
//		}
//		std::cout << std::endl;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int i = 0; i < n-1; i++)
//		{
//			std::cout << ' ';
//		}
//		std::cout << '*';
//		std::cout << std::endl;
//	}*/
//
//	//13
//	/*int n;
//	std::cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		if (i == 0 || i == n - 1)
//		{
//			for (int j = 0; j < n * 2; j++)
//			{
//				std::cout << "*";
//			}
//		}
//		else
//		{
//			std::cout << "*";
//			for (int j = 0; j < n * 2 - 2; j++)
//			{
//				std::cout << "/";
//			}
//			std::cout << "*";
//		}
//		if (i == n / 2)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				std::cout << "|";
//			}
//		}
//		else
//		{
//			for (int j = 0; j < n; j++)
//			{
//				std::cout << " ";
//			}
//		}
//		if (i == 0 || i == n - 1)
//		{
//			for (int j = 0; j < n * 2; j++)
//			{
//				std::cout << "*";
//			}
//		}
//		else
//		{
//			std::cout << "*";
//			for (int j = 0; j < n * 2 - 2; j++)
//			{
//				std::cout << "/";
//			}
//			std::cout << "*";
//		}
//		std::cout << std::endl;
//	}*/
//
//	//14
//	/*int m, n, sum, temp;
//	std::cin >> m >> n;
//	for (int i = m; i <= n; i++)
//	{
//		temp = i;
//		sum = 0;
//		while (true)
//		{
//			sum += temp % 10;
//			temp /= 10;
//			if (temp == 0)
//				break;
//		}
//		if (sum > 9 && sum < 100)
//		{
//			std::cout << i << " ";
//		}
//	}*/
//
//	//15
//	/*int m, n;
//	std::cin >> m >> n;
//	for (int i = m; i <= n; i++)
//	{
//		bool isPrime = true;
//		for (int j = 2; j <= i/2; j++)
//		{
//			if (i%j==0)
//			{
//				isPrime = false;
//			}
//		}
//		if (isPrime)
//		{
//			std::cout << i << ' ';
//		}
//	}*/
//
//	//16
//	/*int n, temp, revNum = 0, newNum = 0, counter = 0;
//	std::cin >> n;
//	temp = n;
//	while (temp != 0)
//	{
//		revNum = revNum * 10 + temp % 10;
//		temp /= 10;
//		counter++;
//	}
//	if (counter % 2 == 1)
//	{
//		for (int i = 1; i <= counter && revNum != 0; i++)
//		{
//			newNum = newNum * 10 + revNum % 10;
//			if (i == counter / 2)
//			{
//				revNum /= 10;
//			}
//			revNum /= 10;
//		}
//	}
//	if (counter % 2 == 0)
//	{
//		for (int i = 1; i <= counter && revNum != 0; i++)
//		{
//			newNum = newNum * 10 + revNum % 10;
//			if (i == counter / 2 - 1 || i == counter / 2)
//			{
//				revNum /= 10;
//			}
//			revNum /= 10;
//		}
//	}
//	std::cout << newNum << ", " << newNum + 1;*/
//
//	return 0;
//}
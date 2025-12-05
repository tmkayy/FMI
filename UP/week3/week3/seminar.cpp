//#include <iostream>
//
//int main() {
//	//1
//	/*int n;
//	std::cin >> n;
//	int end = sqrt(n);
//	for (int i = 2; i <= end; i++)
//	{
//		if (n%i==0)
//		{
//			std::cout << "not prime";
//			return 0;
//		}
//	}
//	std::cout << "prime";*/
//
//	//2
//	/*int n;
//	std::cin >> n;
//	for (int i = n; i > 1; i--)
//	{
//		int end = sqrt(i);
//		bool isPrime = true;
//		for (int j = 2; j <= end; j++)
//		{
//			if (i%j==0)
//			{
//				isPrime = false;
//				break;
//			}
//		}
//		if (!isPrime)
//			continue;
//		int count = 0;
//		while (n%i==0)
//		{
//			count++;
//			n /= i;
//		}
//		if (count>0)
//		{
//			std::cout << i << '^' << count << ' ';
//		}
//	}*/
//
//	//3
//	/*int n; //doesnt work
//	std::cin >> n;
//	int hyphen = 0;
//	for (int i = n; i >= 1; i -= 2)
//	{
//		for (int t = 0; t < hyphen; t++)
//		{
//			std::cout << ' ';
//		}
//		for (int j = 1; j <= i; j++)
//		{
//			std::cout << '*';
//		}
//		for (int t = 0; t < hyphen; t++)
//		{
//			std::cout << ' ';
//		}
//		std::cout << std::endl;
//		hyphen++;
//	}hyphen -= 1;
//
//	for (int i = 2; i <= n; i+=2)
//	{
//		for (int t = 0; t < hyphen; t++)
//		{
//			std::cout << ' ';
//		}
//		for (int j = 1; j <= i; j++)
//		{
//			std::cout << '*';
//		}
//		for (int t = 0; t < hyphen; t++)
//		{
//			std::cout << ' ';
//		}
//		std::cout << std::endl;
//		hyphen--;
//	}*/
//
//	//1
//	/*int sum = 0;
//	while (true) {
//		int n;
//		std::cin >> n;
//		if (n==0)
//		{
//			std::cout << sum; return 0;
//		}
//		sum += n;
//	}*/
//
//	//2
//	/*int a, b, c, d, e;
//	std::cin >> a >> b >> c >> d >> e;
//	for (int x = -100; x <= 100; x++)
//	{
//		if (a*pow(x,4)+b*pow(x,3)+c*pow(x,2)+d*x+e>=0)
//		{
//			std::cout << x << ' ';
//		}
//	}*/
//
//	//3
//	//int n, currentMax, currentMaxNum, currentNum, overallMax, tempnum;
//	//std::cin >> n;
//	//overallMax = 0;
//	//currentMaxNum = 10; //never double digit
//	//while (true)
//	//{
//	//	currentNum = n % 10;
//	//	currentMax = 1;
//	//	n = n/10;
//	//	tempnum = n;
//	//	if (currentNum!=currentMaxNum)
//	//	{
//	//		while (true)
//	//		{
//	//			if (tempnum % 10 == currentNum) {
//	//				currentMax++;
//	//			}
//	//			tempnum /= 10;
//	//			if (tempnum == 0)
//	//			{
//	//				break;
//	//			}
//	//		}
//	//	}
//	//	if (overallMax==currentMax)
//	//	{
//	//		if (currentMaxNum>currentNum)
//	//		{
//	//			currentMaxNum = currentNum;
//	//		}
//	//	}
//	//	else if (overallMax < currentMax)
//	//	{
//	//		overallMax = currentMax;
//	//		currentMaxNum = currentNum;
//	//	}
//	//	if (n==0)
//	//	{
//	//		std::cout << currentMaxNum;
//	//		return 0;
//	//	}
//	//}
//
//	//4 - 1
//	/*int m, n, counter = 0;
//	int count0, count1, count2,
//		count3, count4, count5,
//		count6, count7, count8, count9;
//	std::cin >> m >> n;
//	if (m > n)
//	{
//		m += n;
//		n = m - n;
//		m -= n;
//	}
//	for (int i = m; i <= n; i++)
//	{
//		count0=0, count1=0, count2=0,
//			count3=0, count4=0, count5=0,
//			count6=0, count7=0, count8= 0, count9 = 0;
//		int current = i;
//		while (true)
//		{
//			switch (current%10)
//			{
//			case 0:count0++; break;
//			case 1:count1++; break;
//			case 2:count2++; break;
//			case 3:count3++; break;
//			case 4:count4++; break;
//			case 5:count5++; break;
//			case 6:count6++; break;
//			case 7:count7++; break;
//			case 8:count8++; break;
//			case 9:count9++; break;
//			}
//			current /= 10;
//			if (current==0)
//			{
//				break;
//			}
//		}
//		if (!(count0>1|| count1 > 1|| count2 > 1 ||
//			count3 > 1|| count4 > 1|| count5 > 1 ||
//			count6 > 1 || count7 > 1|| count8 > 1|| count9 > 1))
//		{
//			counter++;
//		}
//	}
//	std::cout << counter;*/
//
//	//4 - 2
//	/*int m,n, counter = 0, currentNum, digit,temp;
//	std::cin >> m >> n;
//	if (m > n)
//	{
//		m += n;
//		n = m - n;
//		m -= n;
//	}
//	for (int i = m; i <= n; i++)
//	{
//		bool isDifferent = true;
//		currentNum = i;
//		while (true)
//		{
//			digit = currentNum % 10;
//			while (true)
//			{
//				int currentDigit = currentNum / 10 % 10;
//				if (digit==currentDigit)
//				{
//					isDifferent = false;
//					break;
//				}
//				currentNum /= 10;
//				if (currentNum == 0)
//				{
//					break;
//				}
//				currentDigit = currentNum % 10;
//			}
//			currentNum /= 10;
//			if (!isDifferent || currentNum == 0)
//			{
//				break;
//			}
//		}
//		if (isDifferent)
//		{
//			counter++;
//		}
//	}
//	std::cout << counter;*/
//
//
//	//5
//	/*int n;
//	std::cin >> n;
//	for (int i = 1; i <= n*n;)
//	{
//		if (((i-1)/n)%2==0)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				std::cout << i << ' ';
//				i++;
//			}
//			std::cout << std::endl;
//		}
//		else {
//			int start = i + (n-1);
//			for (int j = 0; j < n; j++)
//			{
//				std::cout << start << ' ';
//				start--;
//			}
//			i += n;
//			std::cout << std::endl;
//		}
//	}*/
//
//	//6
//	/*int n;
//	std::cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		std::cout << '.';
//		if (n%2==1&&i==n/2+1) {
//			for (int i1 = 0; i1 < n - 2; i1++)
//			{
//				std::cout << ' ';
//			}
//			std::cout << '.';
//			for (int gap = 0; gap < n-2; gap++)
//			{
//				std::cout << '.';
//			}
//			std::cout << '.';
//			for (int i2 = 0; i2 < n - 2; i2++)
//			{
//				std::cout << ' ';
//			}
//		} 
//		else if (n % 2 == 0 && (i == n / 2 + 1 || i == n / 2))
//		{
//			for (int i1 = 0; i1 < n - 2; i1++)
//			{
//				std::cout << ' ';
//			}
//			std::cout << '.';
//			for (int gap = 0; gap < n - 2; gap++)
//			{
//				std::cout << '.';
//			}
//			std::cout << '.';
//			for (int i2 = 0; i2 < n - 2; i2++)
//			{
//				std::cout << ' ';
//			}
//		}
//		else if (i!=1&&i!=n)
//		{
//			for (int i1 = 0; i1 < n-2; i1++)
//			{
//				std::cout << ' ';
//			}
//			std::cout << '.';
//			for (int gap = 0; gap < n-2; gap++)
//			{
//				std::cout << ' ';
//			}
//			std::cout << '.';
//			for (int i2 = 0; i2 < n-2; i2++)
//			{
//				std::cout << ' ';
//			}
//		}
//		else {
//			for (int i1 = 0; i1 < n - 2; i1++)
//			{
//				std::cout << '.';
//			}
//			std::cout << '.';
//			for (int gap = 0; gap < n - 2; gap++)
//			{
//				std::cout << ' ';
//			}
//			std::cout << '.';
//			for (int i2 = 0; i2 < n - 2; i2++)
//			{
//				std::cout << '.';
//			}
//		}
//		std::cout << '.';
//		std::cout << std::endl;
//	}*/
//
//	return 0;
//}
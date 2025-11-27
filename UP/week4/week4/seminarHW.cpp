#include <iostream>


int Power(int n1, int n2)
{
	for (int i = 1; i < n2; i++)
	{
		n1 *= n1;
	}
	return n1;
}

//1
//double Perimeter(int x1, int y1, int x2, int y2, int x3, int y3)
//{
//	double side1, side2, side3;
//	side1 = sqrt(Power((x2 - x1), 2) + Power((y2 - y1), 2));
//	side2 = sqrt(Power((x3 - x2), 2) + Power((y3 - y2), 2));
//	side3 = sqrt(Power((x1 - x3), 2) + Power((y1 - y3), 2));
//	return side1 + side2 + side3;
//}

//2
//int concatWithReverse(int n) {
//	int counter = 0, temp = n, result = 0, revNum = 0;
//	while (temp != 0)
//	{
//		revNum = revNum * 10 + temp % 10;
//		temp /= 10;
//		counter++;
//	}
//	temp = n;
//	for (int i = 1; i <= counter * 2; i++)
//	{
//		if (i <= counter)
//		{
//			result = result * 10 + temp % 10;
//			temp /= 10;
//		}
//		else
//		{
//			result = result * 10 + revNum % 10;
//			revNum /= 10;
//		}
//	}
//	return result;
//}

//3
//bool isSorted(int n)
//{
//	int prevNum = n % 10;
//	int temp = n / 10;
//	bool ascending = true;
//	bool descending = true;
//	while (temp != 0)
//	{
//		int num = temp % 10;
//		if (num > prevNum)
//		{
//			ascending = false;
//			break;
//		}
//		temp /= 10;
//	}
//	prevNum = n % 10;
//	temp = n / 10;
//	while (temp != 0)
//	{
//		int num = temp % 10;
//		if (num < prevNum)
//		{
//			descending = false;
//			break;
//		}
//		temp /= 10;
//	}
//	return ascending || descending;
//}

//4
//bool sameDigits(int n) {
//	int prevNum = n % 10;
//	int temp = n / 10;
//	bool same = true;
//	while (temp != 0)
//	{
//		int num = temp % 10;
//		if (num != prevNum)
//		{
//			same = false;
//			break;
//		}
//		temp /= 10;
//	}
//	return same;
//}

//5
//int sortNum(int n) {
//	int result = 0;
//	for (int i = 1; i <= 9; i++)
//	{
//		int temp = n;
//		while (temp != 0)
//		{
//			if (i == temp % 10)
//			{
//				result = result * 10 + temp % 10;
//			}
//			temp /= 10;
//		}
//	}
//	return result;
//}

//6
//bool isPrefix(int n, int k) {
//
//	do
//	{
//		if (k % 10 != n % 10)
//		{
//			return false;
//		}
//		n /= 10;
//		k /= 10;
//	} while (k != 0);
//
//	return true;
//}

//7
//bool isInfix(int n, int k)
//{
//	if (n==0&&k!=0)
//	{
//		return false;
//	}
//	int tempK = k;
//	do
//	{
//		if (tempK % 10 != n % 10)
//		{
//			n /= 10;
//			return isInfix(n, k);
//		}
//		n /= 10;
//		tempK /= 10;
//	} while (tempK != 0);
//
//	return true;
//}

//8
//char isDigit(char c)
//{
//	return (c >= '0' && c <= '9' ? c : 'e');
//}


int main() {
	//1
	/*std::cout << Perimeter(1, 1, 4, 7, 0, 10);*/

	//2
	/*std::cout << concatWithReverse(1234);*/

	//3
	/*std::cout << (isSorted(111111) ? "true" : "false");*/

	//4
	/*std::cout << (sameDigits(111311) ? "true" : "false");*/

	//5
	/*std::cout << sortNum(531261);*/

	//6
	/*std::cout << (isPrefix(0, 1) ? "true" : "false");*/

	//7
	/*std::cout << (isInfix(2831, 83) ? "true" : "false");*/

	//8
	/*std::cout << isDigit('8');*/

	return 0;
}
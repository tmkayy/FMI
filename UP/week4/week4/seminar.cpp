//#include <iostream>
//
////bool isPrime(int n)
////{
////	int end = sqrt(n);
////	for (int j = 2; j <= end; j++)
////	{
////		if (n % j == 0)
////		{
////			return false;
////		}
////	}
////}
//
////int reverseNum(int n) {
////	int result = 0;
////	while (true)
////	{
////		result = result * 10 + n % 10;
////		n /= 10;
////		if (n == 0)
////		{
////			return result;
////		}
////	}
////}
//
//bool isNegative(int k)
//{
//	return k < 0;
//}
//
////bool isSuffix(int n, int k)
////{
////	if (isNegative(n) || isNegative(k))
////	{
////		return false;
////	}
////	if (k == 0)
////	{
////		return n % 10 == k;
////	}
////	while (k != 0)
////	{
////		if (n % 10 != k % 10)
////		{
////			return false;
////		}
////		n /= 10;
////		k /= 10;
////	}
////
////	return true;
////}
//
////int log(int n, int k) {
////	int temp = 1, count = 0;
////	if (k > n)
////	{
////		return 0;
////	}
////	while (temp <= n)
////	{
////		temp *= k;
////		count++;
////	}
////	return count - 1;
////}
//
////int absolute(int n) {
////	return (n > 0 ? n : n * -1);
////}
//
////char upperToLower(char c) {
////	return 'a' + c - 'A';
////}
//
//int main() {
//	//1
//	/*int n;
//	std::cin >> n;
//	if (n < 0)
//	{
//		std::cout << "wrong input";
//		return -1;
//	}
//	if (n < 6)
//	{
//		return 0;
//	}
//	for (int i = 6; i < n; i += 6)
//	{
//		int firstNum = i - 1;
//		bool prime = isPrime(firstNum);
//		if (!prime)
//		{
//			continue;
//		}
//		int secondNum = i + 1;
//		if (isPrime(secondNum))
//		{
//			std::cout << firstNum << " " << secondNum << std::endl;
//		}
//	}*/
//
//	//2
//	/*int n;
//	std::cin >> n;
//	std::cout << reverseNum(n);*/
//
//	//3
//	/*int n, k;
//	std::cin >> n >> k;
//	std::cout << (isSuffix(n, k) ? "true" : "false");*/
//
//	//4
//	/*int n, k;
//	std::cin >> n >> k;
//	std::cout << log(n, k);*/
//
//	//5
//	/*std::cout << upperToLower('D');*/
//
//	return 0;
//}
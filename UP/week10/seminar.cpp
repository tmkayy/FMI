//#include <iostream>
//
//int toNumber(const char c) {
//	if (c >= '0' && c <= '9')
//	{
//		return c - '0';
//	}
//	return -1;
//}
//
//int myAtoi(const char* str) {
//	if (!str)
//		return 0;
//	int res = 0;
//	bool neg = (*str == '-');
//	if (neg)
//		str++;
//	while (*str != '\0')
//	{
//		int temp = toNumber(*str);
//		if (temp == -1)
//		{
//			return 0;
//		}
//		res = res * 10 + temp;
//		str++;
//	}
//	if (neg)
//		res *= -1;
//	return res;
//}
//
//int reverseNum(int n) {
//	int result = 0;
//	while (n != 0)
//	{
//		result = result * 10 + n % 10;
//		n /= 10;
//	}
//	return result;
//}
//
//void myToString(int n, char* str)
//{
//	if (!str)
//		return;
//	n = reverseNum(n);
//	if (n < 0)
//	{
//		*str = '-'; str++; n *= -1;
//	}
//	while (n != 0)
//	{
//		*str = n % 10 + '0';
//		n /= 10;
//		str++;
//	}
//	*str = '\0';
//}
//
//bool searchInText(const char* text, const char* word) {
//	if (!text || !word)
//		return 0;
//	if (*word == '\0')
//		return 1;
//	while (*text)
//	{
//		if (*text == *word)
//		{
//			for (int i = 1; ; i++)
//			{
//				if (word[i] == '\0')
//					return true;
//				if (word[i] != *(text + i))
//					break;
//			}
//		}
//		text++;
//	}
//	return false;
//}
//
//void myReplace(const char* text, const char* where, const char* what, char* result)
//{
//	if (!text || !where || !what || !result)
//		return;
//
//	const char* textPtr = text;  
//	const char* wherePtr;        
//	const char* whatPtr = what;   
//
//	while (*textPtr)
//	{
//		wherePtr = where;
//		const char* tempTextPtr = textPtr;
//
//		while (*tempTextPtr && *wherePtr && *tempTextPtr == *wherePtr)
//		{
//			tempTextPtr++;
//			wherePtr++;
//		}
//		if (*wherePtr == '\0')
//		{
//			while (*whatPtr)
//			{
//				*result = *whatPtr;
//				result++;
//				whatPtr++;
//			}
//			textPtr = tempTextPtr;
//			whatPtr = what;
//		}
//		else
//		{
//			*result = *textPtr;
//			result++;
//			textPtr++;
//		}
//	}
//	*result = '\0';
//}
//
//
//int main() {
//	/*char c[] = "-123";
//	std::cout << myAtoi(c) - 2;*/
//
//	/*int n = -1234;
//	char str[1000]{};
//	myToString(n, str);
//	std::cout << str;*/
//
//	/*char text[] = "meri ima agunce";
//	char word[] = " ima";
//	std::cout << searchInText(text, word);*/
//
//	char text[] = "this is the best";
//	char where[] = "best";
//	char what[] = "worst";
//	char result[1000]{};
//	myReplace(text, where, what, result);
//	std::cout << result;
//
//	return 0;
//}
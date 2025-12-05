//#include <iostream>
//
//int charToInt(char c)
//{
//	if (c >= '0' && c <= '9')
//	{
//		return c - '0';
//	}
//	else if (c >= 'A' && c <= 'F')
//	{
//		return 10 + c - 'A';
//	}
//
//	return -1;
//}
//
//int charKBaseNum(const char kbaseNum[], int size, int base)
//{
//	int result = 0;
//	int multiplier = 1;
//	for (int i = size - 1; i >= 0; i--)
//	{
//		int currentNum = charToInt(kbaseNum[i]);
//		result += currentNum * multiplier;
//		multiplier *= base;
//	}
//	return result;
//}
//
//char intToChar(int num) {
//	if (num>=0&&num<=9)
//	{
//		return '0' + num;
//	}
//	else if (num >= 10 && num <= 15) {
//		return 'A' + num - 10;
//	}
//}
//
//void swap(char& a, char& b) {
//	a += b;
//	b = a - b;
//	a -= b;
//}
//
//void reverse(char arr[], int size)
//{
//	for (int i = 0; i <= size/2; i++)
//	{
//		swap(arr[i], arr[size - i - 1]);
//	}
//}
//
//void decimalToKBase(int decNum, char res[], int& size, int k)
//{
//	if (decNum == 0)
//	{
//		res[0] = '0';
//		size = 1;
//		return;
//	}
//	size = 0;
//	while (decNum != 0)
//	{
//		char currNum = intToChar(decNum % k);
//		res[size++] = currNum;
//		decNum /= k;
//	}
//	reverse(res, size);
//}
//
//
//
//int main() {
//	//0
//	/*char c[] = { '6', 'B', '6' };
//	std::cout << charKBaseNum(c, 3, 16)<<std::endl;*/
//	//0
//	/*char num[20];
//	int size = 0;
//	decimalToKBase(45, num, size, 2);
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << num[i];
//	}*/
//
//	return 0;
//}
//#include <iostream>
//
//void print(const int c[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << c[i];
//	}
//}
//
////1
//void decimalTo32Bit(int decNum, int c[], int& size)
//{
//	const int base = 2;
//	size = 32;
//	for (int i = size - 1; i >= 0; i--)
//	{
//		c[i] = decNum % 2;
//		decNum /= 2;
//		if (decNum == 0)
//			break;
//	}
//	print(c, size);
//}
//
//int main() {
//	//1
//	int size = 32;
//	int c[32] = { 0 };
//	decimalTo32Bit(2, c, size);
//
//	//2
//
//	return 0;
//}
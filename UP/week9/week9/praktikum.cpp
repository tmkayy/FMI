#include <iostream>

const int SIZE32 = 32;

bool isBitUp(uint8_t num, int index)
{
	uint8_t mask = 1;
	mask = mask << index;
	return num & mask;
}

uint8_t bitUp(uint8_t num, int index)
{
	uint8_t mask = 1 << index;
	return num | mask;
}

uint8_t bitDown(uint8_t num, int index)
{
	uint8_t mask = 1 << index;
	mask = ~mask;
	return num & mask;
}

//2
uint8_t toggleBit(uint8_t num, int index)
{
	uint8_t mask = 1 << index;
	return num ^ mask;
}

//1
void convertTo32(uint32_t num)
{
	for (int i = 31; i >= 0; i--)
	{
		std::cout << isBitUp(num, i);
	}
}

//3
uint32_t rightmostElements(uint32_t num, int index)
{
	uint32_t mask = 0;
	for (size_t i = 0; i < index; i++)
	{
		uint32_t temp = 1 << i;
		mask = mask | temp;
	}
	return num & mask;
}

//4
uint32_t getLeadingZerosCount(uint32_t num) {
	int count = 0;
	uint32_t mask = 1 << 31;
	for (size_t i = 0; i < 32; i++)
	{
		uint32_t temp = num & mask;
		mask = mask >> 1;
		if (temp == 0)
			count++;
		else
			break;
	}
	return count;
}

//5
bool isPermutation(uint32_t a, uint32_t b) {
	int counta0 = 0;
	int counta1 = 0;
	int countb0 = 0;
	int countb1 = 0;
	for (int i = 31; i >= 0; i--)
	{
		if (isBitUp(a, i))
			counta1++;
		else
			counta0++;
		if (isBitUp(b, i))
			countb1++;
		else
			countb0++;
	}
	return counta1 == countb1 && countb0 == counta0;
}

//6
uint32_t takeStuff(int x, int count, int index)
{
	return (x << count - 1) >> index;
}

//7
void Exam(int x) {
	for (size_t i = 0; i < 7; i++)
	{
		if (isBitUp(x, i))
		{
			switch (i)
			{
			case 0: std::cout << "monday "; break;
			case 1: std::cout << "tuesday "; break;
			case 2: std::cout << "wednesday "; break;
			case 3: std::cout << "thursday "; break;
			case 4: std::cout << "friday "; break;
			case 5: std::cout << "saturday "; break;
			case 6: std::cout << "sunday"; break;
			}
		}
	}
}

//8
void swap(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

//9
bool isPalindrome(uint32_t x)
{
	int leading0count = 0;
	for (int i = 0; i <= 32; i++)
	{
		x = x << 1;
		if (!isBitUp(x, 31))
		{
			leading0count++;
		}
		else
		{
			break;
		}
	}
	int numsCount = 32 - leading0count;
	for (int i = 0; i < numsCount / 2; i++)
	{
		if (isBitUp(x, 32 - i - 1) != isBitUp(x, 32 - leading0count - 1))
		{
			return false;
		}
	}return true;
}

//10


int main() {
	std::cout << isPalindrome(1);
	return 0;
}
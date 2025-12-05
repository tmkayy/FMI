#include <iostream>

int myLen(char* c) {
	int count = 0;
	while (*(c + count))
		count++;
	return count;
}

void print(char* const c) {
	int pos = 0;
	while (*(c + pos))
	{
		std::cout << *(c + pos);
		pos++;
	}
}

void swap(char& a, char& b)
{
	a += b;
	b = a - b;
	a -= b;
}

void reverse(char* c) {
	int len = myLen(c); int end = len / 2;
	for (size_t i = 0; i < end; i++)
	{
		swap(c[i], c[len - i - 1]);
	}
}

char int2char(int n) {
	if (n >= 10 && n <= 15)
		return 'A' + n - 10;
	else
		return n + '0';
}

int char2int(char c) {
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	else
		return c - '0';
}

void to2bit(int n, char* num)
{
	for (size_t i = 0; i < 32; i++)
	{
		num[i] = int2char(n % 2);
		n /= 2;
	}
	num[32] = '\0';
	reverse(num);
}

int to10(char* c, int k) {
	int end = myLen(c);
	int pow = 1;
	int result = 0;
	for (int i = end - 1; i >= 0; i--)
	{
		result += char2int(c[i]) * pow;
		pow *= k;
	}
	return result;
}

void toKbase(int n, char* c, int k) {
	int i = 0;
	while (n)
	{
		c[i] = int2char(n % k);
		n /= k;
		i++;
	}
	c[i] = '\0';
	reverse(c);
}



int main() {
	char c[32]{};
	toKbase(3456, c, 14);
	int num = to10(c, 14);
	toKbase(num, c, 16);
	print(c);
}
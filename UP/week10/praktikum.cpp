#include <iostream>

void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

int myStrLen(const char* const str) {
	int counter = 0;
	if (!str)
		return counter;
	while (*(str + counter) != '\0')
	{
		counter++;
	}
	return counter;
}

void print(char* str) {
	if (!str)
		return;
	for (int i = 0; ; i++)
	{
		if (str[i] == '\0')
			return;
		std::cout << str[i];
	}
}

void reverseString(char* str)
{
	if (!str)
		return;
	char* l = str;
	char* r = str;

	while (*r != '\0')
	{
		r++;
	}
	r--;
	while (l <= r)
	{
		swap(*l, *r);
		l++; r--;
	}
}
void printCounter(const int* counter, int size = 26)
{
	if (!counter)
		return;
	for (int i = 0; i < size; i++)
	{
		std::cout << (char)(i + 'a') << " = " << counter[i] << std::endl;
	}
}


void countSmallLetters(const char* str) {
	if (!str)
		return;
	int counter[26]{};
	while (*str != '\0')
	{
		char curr = *str;
		if (curr >= 'a' && curr <= 'z')
		{
			int index = curr - 'a';
			counter[index]++;
		}
		str++;
	}
	printCounter(counter);
}

//1
bool charInStr(const char* str, char c) {
	if (!str)
		return false;
	while (*str != '\0')
	{
		if (*str == c)
			return true;
		str++;
	}
	return false;
}

//2
void flip(char* str) {
	if (!str)
		return;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= ('a' - 'A');
		}
		else if (*str >= 'A' && *str <= 'Z')
		{
			*str += ('a' - 'A');
		}
		str++;
	}
}

//3
int char2num(char c)
{
	return c - '0';
}

void printNums(int* nums)
{
	for (int i = 0; i < 10; i++)
	{
		if (nums[i] != 0)
			std::cout << i << 'x' << nums[i] << ' ';
	}
}

void numOccurances(const char* str)
{
	int result = 0;
	int nums[10]{};
	int end = myStrLen(str);
	for (size_t i = 0; i < end; i++)
	{
		nums[char2num(str[i])]++;
	}
	printNums(nums);
}

//4
int sumOfChars(const char* str)
{
	if (!str)
		return -1;
	int sum = 0;
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			return -1;
		}
		sum += *str;
		str++;
	}
	return sum;
}

//5
void literally1984(char* str) {
	if (!str)
		return;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			*str = '*';
		}
		std::cout << *str;
		str++;
	}
}

//6

void printDiff(const int* arr1, const int* arr2, char* result)
{
	for (int i = 0; i < 128; i++)
	{
		if (arr1[i] != arr2[i])
		{
			std::cout << (char)i;
			*result = (char)i;
			result++;
		}
	}
	*result = '\0';
}

void getDifference(const char* string1, const char* string2, char* result)
{
	if (!string1 || !string2)
	{
		return;
	}
	int count1[128]{};
	int count2[128]{};
	while (*string1 != '\0')
	{
		count1[*string1]++;
		string1++;
	}
	while (*string2 != '\0')
	{
		count2[*string2]++;
		string2++;
	}
	printDiff(count1, count2, result);
}

//7
bool checkstr(const char* str)
{
	if (!str)
		return 0;
	int count = 0;
	while (*str != '\0')
	{
		if (count % 2 == 0 && (*str >= 'a' && *str <= 'z'))
		{
			count++;
		}
		else if (count % 2 == 1 && (*str >= 'A' && *str <= 'Z'))
		{
			count++;
		}
		else
		{
			return 0;
		}
		str++;
	}
	return 1;
}

//8
void myInsert(char* str, char c, int index) {
	int posOf0 = myStrLen(str);
	for (int i = posOf0 + 1; i >= 0; i--)
	{
		if (i == index)
		{
			str[i] = c;
			break;
		}
		str[i] = str[i - 1];
	}
}

//9
void removeSymbol(char* str, char c) {
	int end = myStrLen(str);
	for (size_t i = 0; i < end; i++)
	{
		if (str[i] == c)
		{
			for (size_t j = i; j < end; j++)
			{
				str[j] = str[j + 1];
			}
			end--;
			i--;
		}
	}
}

//10
bool isSubstring(const char* s1, const char* s2) {
	int end1 = myStrLen(s1);
	int end2 = myStrLen(s2);
	if (end2 == 0)
		return 1;
	for (size_t i = 0; i < end1; i++)
	{
		if (s1[i] == s2[0])
		{
			bool found = true;
			int counter2 = 0;
			for (size_t j = i; j < end2; j++)
			{
				if (s1[j] != s2[counter2])
				{
					found = false;
					break;
				}counter2++;
			}
			if (found)
			{
				return true;
			}
		}
	}
	return false;
}

//11
bool isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

unsigned int getWordsCount(const char* words) {
	int end = myStrLen(words);
	int count = 0;
	for (size_t i = 0; i < end; i++)
	{
		if (isLetter(words[i]))
		{
			count++;
			while (isLetter(words[i]) && i != end)
			{
				i++;
			}
		}
	}
	return count;
}

int main() {
	//reverse
	/*char str[] = "zdr";
	std::cout << str << '\n';
	reverseString(str);
	std::cout << str;*/

	//inString
	/*char str[] = "baba";
	countSmallLetters(str);*/

	//1
	/*std::cout << charInStr("haha", 'b');*/

	//2
	/*char c[30] = "sTriNgS$$$s";
	flip(c);*/

	//3
	char str[] = "4231148";
	numOccurances(str);

	//4
	/*char c[10] = "123";
	std::cout << sumOfChars(c);*/

	//5
	/*char c[20] = "a#s50d4Q8=w";
	literally1984(c);*/

	//6
	/*char c1[] = "abcde";
	char c2[] = "acdef";
	char c3[128]{};
	getDifference(c1, c2, c3);*/

	//7
	/*char str[] = "aBcDe";
	std::cout << checkstr(str);*/

	//10
	/*char str[50] = "Hello, y friend!";
	char str2[50] = " y ";
	std::cout << isSubstring(str, str2);*/

	//11
	/*char str[] = "       Helloooo        World            ?????!";
	std::cout << getWordsCount(str);*/

	return 0;
}
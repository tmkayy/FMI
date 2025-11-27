//#include <iostream>
//
//const char CHAR_DIFFERENCE = 'a' - 'A';
//const char CHAR_TO_INT_TRANSFORM = '0';
//
//int strLen(const char* const str)
//{
//	int count = 0;
//	while (*(str + count))
//	{
//		count++;
//	}
//	return count;
//}
//
//void toLower(char* const str) {
//	size_t iter = 0;
//	if (!str)
//		return;
//	while (*str)
//	{
//		if (*str >= 'A' && *str <= 'Z')
//			*(str + iter) += CHAR_DIFFERENCE;
//		iter++;
//	}
//}
//
//void toUpper(char* const str) {
//	size_t iter = 0;
//	if (!str)
//		return;
//	while (*str)
//	{
//		if (*str >= 'a' && *str <= 'z')
//			*(str + iter) -= CHAR_DIFFERENCE;
//		iter++;
//	}
//}
//
//int strCmp(const char* str1, const char* str2) {
//	if (!str1 || !str2)
//		return 0;
//	while (*str1 && *str2)
//	{
//		if (*str1 != *str2)
//		{
//			return *str1 - *str2;
//		}str1++; str2++;
//	}
//	return *str1 - *str2;
//}
//
//void strCopy(const char* src, char* d)
//{
//	while (*src)
//	{
//		*d = *src;
//		d++;
//		src++;
//	}
//	*d = '\0';
//}
//
//void strCat(char* str1, const char* str2)
//{
//	if (!str1 || !str2)
//		return;
//	while (*str1)
//	{
//		str1++;
//	}
//	while (*str2)
//	{
//		*str1 = *str2;
//		str1++; str2++;
//	}
//	*str1 = '\0';
//}
//
//bool contains(const char* text, const char* word)
//{
//	if (!text || !word)
//		return false;
//	if (*word == '\0')
//		return true;
//	while (*text)
//	{
//		if (*text == *word)
//		{
//			for (int i = 1; ; i++)
//			{
//				if (*(word + i) == '\0')
//					return true;
//				if (*(word + i) != *(text + i))
//					break;
//			}
//		}
//		text++;
//	}
//	return false;
//}
//
//bool replace(char* const text, const char* const word, const char* const replace)
//{
//	if (!text || !word || !replace)
//		return false;
//	size_t len = strLen(text);
//	size_t searchLen = strLen(word);
//	size_t replaceLen = strLen(replace);
//	size_t offset = searchLen - replaceLen;
//
//	for (size_t i = 0; i < len - searchLen; i++)
//	{
//		bool found = true;
//		for (size_t j = 0; j < searchLen; j++)
//		{
//			if (text[i + j] != word[j])
//			{
//				found = false;
//				break;
//			}
//		}
//		if (found)
//		{
//			if (offset > 0)
//			{
//				for (int k = len; k >= i + searchLen; k--)
//				{
//					text[k + offset] = text[k];
//				}
//			}
//			else if (offset < 0)
//			{
//				//fix
//				for (int k = len; k >= i + searchLen; k--)
//				{
//					text[k + offset] = text[k];
//				}
//			}
//
//			strCopy(replace, text + i);
//			len += offset;
//			i += replaceLen;
//		}
//	}
//}
//
//int strToNum(char* str)
//{
//	int result = 0;
//	bool neg = (*str == '-');
//	if (neg)
//		str++;
//	while (*str)
//	{
//		result = result * 10 + (*str - CHAR_TO_INT_TRANSFORM);
//		str++;
//	}
//	if (neg)
//		result *= -1;
//	return result;
//}
//
//void swap(char &a, char &b)
//{
//	char temp = a;
//	a = b;
//	b = temp;
//}
//
//void reverseArray(char* arr)
//{
//	size_t count = strLen(arr);
//	size_t end = count / 2;
//	for (size_t i = 0; i < end; i++)
//	{
//		swap(arr[i], arr[count - i - 1]);
//	}
//}
//
//int main() {
//	char num[] = "-12345";
//	std::cout << strToNum(num);
//}
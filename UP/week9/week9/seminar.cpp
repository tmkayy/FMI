//#include <iostream>
//
//void print(const char* str)
//{
//	while (*str)
//	{
//		std::cout << *str; str++;
//	}
//}
//
//unsigned myStrlen(const char* str)
//{
//	if (str)
//	{
//		unsigned count = 0;
//		while (*(str + count++) != '\0') {}
//		return count;
//	}
//	return 0;
//}
//
//void myStrcpy(const char* first, char* second)
//{
//	if (first && second)
//	{
//		while (*first)
//		{
//			*second = *first;
//			first++; second++;
//		}
//		*second = '\0';
//	}
//	else
//		*second = '\0';
//}
//
//void MyStrcat(char* lhs, const char* rhs) {
//	unsigned lhsSize = myStrlen(lhs);
//	lhs += lhsSize;
//	myStrcpy(rhs, lhs);
//}
//
//int MyStrcmp(const char* lhs, const char* rhs)
//{
//	while (*lhs == *rhs && *lhs)
//	{
//		lhs++;
//		rhs++;
//	}
//	return *lhs - *rhs;
//}
//
//int main() {
//	char lol[10] = "abc";
//	char lol2[] = "dbf";
//	MyStrcat(lol, lol2);
//	print(lol);
//	return 0;
//}
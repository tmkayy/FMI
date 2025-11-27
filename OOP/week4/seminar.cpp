//#include <iostream>
//
//namespace consts {
//	const int MAX_NAME_LEN = 20;
//	const int MIN_NAME_LEN = 2;
//	const int MIN_AGE = 0;
//	const int MAX_AGE = 115;
//}
//
//namespace charUtils {
//	bool isUpper(char c) {
//		return c >= 'A' && c <= 'Z';
//	}
//
//	bool isLower(char c) {
//		return c >= 'a' && c <= 'z';
//	}
//
//	bool isStringLowerCase(const char* str) {
//		if (!str)
//			return false;
//		while (*str)
//		{
//			if (isUpper)
//				return false;
//			str++;
//		}
//		return false;
//	}
//}
//
////struct Point {
////	int x;
////	int y;
////
////	bool isInFirstQuadrant() {
////		return x >= 0 && y >= 0;
////	}
////};
//
//class Person {
//	char name[consts::MAX_NAME_LEN];
//	int age;
//
//	bool isNameValid(const char* name) const{
//		if (!name)
//			return false;
//		size_t nameSize = strlen(name);
//		if (nameSize <= consts::MIN_NAME_LEN || nameSize >= consts::MAX_NAME_LEN)
//			return false;
//		if (!charUtils::isUpper(*name))
//			return false;
//		if (!charUtils::isStringLowerCase(name + 1))
//			return false;
//
//		return true;
//	}
//
//	bool isValidAge(int age) const {
//		return age >= consts::MIN_AGE && age <= consts::MAX_AGE;
//	}
//
//public:
//	Person(const char* name, int age) {
//		SetName(name);
//	}
//
//	Person() {}; 
//
//	void SetName(const char* name) {
//		if (isNameValid(name))
//			strcpy(this->name, name);
//		else
//			strcpy(this->name, "Unknown");
//
//	}
//
//	void SetAge(int age) {
//		if (isValidAge(age))
//			this->age = age;
//		else
//			this->age = 0;
//	}
//
//	int getAge() const {
//		return age;
//	}
//
//	const char* getName() const {
//		return name;
//	}
//};
//
//int main() {
//	/*Point p = { 1,2 };
//	std::cout << p.isInFirstQuadrant();*/
//
//	return 0;
//}
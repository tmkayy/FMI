//#include <iostream>
//#include <fstream>
//
//namespace constants {
//	const size_t MAX_SIZE = 1024;
//}
//
//size_t fileSize(std::ifstream& ifs) {
//	size_t currPos = ifs.tellg();
//	ifs.seekg(0, std::ios::end);
//	size_t lastPos = ifs.tellg();
//	ifs.seekg(currPos);
//
//	return lastPos;
//}
//
//size_t countOfLines(const char* fileName) {
//	if (!fileName)
//		return 0;
//
//	std::ifstream file(fileName);
//
//	if (!file.is_open())
//		return 0;
//
//	size_t counter = 0;
//	char buffer[constants::MAX_SIZE];
//	do
//	{
//		file.getline(buffer, constants::MAX_SIZE);
//		counter++;
//	} while (file.eof());
//
//	file.close();
//	return counter;
//}
//
//void printCode() {
//	std::ifstream file("sem1.cpp");
//	if (!file.is_open())
//		return;
//	char buffer[constants::MAX_SIZE];
//	while (!file.eof())
//	{
//		file.getline(buffer, constants::MAX_SIZE);
//		std::cout << buffer << std::endl;
//	}
//
//	file.close();
//}
//
//int main() {
//	std::ifstream file("file.txt");
//	if (!file.is_open())
//	{
//		std::cout << "ERROR";
//		return -1;
//	}
//
//	std::cout << fileSize(file);
//
//	file.close();
//
//	return 0;
//}
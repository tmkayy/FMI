//#include <iostream>
//#include <fstream>
//#pragma warning (disable: 4996)
//
//namespace constants {
//	const int MAX_NAME_LEN = 50;
//	const int FN_LEN = 10;
//	const int MAX_STUDENT_COUNT = 20;
//}
//namespace st {
//	enum class Major {
//		SE, CS, INF
//	};
//
//	struct Student {
//		char name[constants::MAX_NAME_LEN + 1];
//		char fn[constants::FN_LEN + 1];
//		Major major;
//	};
//
//	struct StudentDatabase {
//		size_t studentCount = 0;
//		Student students[constants::MAX_STUDENT_COUNT];
//	};
//
//	void serializeStudent(std::ofstream& ofs, const Student& s) {
//		ofs << s.name << std::endl << s.fn << std::endl << (int)s.major << std::endl;
//	}
//
//	void serializeStudentDatabase(const StudentDatabase& sd, std::ofstream& ofs) {
//		ofs << sd.studentCount << std::endl;
//		for (size_t i = 0; i < sd.studentCount; i++)
//		{
//			serializeStudent(ofs, sd.students[i]);
//		}
//	}
//
//	void deserializeStudent(std::ifstream& ifs, Student& s) {
//		ifs.ignore();
//		ifs.getline(s.name, constants::MAX_NAME_LEN);
//		ifs.getline(s.fn, constants::FN_LEN);
//		int num = 0;
//		ifs >> num;
//		s.major = (Major)num;
//	}
//
//	void deserializeStudentDatabase(std::ifstream& ifs, StudentDatabase& sd) {
//		ifs >> sd.studentCount;
//		for (size_t i = 0; i < sd.studentCount; i++)
//		{
//			deserializeStudent(ifs, sd.students[i]);
//		}
//	}
//}
//
//size_t getFileSize(std::ifstream& ifs) {
//	size_t currPos = ifs.tellg();
//	ifs.seekg(0, std::ios::end);
//	size_t fileSize = ifs.tellg();
//	ifs.seekg(currPos);
//	return fileSize;
//}
//
//struct Student {
//	char* name;
//	double grade;
//};
//
//int main() {
//	//example
//	/*std::ofstream ofs("ex.bin", std::ios::binary);
//	if (!ofs.is_open())
//	{
//		std::cout << "error"; return -1;
//	}
//	int a = 16;
//	ofs.write((const char*)&a, sizeof(a));
//	ofs.close();
//
//	std::ifstream ifs("ex.bin", std::ios::binary);
//	if (!ifs.is_open())
//	{
//		std::cout << "error"; return -1;
//	}
//	int a;
//	ifs.read((char*)&a, sizeof(a));
//	std::cout << a;
//	ifs.close();*/
//
//	//array write
//	/*std::ofstream ofs("ex.bin", std::ios::binary);
//	if (!ofs.is_open())
//	{
//		std::cout << "error"; return -1;
//	}
//	int arr[10] = { 1,2,3,4,5 };
//	size_t size = 5;
//
//	ofs.write((const char*)arr, size * sizeof(int));
//	ofs.close();*/
//
//	//array read
//	/*std::ifstream ifs("ex.bin", std::ios::binary);
//	if (!ifs.is_open())
//	{
//		std::cout << "error"; return -1;
//	}
//	size_t arrSize = getFileSize(ifs) / sizeof(int);
//	int* arr = new int [arrSize] {};
//	ifs.read((char*)arr, arrSize * sizeof(int));
//
//	for (size_t i = 0; i < arrSize; i++)
//	{
//		std::cout << arr[i] << ' ';
//	}
//	delete[] arr;
//	ifs.close();*/
//
//	//struct
//	/*std::ofstream ofs("ex.bin", std::ios::binary);
//	if (!ofs.is_open())
//	{
//		std::cout << "error"; return -1;
//	}
//
//	Student st = { "ivo", 5.6 };
//	ofs.write((const char*)&st, sizeof(st));
//	ofs.close();
//
//	std::ifstream ifs("ex.bin", std::ios::binary);
//	if (!ifs.is_open())
//	{
//		std::cout << "error"; return -1;
//	}
//	Student st2;
//	ifs.read((char*)&st2, sizeof(st2));
//	std::cout << st2.name << ' ' << st2.grade;
//	ifs.close();*/
//
//	/*std::ofstream ofs("ex.bin", std::ios::binary);
//	if (!ofs.is_open())
//	{
//		std::cout << "error"; return -1;
//	}
//	Student st;
//	const int nameLen = 12;
//	st.name = new char[nameLen];
//	strcpy(st.name, "Ivan Ivanov");
//	st.name[nameLen - 1] = '\0';
//	st.grade = 4.4;
//	ofs.write((const char*)&nameLen, sizeof(int));
//	ofs.write((const char*)st.name, nameLen);
//	ofs.write((const char*)&st.grade, sizeof(double));
//	delete[] st.name;
//	ofs.close();*/
//
//	std::ifstream ifs("ex.bin", std::ios::binary);
//	if (!ifs.is_open())
//	{
//		std::cout << "error"; return -1;
//	}
//	int nameLen;
//	ifs.read((char*)&nameLen, sizeof(int));
//	Student st;
//	st.name = new char[nameLen];
//	ifs.read(st.name, nameLen);
//	ifs.read((char*)&st.grade, sizeof(double));
//	std::cout << st.name << ' ' << st.grade;
//	delete[] st.name;
//	ifs.close();
//
//	return 0;
//}
#include <iostream>
#include <fstream>

namespace consts {
	const int MAX_LENGTH = 50;
	const int MAX_FN_LENGTH = 10;
}

namespace Markdown {
	struct Student {
		char Name[consts::MAX_LENGTH + 1];
		char Fn[consts::MAX_FN_LENGTH + 1];
		double avg = 0;
	};

	struct Table {
		Student students[consts::MAX_LENGTH];
		int size = 0;
	};

	void PrintStudentInfo(const char* f, const Table& t) {
		if (!f)
			return;
		for (size_t i = 0; i < t.size; i++)
		{
			if (!strcmp(f, t.students[i].Fn))
			{
				std::cout << "Name: " << t.students[i].Name <<
					", Faculty Number: " << t.students[i].Fn <<
					", Grades: " << t.students[i].avg;
			}
		}
	}

	void UpdateAvg(const char* f, double avg, Table& t) {
		if (!f || avg > 6 || avg < 2)
			return;
		for (size_t i = 0; i < t.size; i++)
		{
			if (!strcmp(f, t.students[i].Fn))
				t.students[i].avg = avg;
		}
	}

	void LoadTable(const char* f, Table& t) {
		if (!f)
			return;
		std::ifstream ifs(f);
		if (!ifs.is_open())
			return;
		while (!ifs.eof())
		{
			ifs.ignore();
		}

	}

	void SaveTable(const char* file, const Table& t) {
		if (!file)
			return;
		std::ofstream ofs(file);
		if (!ofs.is_open())
			return;
		ofs << "| Name | Faculty Number | Grade |" << std::endl
			<< "|------|----------------|-------|" << std::endl;
		for (size_t i = 0; i < t.size; i++)
		{
			ofs << "| " << t.students[i].Name << " | " << t.students[i].Fn << " | " << t.students[i].avg << " | " << std::endl;
		}
		ofs.close();
	}
}

int main() {
	return 0;
}
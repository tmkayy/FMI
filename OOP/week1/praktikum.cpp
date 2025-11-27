#include <iostream>
#include <cstring>
#pragma warning (disable: 4996)

namespace consts {
	const int nameMaxLen = 32;
	const int maxStudents = 50;
}

namespace cnum {

	struct ComplexNumber {
		double re;
		double im;
	};

	ComplexNumber init(double re, double im) {
		ComplexNumber c;
		c.re = re;
		c.im = im;
		return c;
	}

	void print(const ComplexNumber& complex) {
		std::cout << complex.re << ' ' << complex.im << 'i' << std::endl;
	}

	ComplexNumber conjugate(const ComplexNumber& complex) {
		ComplexNumber c;
		c.re = complex.re;
		c.im = complex.im * -1;
		return c;
	}

	ComplexNumber add(const ComplexNumber& lhs, const ComplexNumber& rhs) {
		ComplexNumber c;
		c.re = lhs.re + rhs.re;
		c.im = lhs.im + lhs.im;
		return c;
	}

	ComplexNumber subtract(const ComplexNumber& lhs, const ComplexNumber& rhs) {
		ComplexNumber c;
		c.re = lhs.re - rhs.re;
		c.im = lhs.im - lhs.im;
		return c;
	}

	ComplexNumber multiply(const ComplexNumber& lhs, const ComplexNumber& rhs) {
		ComplexNumber c;
		c.re = lhs.re * rhs.re - lhs.im * rhs.im;
		c.im = lhs.re * rhs.im + lhs.im + rhs.re;
		return c;
	}
	ComplexNumber divide(const ComplexNumber& lhs, const ComplexNumber& rhs) {
		ComplexNumber c;
		double upRe = lhs.re * rhs.re + lhs.im * rhs.im;
		double upIm = lhs.re * rhs.re - lhs.re * rhs.im;
		double bottom = rhs.re * rhs.re + rhs.im * rhs.im;
		if (!bottom)
		{
			c.re = upRe / bottom;
			c.im = upIm / bottom;
		}
		else
		{
			c.re = 0;
			c.im = 0;
		}

		return c;
	}
}

namespace susi {
	enum class Specialty {
		KN, SI, PM, MI
	};

	struct Student {
		double avgGrade = 0;
		int fn;
		Specialty specialty;
		char name[consts::nameMaxLen + 1];
	};

	struct Course {
		Student students[consts::maxStudents];
		int studentCount;
	};

	Student createStudent(char* name, int fn, Specialty specialty)
	{
		Student s;
		if (!name)
			return s;
		s.fn = fn;
		strcpy(s.name, name);
		s.specialty = specialty;
	}

	void printSpecialty(Specialty specialty) {
		switch (specialty)
		{
		case susi::Specialty::KN:
			std::cout << "KN";
			break;
		case susi::Specialty::SI:
			std::cout << "SI";
			break;
		case susi::Specialty::PM:
			std::cout << "PM";
			break;
		case susi::Specialty::MI:
			std::cout << "MI";
			break;
		}
	}

	void printStudent(const Student student) {
		std::cout << "Name: " << student.name << std::endl <<
			"FN: " << student.fn << std::endl <<
			"Average grade: " << student.avgGrade << std::endl <<
			"Specialty: "; printSpecialty(student.specialty);
		std::cout << std::endl;
	}

	void printStudentsInCourse(const Course c) {
		for (size_t i = 0; i < c.studentCount; i++)
		{
			printStudent(c.students[i]);
			std::cout << "----------------------------------------" << std::endl;
		}
	}

	void addStudent(Course c, const Student s) {
		if (c.studentCount == consts::maxStudents)
			return;
		strcpy(c.students[c.studentCount].name, s.name);
		c.students[c.studentCount].fn = s.fn;
		c.students[c.studentCount].avgGrade = s.avgGrade;
		c.students[c.studentCount].specialty = s.specialty;
	}

	void removeStudentByFN(Course& c, int fn) {
		int remove = false;
		for (size_t i = 0; i < c.studentCount; i++)
		{
			if (c.students[i].fn == fn) {
				remove == true;
			}
			if (remove) {
				c.students[i] = c.students[i + 1];
			}
		}
		if (c.students[c.studentCount - 1].fn == fn)
			remove = false;
		if (remove)
			c.studentCount--;
		else
			std::cout << "invalid fn";
	}

	void orderByGrade(Course& c) {
		for (size_t i = 0; i < c.studentCount; i++)
		{
			bool swapped = false;
			for (size_t j = 0; j < c.studentCount - i - 1; j++)
			{
				if (c.students[j].avgGrade >= c.students[j + 1].avgGrade)
				{
					std::swap(c.students[j], c.students[j + 1]);
					swapped = true;
				}
				else if (c.students[j].avgGrade == c.students[j + 1].avgGrade) {
					if (strcmp(c.students[j].name, c.students[j + 1].name) > 0)
					{
						std::swap(c.students[j], c.students[j + 1]);
						swapped = true;
					}
				}
			}
			if (!swapped)
				break;
		}
	}

	void filterStudentsBy(const Course c, bool (*f)(Student s)) {
		for (size_t i = 0; i < c.studentCount; i++)
		{
			if (f(c.students[i]))
				printStudent(c.students[i]);
		}
	}
}

namespace bar {
	enum class Drinks {
		whiskey = 2, vodka = 4, cola = 8, fanta = 16, water = 32, wine = 64, rum = 128, juice = 256
	};

	struct Client {
		char name[consts::nameMaxLen];
		uint8_t drinks;
	};

	bool checkPreference(const Client c, uint8_t drink) {
		return c.drinks & drink;
	}

	void addPreference(Client& c, uint8_t drink) {
		c.drinks =  c.drinks | drink;
	}

	void removePreference(Client& c, uint8_t drink) {
		c.drinks = c.drinks & ~drink;
	}

	void printDrink(uint8_t drink){
		switch (drink)
		{
		case (uint8_t)(Drinks::whiskey):
			std::cout << "whiskey ";
			break;
		case (uint8_t)(Drinks::vodka):
			std::cout << "vodka ";
			break;
		case (uint8_t)(Drinks::cola):
			std::cout << "cola ";
			break;
		case (uint8_t)(Drinks::fanta):
			std::cout << "fanta ";
			break;
		case (uint8_t)(Drinks::water):
			std::cout << "water ";
			break;
		case (uint8_t)(Drinks::wine):
			std::cout << "wine ";
			break;
		case (uint8_t)(Drinks::rum):
			std::cout << "rum ";
			break;
		case (uint8_t)(Drinks::juice):
			std::cout << "juice ";
		}
	}

	void printPreferences(const Client c) {
		std::cout << "client likes: ";
		for (size_t i = 0; i < 8; i++)
		{
			uint8_t mask = 1 << i;
			if (checkPreference(c, mask))
			{
				printDrink(mask);
			}
		}
		std::cout << std::endl;
	}
}

int main() {

	return 0;
}
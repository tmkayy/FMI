#include <iostream>
using namespace std;
class Base {
	int a = 0;
public:
	Base() {
		std::cout << "Base()" << std::endl;
	}
	virtual void f() const {
		std::cout << "Base::f()" << std::endl;
	}
	virtual ~Base() {
		std::cout << "~Base()";
	}

};

class Der1 : public Base {
	int b = 0;
public:
	Der1() {
		std::cout << "Der1()" << std::endl;
	}
	void f() const override {
		Base::f();
		std::cout << "Der1::f()" << std::endl;
	}

	~Der1() override {
		std::cout << "~Der1()" << std::endl;
	}
};

class Der2 : public Der1 {
	int c = 0;
public:
	Der2() {
		std::cout << "Der2()" << std::endl;
	}

	~Der2() override {
		std::cout << "~Der2()" << std::endl;
	}

};

int main() {
	Base* ptr = new Der2();
	ptr->f();
	delete ptr;
}
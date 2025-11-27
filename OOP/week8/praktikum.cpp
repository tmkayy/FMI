#include <iostream>

class A {
	static size_t counter;
	size_t id = 0;

public:
	A() {
		id = counter;
		counter++;
	}
};
int main() {

}
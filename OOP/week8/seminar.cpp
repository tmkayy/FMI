//#include <iostream>
//
//void throwSomething() {
//	int choice;
//	std::cout << "choose exception:";
//
//	std::cin >> choice;
//	switch (choice)
//	{
//	case 1:
//		throw '!';
//		break;
//	case 2:
//		throw 3;
//		break;
//	case 3:
//		throw 3.14;
//		break;
//	case 4:
//		throw std::runtime_error("runtime errror");
//		break;
//	case 5:
//		throw std::out_of_range("out of range");
//		break;
//	default:
//		throw std::logic_error("logic error");
//	}
//}
//
//void caller() {
//	try {
//		throwSomething();
//	}
//	catch (int ex) {
//		std::cout << "caught int error";
//	}
//	catch (double ex) {
//		std::cout << "caught double error";
//	}
//}
//
//
//
//int main() {
//	/*try {
//		caller();
//	}
//	catch (const std::out_of_range& ex) {
//		std::cout << "caught out of range"<<ex.what();
//	}
//	catch (const std::exception& ex) {
//		std::cout << "caught general" << ex.what();
//	}
//	catch (...) {
//		std::cout << "caught ...";
//	}*/
//}
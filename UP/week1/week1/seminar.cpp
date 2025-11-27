//#include <iostream>
//int main() {
//	//1
//	//int n1, n2, n3, temp;
//	//std::cin >> n1 >> n2 >> n3;
//	//if (n1 > n2) // 2, 3
//	//{
//	//	n1 += n2; //n1 = 5, n2 = 3
//	//	n2 = n1 - n2; //n2 = 2, n1 = 5
//	//	n1 -= n2; //n1 = 3, n2 = 2
//	//}
//	//if (n1 > n3)
//	//{
//	//	temp = n1;
//	//	n1 = n3;
//	//	n3 = temp;
//	//}
//	//if (n2 > n3)
//	//{
//	//	temp = n2;
//	//	n2 = n3;
//	//	n3 = temp;
//	//}
//	//std::cout << n1 << ' ' << n2 << ' ' << n3;
//
//	//2
//	//char t;
//	//const double PI = 3.141;
//	//std::cin >> t;
//	//switch (t)
//	//{
//	//case 's':
//	//	int side;
//	//	std::cin >> side;
//	//	std::cout << side * side;
//	//	break;
//	//case 'r':
//	//	int a, b;
//	//	std::cin >> a >> b;
//	//	std::cout << a * b;
//	//	break;
//	//case 'c':
//	//	int r; std::cin >> r;
//	//	std::cout << PI * r * r;
//	//	break;
//	//case 't':
//	//	double ha;
//	//	std::cin >> a >> ha;
//	//	std::cout << a * ha / 2;
//	//	break;
//	//}
//
//	//3
//	/*int hour, min;
//	std::cin >> hour >> min;
//	min += 15;
//	if (min>=60)
//	{
//		hour += 1;
//		min %= 60;
//	}
//	hour %= 24;
//	if (hour < 10)
//	{
//		std::cout << 0;
//	}std::cout << hour << ':';
//	if (min<10)
//	{
//		std::cout << 0;
//	}std::cout << min;*/
//
//	//4
//	int n1, n2, n3, n4, n5;
//	std::cin >> n1 >> n2 >> n3 >> n4 >> n5;
//	if ((n2 <= n1 && n2 <= n3) || (n2 >= n1 && n2 >= n3))
//	{
//		if ((n3 <= n2 && n3 <= n4) || (n3 >= n2 && n3 >= n4))
//		{
//			if ((n4 <= n3 && n4 <= n5) || (n4 >= n3 && n4 >= n5))
//			{
//				std::cout << "yes";
//				return 0;
//			}
//		}
//	}std::cout << "no";
//
//	return 0;
//}
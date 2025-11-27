//#include <iostream>
//
//const int MAX_LENGTH = 100;
//
////eratosten
//void assignValue(bool arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//		arr[i] = 0;
//}
//
////eratosten
//void checkNotPrime(bool arr[], int num, int end)
//{
//	int res = num + num;
//	while (res<end)
//	{
//		arr[res] = true;
//		res += num;
//	}
//}
//
////eratosten
//void Eratosten(bool arr[], int n)
//{
//	for (int i = 2; i < n; i++)
//	{
//		if (!arr[i])
//		{
//			std::cout << i << ' ';
//			checkNotPrime(arr, i, n);
//		}
//	}
//}
//
//int main() {
//	//eratosten
//	/*bool arr[MAX_LENGTH];
//	int n;
//	std::cin >> n;
//	assignValue(arr, MAX_LENGTH);
//	Eratosten(arr, n);*/
//
//
//
//	return 0;
//}
//#include <iostream>
//
//const int SIZE = 10;
//
//void print(int mat[][SIZE], int rows, int cols) {
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			std::cout << mat[i][j] << ' ';
//		}
//		std::cout << std::endl;
//	}
//}
//
//void swamp(int& a, int& b) {
//	a += b;
//	b = a - b;
//	a -= b;
//}
//
//void inputArrayValues(int mat[][SIZE], int rows, int cols) {
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			std::cout << "matrix[" << i << "][" << j << "]: ";
//			std::cin >> mat[i][j];
//		}
//	}
//}
//
//void Transpose(int mat[][SIZE], int rows, int cols) {
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = i + 1; j < cols; j++)
//		{
//			swamp(mat[i][j], mat[j][i]);
//		}
//	}
//}
//
//void MultiplyMatrix(int matrix[][SIZE], int matrix2[][SIZE], int n, int m, int k)
//{
//	int resMatrix[SIZE][SIZE] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < k; j++)
//		{
//			for (int l = 0; l < m; l++)
//			{
//				resMatrix[i][j] += matrix[i][l] * matrix2[l][j];
//			}
//		}
//	}
//	print(resMatrix, n, k);
//}
//
//
//
//int main() {
//	//transpose
//	/*int mat[SIZE][SIZE] = {
//						{1,1,1,1},
//						{2,2,2,2},
//						{3,3,3,3},
//						{4,4,4,4} };
//	Transpose(mat, 4, 4);
//	print(mat, 4, 4);*/
//
//	//multiply
//	/*int matrix1[SIZE][SIZE];
//	int n, m;
//	std::cin >> n >> m;
//
//	inputArrayValues(matrix1, n, m);
//
//	int matrix2[SIZE][SIZE];
//	int k;
//	std::cin >> k;
//
//	inputArrayValues(matrix2, m, k);
//
//	print(matrix1, n, m);
//	std::cout << std::endl;
//	print(matrix1, m, k);
//	std::cout << std::endl;
//
//	MultiplyMatrix(matrix1, matrix2, n, m, k);*/
//
//
//	return 0;
//}
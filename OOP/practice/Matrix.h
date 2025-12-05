#pragma once
class Matrix
{
	unsigned int rows = 2;
	unsigned int cols = 2;
	int** mat = nullptr;

	void copyFrom(const Matrix& other);
	void free();
public:
	Matrix();
	Matrix(unsigned int rows, unsigned int cols);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator=(const Matrix& other);

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(const int n);

	bool operator==(const Matrix& other);
	bool operator!=(const Matrix& other);

	const int* operator[](unsigned int idx) const;
	int* operator[](unsigned int idx);
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, int n);
Matrix operator*(int n, const Matrix& lhs);
#include "Matrix.h"

void Matrix::copyFrom(const Matrix& other)
{
	this->rows = other.rows;
	this->cols = other.cols;
	this->mat = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		this->mat[i] = new int[cols];
		for (size_t j = 0; j < cols; j++)
		{
			this->mat[i][j] = other.mat[i][j];
		}
	}
}

void Matrix::free()
{
	for (size_t i = 0; i < this->rows; i++)
	{
		delete[] this->mat[i];
	}
	delete[] mat;
	this->rows = 0;
	this->cols = 0;
}

Matrix::Matrix()
{
	this->rows = 2;
	this->cols = 2;
	this->mat = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		this->mat[i] = new int[cols];
	}
}

Matrix::Matrix(unsigned int rows, unsigned int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->mat = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		this->mat[i] = new int[cols];
	}
}

Matrix::Matrix(const Matrix& other)
{
	copyFrom(other);
}

Matrix::~Matrix()
{
	free();
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	if (this->cols == other.cols && this->rows == other.rows) {
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				this->mat[i][j] += other.mat[i][j];
			}
		}
	}
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	Matrix result(lhs);
	result += rhs;
	return result;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	if (this->cols == other.cols && this->rows == other.rows) {
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				this->mat[i][j] -= other.mat[i][j];
			}
		}
	}
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	if (this->cols == other.rows) {
		Matrix result(this->rows, other.cols);
		for (size_t i = 0; i < this->rows; i++)
		{
			for (size_t j = 0; j < other.cols; j++)
			{
				for (size_t k = 0; k < this->cols; k++)
				{
					result.mat[i][j] += this->mat[i][k] * other.mat[k][j];
				}
			}
		}
		*this = result;
	}
	return *this;
}

Matrix& Matrix::operator*=(const int n)
{
	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->cols; j++)
		{
			mat[i][j] *= n;
		}
	}
}

bool Matrix::operator==(const Matrix& other)
{
	if (this->cols == other.cols && this->rows == other.rows) {
		for (size_t i = 0; i < this->rows; i++)
		{
			for (size_t j = 0; j < this->cols; j++)
			{
				if (this->mat[i][j] != other.mat[i][j])
					return false;
			}
		}
		return true;
	}
	return false;
}

bool Matrix::operator!=(const Matrix& other)
{
	return !operator==(other);
}

const int* Matrix::operator[](unsigned int idx) const
{
	return this->mat[idx];
}

int* Matrix::operator[](unsigned int idx)
{
	return this->mat[idx];
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
	Matrix result(lhs);
	result -= rhs;
	return result;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
	Matrix result(lhs);
	result *= rhs;
	return result;
}

Matrix operator*(const Matrix& lhs, int n)
{
	Matrix result(lhs);
	result *= n;
	return result;
}

Matrix operator*(int n, const Matrix& lhs)
{
	Matrix result(lhs);
	result *= n;
	return result;
}

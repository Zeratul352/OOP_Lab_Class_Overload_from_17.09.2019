#include "pch.h"
#include "Matrix.h"


void Matrix::Create()
{
	matrix = new double*[length];
	for (int i = 0; i < length; i++) {
		matrix[i] = new double [width];
	}
}

Matrix::Matrix()
{
}

Matrix::Matrix(int len, int wid)
{
	length = len;
	width = wid;
	Create();
}

Matrix::Matrix(int len, int wid, double ** matr)
{
	length = len;
	width = wid;
	Create();
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = matr[i][j];
		}
	}
}

Matrix Matrix::operator+(double a)
{
	if (this->width != this->length) {
		double ** mat = new double*[1];
		for (int i = 0; i < 1; i++) {
			mat[i] = new double[1];
		}
		mat[0][0] = 0;
		return Matrix(1, 1, mat);
	}
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		SetElem(i, i, GetElem(i, i) + a);
		//ar[i][i] += a;//метод set по индексам или перегрузка [];
	}
	return matr;
}
Matrix Matrix::operator-(double a)
{
	if (this->width != this->length) {
		double ** mat = new double*[1];
		for (int i = 0; i < 1; i++) {
			mat[i] = new double[1];
		}
		mat[0][0] = 0;
		return Matrix(1, 1, mat);
	}
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		SetElem(i, i, GetElem(i, i) - a);
	}
	return matr;
}
Matrix Matrix::operator*(double a)
{
	
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		SetElem(i, i, GetElem(i, i) * a);
	}
	return matr;
}

Matrix Matrix::operator/(double a)
{
	if (a == 0) {
		Matrix matr = Matrix(1, 1);
		matr.SetElem(0, 0, 0);
		return matr;
	}
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		SetElem(i, i, GetElem(i, i) / a);
	}
	return matr;
}

Matrix Matrix::operator+(Matrix matrix1)
{
	if ((this->length != matrix1.GetLength()) || (this->width != matrix1.GetWidth)) {
		double ** mat = new double*[1];
		for (int i = 0; i < 1; i++) {
			mat[i] = new double[1];
		}
		mat[0][0] = 0;
		return Matrix(1, 1, mat);
	}
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->width; j++) {
			matr.SetElem(i, j, GetElem(i, j) + matrix1.GetElem(i, j));
		}
	}
	return matr;
}
Matrix Matrix::operator-(Matrix matrix1)
{
	if ((this->length != matrix1.GetLength()) || (this->width != matrix1.GetWidth)) {
		double ** mat = new double*[1];
		for (int i = 0; i < 1; i++) {
			mat[i] = new double[1];
		}
		mat[0][0] = 0;
		return Matrix(1, 1, mat);
	}
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->width; j++) {
			matr.SetElem(i, j, GetElem(i, j) - matrix1.GetElem(i, j));
		}
	}
	return matr;
}
Matrix Matrix::operator*(Matrix matrix1)
{
	if (this->width != matrix1.GetLength) {
		double ** mat = new double*[1];
		for (int i = 0; i < 1; i++) {
			mat[i] = new double[1];
		}
		mat[0][0] = 0;
		return Matrix(1, 1, mat);
	}
	Matrix matr = Matrix(this->length, matrix1.GetWidth);

	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < matrix1.GetWidth; j++) {
			matr.SetElem(i, j, 0);
			for (int k = 0; k < matrix1.GetWidth; k++) {
				matr.SetElem(i, j, matr.GetElem(i, j) + this->GetElem(i, k) * matrix1.GetElem(k, j));
			}
		}
	}
	return matr;
}

Matrix Matrix::operator/(Matrix matrix1) {
	Matrix matr = Matrix(1, 1);
	matr.SetElem(0, 0, 0);
	return matr;
}

bool Matrix::operator>(Matrix matrix1)
{
	int a = this->GetSumOfElements(*this); //??? will it work???
	int b = GetSumOfElements(matrix1);
	if (a > b) {
		return true;
	}
	return false;
}
bool Matrix::operator<(Matrix matrix1)
{
	int a = this->GetSumOfElements(*this); //??? will it work???
	int b = GetSumOfElements(matrix1);
	if (a < b) {
		return true;
	}
	return false;
}
bool Matrix::operator>=(Matrix matrix1)
{
	int a = this->GetSumOfElements(*this); //??? will it work???
	int b = GetSumOfElements(matrix1);
	if (a >= b) {
		return true;
	}
	return false;
}
bool Matrix::operator<=(Matrix matrix1)
{
	int a = this->GetSumOfElements(*this); //??? will it work???
	int b = GetSumOfElements(matrix1);
	if (a <= b) {
		return true;
	}
	return false;
}
bool Matrix::operator==(Matrix matrix1)
{
	int a = this->GetSumOfElements(*this); //??? will it work???
	int b = GetSumOfElements(matrix1);
	if (a == b) {
		return true;
	}
	return false;
}

Matrix Matrix::operator=(const Matrix & object)
{
	if (this != &object) {
		for (int i = 0; i < length; i++) {
			delete matrix[i];
		}
		length = object.GetLength;
		width = object.GetWidth;
		Create();
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				//matrix[i][j] = object.GetElem(i, j);// some error happens here
			}
		}
	}
}



void Matrix::SetElem(int i, int j, double number)
{
	matrix[i][j] = number;
}

double Matrix::GetElem(int i, int j)
{
	return matrix[i][j];
}

const double Matrix::GetConstElem(int i, int j)
{
	return matrix[i][j];
}

int Matrix::GetLength()
{
	return length;
}

int Matrix::GetWidth()
{
	return width;
}

double Matrix::GetSumOfElements(Matrix matrix)
{
	double sum = 0;
	for (int i = 0; i < matrix.GetLength; i++) {
		for (int j = 0; j < matrix.GetWidth; j++) {
			sum += matrix.GetElem(i, j);
		}
	}
	return sum;
}


Matrix::~Matrix()
{
	for (int i = 0; i < length; i++) {
		delete matrix[i];
	}
}

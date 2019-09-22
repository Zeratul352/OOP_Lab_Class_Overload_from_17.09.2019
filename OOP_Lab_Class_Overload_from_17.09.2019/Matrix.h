#pragma once
#include <iostream>
using namespace std;
class Matrix
{
	int length;
	int width;
	double** matrix;
	void Create();
public:
	Matrix();
	Matrix(int len, int wid);
	Matrix(int len, int wid, double** matr);
	Matrix operator+(double a);
	Matrix operator+(Matrix matrix1);
	Matrix operator-(double a);
	Matrix operator-(Matrix matrix1);
	Matrix operator*(double a);
	Matrix operator*(Matrix matrix1);
	Matrix operator/(double a);
	Matrix operator/(Matrix matrix1);
	bool operator>(Matrix matrix1);
	bool operator<(Matrix matrix1);
	bool operator>=(Matrix matrix1);
	bool operator<=(Matrix matrix1);
	bool operator==(Matrix matrix1);
	Matrix operator=(const Matrix& object);// !!!
	void SetElem(int i, int j, double number);
	double GetElem(int i, int j);
	const double GetConstElem(int i, int j);
	int GetLength();
	int GetWidth();
	double GetSumOfElements(Matrix matrix);
	~Matrix();
};


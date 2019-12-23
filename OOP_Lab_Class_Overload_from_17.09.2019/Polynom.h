#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "Error.h"

using namespace std;

class Polynom {
private:
	int deg;
	double* koef;
	void CorrectDeg(); // функция корректировки степени полинома

public:
	Polynom();
	Polynom(int, double*);
	Polynom(int a);
	Polynom(const Polynom&); //копирующий контсруктор
	Polynom(const char*);
	~Polynom();

	int GetDeg();
	int Get_i();
	double GetKoef(int);
	int SetKoef(double, int);
	Polynom CreateNew();
	static Polynom Plus(Polynom first, Polynom second);
	static Polynom Minus(Polynom first, Polynom second);
	static Polynom Multiply(Polynom first, Polynom second);
	static Polynom Devide(Polynom first, Polynom second);
	Polynom Module(int a);
	Polynom operator + (const Polynom&);
	Polynom& operator += (const Polynom&);
	Polynom operator - (const Polynom&);
	Polynom& operator -= (const Polynom&);
	double operator [] (int k);
	Polynom operator * (const Polynom&);
	Polynom& operator *= (const Polynom&);
	bool operator > (Polynom&);
	bool operator >= (Polynom&);
	bool operator < (Polynom&);
	bool operator <= (Polynom&);
	bool operator == (Polynom&);
	bool operator != (Polynom&);
	Polynom& operator = (const Polynom&);
	friend Polynom MultConst(double, Polynom&); //умножения полинома на константу
	void KoefListPolynom();
	double SumKoefPolynom();
	void InputPolynom();
	void OutputPolynom();
	char* convert_toString();
};
ostream &operator<<(ostream & cout, const Polynom& object);
istream &operator>>(istream & cin, Polynom& object);

#pragma once
#include "Matrix.h"
template <typename T>
class Sorter
{
protected:
	//double GetFirstNumber(Matrix first);
	//double GetSecondNumber(Matrix first);
	int Compare(T first, T second);
public:
	Sorter();
	virtual vector<T> Sorting(vector <T> arr) = 0;
	~Sorter();
};
template <typename T>
class UsualSort :
	public Sorter<T>
{	
public:
	UsualSort();
	virtual vector <T> Sorting(vector <T> arr);
	~UsualSort();
};
template <typename T>
class QuickSort :
	public Sorter<T>
{
public:
	QuickSort();
	virtual vector <T> Sorting(vector <T> arr);
	~QuickSort();
};


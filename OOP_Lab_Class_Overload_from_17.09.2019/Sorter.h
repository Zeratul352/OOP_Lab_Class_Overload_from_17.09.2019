#pragma once
#include "Matrix.h"
#include "Container.h"
template <class T>
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
template <class T>
class UsualSort :
	public Sorter<T>
{	
public:
	UsualSort();
	virtual vector <T> Sorting(vector <T> arr);
	~UsualSort();
};
template <class T>
class QuickSort :
	public Sorter<T>
{
public:
	QuickSort();
	virtual vector <T> Sorting(vector <T> arr);
	~QuickSort();
};


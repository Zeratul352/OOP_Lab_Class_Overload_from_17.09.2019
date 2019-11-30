#include "pch.h"
#include "Sorter.h"
#include <ctime>
#include <random>

template <class T>
Sorter<T>::Sorter()
{
}
template <class T>
int Sorter<T>::Compare(T first, T second)
{
	/*if (first.GetLength() != first.GetWidth()) {
		throw Exception4();
	}
	if (second.GetLength() != second.GetWidth()) {
		throw Exception4();
	}
	double diagonaly[4];
	for (int i = 0; i < 4; i++) {
		diagonaly[i] = 0;
	}
	int len1 = first.GetLength();
	for (int i = 0; i < len1; i++) {
		diagonaly[0] += first[i][i];
		diagonaly[1] += first[len1 - 1 - i][i];
	}
	int len2 = second.GetLength();
	for (int i = 0; i < len2; i++) {
		diagonaly[2] += second[i][i];
		diagonaly[3] += second[len2 - 1 - i][i];
	}
	int num1 = diagonaly[0] * diagonaly[1];
	int num2 = diagonaly[2] * diagonaly[3];
	if (num1 > num2) {
		return 1;
	}
	else if (num1 < num2) {
		return -1;
	}
	else {
		if (diagonaly[0] > diagonaly[2]) {
			return 1;
		}
		else if (diagonaly[0] < diagonaly[2]) {
			return -1;
		}
		else {
			return 0;
		}
	}
}

double Sorter::GetFirstNumber(Matrix first)
{
	if (first.GetLength() != first.GetWidth()) {
		throw Exception4();
	}
	double a = 0;
	int num = first.GetLength();
	for (int i = 0; i < num; i++) {
		a += first[i][i];
	}*/
	int a = 0;
	if (first > second) {
		a = 1;
	}else if (second == first) {
		a = 0;
	}
	else {
		a = -1;
	}
	return a;
}

/*double Sorter::GetSecondNumber(Matrix first)
{
	if (first.GetLength() != first.GetWidth()) {
		throw Exception4();
	}
	double a = 0;
	int num = first.GetLength();
	for (int i = 0; i < num; i++) {
		a += first[num - 1 - i][i];
	}
	return a;
}*/

template <class T>
Sorter<T>::~Sorter()
{
}

template <class T>
UsualSort<T>::UsualSort()
{
}
template <class T>
vector <T> UsualSort<T>::Sorting(vector <T> arr)
{
	int number = arr.size();
	for (int i = 0; i < number - 1; i++) {
		for (int j = 0; j < number - 1 - i; j++) {
			int command = Compare(arr[j], arr[j + 1]);
			if (command == 1) {
				Matrix temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}

template <class T>
UsualSort<T>::~UsualSort()
{
}

template <class T>
QuickSort<T>::QuickSort()
{
}
template <class T>
vector <T> QuickSort<T>::Sorting(vector <T> arr)
{
	int right = arr.size();
	/*int i = left, j = right;
	Matrix temp;
	Matrix pivot = arr[(left + right) / 2];
	while (i <= j) {
		while (Compare(arr[i], pivot) == -1) {
			i++;
		}
		while (Compare(arr[j], pivot) == 1) {
			j--;
		}
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if (left < j) {
		QuickSorting(arr, j, left);
	}
	if (i < right) {
		QuickSorting(arr, right, i);
	}*/
	for (int i = 0; i < right; i++) {
		srand(time(0));
		int first = rand() % right;
		int second = rand() % right;
		Matrix temp = arr[second];
		arr[second] = arr[first];
		arr[first] = temp;
	}
	return arr;
}

template <class T>
QuickSort<T>::~QuickSort()
{
}


#include "pch.h"
#include "Loader.h"

template <class T>
Loader<T>::Loader()
{
}

/*void Loader::SetElem(Matrix * object, int i, int j, double num)
{
	object->SetElem(i, j, num);
}*/

/*void Loader::SetMatrix(Matrix * object)
{
	
}*/

template <class T>
Loader<T>::~Loader()
{
}

template <typename T>
ConsoleLoader<T>::ConsoleLoader()
{
}

/*void ConsoleLoader::SetConsoleElem(Matrix * object, int i, int j)
{
	double num;
	cin >> num;
	SetElem(object, i, j, num);
}*/
template <class T>
T ConsoleLoader<T>::GetObject()
{
	T object = T();
	cin >> T;
	return T;
}
/*
void ConsoleLoader::SetStringMatrix(Matrix * object)
{
	string line;
	cin >> line;
	Matrix A = Matrix(line);
	*object = A;
}*/

template <class T>
ConsoleLoader<T>::~ConsoleLoader()
{
}

template <class T>
FileLoader<T>::FileLoader()
{
}
/*
void FileLoader::SetFileElem(Matrix * object, int i, int j)
{
	freopen("input.txt", "r", stdin);
	double num;
	cin >> num;
	SetElem(object, i, j, num);
	fclose(stdin);
}
*/


template <class T>
T FileLoader<T>::GetObject()
{
	freopen("input.txt", "r", stdin);
	T A = T();
	cin >> A;
	fclose(stdin);
	return A;
}
/*
void FileLoader::SetStringFileMatrix(Matrix * object)
{
	freopen("input.txt", "r", stdin);
	string line;
	cin >> line;
	Matrix A = Matrix(line);
	*object = A;
	fclose(stdin);
}
*/
template <class T>
FileLoader<T>::~FileLoader()
{
}

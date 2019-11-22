#pragma once
#include "Matrix.h"
#include <cstdio>
template <typename T>
class Loader
{
public:
	Loader();
	//static void SetElem(Matrix * object, int i, int j, double num);
	virtual T GetObject() = 0;
	//void SetMatrix(Matrix * object);
	~Loader();
};
template <typename T>
class ConsoleLoader :
	public Loader<T>
{
public:
	ConsoleLoader();
	//void SetConsoleElem(Matrix * object, int i, int j);
	virtual T GetObject();
	//void SetStringMatrix(Matrix * object);
	~ConsoleLoader();
};
template <typename T>
class FileLoader :
	public Loader<T>
{
public:
	FileLoader();
	//void SetFileElem(Matrix * object, int i, int j);
	virtual T GetObject();
	//void SetStringFileMatrix(Matrix * object);
	~FileLoader();
};


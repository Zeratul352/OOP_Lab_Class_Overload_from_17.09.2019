#pragma once
#include "Matrix.h"
#include "Container.h"
#include <cstdio>
template <class T>
class Loader
{
public:
	Loader();
	//static void SetElem(Matrix * object, int i, int j, double num);
	virtual T GetObject() = 0;
	//void SetMatrix(Matrix * object);
	~Loader();
};

template <class T>
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
template <class T>
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


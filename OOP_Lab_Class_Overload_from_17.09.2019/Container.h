#pragma once
#include <memory>
#include "Matrix.h"
#include "Loader.h"
#include "Sorter.h"
template <typename T>
class Iterator
{
public:
	Iterator();
	virtual void Next() = 0;
	virtual T Get() = 0;
	~Iterator();
};
template <typename T>
class ContainerIterator :
	public Iterator<T>
{
	int i = 0;
	int size;
	//vector <Matrix> & array;
	shared_ptr<vector<T>> array;
public:
	ContainerIterator(vector <T> * arr, int s);
	virtual void Next();
	bool End();
	virtual T Get();
	~ContainerIterator();
};
template <typename T>
class Container //:	public Loader, public Sorter
{
	shared_ptr<Loader<T>> loader;
	shared_ptr<Sorter<T>> sorter;

/*	ConsoleLoader * m_cloader;
	UsualSort * m_usorter;
	FileLoader * m_floader;
	QuickSort * m_qsorter;
*/
	vector <T> box;
public:
	Container();
//	virtual void LoadConsole();
//	virtual void LoadFile();
//	virtual void next();
//	virtual Matrix first();
//	virtual bool end();
//	virtual void UsualSorting();
//	virtual void QuickSorting();
	void Sort();
	void Add();
	void SwitchLoader(string type);
	void SwitchSorter(string type);
	ContainerIterator<T> GetIterator();
	void Delete(int number);
	void Print();
	T operator[](int a);
	~Container();
};




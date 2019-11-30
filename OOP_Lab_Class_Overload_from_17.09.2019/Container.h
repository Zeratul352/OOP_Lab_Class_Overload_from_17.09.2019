#pragma once
#include <memory>
#include <map>
#include <cstdio>
#include <ctime>
#include <random>
#include "Matrix.h"
#include <utility>



template <class T>
class Iterator
{
public:
	Iterator();
	virtual void Next() = 0;
	virtual T Get() = 0;
	~Iterator();
};
template <class T>
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
template <class T>
class Loader
{
public:
	Loader(){}
	//static void SetElem(Matrix * object, int i, int j, double num);
	virtual T GetObject() = 0;
	//void SetMatrix(Matrix * object);
	~Loader(){}
};

template <class T>
class ConsoleLoader :
	public Loader<T>
{
public:
	ConsoleLoader(){}
	//void SetConsoleElem(Matrix * object, int i, int j);
	virtual T GetObject() {
		T object = T();
		cin >> T;
		return T;
	}
	//void SetStringMatrix(Matrix * object);
	~ConsoleLoader(){}
};
template <class T>
class FileLoader :
	public Loader<T>
{
public:
	FileLoader(){}
	//void SetFileElem(Matrix * object, int i, int j);
	virtual T GetObject() {
		freopen("input.txt", "r", stdin);
		T A = T();
		cin >> A;
		fclose(stdin);
		return A;
	}
	//void SetStringFileMatrix(Matrix * object);
	~FileLoader(){}
};



template <class T>
class Sorter
{
protected:
	//double GetFirstNumber(Matrix first);
	//double GetSecondNumber(Matrix first);
	int Compare(T first, T second) {
		int a = 0;
		if (first > second) {
			a = 1;
		}
		else if (second == first) {
			a = 0;
		}
		else {
			a = -1;
		}
		return a;
	}
public:
	Sorter(){}
	virtual vector<T> Sorting(vector <T> arr) = 0;
	~Sorter(){}
};
template <class T>
class UsualSort :
	public Sorter<T>
{
public:
	UsualSort(){}
	virtual vector <T> Sorting(vector <T> arr) {
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
	~UsualSort(){}
};
template <class T>
class QuickSort :
	public Sorter<T>
{
public:
	QuickSort(){}
	virtual vector <T> Sorting(vector <T> arr) {
		int right = arr.size();

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
	~QuickSort(){}
};


template <class T>
class Calculator
{
	T(*action)(T first, T second);
	int module;
public:
	//Calculator();
	Calculator(string line) {
		char operation = line[0];
		line.erase(line.begin());
		module = 0;
		if (line == "") {
			module = 0;
		}
		else {
			module = stoi(line);
		}
		switch (operation) {
		case '+': {
			action = T::Plus;
		}
		case '-': {
			action = T::Minus;
		}
		case '*': {
			action = T::Multiply;
		}
		case '/': {
			action = T::Devide;
		}
		default:throw BadCommandException();
		}
	}
	//Calculator(char k, int a) :operation(k), module(a) {}
	T operator()(T first, T second) {
		return action(first, second) % module;
	}
	~Calculator();
};
template <class T>
class CommandMap
{
	multimap <string, Calculator<T>> commands;
public:
	CommandMap();
	CommandMap(vector <string> commandline) {
		commands = multimap<string, Calculator<T>>(commandline.size());
		for (int i = 0; i < commandline.size(); i++) {
			Calculator<T> functor = Calculator<T>(commandline[i]);
			commands[i]->first = commandline[i];
			commands[i]->second = functor;
			//commands.insert(pair<string, Calculator<T>>(commandline[i], functor);
		}
	}
	Calculator<T> GetFunctor(int index) {
		return commands[index]->second;
	}
	~CommandMap();
};


template <class T>
class Container //:	public Loader, public Sorter
{
	shared_ptr <Loader<T>> loader;
	shared_ptr <Sorter<T>> sorter;

/*	ConsoleLoader * m_cloader;
	UsualSort * m_usorter;
	FileLoader * m_floader;
	QuickSort * m_qsorter;
*/
	vector <T> box;
	vector <string> commandline;
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
	void AddCommand(string line);
	void SetCommandLine(vector <string> line);
	T Calculate() {
		T item = box[0];
		CommandMap<T> FunctorMap = CommandMap<T>(commandline);
		int lim;
		if (box.size() > commandline.size()) {
			lim = commandline.size();
		}
		else {
			lim = box.size() - 1;
		}
		for (int i = 0; i < lim; i++) {
			item = FunctorMap.GetFunctor(i)(item, box[i + 1]);
		}
		return item;
	}
	ContainerIterator<T> GetIterator();
	void Delete(int number);
	void Print();
	T operator[](int a);
	~Container();
};










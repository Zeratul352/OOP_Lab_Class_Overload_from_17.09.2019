#include "pch.h"
#include "Container.h"

template <class T>
Iterator<T>::Iterator()
{
}

template <class T>
Iterator<T>::~Iterator()
{
}

//Matrix Z = Matrix(0);
template <class T>
Container<T>::Container(): loader(new ConsoleLoader), sorter(new UsualSort)
{
	
	
}

/*void Container::Load()
{
	Matrix A = Matrix();
	loader->SetMatrix(&A);
	box.push_back(A);
}

void Container::LoadFile()
{
	Matrix A = Matrix();
	m_floader->SetFileMatrix(&A);
	box.push_back(A);
}

void Container::next()
{
	index++;
}

Matrix Container::first()
{
	if (box.size() == 0) {
		throw Error();
	}
	return box[0];
}

bool Container::end()
{
	if (index == box.size()) {
		return true;
	}
	return false;
}

void Container::UsualSorting()
{
	
	Matrix *array = new Matrix[50];
	for (int i = 0; i < box.size(); i++) {
		array[i] = box[i];
	}
	m_usorter->Sorting(&array, box.size());
	for (int i = 0; i < box.size(); i++) {
		box[i] = array[i];
	}
	delete array;
	box = m_usorter->Sorting(box);
}*/
template <class T>
void Container<T>::Sort()
{
	/*Matrix * array = new Matrix[box.size()];
	for (int i = 0; i < box.size(); i++) {
		array[i] = box[i];
	}
	m_qsorter->QuickSorting(&array, box.size() - 1);
	for (int i = 0; i < box.size(); i++) {
		box[i] = array[i];
	}
	delete array;*/
	box = sorter->Sorting(box);
}
template <class T>
void Container<T>::Add()
{
	
	box.push_back(loader->GetObject());
}
template <class T>
void Container<T>::SwitchLoader(string type)
{
	
	if (type == "console") {
		shared_ptr <ConsoleLoader> p(new ConsoleLoader);
		loader = p;
	}
	else if (type == "file") {
		shared_ptr <FileLoader> p(new FileLoader);
		loader = p;
	}
	else {
		shared_ptr <ConsoleLoader> p(new ConsoleLoader);
		loader = p;
	}
}
template <class T>
void Container<T>::SwitchSorter(string type)
{
	if (type == "usual") {
		shared_ptr <UsualSort> p(new UsualSort);
		sorter = p;
	}
	else if (type == "quick") {
		shared_ptr <QuickSort> p(new QuickSort);
		sorter = p;
	}
}
template<class T>
void Container<T>::AddCommand(string line)
{
	commandline.push_back(line);
}
template<class T>
void Container<T>::SetCommandLine(vector<string> line)
{
	commandline = line;
}
/*template<class T>
T Container<T>::Calculate()
{
	T item = box[0];
	CommandMap<T> FunctorMap = CommandMap<T>(commandline);
	int lim;
	if (box.size() > commandline.size()) {
		lim = commandline.size();
	}
	else {
		lim = box.size();
	}
	for (int i = 0; i < lim; i++) {
		//item = FunctorMap.
	}
	return item;
}*/
	

template <class T>
ContainerIterator<T> Container<T>::GetIterator()
{
	return ContainerIterator<T>(&box, box.size());
}
template <class T>
void Container<T>::Delete(int number)
{
	if (number >= box.size()) {
		throw Error();
	}
	box.erase(box.begin() + number);
}
template <class T>
void Container<T>::Print()
{
	for (int i = 0; i < box.size(); i++) {
		cout << box[i] << endl;
	}
}
template <class T>
T Container<T>::operator[](int a)
{
	if (a >= box.size()  ||  a<0) {
		throw Error();
	}
	return box[a];
}



template <class T>
Container<T>::~Container()
{
}

template <class T>
ContainerIterator<T>::ContainerIterator(vector <T> * arr, int s) {

	size = s;
	shared_ptr<vector<T>> p (arr);
	array = p;
}

template <class T>
void ContainerIterator<T>::Next()
{
	i++;
}
template <class T>
bool ContainerIterator<T>::End()
{
	if (i == size) {
		return true;
	}
	return false;
}
template <class T>
T ContainerIterator<T>::Get()
{
	return (*array)[i];
}

template <class T>
ContainerIterator<T>::~ContainerIterator()
{
}




template <class T>
Calculator<T>::~Calculator()
{
}

template <class T>
CommandMap<T>::CommandMap()
{
}

template <class T>
CommandMap<T>::~CommandMap()
{
}

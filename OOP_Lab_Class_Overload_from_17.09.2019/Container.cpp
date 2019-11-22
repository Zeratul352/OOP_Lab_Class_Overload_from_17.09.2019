#include "pch.h"
#include "Container.h"

template <typename T>
Iterator<T>::Iterator()
{
}

template <typename T>
Iterator<T>::~Iterator()
{
}

//Matrix Z = Matrix(0);
template <typename T>
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
template <typename T>
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
template <typename T>
void Container<T>::Add()
{
	
	box.push_back(loader->GetObject());
}
template <typename T>
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
template <typename T>
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
template <typename T>
ContainerIterator<T> Container<T>::GetIterator()
{
	return ContainerIterator<T>(&box, box.size());
}
template <typename T>
void Container<T>::Delete(int number)
{
	if (number >= box.size()) {
		throw Error();
	}
	box.erase(box.begin() + number);
}
template <typename T>
void Container<T>::Print()
{
	for (int i = 0; i < box.size(); i++) {
		cout << box[i] << endl;
	}
}
template <typename T>
T Container<T>::operator[](int a)
{
	if (a >= box.size()  ||  a<0) {
		throw Error();
	}
	return box[a];
}



template <typename T>
Container<T>::~Container()
{
}

template <typename T>
ContainerIterator<T>::ContainerIterator(vector <T> * arr, int s) {

	size = s;
	shared_ptr<vector<T>> p (arr);
	array = p;
}

template <typename T>
void ContainerIterator<T>::Next()
{
	i++;
}
template <typename T>
bool ContainerIterator<T>::End()
{
	if (i == size) {
		return true;
	}
	return false;
}
template <typename T>
T ContainerIterator<T>::Get()
{
	return (*array)[i];
}

template <typename T>
ContainerIterator<T>::~ContainerIterator()
{
}

﻿// OOP_Lab_Class_Overload_from_17.09.2019.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_DEPRECATE
#include "pch.h"
#include "Matrix.h"
#include "Error.h"
#include "Container.h"
#include "Polynom.h"
#include <iostream>



int main()
{
	
	try {
		vector <Container<Polynom>> A;
		Container<Polynom> B;
		A.push_back(B);
		for (int i = 0; i < 4; i++) {
			A[0].Add();
		}
		A[0].Sort();
		//ContainerIterator<Matrix> B = A.GetIterator();
		vector <string> operations;
		for (int i = 0; i < 3; i++) {
			string a;
			cin >> a;
			operations.push_back(a);
		}
		A[0].SetCommandLine(operations);
		cout << A[0].Calc();
	}
	catch(Error e){
		e.PrintError();
		return 0;
	}
//	string str;
//	cin >> str;
//	Matrix B = Matrix(str);
	//cout << B;
	
//	Matrix A = Matrix("[1, 1; 1, 1]");
	/*try {
		A = A / 0;
	}
	catch (Error e) {
		e.PrintError();
	}
	try {
		cout << A; //  +"[0, 1; 1, 0]";
	}*/
	
	catch (...) {
		cout << "Unknown error detected " << endl;
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

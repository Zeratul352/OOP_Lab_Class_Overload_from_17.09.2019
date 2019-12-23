#pragma once
#include<string>
#include "pch.h"
using namespace std;
class all_exceptions {
protected:
	string message;

public:
	virtual string what() = 0;

};

class overflow_exception : public all_exceptions {
public:
	overflow_exception()
	{
		message = "Ошибка! Переполнение!";
	}

	overflow_exception(string _message)
	{
		message = _message;
	}

	string what() {
		return message;
	}

};


class wrong_index_exception : public all_exceptions {
public:
	wrong_index_exception()
	{
		message = "Ошибка! Обращение к несуществующему индексу! Проверьте индексы";
	}

	wrong_index_exception(string _message)
	{
		message = _message;
	}

	string what() {
		return message;
	}

};

class wrong_input_exception : public all_exceptions {
public:
	wrong_input_exception()
	{
		message = "Ошибка ввода!";
	}

	wrong_input_exception(string _message)
	{
		message = _message;
	}

	string what() {
		return message;
	}

};

class unexpected_exception : public all_exceptions {
public:
	unexpected_exception()
	{
		message = "!!!Ошибка!!!";
	}

	unexpected_exception(string _message)
	{
		message = _message;
	}

	string what() {
		return message;
	}

};
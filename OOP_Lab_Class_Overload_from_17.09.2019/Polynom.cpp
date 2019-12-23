
#include<string>
#include<iostream>

#include "pch.h"
#include "Polynom.h"
#include "except.h"
using namespace std;

Polynom::Polynom() {
	deg = 0;
	koef = new double[deg + 1];
	koef[0] = 0.0;
}

Polynom::Polynom(int new_deg, double* new_koef) {
	deg = 0;
	for (int i = 0; i <= new_deg; i++)
		if (new_koef[i] != 0) deg = i;
	koef = new double[deg + 1];
	for (int i = 0; i <= deg; i++)
		koef[i] = new_koef[i];
}

Polynom::Polynom(int a)
{
	deg = 0;
	koef = new double[deg + 1];
	koef[0] = 0.0;
}

//копирующий конструктор
Polynom::Polynom(const Polynom& f) {
	deg = f.deg;
	koef = new double[deg + 1];
	for (int i = 0; i <= deg; i++)
		koef[i] = f.koef[i];
}

Polynom::~Polynom() {
	delete[] koef;
}
int Polynom::GetDeg() {
	return deg;
}

double Polynom::operator[](int k) {
	if (k < 0 || k >= sizeof(koef))
		throw wrong_index_exception();
	return koef[k];
}

double Polynom::GetKoef(int i) {
	if ((i >= 0) && (i <= deg))
		return koef[i];
	else
		return 0.0;
}

int Polynom::SetKoef(double new_koef, int i) {
	if ((i >= 0) && (i <= deg)) koef[i] = new_koef;
	else return deg;
	void CorrectDeg();
	return deg;
}

Polynom Polynom::CreateNew()
{
	Polynom A = Polynom();
	cin >> A;
	return A;
}

Polynom Polynom::Plus(Polynom first, Polynom second)
{
	return first + second;
}

Polynom Polynom::Minus(Polynom first, Polynom second)
{
	return first - second;
}

Polynom Polynom::Multiply(Polynom first, Polynom second)
{
	return first * second;
}

Polynom Polynom::Devide(Polynom first, Polynom second)
{
	throw BadCommandException();
}

Polynom Polynom::Module(int a)
{
	for (int i = 0; i < deg; i++) {
		koef[i] = fmod(koef[i], a);
	}
	return *this;
}

Polynom Polynom::operator + (const Polynom& t) {
	int i;
	Polynom result;

	if (deg >= t.deg) { //если степень первого полинома больше степени второго
		result = Polynom(deg, koef);
		for (i = 0; i <= t.deg; i++)

			if ((koef[i] > 0 && t.koef[i] > 0 && koef[i] + t.koef[i] < 0) ||
				(koef[i] < 0 && t.koef[i] < 0 && koef[i] + t.koef[i] > 0)) {
				throw overflow_exception();
			}
		result.koef[i] = koef[i] + t.koef[i];
	}
	else {                   //если степень второго полинома больше степень первого
		result = Polynom(t.deg, t.koef);
		for (i = 0; i <= deg; i++)

			if ((koef[i] > 0 && t.koef[i] > 0 && koef[i] + t.koef[i] < 0) ||
				(koef[i] < 0 && t.koef[i] < 0 && koef[i] + t.koef[i] > 0)) {
				throw overflow_exception();
			}
		result.koef[i] = koef[i] + t.koef[i];
	}
	result.CorrectDeg();
	return result;
}


Polynom& Polynom::operator += (const Polynom& t) {
	if (deg >= t.deg) { //если степень первого полинома больше степени второго
		for (int i = 0; i <= t.deg; i++) {
			if ((koef[i] > 0 && t.koef[i] > 0 && koef[i] + t.koef[i] < 0) ||
				(koef[i] < 0 && t.koef[i] < 0 && koef[i] + t.koef[i] > 0)) {
				throw overflow_exception();
			}
			koef[i] += t.koef[i];
		}
	}
	else {                   //если степень второго полинома больше степень первого
		for (int i = 0; i <= deg; i++)
		{
			if ((koef[i] > 0 && t.koef[i] > 0 && koef[i] + t.koef[i] < 0) ||
				(koef[i] < 0 && t.koef[i] < 0 && koef[i] + t.koef[i] > 0)) {
				throw overflow_exception();
			}
			koef[i] += t.koef[i];
		}
	}
	this->CorrectDeg();
	return *this;
}

Polynom Polynom::operator - (const Polynom& t) {
	int i;
	Polynom result = Polynom();

	if (deg >= t.deg) { //если степень первого полинома больше степени второго
		result = Polynom(deg, koef);
		for (i = 0; i <= t.deg; i++)
			if ((koef[i] > 0 && t.koef[i] > 0 && koef[i] + t.koef[i] < 0) ||
				(koef[i] < 0 && t.koef[i] < 0 && koef[i] + t.koef[i] > 0)) {
				throw overflow_exception();
			}
		result.koef[i] = koef[i] - t.koef[i];
	}
	else {                   //если степень второго полинома больше степень первого//????????

		result = Polynom(t.deg, t.koef);
		for (i = 0; i <= deg; i++)
			if ((koef[i] > 0 && t.koef[i] > 0 && koef[i] + t.koef[i] < 0) ||
				(koef[i] < 0 && t.koef[i] < 0 && koef[i] + t.koef[i] > 0)) {
				throw overflow_exception();
			}
		result.koef[i] = koef[i] - t.koef[i];
		for (int j = deg; j <= t.deg; i++) {
			koef[j] = (-1) * koef[j];
		}
	}
	result.CorrectDeg();
	return result;
}

Polynom& Polynom::operator -= (const Polynom& t) {
	if (deg >= t.deg) { //если степень первого полинома больше степени второго
		for (int i = 0; i <= t.deg; i++) {
			if ((koef[i] > 0 && t.koef[i] > 0 && koef[i] + t.koef[i] < 0) ||
				(koef[i] < 0 && t.koef[i] < 0 && koef[i] + t.koef[i] > 0)) {
				throw overflow_exception();
			}
			koef[i] -= t.koef[i];
		}
	}
	else {                   //если степень второго полинома больше степень первого//????????
		for (int i = 0; i <= deg; i++) {
			if ((koef[i] > 0 && t.koef[i] > 0 && koef[i] + t.koef[i] < 0) ||
				(koef[i] < 0 && t.koef[i] < 0 && koef[i] + t.koef[i] > 0)) {
				throw overflow_exception();
			}
			koef[i] -= t.koef[i];
			for (int j = deg; j <= t.deg; j++) {
				koef[j] = (-1) * koef[j];
			}
		}
	}
	this->CorrectDeg();
	return *this;
}

Polynom Polynom::operator *(const Polynom& t) {
	Polynom temp;
	temp.deg = deg * t.deg;
	temp.koef = new double[temp.deg + 1];
	for (int i = 0; i <= deg; i++)
	{
		for (int j = 0; j <= t.deg; j++)
		{
			temp.koef[i + j] += koef[i] * t.koef[j];
		}
	}
	return temp;
}

Polynom& Polynom::operator *=(const Polynom& t) {
	double* temp_koef = new double[deg * t.deg + 1];
	for (int i = 0; i <= deg; i++)
	{
		for (int j = 0; j <= t.deg; j++)
		{
			temp_koef[i + j] += koef[i] * t.koef[j];
		}
	}
	delete[]koef;
	koef = temp_koef;
	this->deg = deg * t.deg + 1;
	return *this;
}

Polynom& Polynom::operator = (const Polynom& t) {
	if (this != &t) {
		deg = t.deg;
		delete[] koef;
		koef = new double[deg + 1];
		for (int i = 0; i <= deg; i++)
			koef[i] = t.koef[i];
		return *this;
	}
}

Polynom operator * (double K, Polynom& t) {
	return MultConst(K, t);
}

Polynom operator * (Polynom& t, double K) {
	return MultConst(K, t);
}

Polynom MultConst(double K, Polynom& t) {
	if (K == 0) {
		Polynom result;
		return result;
	}
	else {
		int deg = t.deg;
		double* tmp_koef = new double[deg + 1];
		for (int i = 0; i <= deg; i++)
			tmp_koef[i] = K * t.koef[i];
		Polynom result(deg, tmp_koef);
		delete[] tmp_koef;
		return result;
	}
}

ostream & operator<<(ostream & cout, const Polynom & object)
{
	Polynom N = Polynom(object);
	N.OutputPolynom();
	return cout;
}

istream & operator>>(istream & cin, Polynom & object)
{
	object.InputPolynom();
	return cin;
}

void Polynom::CorrectDeg() { // коэффициент при максимальной степени должен быть ненулевым
	if (koef[deg] == 0) {
		do {
			deg--;
		} while (deg && koef[deg] == 0);
	}
}

void Polynom::InputPolynom() {
	cout << "Input degree: ";
	cin >> deg;
	delete[] koef;
	koef = new double[deg + 1];
	for (int i = 0; i < deg; i++) {
		cout << "K" << i << " = ";
		cin >> koef[i];
	}
	do {
		cout << "K" << deg << " = ";
		cin >> koef[deg];
		if (koef[deg] == 0)
			cout << "K" << deg << " must not be zero!!!\n";
	} while (!koef[deg]);
}

void Polynom::OutputPolynom() {
	if (koef[deg] == 1)
		cout << "X^" << deg;
	else if (koef[deg] == -1)
		cout << "-X^" << deg;
	else
		cout << koef[deg] << "X^" << deg;

	for (int i = deg - 1; i > 0; i--) {
		if (koef[i] > 0) {
			if (koef[i] == 1)
				cout << " + " << "X^" << i;
			else
				cout << " + " << koef[i] << "X^" << i;
		}
		else if (koef[i] < 0)
			if (koef[i] == -1)
				cout << " - " << "X^" << i;
			else
				cout << " - " << (-1) * koef[i] << "X^" << i;
	}

	if (koef[0] > 0)
		cout << " + " << koef[0] << "\n";
	else if (koef[0] < 0)
		cout << " - " << (-1) * koef[0] << "\n";
}
void Polynom::KoefListPolynom() {
	while (deg >= 0)
	{
		cout << "K" << deg << " = " << koef[deg] << endl;
		deg--;
	}
}
double Polynom::SumKoefPolynom() {
	double sum = 0;
	for (int i = 0; i <= deg; i++) {
		sum += koef[i];

	}
	return sum;
}
bool Polynom::operator > (Polynom& t) {
	return this->SumKoefPolynom() > t.SumKoefPolynom();
}

bool Polynom::operator >= (Polynom& t) {
	return this->SumKoefPolynom() >= t.SumKoefPolynom();
}

bool Polynom::operator < (Polynom& t) {
	return this->SumKoefPolynom() < t.SumKoefPolynom();
}

bool Polynom::operator <= (Polynom& t) {
	return this->SumKoefPolynom() <= t.SumKoefPolynom();
}

bool Polynom::operator == (Polynom& t) {
	if ((this->deg) != (t.deg)) return false;
	for (int i = 0; i <= t.deg; i++)
	{
		if ((this->koef[i]) != (t.koef[i])) { return false; break; }
	}
	return true;
}


bool Polynom::operator != (Polynom& t) {
	if ((this->deg) != (t.deg)) return true;
	for (int i = 0; i <= t.deg; i++)
	{
		if ((this->koef[i]) != (t.koef[i])) { return true; break; }
	}
	return false;
}

Polynom::Polynom(const char* s) {
	//vector<int> convert () {
		//char* s = new char [100];
	int a[100] = { 0 };
	int n[100] = { 0 };
	int znak[100] = { 1 };
	int l = strlen((char*)s);
	//cout << "---------------------------------------------------------------------------" << "\n";
	//cout << "Please enter a line containing only natural degrees and integer coefficient" << "\n";
	//cin >> s;
	int k = 0, i = 0, error = 0;

	// vector <int> a (100, 0);
	// vector <int> n (100, 0);
	// vector <int> znak (100, 1);
	while (k < l) {
		if (s[k] == '-' && k == 0) { znak[i] = -1; k++; }
		if (s[k] == '+' && k == 0) { k++; }

		//cout<<"1:"<<k<<" "<<s[k]<<" \n";
		while (int(s[k]) - 48 <= 9 && int(s[k]) - 48 >= 0)
		{
			a[i] = a[i] * 10 + int(s[k]) - 48;
			k++;

		}
		//cout<<"2:"<<k<<" "<<s[k]<<" \n";
		if (s[k] == '*')
		{
			k++;
			if (s[k] == 'x')
			{
				k++;
				if (s[k] == '^')
				{
					k++;
					while (int(s[k]) - 48 <= 9 && int(s[k]) - 48 >= 0)
					{
						n[i] = n[i] * 10 + int(s[k]) - 48;
						k++;
					}
					if ((s[k] == '+') || (s[k] == '-'))
					{
						if (s[k] == '-') znak[i + 1] = -1;
						i++;
						k++;
						if (k >= l) break;
						// cout << k << " " << l;
					} //else   { cout << "ERROR1" << "\n"; error++; break;}

				}
				//else  { cout << "ERROR2" << "\n"; error++; break;}
				else { throw wrong_input_exception(); error++; break; }
			}
			//else { cout << "ERROR3" << "\n"; error++; break;}
			else { throw wrong_input_exception(); error++; break; }
		}
		// else  { cout << "ERROR4" << "\n"; error++; break;}
		else { throw wrong_input_exception(); error++; break; }
	}

	int max_deg = 0;
	for (int j = 0; j < i; j++)
	{
		if (n[i] > max_deg) max_deg = n[i];
	}
	deg = max_deg;

	for (int k = 0; k < i; k++)
		for (int j = 0; j < i; j++)
		{
			//if (n[k]<n[j]) {swap(n[k], n[j]); swap (a[k], a[j]); swap (znak[k], znak[j]);}
			if (n[j] < n[j + 1]) { swap(n[j], n[j + 1]); swap(a[j], a[j + 1]); swap(znak[j], znak[j + 1]); }
		}

	//double* coef = new double[deg];
	for (int j = 0; j < i; j++)
		koef[n[j]] = a[j];

	/*
int degs[max_deg]={0};
int coef[max_deg]={0};
for (int j = 0; j<= max_deg; j++)
	degs[j] = j;
for (int j = 0; j<max_deg; j++)
	coef[j] = a[j];

//string p="";
cout << "Введенный полином:" << "\n";
if (error == 0)
for (int j = 0; j <= i; j++)
   {
	   if (znak[j] == 1)
	   {
			//if (j != 0)
				cout << "+" << a[j] << "*x^" << n[j];
			//else
			 //   cout << a[j] << "*x^" << n[j];
	   }
		if (znak[j] == -1)
			cout << znak[j]*a[j] << "*x^" << n[j];
	   // p+=(char)(znak[j]*a[j]);
	   // p+= "*x^";
	   // p+=(char)(n[j]);
   }
   //cout << p;
*/
}




/*
char* Polynom::convert_toString () {
	char* s = new char [1000];

	 for (int j = 0; j<i; j++)
	{
		if (n[j]<n[j+1]) {swap(n[j], n[j+1]); swap (a[j], a[j+1]); swap (znak[j], znak[j+1]);}
	}
	for (int j = 0; j <= i; j++)
	   if (error == 0) cout << "x^" << n[j] << " " << "coef = " << znak[j]*a[j] << endl;
	return s;
}
*/





#include "FRACTION.h"
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

class Fraction;


/////////////////////////////////////////////////////////////////
////    РЕАЛИЗАЦИЯ методов  КЛАССА							 ////
/////////////////////////////////////////////////////////////////
int Fraction::get_integer()const
{ 
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void  Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
//					Constructors:


///*В классе Fraction реализовать :
//1. Конструкторы и вывод на экран;
//5;		//double a = 5;
//1 / 2;
//2(3 / 4);
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefaultConstructor:\t" << this << endl;
}
Fraction::Fraction(double decimal)
{
	this->integer = decimal;	//сохраняем целую часть
	decimal -= integer;			//убираем целую часть из десятичной дроби
	this->denominator = 1e+9;
	this->numerator = decimal * denominator;
	reduce();
	cout << "DConstructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "1ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}

//3. Перегрузить арифметические операторы : +, -, *, / ;
//4. Перегрузить операторы++ / --;
//5. Перегрузить составные присваивания : +=, -=, *=, /=;


	//				Operators:
Fraction& Fraction:: operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}

Fraction& Fraction::operator ++()//префикс
{
	integer++;
	numerator++;
	denominator++;
	return *this;
}
Fraction& Fraction:: operator ++(int)//постфикс
{
	Fraction old = *this;
	integer++;
	numerator++;
	denominator++;
	return old;
}

//5. Перегрузить составные присваивания : +=, -=, *=, /=;

Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

Fraction& Fraction:: operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction:: operator +=(const Fraction& other)
{
	return*this = *this + other;


}
Fraction& Fraction:: operator -=(const Fraction& other)
{
	return*this = *this - other;
}

Fraction& Fraction:: operator/=(const Fraction& other)
{
	return *this = *this / other;
}

//				Type-cast operators:
 Fraction:: operator int()const
{
	return Fraction(*this).to_proper().integer;
}
 Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}

//				Methods:
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}
Fraction& Fraction::reduce()
{
	//https://www.webmath.ru/poleznoe/formules_12_7.php
	int more, less, rest = 0;
	if (numerator > denominator)more = numerator, less = denominator;
	else less = numerator, more = denominator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;	//GCD - Greates Common Divisor (Наибольший общий делитель)
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
std::ostream& Fraction::print(std::ostream& os)const
{
	if (integer)os << integer;
	if (numerator)
	{
		if (integer)os << "(";
		os << numerator << "/" << denominator;
		if (integer)os << ")";
	}
	else if (integer == 0)os << 0;
	//os << endl;
	return os;
}


Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const  Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}


Fraction  operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	((left.get_numerator() * right.get_denominator() + left.get_denominator() * right.get_numerator()),
		(left.get_denominator() * right.get_denominator())
	).reduce().to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	((left.get_numerator() * right.get_denominator() - left.get_denominator() * right.get_numerator()),
		(left.get_denominator() * right.get_denominator())
	).reduce().to_proper();
}


//////////////////////////////////////////////////////////////////
//////					Comparison operators				//////
//////////////////////////////////////////////////////////////////
//6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;
bool operator==(Fraction left, Fraction right)
{

	return
		left.to_proper().get_integer() == right.to_proper().get_integer() &&
		left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right); //НЕ равно
}

bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left < right);	//Больше или равно - это НЕ меньше
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	//return left < right || left == right;
	return !(left > right);
}

/////////////////////////////////////////////////////////////////
//7. Перегрузить оператор ввода с клавиатуры;*/

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	return obj.print(os);
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj(integer, numerator, denominator);*/

	/*
		5;
		1/2;
		2(3/4);
		2 3/4;
	*/

	int number[3] = {};

	const int SIZE = 32;
	char buffer[SIZE] = {};
	char delimiters[] = "/ ()";

	//is >> buffer;
	is.getline(buffer, SIZE);

	int n = 0;	//счетчик чисел в веденной строке
	/*https ://legacy.cplusplus.com/reference/cstring/strtok/ */
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = atoi(pch);
	//функция atoi(...) ASCII-string to integer преобразует строку в число,
	//если строка является числом, т.е., содержит цифры.
	/* https: //legacy.cplusplus.com/reference/cstdlib/atoi/ */

	switch (n)
	{
	case 1:obj.set_integer(number[0]); break;
	case 2:
		obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);
		break;
	case 3:obj(number[0], number[1], number[2]);
	}

	return is;
}
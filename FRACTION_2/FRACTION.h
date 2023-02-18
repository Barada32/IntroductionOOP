#pragma once
#include<iostream>




using namespace std;
using std::cin;
using std::cout;
using std::endl;;


class Fraction;


class Fraction
{
	int integer;		//целая часть
	int numerator;		//числитель
	int denominator;	//знаменатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//					Constructors:


	///*В классе Fraction реализовать :
	//1. Конструкторы и вывод на экран;
	//5;		//double a = 5;
	//1 / 2;
	//2(3 / 4);
	Fraction();
	Fraction(double decimal);
	explicit Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//3. Перегрузить арифметические операторы : +, -, *, / ;
//4. Перегрузить операторы++ / --;
//5. Перегрузить составные присваивания : +=, -=, *=, /=;


	//				Operators:
	Fraction& operator()(int integer, int numerator, int denominator);

	Fraction& operator ++();//префикс
	Fraction& operator ++(int);//постфикс

	//5. Перегрузить составные присваивания : +=, -=, *=, /=;

	Fraction& operator=(const Fraction& other);

	Fraction& operator*=(const Fraction& other);
	Fraction& operator +=(const Fraction& other);
	Fraction& operator -=(const Fraction& other);

	Fraction& operator/=(const Fraction& other);

	//				Type-cast operators:
	explicit operator int()const;
	explicit operator double()const;

	//				Methods:
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	Fraction& reduce();
	std::ostream& print(std::ostream& os)const;

};


//////////////////////////////////////////////////////////////////
//////					Comparison operators				//////
//////////////////////////////////////////////////////////////////
//6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);

/////////////////////////////////////////////////////////////////
//7. Перегрузить оператор ввода с клавиатуры;*/

std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);

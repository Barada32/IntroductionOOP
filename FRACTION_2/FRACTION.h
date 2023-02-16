#pragma once
#include<iostream>
//#define _CRT_SECURE_NO_WARNINGS



using namespace std;
using std::cin;
using std::cout;
using std::endl;;


class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;		//����� �����
	int numerator;		//���������
	int denominator;	//�����������
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//					Constructors:


	///*� ������ Fraction ����������� :
	//1. ������������ � ����� �� �����;
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

	//3. ����������� �������������� ��������� : +, -, *, / ;
//4. ����������� ���������++ / --;
//5. ����������� ��������� ������������ : +=, -=, *=, /=;


	//				Operators:
	Fraction& operator()(int integer, int numerator, int denominator);

	Fraction& operator ++();//�������
	Fraction& operator ++(int);//��������

	//5. ����������� ��������� ������������ : +=, -=, *=, /=;

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
//6. ����������� ��������� ��������� : == , != , > , < , >= , <= ;
bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);

/////////////////////////////////////////////////////////////////
//7. ����������� �������� ����� � ����������;*/

std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);

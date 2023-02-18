#pragma once
#include<iostream>




using namespace std;
using std::cin;
using std::cout;
using std::endl;;


class Fraction;


class Fraction
{
	int integer;		//����� �����
	int numerator;		//���������
	int denominator;	//�����������
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
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
//7. ����������� �������� ����� � ����������;*/

std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);

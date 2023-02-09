#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;



class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;		//целая часть
	int numerator;		//числитель
	int denominator;	//знаменатель
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


	///*В классе Fraction реализовать :
	//1. Конструкторы и вывод на экран;
	//5;		//double a = 5;
	//1 / 2;
	//2(3 / 4);
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		this->integer = decimal;	//сохраняем целую часть
		decimal -= integer;			//убираем целую часть из десятичной дроби
		this->denominator = 1e+9;
		this->numerator = decimal * denominator;
		reduce();
		cout << "DConstructor:\t\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//3. Перегрузить арифметические операторы : +, -, *, / ;
//4. Перегрузить операторы++ / --;
//5. Перегрузить составные присваивания : +=, -=, *=, /=;


	//				Operators:
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	Fraction& operator ++()//префикс
	{
		integer++;
		numerator++;
		denominator++;
		return *this;
	}
	Fraction& operator ++(int)//постфикс
	{
		Fraction old = *this;
		integer++;
		numerator++;
		denominator++;
		return old;
	}

	//5. Перегрузить составные присваивания : +=, -=, *=, /=;

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator +=(const Fraction& other)
	{
		return*this = *this + other;


	}
	Fraction& operator -=(const Fraction& other)
	{
		return*this = *this - other;
	}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//				Type-cast operators:
	explicit operator int()const
	{
		return Fraction(*this).to_proper().integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//				Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
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
	std::ostream& print(std::ostream& os)const
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
};

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
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}


Fraction operator+(Fraction left, Fraction right)
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

/////////////////////////////////////////////////////////////////

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
#define COMPARISON_OPERATORS
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER

//#define HOME_WORK_1
//#define HOME_WORK_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(2, 3);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	double a = 2;
	double b = 3;
	double c = a * b;
	cout << "Создание дробей\n";
	Fraction A(1, 2, 3);
	Fraction B(1, 1, 3);
	cout << A;
	cout << B;



	Fraction C = A * B; cout << "Умножение дробей\n"; cout << C << endl;
	Fraction D = A / B; cout << "Деление дробей\n"; cout << D << endl;
	Fraction F = A - B; cout << "Вычитание дробей\n"; cout << F << endl;
	Fraction E = A + B; cout << "Сложение дробей\n"; cout << E << endl;


	A *= B; cout << "*= дробей\n"; cout << A << endl;
	A /= B; cout << "/= дробей\n"; cout << A << endl;
	A += A; cout << "+= дробей\n"; cout << A << endl;
	A -= B; cout << "-= дробей\n"; cout << A << endl;
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS
	cout << " <= дробей\n"<<(Fraction(1, 3) <= Fraction(5, 10)) << endl;
	cout << " == дробей\n" << (Fraction(1, 3) == Fraction(5, 10)) << endl;
	cout << " >= дробей\n" << (Fraction(1, 3) >= Fraction(5, 10)) << endl;
	cout << " < дробей\n" << (Fraction(1, 3) < Fraction(5, 10)) << endl;
	cout << " > дробей\n" << (Fraction(1, 3) > Fraction(5, 10)) << endl;
	

#endif // COMPARISON_OPERATORS

#ifdef TYPE_CONVERSIONS_BASICS
			//	(type)value;	//C-like notation (C-подобная форма записи)
//	type(value);	//Functional notation (Функциональная форма записи)

//cout << 7. / 2 << endl;

	int a = 2;		//No conversions
	double b = 3;	//Conversion from less to more
	int c = b;		//Conversion from more to less with no data loss
	int d = 4.5;	//Conversion from more to less with data loss  
#endif // TYPE_CONVERSIONS_BASICS

	/*
	-------------------------------------
	1. Преобразование другиъ типов в наш;
		Single-argument constructor;
		Assignment operator;
	2. Преобразование и нашего типа в другие типы;
	-------------------------------------
	*/

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;	//Conversion from other to class preformed by Single-argument constructor
	A.print();

	Fraction B;
	B = Fraction(8);			//Conversion from other to class preformed by Assignment operator
	B.print();

	//	explicit - явный  
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
			/*
-------------------------------------
Type-cast operators
operator type()const
{
	conversion algorithm;
	return ...;
}
-------------------------------------
*/

	Fraction A(11, 4);
	A.print();
	int a = (int)A;
	cout << a << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

#ifdef HOME_WORK_1
	Fraction B(2, 3, 4);
	double b = (double)B;
	cout << b << endl;
#endif // HOME_WORK_1

#ifdef HOME_WORK_2
	Fraction B = 2.75;
	//B.print(cout) << endl;;
	cout << B << endl;

	//Fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	///*
	//	5;
	//	1/2;
	//	2(3/4);
	//	2 3/4;
	//*/
	cout << A << endl;
#endif // HOME_WORK_2
}
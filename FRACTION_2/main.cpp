#include <iostream>
using namespace std;
#define delimetr "\n__________________________________\n"

/*В классе Fraction реализовать :
1. Конструкторы и вывод на экран;
5;		//double a = 5;
1 / 2;
2(3 / 4);
2. Написать методы :
Fraction & to_proper();	//целую часть интегрирует в числитель
Fraction& to_improper();//выделяет целую часть из числителя


3. Перегрузить арифметические операторы : +, -, *, / ;
4. Перегрузить операторы++ / --;
5. Перегрузить составные присваивания : +=, -=, *=, /=;
6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;
7. Перегрузить оператор ввода с клавиатуры;*/
int nod(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return nod(b, a % b);
}

class Fraction//структура 
{
	int integer;//целая
	int numerator;//числитиль
	int denominator;//знаменатель

public:

	int get_integer() const { return integer; }
	int get_numerator() const { return numerator; }
	int get_denominator() const { return denominator; }

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
	/*Constructor */

	Fraction(int integer = 0, int numerator = 1, int denominator = 1)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t" << this << endl;
	}




	/*Destructor*/
	~Fraction()
	{
		cout << "Destructor:\t " << this << endl;
	}


	/*Operators:*/
	Fraction& operator()(int a, int x, int y)
	{
		set_integer(a);
		set_numerator(x);
		set_denominator(y);
		return *this;

	}


		 /*methods*/
		 /*2. Написать методы :
		 Fraction & to_proper();	целую часть интегрирует в числитель*/
	Fraction& to_proper(const Fraction& A)
	{


		int proper = (A.get_integer() * A.get_denominator()) + A.get_numerator();
		int denominator = A.get_denominator();
		set_integer(0);
		set_numerator(proper);


		return*this;


	}
	/*Fraction& to_improper();выделяет целую часть из числителя*/
	Fraction& to_improper(const Fraction& A) 
	{
		int integer = A.get_integer();

		integer = A.get_numerator() / A.get_denominator();

		set_integer(integer);
		set_numerator(A.get_numerator() % A.get_denominator());


		return*this;



	}



	void print()const
	{
		if (integer == 0)
		{
			cout << "( " << numerator << "/ " << denominator << " )" << endl;
		}
		else
			cout << integer << "( " << numerator << "/ " << denominator << " )" << endl;
	}

};
/*3. Перегрузить арифметические операторы : +, -, *, / ;*/
Fraction operator+(const Fraction& left, const Fraction& right)
{
		Fraction res;

		int n1 = left.get_numerator(), d1 = left.get_denominator(), n2 = right.get_numerator(), d2 = right.get_denominator();
		int res_num = (n1 * d2) / nod(d1, d2) + (n2 * d1) / nod(d1, d2);
		int res_den = (d1 * d2) / nod(d1, d2);
		res.set_numerator(res_num / nod(res_num, res_den));
		res.set_denominator(res_den / nod(res_num, res_den));
		res.set_integer(left.get_integer() + right.get_integer());
		return res;
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction res;
	int n1 = left.get_numerator(), d1 = left.get_denominator(), n2 = right.get_numerator(), d2 = right.get_denominator();
	res.set_numerator((n1 * d2) / nod(d1, d2) - (n2 * d1) / nod(d1, d2));
	res.set_denominator((d1 * d2) / nod(d1, d2));
	res.set_integer(left.get_integer() - right.get_integer());
	return res;
}
Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction res;
	int n1 = left.get_numerator(), d1 = left.get_denominator(), n2 = right.get_numerator(), d2 = right.get_denominator();
	int res_num = n1 * n2;
	int res_den = d1 * d2;
	
	res.set_numerator(res_num/nod(res_num, res_den)) ;
	res.set_denominator(res_den / nod(res_num, res_den));
	res.set_integer(left.get_integer() * right.get_integer());
	
	return res;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction res;
	int n1 = left.get_numerator(), d1 = left.get_denominator(), n2 = right.get_numerator(), d2 = right.get_denominator();
	int res_num = n1 * d2;
	int res_den = d1 * n2;

	res.set_numerator(res_num / nod(res_num, res_den));
	res.set_denominator(res_den / nod(res_num, res_den));
	res.set_integer(left.get_integer() / right.get_integer());

	return res;
}


void main()
{
	setlocale(LC_ALL, "RUS");

	Fraction A(3, 4, 5);
	Fraction B(2, 1, 2);
	
	A.print();
	B.print();
	
	cout << delimetr << "C = A + B=\n" ;
	Fraction C = A + B;
	C.print();
	cout <<delimetr << "C = A - B=\n"  ;
	C = A - B;
	C.print();
	cout << delimetr << "C = A * B =\n";
	C = A * B;
	C.print();
	cout << delimetr << "C = A / B=\n" ;
	C = A / B;
	C.print();
	cout << delimetr << "целую часть интегрирует в числитель\n";
	A.to_proper(A);
	A.print();
	cout << delimetr << "целую часть вставляет в числитель\n";
	A.to_improper(A);
	A.print();
	cout << delimetr;
	
	
}	
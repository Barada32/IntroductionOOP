#include <iostream>
using namespace std;
#define delimetr "\n__________________________________\n"

/*� ������ Fraction ����������� :
1. ������������ � ����� �� �����;
5;		//double a = 5;
1 / 2;
2(3 / 4);
2. �������� ������ :
Fraction & to_proper();	//����� ����� ����������� � ���������
Fraction& to_improper();//�������� ����� ����� �� ���������


3. ����������� �������������� ��������� : +, -, *, / ;
4. ����������� ���������++ / --;
5. ����������� ��������� ������������ : +=, -=, *=, /=;
6. ����������� ��������� ��������� : == , != , > , < , >= , <= ;
7. ����������� �������� ����� � ����������;*/
int nod(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return nod(b, a % b);
}

class Fraction//��������� 
{
	int integer;//�����
	int numerator;//���������
	int denominator;//�����������

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

	
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;

	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor:\t" << this << endl;

	}
	Fraction(int numerator, int denominator)
	{

		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator ( denominator);
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}

	/*Destructor*/
	~Fraction()
	{
		cout << "Destructor:\t " << this << endl;
	}



	//Method

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
		
		int more, less, rest = 0;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	//GCD - Greates Common Divisor (���������� ����� ��������)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer)cout << integer;

		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}

};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;                                                                                                            

}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
//4. ����������� ������������ : =, +=, -=, *=, /=;
//bool operator==(const Point& left, const Point& right)
//{
//	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
//		return true;
//	else*/
//		return (left.get_x() == right.get_x() && left.get_y() == right.get_y());
//}
//bool operator!=(const Point& left, const Point& right)
//{
//	return!(left == right);


	void main()
	{
		setlocale(LC_ALL, "RUS");

		Fraction A;
		A.print();

		Fraction B = 5;
		B.print();
		Fraction C(2, 3);
		C.print();
		Fraction D(2, 3, 4);
		D.print();
		Fraction E = D;
		D.print();
	}
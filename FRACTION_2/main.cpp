#include<iostream>
#include "FRACTION.h"
#define _CRT_SECURE_NO_WARNINGS

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS
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
	cout<<A;

	Fraction B;
	B = Fraction(8);			//Conversion from other to class preformed by Assignment operator
	cout << B;

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
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;
#endif // HOME_WORK_2
}
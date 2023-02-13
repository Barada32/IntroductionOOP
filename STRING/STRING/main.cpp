#include<iostream>
#include"String.h"



#define BASE_CHECK
//#define CALLING_CONSTRUCTOR


void main()
{
	setlocale(LC_ALL, "");

	
#ifdef BASE_CHECK
	String str1(5);
	str1.print();

	str1 = "Hello";	//"Hello" - это строковая константа
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;
	String str3 = str1 + str2;
	String str4 = str3;
	str4.print();
#endif // BASE_CHECK
//
//	String str1;	//Default constructor
//	str1.print();
//	String str2 = "Hello";	//Single argument constructor
//	str2.print();
//	String str3 = str2;	//Copy constructor
//	str3.print();
//	String str4();	//Здесь не вызывается никакой конструктор, потому что НЕ создается объект,
//	//Здесь объявлется функция str4(), которая не принимает никаких параметров,
//	//и возвращает значение типа String.
////str4.print();	//str4 - это НЕ объект, это функция, а для функции нельзя вызвать метод.
////Если мы хотим явно вызвать конструктор по умолчанию, то это можно сделать так:
//	String str5{};	//Явный вызов конструктора по умолчанию.
//	str5.print();
//	String str6{ 22 };
//	str6.print();
//	String str7{ "World" };
//	str7.print();
//	String str8{ str7 };	//Copy constructor


}
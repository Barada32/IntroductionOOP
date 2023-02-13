#pragma once
#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;;
//////////////////////////////
///CLASS DECLARATION //////
//////////////////////////////
class String;
String  operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
class String
{
	int size;		//размер строки
	char* str; 		//адрес строки в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other)noexcept;

	~String();

	//operators
	String& operator =(const String& other);
	String& operator=(String&& other)noexcept;
	String& operator+=(const String& other);
	//				Methods:
	void print()const;
};

//////////////////////////////
///CLASS DECLARATION END//////
//////////////////////////////
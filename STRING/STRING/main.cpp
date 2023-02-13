#include<iostream>
using namespace std;
#define BASE_CHECK
//#define CALLING_CONSTRUCTOR
class String
{
	int size;		//размер строки
	char* str; 		//адрес строки в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//				Constructors:
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str) :String(strlen(str)+1)
	{
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "1ArgConstructor: \t" << this << endl;
	}
	String(const String& other): String(other.str)
	{
		//Deep copy - побитовое копирование
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << endl;
	}
	String(String&& other)noexcept:size(other.size),str(other.str)
	{
		//Shallow Copy - поверхностное копирование
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor: " << this << endl;
	}

	~String()
	{
		delete this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//operators
	String& operator =(const String& other)
	{
		/*l value = r_value;*/
		if (this == &other)return *this;
		delete[]this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	} 
	String& operator=(String&& other)noexcept
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssigment:\t" << this << endl;
		return *this;
	}


	//				Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};
String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
	{
		cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return cat;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}


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
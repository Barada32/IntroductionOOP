#include"String.h"

int String::get_size()const
{
	return size;
}
const  char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//				Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "1ArgConstructor: \t" << this << endl;
}
String::String(const String& other) : String(other.str)
{
	//Deep copy - побитовое копирование
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << endl;
}
String::String(String&& other)noexcept :size(other.size), str(other.str)
{
	//Shallow Copy - поверхностное копирование
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor: " << this << endl;
}

String::~String()
{
	delete this->str;
	cout << "Destructor:\t" << this << endl;
}

//operators
String& String::operator =(const String& other)
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
String& String:: operator=(String&& other)noexcept
{
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssigment:\t" << this << endl;
	return *this;
}


//				Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}
String  operator+(const String& left, const String& right)
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
//////////////////////////////
///CLASS DEFINITION  END//////
//////////////////////////////
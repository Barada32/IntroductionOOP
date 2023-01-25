//Introduction OOP
#include <iostream>
using namespace std;
#define delimetr "\n__________________________________\n"
//#define DISTANCE_CHECK
//#define STRUCT_POINT 
//#define CONSTRUCTOR_CHECK
//#define ASSIGMENT_CHECK_1
//#define ASSIGMENT_CHECK_2 
#define OVERLOAD_OPERATORS_1
// 
//1. В классе Point написать get / set - методы;
//2. В классе Point написать метод ? ? ? distance(? ? ? ), 
// который возвращает расстояние до указанной точки;
//3. Написать функцию ? ? ? distance(? ? ? ), которая возвращает расстояние между двумя точками;



class Point//структура 
{
	double x;//переменные поля структуры
	double y;
public:
	double get_x() const { return x; }
	double get_y() const { return y; }
	void set_x(double x) { this -> x = x; }
	void set_y(double y) { this -> y = y; }
	//Constructor and Destructor

	//Point()
	//{
	//	x = y = 0;
	//	//RAII - Resourse Aqulisation is Initialisation
	//	//(Выделение ресурсов - значит инициализация)
	//	cout << "Constructor:\t " << this << endl;
	//}
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
	}
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor" << this << endl;
	}*/

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy_Constructor:\t " << this << endl;

	}

	
	~Point()
	{
		cout << "Destructor:\t " << this << endl;
	}
	//Operators:
	
	Point& operator =(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator ++()
	{
		x++;
		y++;
		return *this;
	}
	Point& operator ++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}


	//methods

	double distanse(const Point& other)const
	{
		double x_distanse = this->x - other.x;
		double y_distanse = this->y - other.y;
		double distanse = sqrt(x_distanse * x_distanse + y_distanse * y_distanse);
		return distanse;
	}
	void print()const
	{
		cout << "X= " << x << "\tY = " << y << endl;
	}

};
double distance(const Point& A,const Point& B)
{
	double x_distanse = A.get_x() - B.get_x();

	double y_distanse = A.get_y() - B.get_y();
	double distanse = sqrt(x_distanse * x_distanse + y_distanse * y_distanse);
	return distanse;
}
Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
	
}
void main()
{
	setlocale(LC_ALL, "RUS");
#ifdef STRUCT_POINT
	//обьявление обьекта(экземпляра) 'A' типа(структуры) Point;
	/*Point* pA = &A;
	cout << pA->x  << "\t" << pA->y << endl;*/
#endif
#ifdef DISTANCE_CHECK
	Point A;
	Point B;

	B.set_x(7);
	B.set_y(8);
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << delimetr << endl;
	cout << "растояние между точками А и В" << A.distanse(B) << endl;;
	cout << delimetr << endl;
	cout << "растояние между точками А и В" << B.distanse(A) << endl;;
	cout << delimetr << endl;
	cout << "растояние между точками А и В" << distance(A, B) << endl;;
	cout << delimetr << endl;
	cout <<"растояние между точками А и В" << distance(B, A) << endl;;
#endif
#ifdef CONSTRUCTOR_CHECK
	Point A; //Конструктор по умолчанию 
	/*cout << A.get_x() << "\t" << A.get_y() << endl;*/
	A.print();
	Point B(2, 3);
	B.print();
	Point C=4;
	C.print();
	Point D = C;
	D.print();
#endif	  
#ifdef ASSIGMENT_CHECK_1
	Point A(2, 3);
	A.print();

	Point B = A;//CopyConstructor
	B.print();

	Point C;
	C = B; //Assigment operator

#endif
#ifdef ASSIGMENT_CHECK_2
	int a, b, c;
	a = b = c = 0;
	cout << delimetr << endl;
	Point A, B, C;
	cout << delimetr << endl;
	A = B =  C = Point(2, 3);
	cout << delimetr << endl;


#endif // ASSIGMENT_CHECK_2
#ifdef  OVERLOAD_OPERATORS_1
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();
	++C;
	C.print();
	C++;
	C.print();
#endif //  OVERLOAD_OPERATORS_1

}
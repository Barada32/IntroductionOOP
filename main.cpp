//Introduction OOP
#include <iostream>
using namespace std;

//#define DISTANCE_CHECK
//#define STRUCT_POINT
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
	
	~Point()
	{
		cout << "Destructor:\t " << this << endl;
	}


	//methods

	double distanse(Point other)const
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
double distance(Point A, Point B)
{
	double x_distanse = A.get_x() - B.get_x();

	double y_distanse = A.get_y() - B.get_y();
	double distanse = sqrt(x_distanse * x_distanse + y_distanse * y_distanse);
	return distanse;
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
	cout << A.distanse(B) << endl;;
	cout << distance(A, B) << endl;;
#endif
	Point A; //Конструктор по умолчанию 
	/*cout << A.get_x() << "\t" << A.get_y() << endl;*/
	A.print();
	Point B(2, 3);
	B.print();
	Point C=4;
	C.print();

}
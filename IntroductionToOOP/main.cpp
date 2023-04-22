//IntroductionToOOP
#include <iostream>
using namespace std;

#define delimeter "\n----------------------------------------\n"

/*
Создавая структуру или класс, мы создаем новый тип данных,
пользовательский тип данных
В отличии от примитивных типов, 
которые могут хранить только одно определенной значение
поользовательские типы могут хранить множество разных значений,
которые и позволяют описывать объекты
					Класс - это тип данных
					Структура - это тип данных
*/

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//----------------------------------------------
	//					Constructor:
	//----------------------------------------------

	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//----------------------------------------------
	//					Operators:
	//----------------------------------------------

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	//----------------------------------------------
	//					Methods:
	//----------------------------------------------

	double distance(const Point& other)const // Point other - другой объект (другая точка)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//Функция distance
double distance(const Point& A,const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
//#define ASSIGMENT_CHECK

int main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;
	int a;			//Объявление переменной 'a' типа 'int'
	Point A;		//Объявление переменной 'A' типа 'Pount'
					//Объявление объекта 'A' структуры 'Point'
					//Создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(A) << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK
	Point A;
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;	//Single-argument constructor
	B.print();

	Point C(2,3);
	C.print();

	Point D = C; // Copy constructor (Deep copy) new
				 // Shallow copy
	D.print();

	Point E;
	E = D;		// Copy assigment (оператор присваивания)
#endif // CONSTRUCTORS_CHECK

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();
	cout << delimeter << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками А и В:   " << distance(A, B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками B и A:   " << distance(B, A) << endl;
	cout << delimeter << endl;
#endif // DISTANCE_CHECK

#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimeter << endl;
	A = B = C = Point(2, 3);
	cout << delimeter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGMENT_CHECK
}					

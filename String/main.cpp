#include<iostream>
using namespace std;

class String
{
	int size;	 //размер строки в байтах
	char* str;  //адрес строки в динамической памяти
public:
	// Constructors:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size]{};
		cout << "Constructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//	Methods:
	void print()const
	{
		cout << "Size:" << endl;
		cout << "Str:" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello String" << endl;
}
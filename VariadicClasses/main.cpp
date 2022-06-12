#include <iostream>
#include "Component1.h"

using namespace std;

template<class T>
void templateFunc(T a)
{
	cout << "a = " << a << "; Type of a is: " << typeid(a).name() << "; Size of a = " << sizeof(a) << endl;
}
void findVarMax()
{
	cout << "findVarMax() called" << endl;
}
template<class T, class... Ts>
void findVarMax(T a, Ts... b)
{
	cout << "a = " << a << "; Type of a is: " << typeid(a).name() << "; Size of a = " << sizeof(a) << endl;
	findVarMax(b...);
}
// with initializer list, all params must be the same type
template <class T>
void func2(std::initializer_list<T> list)
{
	for (auto elem : list)
	{
		std::cout << elem << std::endl;
	}
}

int main()
{
	int i = 4;
	//templateFunc(i);
	double d = 4;
	//templateFunc(d);
	char c = 'f';
	Component1<int,double,char> c1;
	c1.findVarMax(i, d, c); // does not work to be called recursively
	//c1.findVarMaxLoc(i, d, c);

	//findVarMax(i, d, c);
	//func2({ 10, 20, 30, 40 });
}


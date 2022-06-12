#pragma once
#include <iostream>
using namespace std;

template<class T,class... Ts >
class Component1
{
public:
	Component1();

	void findMax(T b);
	void findVarMax(T a)
	{
		std::cout << "findVarMax: " <<a << std::endl;
	}
	void findVarMax(T a,Ts... b);

	// To be able to reqursively call the variadic function, it must be of different
	// template parameters than the class
	template <typename U>
	void findVarMaxLoc(U t)
	{
		cout << "a = " << t << "; Type of a is: " << typeid(t).name() << "; Size of a = " << sizeof(t) << endl;
		cout << "maxElemSize = " << maxElemSize << endl;
	}
	template<class U, class... Us>
	void findVarMaxLoc(U a, Us... b);

	static int maxElemSize;
};

template<class T, class... Ts >
int Component1<T, Ts...>::maxElemSize = 0;

template<class T, class... Ts>
Component1<T,Ts...>::Component1()
{
	cout << "Component1 created" << endl;
}

template<class T, class... Ts>
void Component1<T, Ts...>::findMax(T b)
{

}

template<class T, class... Ts>
void Component1<T, Ts...>::findVarMax(T a, Ts... b)
{
	//cout << "a = " << a << "; Type of a is: " << typeid(a).name() << "; Size of a = " << sizeof(a) << endl;
	findVarMaxLoc(a, b...);// call this similar function. it can be called reqursively
	//findVarMax(b...); // cannot be called reqursively
}

template<class T, class ...Ts>
template<class U, class ...Us>
void Component1<T, Ts...>::findVarMaxLoc(U a, Us ...b)
{
	if (maxElemSize < sizeof(a))
	{
		maxElemSize = sizeof(a);
	}
	cout << "a = " << a << "; Type of a is: " << typeid(a).name() << "; Size of a = " << sizeof(a) << endl;
	findVarMaxLoc(b...); // can be called reqursively, because the template type is different from the class types
}

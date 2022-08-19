// FriendFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class A {
	int a, b;
public:
	friend int sum(A x);
	void set_ab(int i, int j);
};
void  A::set_ab(int i, int j)
{
	a = i;
	b = j;
}
int sum(A x)          // Note: sum() is not a member function of any class.
{
	/* Because sum() is a friend of class A, it can directly access a and b. */
	return x.a + x.b;
}
int main()
{
	A n;
	n.set_ab(3, 4);
	cout << sum(n);
	return 0;
}


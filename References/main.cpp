#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int& ra = a;
	ra += 3;
	cout << a << endl;
	a += 3;
	cout << ra << endl;
	cout << &a << endl;
	cout << &ra << endl;



}
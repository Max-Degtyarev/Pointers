#include<iostream>
using namespace std;

//int sum(int count, int number, ...);
//int product(int number, ...);

int summ(int number, ...)
{
	int s = 0;
	for (int* pa = &number; *pa != 0; pa++)
	{
		s += *pa;
	}
	return s;
}
int product(int number, ...)
{
	int s = 1;
	for (int* pa = &number; *pa != 0; pa++)
	{
		s *= *pa;
	}
	return s;
}

void funk(int* n)
{
	*n = 2;

}


void main()
{
	setlocale(LC_ALL, "");
	/*cout << "Сумма: " << sum(5, 3, 5, 8, 13, 21) << endl;
	cout << "Произведение: " << product(3, 5, 8, 0);*/

	cout << "Результат сложения: " << summ(3, 5, 2, 10, 0) << endl;
	cout << "Результат умножения: " << product(3, 5, 2, 10, 0) << endl;

	int n = 1;
	cout << n << endl;
	funk(&n);
	cout << n << endl;


}

int sum(int count, int number, ...)
{
	// - count - кол-во параметров в списке аргументов
	// - number - первое слагаемое
	int sum = 0;
	int* p_number = &number; // получаем адрес первого слагаемого
	for (int i = 0; i < count; i++)
	{
		sum += *p_number;
		p_number++;

	}
	return sum;
}
int product(int number, ...)
{
	int product = 1;
	for (int* p_number = &number; *p_number != 0; p_number++)
	{
		product *= *p_number;
	}
	return product;

	
}

#include<iostream>
using namespace std;

int sum(int count, int number, ...);
int product(int number...);

void main()
{
	setlocale(LC_ALL, "");
	cout << "Сумма: " << sum(5, 3, 5, 8, 13, 21) << endl;
	cout << "Произведение: " << product(3, 5, 8, 13, 21, 0);

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
int product(int number...)
{
	int product = 1;
	for (int* p_number = &number; *p_number != 0; p_number++)
	{
		product *= *p_number;
	}
	return product;


}

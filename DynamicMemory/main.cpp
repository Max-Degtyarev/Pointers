#include<iostream>
using namespace std;
using std::cout;




//#define PUSH_BACK
#define PUSH_FRONT
//#define HOMEWORK
//#define HOMEWORK_2


#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);
int* push_back(int arr[], int n, int value);
int* push_front(int arr[], int n, int value);


//void Print(int arr[], int n);

void main()
{
	setlocale(LC_ALL, "");
#ifdef PUSH_BACK
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n+1);
	delete[] arr;
#endif


#ifdef PUSH_FRONT
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n+1);
	delete[] arr;
#endif




#ifdef HOMEWORK_2
	int m;		//количество добавляемых элементов
	int value;	//значение добавляемых элементов
	cout << "Введите количество добавляемых элементов: "; cin >> m;
	//cout << "Введите значение добавляемых элементов: "; cin >> value;
	
	int* buffer = new int[n + m];
	for (int i = 0; i < n; i++)
	{
		*(buffer + i) = *(arr + i);
	}
	delete[] arr;
	arr = buffer;
	cout << "Введите значения добавляемых элементов (" << m << " шт):";
	for (int i = n; i < n + m; i++)
	{
		//arr[i] = value;
		cin >> arr[i];
	}
	/*int value1;
	int value2;
	cout << "Введите добавляемые значения через пробел: "; cin >> value1; cin >> value2;
	arr[n] = value1;
	arr[n + 1] = value2;*/
	//n++;
	//n++;
	n += m;
	Print(arr, n);
	delete[] buffer;

	/*const int SIZE = 5;
	int brr[SIZE];
	cout << typeid(brr).name() << endl;
	FillRand(brr, SIZE);
	Print(brr, SIZE);*/
#endif
		



#ifdef HOMEWORK
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 60;
	}
	cout << endl << "Исходный массив: " << endl;
	Print(arr, n);
	cout << endl << endl;

	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(arr + i) % 2 == 0)a++;
		else b++;
	}

	int* arr2 = new int[a];
	int* arr3 = new int[b];
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			//*(arr2) = arr[i];
			//arr2++;
			*arr2++ = arr[i];
		}
		else
		{
			arr3[k] = arr[i];
			k++;
		}
	}
	arr2 -= a;
	cout << "Массив с четными значениями: " << endl; Print(arr2, a); cout << endl << endl;
	cout << "Массив с нечетными значениями: " << endl; Print(arr3, b); cout << endl;
	
#endif

	/*int brr[] = { 3,5,8,13,21 };
	cout << typeid(brr).name() << endl;
	Print(brr, sizeof(brr) / sizeof(brr[0]));*/
}

//void Print(int arr[], int n)
//{
//	cout << typeid(arr).name() << endl;
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d %s", arr[i], " ");
//	}
//}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int* arr, const int n)
{
	//cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

}

int* push_back(int arr[], int n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		*(buffer + i) = *(arr + i);
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}

int* push_front(int arr[], int n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	return arr;

}






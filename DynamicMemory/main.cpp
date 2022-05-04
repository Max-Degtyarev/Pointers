#include<iostream>
using namespace std;
using std::cout;

#define tab "\t"

//#define PRINT_F

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);


#if defined PRINT_F
void Print(int arr[], int n);
#endif // PRINT_F

#if not defined PRINT_F
void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);

#endif // !PRINT_F

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int index, int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);




//#define PUSH_BACK
//#define PUSH_FRONT
//#define INSERT
//#define POP_BACK
//#define POP_FRONT
//#define ERASE
//#define HOMEWORK
//#define HOMEWORK_2
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1

#ifdef PUSH_BACK
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
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
	Print(arr, n);
	delete[] arr;
#endif



#ifdef INSERT
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int index, value;
	cout << "Введите индекс для вставки значения: "; cin >> index;
	cout << "Введите значение: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);
	delete[] arr;
#endif


#ifdef POP_BACK
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;
	cout << "Массив с удаленным последним элементом" << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	delete[] arr;
#endif


#ifdef POP_FRONT
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;
	cout << "Массив с удаленным нулевым элементом" << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	delete[] arr;
#endif


#ifdef ERASE
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;
	int index;
	cout << "Введите индекс значения которое необходимо удалить: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);
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

#endif	DYNAMIC_MEMORY_1

	int rows; // количество строк
	int cols; // количество элементов строки
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	//1) Создаем массив указателей
	int** arr = new int* [rows];
	
	//2) Создаем строки
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}


#ifdef PRINT_F
void Print(int arr[], int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		printf("%d %s", arr[i], " ");
	}
}
#endif // PRINT_F

#if not defined PRINT_F
void Print(int* arr, const int n)
{
	//cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

#endif

int* push_back(int arr[], int& n, int value)
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

int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;

}

int* insert(int arr[], int& n, int index, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		/*if (i < index)buffer[i] = arr[i];
		else buffer[i + 1] = arr[i];*/
		//(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		if (i < index)buffer[i] = arr[i];
		else buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;

}


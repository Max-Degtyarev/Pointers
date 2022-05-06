#include<iostream>
using namespace std;
using std::cout;

#define tab "\t"



void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols, int maxRand = 100, int minRand = 10);



//void Print(int arr[], int n);
//void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);



int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int index, int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);

int** Allocate(int rows, int cols);
int** Allocate_2(int rows, int cols);
int** Allocate_3(int& rows, int cols);
int** Allocate_plus_col(int rows, int& cols);
int** Allocate_sub_col(int rows, int& cols);

int** push_row_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int cols);
int** insert_row(int** arr, int& rows, int cols, int index);
int** pop_row_back(int** arr, int& rows, int cols);
int** pop_row_front(int** arr, int& rows, int cols);
int** erase_row(int** arr, int& rows, int cols, int index_2);
int** push_col_back(int** arr, int rows, int& cols);
int** push_col_front(int** arr, const int rows, int& cols);
int** insert_col(int** arr, int rows, int& cols, int index_3);
int** pop_col_back(int** arr, int rows, int& cols);
int** pop_col_front(int** arr, int rows, int& cols);
int** erase_col(int** arr, int rows, int& cols, int index_4);
void Clear(int** arr, const int rows, const int cols);


//#define PUSH_BACK
//#define PUSH_FRONT
//#define INSERT
//#define POP_BACK
//#define POP_FRONT
//#define ERASE
//#define HOMEWORK
//#define HOMEWORK_2
//#define DYNAMIC_MEMORY_1
//#define CLASSWORK


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

#ifdef CLASSWORK
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
#endif

	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов: "; cin >> cols;
	
	int** arr = Allocate(rows, cols);
	
	FillRand(arr, rows, cols);
	
	Print(arr, rows, cols);

	cout << endl << "Добавление строки в конец массива" << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Добавление строки в начало массива" << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	int index;
	cout << endl << "Введите индекс строки для добавления: ";
	do
	{
		cin >> index;
		if (index < 0 || index > rows)cout << "\aВы ввели неправильный индекс" << endl;

	} while (index < 0 || index > rows);
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << endl << "Удаление последней строки массива" << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	cout << endl << "Удаление первой строки массива" << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	int index_2;
	cout << endl << "Введите индекс строки для удаления: ";
	do
	{
		cin >> index_2;
		if (index_2 < 0 || index_2 > rows - 1)cout << "\aВы ввели неправильный индекс" << endl;

	} while (index_2 < 0 || index_2 > rows - 1);
	arr = erase_row(arr, rows, cols, index_2);
	Print(arr, rows, cols);

	cout << endl << "Добавление столбца в конец массива" << endl;
	arr = push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Добавление столбца в начало массива" << endl;
	arr = push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	int index_3;
	cout << endl << "Введите индекс столбца для добавления: "; cin >> index_3;
	arr = insert_col(arr, rows, cols, index_3);
	Print(arr, rows, cols);

	cout << endl << "Удаление последнего столбца массива" << endl;
	arr = pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Удаление первого столбца массива" << endl;
	arr = pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	int index_4;
	cout << endl << "Введите индекс столбца для удаления: "; cin >> index_4;
	arr = erase_col(arr, rows, cols, index_4);
	Print(arr, rows, cols);

	Clear(arr, rows, cols);
}


int** Allocate(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}

int** Allocate_2(int rows, int cols)
{
	/*int** buffer = new int* [++rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols];
	}
	return buffer;*/
	return Allocate(rows + 1, cols);
}

int** Allocate_3(int& rows, int cols)
{
	/*int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols];
	}
	return buffer;*/
	return Allocate(--rows, cols);
}

int** Allocate_plus_col(int rows, int& cols)
{
	/*int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1];
	}
	cols++;
	return buffer;*/
	cols++;
	return Allocate(rows, cols);
}

int** Allocate_sub_col(int rows, int& cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1];
	}
	cols--;
	return buffer;
}





void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void FillRand(int** arr, const int rows, const int cols, int maxRand, int minRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}



//void Print(int arr[], int n)
//{
//	cout << typeid(arr).name() << endl;
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d %s", arr[i], " ");
//	}
//}
//
//
//
//void Print(int* arr, const int n)
//{
//	//cout << typeid(arr).name() << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << tab;
//	}
//	cout << endl;
//}



void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*arr + j) << " ";
		}
		arr++;
		cout << endl;
	}
}

int** push_row_back(int** arr, int& rows, int cols)
{
	int** buffer = Allocate_2(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int j = 0; j < cols; j++)
	{
		buffer[rows][j] = rand() % 90 + 10;
	}
	rows++;
	return arr;
}

int** push_row_front(int** arr, int& rows, int cols)
{
	int** buffer = Allocate_2(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i + 1][j] = arr[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int j = 0; j < cols; j++)
	{
		buffer[0][j] = rand() % 90 + 10;
	}
	rows++;
	return arr;
}

int** insert_row(int** arr, int& rows, int cols, int index)
{
	int** buffer = Allocate_2(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i < index ? i : i + 1][j] = arr[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int j = 0; j < cols; j++)
	{
		buffer[index][j] = rand() % 90 + 10;
	}
	rows++;
	return arr;
}

int** pop_row_back(int** arr, int& rows, int cols)
{
	int** buffer = Allocate_3(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}

int** pop_row_front(int** arr, int& rows, int cols)
{
	int** buffer = Allocate_3(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i + 1][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}

int** erase_row(int** arr, int& rows, int cols, int index_2)
{
	int** buffer = Allocate_3(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i < index_2 ? i : i + 1][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}

int** push_col_back(int** arr, int rows, int& cols)
{
	int** buffer = Allocate_plus_col(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = 0; i < rows; i++)
	{
		for (int j = cols - 1; j < cols; j++)
		{
			buffer[i][j] = rand() % 90 + 10;
		}
	}
	return arr;
}

int** push_col_front(int** arr, int rows, int& cols)
{
	int** buffer = Allocate_plus_col(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			buffer[i][j] = rand() % 90 + 10;
		}
	}
	return arr;
}

int** insert_col(int** arr, int rows, int& cols, int index_3)
{
	int** buffer = Allocate_plus_col(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j < index_3 ? j : j + 1] = arr[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = 0; i < rows; i++)
	{
		buffer[i][index_3] = rand() % 90 + 10;
	}
	return arr;
}

int** pop_col_back(int** arr, int rows, int& cols)
{
	int** buffer = Allocate_sub_col(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}

int** pop_col_front(int** arr, int rows, int& cols)
{
	int** buffer = Allocate_sub_col(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}

int** erase_col(int** arr, int rows, int& cols, int index_4)
{
	int** buffer = Allocate_sub_col(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j < index_4 ? j : j + 1];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}

void Clear(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

























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




#include <iostream>													//базовая библиотека плюсов, можно сказать
#include <ctime>													//библиотека для работы генератора рандомных чисел
using namespace std;													//чтобы постоянно не писать std::


int main()
{
	int Yes = 0;													//переменная чтоб программу потом перезапускать не в новой консольке  
	while (Yes == 0)												//см. выше
	{
		srand(time(0));												//сбрасывает генератор рандомных чисел - позволяет получать новые рандомные числа при новом запуске программы - иначе будут те же самые числа при повторном запуске проги
		int Size = 0, i, Num = 0;										//Size - размер массивов - количество точек. Num - количество точек внутри круга
		float pi;												//инициализация переменной в которой будет наше вычисленное значение числа пи
		cout << "Enter the number of points\n";
		cin >> Size;												//Вводим количество точек
		float* X = new float[Size], * Y = new float[Size];							//делаем два динамическим массива, тип данных в массивах - float
		for (i = 0; i < Size; i++)										//Заполняем эти два массива рандомными цифрами от 0 до 1 (Пример: 0.2739571923)
		{
			X[i] = 0.0 + 1.0 * rand() / (float)RAND_MAX;
			Y[i] = 0.0 + 1.0 * rand() / (float)RAND_MAX;
		}
		float x, y;
		i = 0;
		while (i < Size)											//Считаем сколько точек входит внутрь круга по формуле в строке 28. Если точка входит, то мы увеличиваем счетчик Num,и идем к следующей точке
		{
			x = X[i];
			y = Y[i];
			if ((x * x) + (y * y) <= 1.0)
			{
				Num = Num + 1;
				i += 1;
			}
			else i += 1;
		}
		pi = (4 * Num) / float(Size);										//Считаем наше число Пи. От запуска к запуску для одного и того же количества точек ответ будет розниться - это нормально
		cout << pi;
		cout << "\nNumber of points in circle\n" << Num;
		cout << "\nReplay? Yes - 0, No - 1\n";
		cin >> Yes;
	}

}

#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>

#include "Lab01.h"
#include "Lab02.h"
#include "Lab03.h"


int main() {
	srand(time(NULL));
	SetConsoleOutputCP(CP_UTF8);
	int a = -1;
	while (a != 0) {
		printf("Список лабораторных работ:\n"
			"1.Lab01 (Сортировка)\n "
			"1-1.Пузырьковая сортировка\n 1-2.Шейкерная сортировка\n 1-3.Сортировка расчёской\n"
			"2.Lab02 (Битовые операции)\n "
			"2-1.Действия с числом\n 2-2.Дамп (short, int, long long)\n 2-3.Дамп (float , double, long double)\n"
			"3.Lab03 (Работа со строками)\n "
			"3-1.Тестирование функции strlen\n 3-2.Тестирование функции strcmp\n 3-3.Тестирование функции strdel\n 3-4.Тестирование функции strins\n 3-5.Тестирование функции strcopy\n 3-6.Тестирование функции strpos\n>>");
		scanf_s("%d", &a);
		Clear();
		switch (a)
		{
		case 1: Hello1(); break;
		case 2: Hello2(); break;
		case 3: Hello3(); break;
		default: break;
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <ctime>
#include "Lab01.h"
#include "Lab02.h"
#include "Lab03.h"

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "ru"); 
    int a = -1;
    while (a != 0) {
        printf("������ ������������ �����:\n"
            "1.Lab01 (����������)\n "
            "1-1.����������� ����������\n 1-2.��������� ����������\n 1-3.���������� ���������\n"
            "2.Lab02 (������� ��������)\n "
            "2-1.�������� � ������\n 2-2.���� (short, int, long long)\n 2-3.���� (float , double, long double)\n"
            "3.Lab03 (������ �� ��������)\n "
            "3-1.������������ ������� strlen\n 3-2.������������ ������� strcmp\n 3-3.������������ ������� strdel\n 3-4.������������ ������� strins\n 3-5.������������ ������� strcopy\n 3-6.������������ ������� strpos\n>>");
        scanf_s("%d", &a);
        switch (a)
        {
        case 1: system("cls"); Hello1(); break;
        case 2: system("cls"); Hello2(); break;
        case 3: system("cls"); Hello3(); break;
        default: system("cls"); break;
        }
    }
	return 0;
}
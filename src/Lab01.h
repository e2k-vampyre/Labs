#include <Windows.h>
#define N 10 //Количество чисел
#define D 10 // -D..D 
#define T 250 //Таймер


int* Array_Sort() {
    int* A = new int[N];
    for (int i = 0; i < N; i++) {
        int temp = rand() % (D * 2) + 1 - (D + 1);
        while (temp == 0) temp = rand() % (D * 2) + 1 - (D + 1);
        A[i] = temp;
    }
    return A;
}
void SetColor(int i) {
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, i | 0);
}
void Visual_Sort(int* A, int a, int b) {
    for (int i = D; i >= -D; i--) {
        printf("%d\t", i);
        for (int j = 0; j < N; j++) {
            if (i == 0) printf("%s", "==");
            else if (i > 0 && A[j] >= i) {
                if (j == a || j == b) SetColor(4);
                printf("* ");
            }
            else if (i < 0 && A[j] <= i) {
                if (j == a || j == b) SetColor(4);
                printf("* ");
            }
            else printf("  ");
            SetColor(15);
        }
        printf("\n");
    }
    printf(" \t");
    for (int i = 0; i < N; i++) {
        if (i == a || i == b) SetColor(4);
        printf("%d ", A[i]);
        SetColor(15);
    }
}
void Bubble_sort() {
    int* A = Array_Sort();
    int a = 0;
    Visual_Sort(A, -1, -1);
    Sleep(T);
    while (a != N - 1) {
        for (int i = 1; i < N - a; i++) {
            if (A[i - 1] > A[i]) {
                int temp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = temp;
                system("cls");
                Visual_Sort(A, i - 1, i);
                Sleep(T);
            }
        }
        a++;
    }
    system("cls");
    Visual_Sort(A, -1, -1);
    printf("\n");
}
void Shaker_sort() {
    int* A = Array_Sort();
    int a = 0;
    Visual_Sort(A, -1, -1);
    Sleep(T);
    while (a != N / 2) {
        int max = a;
        int min = N - 1 - a;
        for (int i = a; i < N - 1; i++) {
            if (A[max] <= A[i + 1]) {
                max = i + 1;
                continue;
            }
            else {
                int temp;
                temp = A[i + 1];
                A[i + 1] = A[max];
                A[max] = temp;
                max++;
                system("cls");
                Visual_Sort(A, max, -1);
                Sleep(T);
            }
        }
        for (int i = N - 1 - a; i > a; i--) {
            if (A[min] >= A[i - 1]) {
                min = i - 1;
                continue;
            }
            else {
                int temp;
                temp = A[i - 1];
                A[i - 1] = A[min];
                A[min] = temp;
                min--;
                system("cls");
                Visual_Sort(A, min, -1);
                Sleep(T);
            }
        }
        a++;
    }
    system("cls");
    Visual_Sort(A, -1, -1);
    printf("\n");
}
void Comb_sort() {
    int* A = Array_Sort();
    int l = N - 1, a = 0;
    Visual_Sort(A, -1, -1);
    Sleep(T);
    while (a != N - 1) {
        a = 0;
        for (int i = 0; i < N - 1; i++) {
            if (i + l >= N) break;
            if (A[i] <= A[i + l]) {
                a++;
                continue;
            }
            else if (A[i] > A[i + l]) {
                int temp;
                temp = A[i + l];
                A[i + l] = A[i];
                A[i] = temp;
                system("cls");
                Visual_Sort(A, i, i + l);
                Sleep(T);
            }
        }
        l /= 1.3;
    }
    system("cls");
    Visual_Sort(A, -1, -1);
    printf("\n");
}
void Hello1() {
    int a = -1;
    while (a != 0) {
        printf("1.Пузырьковая сортировка\n2.Шейкерная сортировка\n3.Сортировка расчёской\n>>");
        scanf_s("%d", &a);
        switch (a)
        {
        case 1: system("cls"); Bubble_sort(); break;
        case 2: system("cls"); Shaker_sort(); break;
        case 3: system("cls"); Comb_sort(); break;
        default: system("cls"); break;
        }
    }
}
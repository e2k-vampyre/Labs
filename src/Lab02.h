#include <fstream>
#define N 1000000

void Showbyte(const unsigned char* A, int size) {
    unsigned char mask = 128;
    A += size - 1;
    for (int i = size; i > 0; i--) {
        for (int j = 0; j < 8; j++) {
            if (j % 4 == 0 && j != 0) printf(" ");
            if (*A & (mask >> j)) printf("1");
            else printf("0");
        }
        printf("  ");
        A--;
    }
    printf("\n");
}
void DPOD(long long a,long long size) {
    long long mask = size * 8ll - 1ll;
    printf("Число %lld\n", a);
    printf("DUMP|");
    unsigned char* A = (unsigned char*)&a;
    Showbyte(A, size);
    if (a < 0) {
        a = ~a + 1ll;
        a |=  (1ll << mask);
        printf("  ПК|");
        Showbyte(A, size);
        a &= ~(1ll << mask);
        a = ~a;
        printf("  ОК|");
        Showbyte(A, size);
        a +=1;
        printf("  ДК|");
        Showbyte(A, size);
    }
    else {
        printf("  ПК|");
        Showbyte(A, size);
        printf("  ОК|");
        Showbyte(A, size);
        printf("  ДК|");
        Showbyte(A, size);
    }
}
void DUMP_float(float a,int size) {
    printf("Число %Lf\n", a);
    unsigned char* A = (unsigned char*)&a;
    printf("DUMP|");
    Showbyte(A, size);
}
void DUMP_double(long double a, int size) {
    printf("Число %Lf\n", a);
    unsigned char* A = (unsigned char*)&a;
    printf("DUMP|");
    Showbyte(A, size);
}

void Lab201(){
    short number;
    int select = -1;
    printf("Введите число [-32000;32000]:\n>>");
    scanf_s("%hd", &number);
    while (select != 0) {
        printf("%hd |", number);
        unsigned char* A = (unsigned char*)&number;
        Showbyte(A, sizeof(number));
        printf("1.Установить бит в 1\n2.Сбросить бит в 0\n3.Опросить бит\n4.Изменить бит\n0.Выход\n>>");
        scanf_s("%d", &select);
        switch (select) {
        case 1: {
            int a;
            printf("Введите номер бита:\n>>");
            scanf_s("%d", &a);
            number |= 1 << 16 - a;
            break;
        }
        case 2: {
            int a;
            printf("Введите номер бита:\n>>");
            scanf_s("%d", &a);
            number &= ~(1 << 16 - a);
            break;
        }
        case 3: {
            int showbit;
            printf("Введите номер бита:\n>>");
            scanf_s("%d", &showbit);
            printf("%hd |", number);
            for (int i = 1; i < 17; i++) {
                if (i % 5 == 0) printf(" ");
                if (i % 9 == 0) printf("  ");
                if (i == showbit)
                    if (number & 1 << 16 - showbit) printf("1");
                    else printf("0");
                else printf(" ");
            }
            printf("\n");
            break;
        }
        case 4: {
            int a;
            printf("Введите номер бита:\n>>");
            scanf_s("%d", &a);
            number ^= 1 << 16 - a;
            break;
        }
        }
    }
    system("cls");
}
void Lab202() {
    printf("Введите число short:\n>>");
    short a;
    scanf_s("%hi", &a);
    DPOD(a, sizeof(a));
    DPOD(-a, sizeof(a));
    printf("Введите число int:\n>>");
    int b;
    scanf_s("%i", &b);
    DPOD(b, sizeof(b));
    DPOD(-b, sizeof(b));
    printf("Введите число long long:\n>>");
    long long c;
    scanf_s("%lld", &c);
    printf("%d", sizeof(c));
    DPOD(c, sizeof(c));
    DPOD(-c, sizeof(c));
}
void Lab203() {
    float s;
    printf("Введите число float:\n>>");
    scanf_s("%f", &s);
    DUMP_float(s, sizeof(s));
    DUMP_float(-s, sizeof(s));
    double e;
    printf("Введите число double:\n>>");
    scanf_s("%lf", &e);
    DUMP_double(e, sizeof(e));
    DUMP_double(-e, sizeof(e));
    long double f;
    printf("Введите число long double:\n>>");
    scanf_s("%Lf", &f);
    DUMP_double(f, sizeof(f));
    DUMP_double(-f, sizeof(f));
}
void Lab204() {
    unsigned char prime[N / 8];
    std::ofstream outfile;
    outfile.open("D:\\Program\\LabProject\\LabProject\\4.txt");
    for (int i = 0; i < N / 8; i++) prime[i] = 0xFF;
    for (int i = 2; i * i < N / 2; i++) {
        if (prime[i / 8] & 1 << 8 - i % 8) {
            for (int j = i + i; j < N; j += i) {
                prime[j / 8] ^= prime[j / 8] & 1 << 8 - j % 8;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (prime[i / 8] & 1 << 8 - i % 8)
            outfile << i << " ";
        if (i % 100 == 0)
            outfile << "\n";
    }
}

void Hello2() {
    int v = -1;
    while (v != 0) {
        printf("1.Действия с short\n2.Дамп (short, int, long long)\n3.Дамп (float , double, long double)\n>>");
        scanf_s("%d", &v);
        switch (v)
        {
        case 1: system("cls"); Lab201(); break;
        case 2: system("cls"); Lab202(); break;
        case 3: system("cls"); Lab203(); break;
        case 4: system("cls"); Lab204(); break;
        default: system("cls"); break;
        }
    }
}

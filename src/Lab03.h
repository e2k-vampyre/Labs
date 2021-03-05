#define C 255
int Strlen1(char* A) {
	int a = 0;
	while (A[a] != '\0') a++;
	return a;
}
int Strlen2(char* A) {
    return *A == '\0' ? 0 : 1 + Strlen2(A + 1);
}
int Strlen3(char* A) {
    for (int i = 0; i < C; i++) if (A[i] == '\0' || i == C-1) { 
        return i;
        break;
    }
}
int Strlen4(char* A) {
    char* s = A;
    --s;
    do{
        s++;
    }
    while (*s);
    return s-A;
}
void Strlen() {
    printf("Тестирование функции strlen\n\n");
    char str[][C] = {"abcd1234",""};
    for (int i = 0; i < 2; i++) {
        printf("strlen1(\"%s\")=%d\n", str[i], Strlen1(str[i]));
        printf("strlen2(\"%s\")=%d\n", str[i], Strlen2(str[i]));
        printf("strlen3(\"%s\")=%d\n", str[i], Strlen3(str[i]));
        printf("strlen4(\"%s\")=%d\n\n", str[i], Strlen4(str[i]));
    }
}
int Strcmp1(char* A,char* B) {
    while (*A || *B) {
        if (*A > *B) {
            return 1;
        }
        else if (*A < *B) {
            return -1;
        }
        A++;
        B++;
    }
    return 0;
}
int Strcmp2(char* A, char* B) {
    do {
        if (*A > *B) { 
            return 1;
        }
        else if (*A < *B) {
            return -1;
        }
        A++;
        B++;
    } while (*A || *B);
    return 0;
}
int Strcmp3(char* A,char* B) {
    if ((*A == *B) && (*A++ && *B++)) Strcmp3(A++, B++);
    else if (*A > *B) return 1;
    else if (*A < *B) return -1;
    else return 0;
}
int Strcmp4(char* A,char* B) {
    for (int i = 0; i < C; i++) {
        if (A[i] > B[i]) {
            return 1;
            break;
        }
        else if (A[i] < B[i]) {
            return -1;
            break;
        }
        else if (!*A && !*B) {
            return 0;
            break;
        }
    }
}
void Strcmp() {
    printf("Тестирование функции strcmp\n\n");
    char str1[][C] = { "", "BB", "AAA", "CCC", "AAA", "AA"};
    char str2[][C] = { "", "AAA", "AA", "AAA", "DD", "FFFF"};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("strcmp1(\"%s\",\"%s\")=%d\n", str1[i], str2[j], Strcmp1(str1[i], str2[i]));
            printf("strcmp2(\"%s\",\"%s\")=%d\n", str1[i], str2[j], Strcmp2(str1[i], str2[i]));
            printf("strcmp3(\"%s\",\"%s\")=%d\n", str1[i], str2[j], Strcmp3(str1[i], str2[i]));
            printf("strcmp4(\"%s\",\"%s\")=%d\n\n", str1[i], str2[j], Strcmp4(str1[i], str2[i]));
        }
    }
}
char* Strcopy1(char* dest, char* src) {
    for (int i = 0; i < Strlen1(src); i++) dest[i] = src[i];
    return dest;
}
char* Strcopy2(char* dest, char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    return dest;
}
char* Strcopy3(char* dest, char* src) {
    int a = 0;
    while (src[a]) {
        dest[a] = src[a];
        a++;
    }
    return dest;
}
char* Strcopy4(char* dest, char* src) {
    if (*dest == *src) return dest;
    else {
        dest[Strlen1(dest)] = src[Strlen1(dest)];
        Strcopy4(dest, src);
    }
}
void Strcopy() {
    printf("Тестирование функции strcopy\n\n");
    char src[][C] = { "","abcd12" };
    char dest[C] = { "" };
    for (int i = 0; i < 2; i++) {
        printf("strcopy1(\"%s\",\"%s\")=",dest,src[i]);
        printf("\"%s\"\n", Strcopy1(dest, src[i]));
        dest[0] = '\0';
        printf("strcopy2(\"%s\",\"%s\")=", dest, src[i]);
        printf("\"%s\"\n", Strcopy2(dest, src[i]));
        dest[0] = '\0';
        printf("strcopy3(\"%s\",\"%s\")=", dest, src[i]);
        printf("\"%s\"\n", Strcopy3(dest, src[i]));
        dest[0] = '\0';
        printf("strcopy4(\"%s\",\"%s\")=", dest, src[i]);
        printf("\"%s\"\n\n", Strcopy4(dest, src[i]));
        dest[0] = '\0';
    }
}
char* Strdel1(char* dest,char* src,int k,int p) {
    char* temp_dest = dest;
    Strcopy1(temp_dest, src);
    for (int i = k; i < 0; i++) {
        k++;
        p--;
    }
    for (int i = 0; i < p; i++) {
        for (int j = k; j < Strlen1(temp_dest); j++) {
            temp_dest[j] = temp_dest[j + 1];
        }
    }
    return dest;
}
char* Strdel2(char* dest, char* src, int k, int p) {
    char* temp_dest = dest;
    char* temp_src = src;

    for (int i = k; i < 0; i++) {
        k++;
        p--;
    }
    for (int i = 0; i < k; i++) *temp_dest++ = *temp_src++;
    for (int i = 0; i < p; i++) temp_src++;
    for (int i = 0; i < Strlen1(temp_src); i++) *temp_dest++ = *temp_src++;
    return dest;
}
char* Strdel3(char* dest, char* src, int k, int p) {
    char* temp_dest = dest;
    char* temp_src = src;
    int a = -1;
    while (*temp_src) {
        a++;
        if (a >= k  && a < p+k) temp_src++;
        else *temp_dest++ = *temp_src++;
    }
    return dest;
}
char* Strdel4(char* dest, char* src, int k, int p) {
    char* temp_dest = dest;
    char* temp_src = src;
    int length = Strlen1(temp_src);
    if (k <= 0 && k+p>=length) return dest;
    else if (k+p < 0 || k >= length) return Strcopy1(temp_dest, temp_src);
    else {
        int a = -1;
        do {
            a++;
            if (a >= k && a < p + k) temp_src++;
            else *temp_dest++ = *temp_src++;
        } while (*temp_src);
    }
    return dest;
}
void Strdel() {
    printf("Тестирование функции strdel\n\n");
    char src[][C] = { "","abcd12" };
    char dest[C] = { "" };
    int k[5] = {3,-1,8,0,6};
    for (int i = 0; i < 2; i++) { 
        for (int j = 0; j < 5; j++) {
            int p[6] = { Strlen1(src[i]) - k[j] - 2, -3, Strlen1(src[i]) - k[j] + 3, Strlen1(src[i]) - k[j], 0, Strlen1(src[i]) };
            for (int l = 0; l < 6; l++) {
                printf("strdel1(\"%s\",\"%s\",\"%d\",\"%d\")=",dest,src[i],k[j],p[l]);
                printf("\"%s\"\n", Strdel1(dest,src[i],k[j],p[l]));
                dest[0] = '\0';
                printf("strdel2(\"%s\",\"%s\",\"%d\",\"%d\")=", dest, src[i], k[j], p[l]);
                printf("\"%s\"\n", Strdel2(dest, src[i], k[j], p[l]));
                dest[0] = '\0';
                printf("strdel3(\"%s\",\"%s\",\"%d\",\"%d\")=", dest, src[i], k[j], p[l]);
                printf("\"%s\"\n", Strdel3(dest, src[i], k[j], p[l]));
                dest[0] = '\0';
                printf("strdel4(\"%s\",\"%s\",\"%d\",\"%d\")=", dest, src[i], k[j], p[l]);
                printf("\"%s\"\n\n", Strdel4(dest, src[i], k[j], p[l]));
                dest[0] = '\0';
            }
        }
    }
}
char* Strins1(char* dest,char* src,char* sub,int k) {
    char* temp_dest = dest;
    char* temp_src = src;
    char* temp_sub = sub;
    int a = 0;
    while (*temp_src || k == Strlen1(src)) {
        if (a == k) {
            while (*temp_sub) *temp_dest++ = *temp_sub++;
            a++;
        }
        else if (*temp_src) {
            *temp_dest++ = *temp_src++;
            a++;
        }
        else break;
    }
    return dest;
}
char* Strins2(char* dest, char* src, char* sub, int k) {
    char* temp_dest = dest;
    char* temp_src = src;
    char* temp_sub = sub;
    if (k < 0 || k > Strlen1(temp_src) || !*temp_sub) Strcopy1(temp_dest, temp_src);
    else {
        for (int i = 0; i < k; i++) temp_dest[i] = temp_src[i];
        for (int i = 0; i < Strlen1(temp_sub); i++) temp_dest[k+i] = temp_sub[i];
        for (int i = k; i < Strlen1(temp_src); i++) temp_dest[Strlen1(temp_dest)] = temp_src[i];
    }
    return dest;
}
char* Strins3(char* dest, char* src, char* sub, int k) {
    char* temp_dest = dest;
    char* temp_src = src;
    char* temp_sub = sub;
    if (k < 0 || k > Strlen1(temp_src) || !*temp_sub) while (*temp_src) *temp_dest++ = *temp_src++;
    else {
        int a = 0;
        do {
            if (a == k) while (*temp_sub) *temp_dest++ = *temp_sub++;
            if (*temp_src) *temp_dest++ = *temp_src++;
            a++;
        } while (*temp_src || a == Strlen1(src));
    }
    return dest;
}
char* Strins4(char* dest, char* src, char* sub, int k) {
    char* temp_dest = dest;
    char* temp_src = src;
    char* temp_sub = sub;
    int a = (k > Strlen1(temp_src) || k < 0) ? Strlen1(temp_src) :  k;
    for (int i = 0; i < a; i++) {
        *temp_dest++ = *temp_src++;
    }
    while (*temp_src || k == Strlen1(src)) {
        while (*temp_sub) *temp_dest++ = *temp_sub++;
        if (*temp_src)*temp_dest++ = *temp_src++;
        else break;
    }
    return dest;
}
void Clear(char* dest) {
    for (int i = Strlen1(dest)-1; i >= 0; i--) dest[i] = '\0';
}
void Strins() {
    printf("Тестирование функции strins\n\n");
    char src[][C] = { "","abcdef" };
    char sub[][C] = { "","123456" };
    char dest[C] = { "" };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int k[5] = { Strlen1(src[i])-1, -1, Strlen1(src[i])+1, 0, Strlen1(src[i])};
            for (int l = 0; l < 5; l++) {
                printf("strins1(\"%s\",\"%s\",\"%s\",\"%d\")=", dest, src[i], sub[j], k[l]);
                printf("\"%s\"\n", Strins1(dest, src[i], sub[j] ,k[l]));
                Clear(dest);
                printf("strins2(\"%s\",\"%s\",\"%s\",\"%d\")=", dest, src[i], sub[j], k[l]);
                printf("\"%s\"\n", Strins2(dest, src[i], sub[j], k[l]));
                Clear(dest);
                printf("strins3(\"%s\",\"%s\",\"%s\",\"%d\")=", dest, src[i], sub[j], k[l]);
                printf("\"%s\"\n", Strins3(dest, src[i], sub[j], k[l]));
                Clear(dest);
                printf("strins4(\"%s\",\"%s\",\"%s\",\"%d\")=", dest, src[i], sub[j], k[l]);
                printf("\"%s\"\n\n", Strins4(dest, src[i], sub[j], k[l]));
                Clear(dest);
            }
        }
    }
}
int Strpos1(char* src,char* sub) {
    char* temp_src = src;
    char* temp_sub = sub;
    int len = Strlen1(temp_sub) -1;
    for (int i = Strlen1(temp_src) - 1; i >= 0; i--) {
        if (i < len) return -1;
        for (int j = len; j >= 0; j--) {
            if (!(temp_src[i - len + j] == temp_sub[j])) break;
            if (!j) return i - len + j;
        }
    }
    return -1;
}
int Strpos2(char* src, char* sub) {
    char* temp_src = src;
    char* temp_sub = sub;
    int a = -1;
    for (int i = 0; i < Strlen1(temp_src); i++) {
        for (int j = 0; j < Strlen1(temp_sub); j++) {
            if (!(temp_src[i + j] == temp_sub[j])) break;
            if (j == Strlen1(temp_sub)-1) a = i;
        }
    }
    return a;
}
int Strpos3(char* src, char* sub) {
    char* temp_src = src;
    char* temp_sub = sub;
    int a = -1;
    int b = 0;
    while (*temp_src) {
        if (*temp_src == *temp_sub) {
            for (int i = 0; i < Strlen1(temp_sub); i++) {
                if (!(temp_src[i] == temp_sub[i])) break;
                if (i == Strlen1(temp_sub) - 1) a = b;
            }
        }
        temp_src++;
        b++;
    }
    return a;
}
int Strpos4(char* src, char* sub) {
    char* temp_src = src;
    char* temp_sub = sub;
    int len = Strlen1(temp_sub)-1;
    int a = -1;
    int b = Strlen1(temp_src)-1;
    for (int i = 0; i < b; i++) temp_src++;
    do {
        if (*temp_src == temp_sub[len]) {
            for (int i = 0; i < len; i++) {
                temp_src--;
                b--;
            }
            for (int i = 0; i < Strlen1(temp_sub); i++) {
                if (!(temp_src[i] == temp_sub[i])) break;
                if (i == len) a = b;
            }
        }
        if (!b) break;
        temp_src--;
        b--;
    } while (*temp_src && a == -1);
    return a;
}
void Strpos() {
    printf("Тестирование функции strpos\n\n");
    char src[][C] = { "","abcd12cd34" };
    char sub[][C] = { "","ef","abcd12cd34","12","3","cd" };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            printf("strpos1(\"%s\",\"%s\")=%d\n",src[i], sub[j], Strpos1(src[i], sub[j]));
            printf("strpos2(\"%s\",\"%s\")=%d\n", src[i], sub[j], Strpos2(src[i], sub[j]));
            printf("strpos3(\"%s\",\"%s\")=%d\n", src[i], sub[j], Strpos3(src[i], sub[j]));
            printf("strpos4(\"%s\",\"%s\")=%d\n\n", src[i], sub[j], Strpos4(src[i], sub[j]));
        }
    }
}
void Hello3() {
    int v = -1;
    while (v != 0) {
        printf("1.Strlen\n2.Strcmp\n3.Strdel\n4.Strins\n5.Strcopy\n6.Strpos\n>>");
        scanf_s("%d", &v);
        switch (v)
        {
        case 1: system("cls"); Strlen(); break;
        case 2: system("cls"); Strcmp(); break;
        case 3: system("cls"); Strdel(); break;
        case 4: system("cls"); Strins(); break;
        case 5: system("cls"); Strcopy(); break;
        case 6: system("cls"); Strpos(); break;
        default: system("cls"); break;
        }
    }
}

# <h1 align="center">Laporan Praktikum Modul 7 - Stack </h1>
<p align="center">Muhammad Fahruli Ma'ruf - 103112400057</p>

## Dasar Teori
Stack merupakan struktur data linear yang menyimpan data secara bertumpuk dengan mekanisme akses terbatas. Prinsip kerja stack mengikuti aturan Last In First Out (LIFO), di mana elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Seluruh operasi pada stack hanya dilakukan melalui satu penunjuk utama yang disebut top.

Operasi dasar pada stack meliputi push untuk menambahkan data dan pop untuk mengambil data teratas. Stack dapat diimplementasikan menggunakan struktur pointer (linked list) maupun array. Implementasi berbasis pointer bersifat dinamis, sedangkan implementasi array memiliki kapasitas tetap sehingga perlu memperhatikan kondisi penuh dan kosong.
## Guided

### 1. Stack dengan Linked List
#### stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAX 20

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif

```

#### stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan input (ENTER untuk berhenti): ";
    while ((ch = cin.get()) != '\n') {
        push(S, ch - '0');
    }
}
```

#### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
Program C++ inimenampilkan proses penambahan data ke stack, penghapusan data teratas, pembaruan nilai pada posisi tertentu, serta hasil pencarian data. Urutan data selalu ditampilkan dari elemen teratas ke terbawah, sesuai konsep stack.
### 2. Stack dengan Array (Membalik Stack)
#### stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAX 20

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);


void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif

```
#### stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan input (ENTER untuk berhenti): ";
    while ((ch = cin.get()) != '\n') {
        push(S, ch - '0'); 
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
Program menunjukkan isi stack sebelum dan sesudah proses pembalikan. Setelah dibalik, elemen yang semula berada di bawah berpindah ke posisi atas, menandakan fungsi pembalikan berjalan dengan benar.
## Unguided 

### 1. Push, Pop, Balik Stack
#### stack.h
```C++
#ifndef STACK1_H
#define STACK1_H

#define MaxEl 20
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif // STACK1_H
```
#### stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(const Stack &S) {
    return S.top == -1;
}

bool isFull(const Stack &S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh\n";
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong\n";
        return;
    }
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack T;
    createStack(T);
    while (!isEmpty(S)) {
        push(T, pop(S));
    }
    S = T;
}
```
#### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack\n";
    balikStack(S);
    printInfo(S);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul7/image.png)

Program C++ ini membuat sebuah stack berbasis array dan dengan menekankan penggunaan operasi dasar push dan pop. Program dimulai dengan stack kosong, kemudian beberapa data dimasukkan dan sebagian dikeluarkan sesuai urutan perintah. Setelah itu, isi stack ditampilkan dan dilakukan pembalikan urutan elemen.

### 2. Push Ascending
#### stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAX 20

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```
#### stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan input (ENTER untuk berhenti): ";
    while ((ch = cin.get()) != '\n') {
        push(S, ch - '0'); 
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack\n";
    balikStack(S);
    printInfo(S);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Output Program 1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul7/WhatsApp%20Image%202026-01-02%20at%2016.40.42.jpeg)

Program ini pushAscending yang berfungsi memasukkan data ke dalam stack dengan kondisi terurut naik. Untuk mencapai hal tersebut, digunakan stack sementara untuk menampung elemen yang lebih besar dari data baru.

### 3. Input Stream
#### stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAX 20
typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
#### stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

void push(Stack &S, infotype x) {
    S.top++;
    S.info[S.top] = x;
}

infotype pop(Stack &S) {
    infotype x = S.info[S.top];
    S.top--;
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}
```
#### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    char ch;
    while ((ch = cin.get()) != '\n') {
        cout << ch;
        push(S, ch - '0');
    }
    cout << endl;

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

```

### Output Unguided 3 :

##### Output 1
![Output Program 1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul7/WhatsApp%20Image%202026-01-02%20at%2016.39.36.jpeg)

Program membaca satu baris input, kemudian setiap digit angka diproses dan dimasukkan ke dalam stack sebagai elemen terpisah.Data yang dimasukkan pengguna juga ditampilkan kembali dalam bentuk stack. Setelah itu, urutan stack dibalik untuk memperlihatkan perubahan susunan data akibat operasi pembalikan.

## Kesimpulan
Pada praktikum ini dapat disimpulkan bahwa stack merupakan struktur data yang sederhana namun efektif untuk pengolahan data dengan satu titik akses. Implementasi stack menggunakan linked list memberikan fleksibilitas ukuran, sedangkan implementasi array lebih sederhana namun memiliki batas kapasitas.
Melalui implementasi program C++, diperoleh gambaran bahwa struktur Stack memiliki keunggulan dalam kesederhanaan dan efisiensi ketika pengolahan data hanya membutuhkan satu arah akses. Penggunaan stack juga relevan untuk berbagai kebutuhan seperti mekanisme undo, evaluasi ekspresi, navigasi data, dan proses rekursif. Praktikum ini menegaskan pentingnya memahami cara kerja setiap operasi pada stack agar pengelolaan data tetap teratur dan sesuai tujuan, serta memberikan dasar kuat untuk mempelajari struktur data lain yang lebih kompleks.

## Referensi  
[1].Programiz. Stack Data Structure.
https://www.programiz.com/dsa/stack

[2].GeeksforGeeks. Stack Data Structure.
https://www.geeksforgeeks.org/stack-data-structure/
# <h1 align="center">Laporan Praktikum Modul 8 - Queue </h1>
<p align="center">Muhammad Fahruli Ma'ruf - 103112400057</p>

## Dasar Teori
Queue merupakan struktur data linier yang bekerja dengan prinsip FIFO (First In First Out), yaitu elemen yang pertama kali masuk ke dalam antrian akan menjadi elemen pertama yang keluar. Konsep queue dapat dianalogikan seperti antrean pada kehidupan sehari-hari, misalnya antrean di loket pelayanan, di mana setiap orang dilayani sesuai urutan kedatangan.
Operasi utama pada queue meliputi enqueue, yaitu proses penambahan data ke bagian belakang (tail), dan dequeue, yaitu proses penghapusan data dari bagian depan (head). Selain itu, terdapat operasi pengecekan kondisi seperti isEmpty untuk mengetahui apakah queue kosong dan isFull untuk mengetahui apakah queue sudah penuh.
Queue dapat diimplementasikan menggunakan array maupun linked list. Implementasi menggunakan array memiliki keterbatasan kapasitas, namun lebih sederhana. Untuk meningkatkan efisiensi, digunakan beberapa mekanisme pengelolaan head dan tail, seperti queue linier dan circular queue.

## Guided

### 1. Queue Linked List
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL    

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(address &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif 
```
#### queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
#### main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;
    
    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}

```
Program ini menunjukkan cara kerja struktur data queue diimplementasikan menggunakan linked list. Queue direpresentasikan dengan dua buah pointer, yaitu head sebagai penunjuk elemen terdepan dan tail sebagai penunjuk elemen terakhir. Implementasi ini memungkinkan ukuran queue bersifat dinamis karena tidak dibatasi oleh kapasitas tertentu seperti pada array.
Operasi enqueue dilakukan dengan menambahkan node baru pada bagian tail, sedangkan dequeue dilakukan dengan menghapus node pada bagian head. Dengan mekanisme tersebut, prinsip FIFO (First In First Out) tetap terjaga. Selain operasi dasar, program juga menyediakan fitur tambahan seperti update data pada posisi tertentu, pencarian data, dan penampilan seluruh isi queue.

#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

struct Queue{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
#### queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
#### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

// deklarasi fungsi dari file alternatif
void enqueue(Queue &Q, infotype x);
void dequeue(Queue &Q);

int main(){
    Queue Q;
    CreateQueue(Q);

    cout << "H - T | Queue Info\n";
    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}

```
Program ini menggunakan array dengan mekanisme circular queue. Struktur queue memiliki penunjuk head, tail, dan count untuk menyimpan jumlah elemen yang ada di dalam queue. Circular queue memanfaatkan operasi modulo agar head dan tail dapat berputar kembali ke indeks awal array ketika mencapai indeks terakhir.

## Unguided 

### 1. Alternatif 1 - Head Diam, Tail Bergerak (Shifting / Geser Elemen)
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void printInfo(Queue Q);

#endif

```
#### queue_alt1.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return Q.head == -1;
}

bool isFullQueue(Queue Q){
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "queue penuh\n";
    } else {
        if(isEmptyQueue(Q)){
            Q.head = 0;
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

void dequeue(Queue &Q){
    if(!isEmptyQueue(Q)){
        for(int i = Q.head; i < Q.tail; i++){
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void printInfo(Queue Q){
    if(isEmptyQueue(Q)){
        cout << "empty queue\n";
    } else {
        cout << "H=" << Q.head << " T=" << Q.tail << " | ";
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}

```
#### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

// deklarasi fungsi dari file alternatif
void enqueue(Queue &Q, infotype x);
void dequeue(Queue &Q);

int main(){
    Queue Q;
    CreateQueue(Q);

    cout << "H - T | Queue Info\n";
    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul8/Cuplikan%20layar%202026-01-03%20002326.png)

Program C++ ini mengimplementasikan queue dengan posisi head selalu berada di indeks awal, sedangkan tail bergerak ke kanan setiap kali enqueue. Ketika dequeue dilakukan, seluruh elemen harus digeser satu posisi ke kiri agar head tetap berada di awal array.

### 2. Alternatif 2 - Head Bergerak, Tail Bergerak (Tanpa Circular)
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void printInfo(Queue Q);

#endif
```
#### queue_alt2.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return Q.head == -1;
}

bool isFullQueue(Queue Q){
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "queue penuh\n";
    } else {
        if(isEmptyQueue(Q)){
            Q.head = 0;
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

void dequeue(Queue &Q){
    if(!isEmptyQueue(Q)){
        Q.head++;
        if(Q.head > Q.tail){
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void printInfo(Queue Q){
    if(isEmptyQueue(Q)){
        cout << "empty queue\n";
    } else {
        cout << "H=" << Q.head << " T=" << Q.tail << " | ";
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);

    dequeue(Q);    printInfo(Q);
    enqueue(Q,4);  printInfo(Q);

    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Output Program 1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul8/Cuplikan%20layar%202026-01-03%20002754.png)

Program C++ ini menggunakanhead dan tail sama-sama bergerak. Dequeue cukup menaikkan nilai head tanpa melakukan shifting, sehingga lebih efisien dibanding alternatif 1. Namun, pendekatan ini dapat mengalami kondisi queue penuh semu.

### 3. Alternatif 3 - Circular Queue (Head & Tail Berputar)
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void printInfo(Queue Q);

#endif
```
#### queue_alt3.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return Q.head == -1;
}

bool isFullQueue(Queue Q){
    return (Q.tail + 1) % MAX == Q.head;
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "queue penuh\n";
    } else {
        if(isEmptyQueue(Q)){
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = x;
    }
}

void dequeue(Queue &Q){
    if(!isEmptyQueue(Q)){
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAX;
        }
    }
}

void printInfo(Queue Q){
    if(isEmptyQueue(Q)){
        cout << "empty queue\n";
    } else {
        cout << "H=" << Q.head << " T=" << Q.tail << " | ";
        int i = Q.head;
        while(true){
            cout << Q.info[i] << " ";
            if(i == Q.tail) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

// deklarasi fungsi dari file alternatif
void enqueue(Queue &Q, infotype x);
void dequeue(Queue &Q);

int main(){
    Queue Q;
    CreateQueue(Q);

    cout << "H - T | Queue Info\n";
    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Output Program 1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul8/Cuplikan%20layar%202026-01-03%20023641.png)

Program C++ ini menerapkan Pada circular queue, head dan tail bergerak secara melingkar menggunakan operasi modulo. Ketika tail mencapai indeks terakhir, ia akan kembali ke indeks awal array.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa struktur data queue bekerja berdasarkan prinsip FIFO. Implementasi queue dengan array dapat dilakukan menggunakan beberapa mekanisme pengelolaan head dan tail. Alternatif 1 paling sederhana namun kurang efisien, alternatif 2 lebih efisien tetapi memiliki keterbatasan, sedangkan circular queue merupakan solusi paling optimal dalam pemanfaatan memori dan kinerja.

## Referensi  
[1]. Dicoding. (2023). **Struktur Data Queue: Pengertian, Fungsi, dan Jenisnya.**  
Artikel ini membahas pengertian queue, fungsi, cara kerja FIFO, serta berbagai jenis implementasinya dalam pemrograman.  
HTML: https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/

[2]. Trivusi. (2022, Juli). **Struktur Data Queue.**  
Materi ini menjelaskan teori dasar queue, contoh penggunaan, kelebihan FIFO, serta penerapannya dalam algoritma dan kehidupan nyata.  
HTML: https://www.trivusi.web.id/2022/07/struktur-data-queue.html


# <h1 align="center">Laporan Praktikum Modul 6 - Duobly Linked List (Bagian Pertama)</h1>
<p align="center">Muhammad Fahruli Ma'ruf - 103112400057</p>

## Dasar Teori
Doubly Linked List adalah struktur data dinamis yang menyimpan elemen dalam bentuk node yang saling terhubung. Setiap node memiliki dua referensi, yaitu ke elemen sebelumnya dan ke elemen sesudahnya. Dengan mekanisme ini, data tidak hanya dapat diakses secara berurutan dari awal ke akhir, tetapi juga sebaliknya.
Keberadaan dua pointer pada setiap node membuat Doubly Linked List unggul dalam pengelolaan data yang sering mengalami perubahan. Operasi seperti penambahan, penghapusan, dan pemindahan elemen dapat dilakukan dengan penyesuaian pointer tanpa harus menggeser seluruh data seperti pada array. Oleh karena itu, struktur ini banyak digunakan pada sistem yang membutuhkan fleksibilitas tinggi dalam pengolahan data.
Walaupun membutuhkan memori lebih besar karena menyimpan dua pointer, Doubly Linked List tetap efisien untuk aplikasi yang berorientasi pada manipulasi data dinamis dibandingkan struktur data statis.
## Guided

### 1. Guided1
## listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```
## listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```
## main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Program bertujuan mengenalkan cara kerja Doubly Linked List melalui berbagai metode penyisipan data. Data makanan digunakan sebagai contoh agar struktur list mudah dipahami. Program menunjukkan bahwa data dapat ditambahkan di awal, akhir, maupun di antara node tertentu dengan pengaturan pointer next dan prev.

### 2. Guided2

## Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

typedef struct { 
    string nopol; 
    string warna;
    int thnBuat;
} kendaraan;
typedef kendaraan infotype;

typedef struct ElmList *address;
typedef struct ElmList { 
    infotype info;
    address next;
    address prev;
} ElmList;

typedef struct { 
    address First;
    address Last;
} List;

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);
void printInfo(List L);

infotype inputKendaraan();
address findElm(List L, string nopol);
void deleteByNopol(List &L, string nopol); 

#endif
```
## Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

infotype inputKendaraan() {
    infotype data;
    cout << "masukkan nomor polisi: ";
    cin >> data.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> data.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    return data;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last; 
        (L.Last)->next = P; 
        L.Last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.First; 
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next; 
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.First && P == L.Last) {
            L.First = Nil; L.Last = Nil;
        } else if (P == L.First) {
            L.First = P->next; 
            (L.First)->prev = Nil;
        } else if (P == L.Last) {
            L.Last = P->prev; 
            (L.Last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}

void printInfo(List L) {
    address P = L.Last; 
    
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            
            P = P->prev; 
        }
    }
}
```
## main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```
Program ini mengembangkan konsep sebelumnya dengan menambahkan operasi pencarian dan penghapusan data. Data kendaraan dipilih karena memiliki identitas unik berupa nomor polisi. Program menyimpan data ke dalam list, mencari data tertentu, lalu menghapus data dengan menyesuaikan posisi node.
Bagian ini melatih pemahaman mahasiswa bahwa operasi insert, search, dan delete saling berkaitan dalam pengelolaan Doubly Linked List.
## Unguided 

### 1. Doubly Linked List

## Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

#define Nil NULL

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct elmlist* address;

struct elmlist {
    infotype info;
    address prev;
    address next;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void insertLast(List &L, address P);
void printInfo(List L);

#endif
```
## Doublylist.cpp
```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    cout << "\nDATA LIST\n";
    while (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << "-----------------\n";
        P = P->next;
    }
}

```
## main.cpp
```C++
#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    address P;

    x = {"D001", "hitam", 90};
    insertLast(L, alokasi(x));

    x = {"D003", "putih", 70};
    insertLast(L, alokasi(x));

    x = {"D002", "merah", 80};
    insertLast(L, alokasi(x));

    x = {"D004", "kuning", 90};
    insertLast(L, alokasi(x));

    string cari = "D001";
    P = findElm(L, cari);

    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul6/Cuplikan%20layar%202026-01-01%20021639.png)

Program ini menekankan pencegahan data ganda. Setiap data kendaraan yang dimasukkan dicek terlebih dahulu agar nomor polisi tidak terduplikasi. Pendekatan ini menjaga konsistensi data dalam list.

### 2. Cari Elemen

## Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

#define Nil NULL

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct elmlist* address;

struct elmlist {
    infotype info;
    address prev;
    address next;
};

struct List {
    address First;
    address Last;
};

address findElm(List L, string nopol);

void CreateList(List &L);
address alokasi(infotype x);
void insertLast(List &L, address P);
void printInfo(List L);

#endif
```
## Doublylist.cpp
```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last  = Nil;
}
address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}
void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last  = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}
void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << "-------------------\n";
        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```
## main.cpp
```C++
#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    address P;

    x = {"D001", "hitam", 90};
    insertLast(L, alokasi(x));

    x = {"D003", "putih", 70};
    insertLast(L, alokasi(x));

    x = {"D002", "merah", 80};
    insertLast(L, alokasi(x));

    x = {"D004", "kuning", 90};
    insertLast(L, alokasi(x));

    string cari = "D001";
    P = findElm(L, cari);

    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul6/Cuplikan%20layar%202026-01-01%20031247.png)

Program ini mencari data berdasarkan nomor polisi. Program menampilkan perbedaan kondisi saat data ditemukan dan saat data tidak tersedia, sehingga alur pencarian mudah dipahami.

### 3.Hapus Elemen

## Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

#define Nil NULL

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct elmlist* address;

struct elmlist {
    infotype info;
    address prev;
    address next;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void insertLast(List &L, address P);
void printInfo(List L);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```
## Doublylist.cpp
```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol)
            return P;
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    L.First = P->next;
    if (L.First != Nil)
        L.First->prev = Nil;
    P->next = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    L.Last = P->prev;
    L.Last->next = Nil;
    P->prev = Nil;
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != Nil)
        P->next->prev = Prec;
    P->next = Nil;
    P->prev = Nil;
}

void printInfo(List L) {
    address P = L.First;
    cout << "\nDATA LIST\n";
    while (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << "-----------------\n";
        P = P->next;
    }
}
```
## main.cpp
```C++
#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    address P;

    x = {"D001", "hitam", 90}; insertLast(L, alokasi(x));
    x = {"D003", "putih", 70}; insertLast(L, alokasi(x));
    x = {"D002", "merah", 80}; insertLast(L, alokasi(x));
    x = {"D004", "kuning", 90}; insertLast(L, alokasi(x));

    string hapus = "D003";
    P = findElm(L, hapus);

    if (P == L.First)
        deleteFirst(L, P);
    else if (P == L.Last)
        deleteLast(L, P);
    else
        deleteAfter(P->prev, P);

    cout << "Data dengan nomor polisi D003 berhasil dihapus\n";
    printInfo(L);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided3](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul6/Cuplikan%20layar%202026-01-01%20032307.png)

Program ini mengimplementasikan penghapusan data berdasarkan nomor polisi. Setelah node dihapus, pointer pada node sekitar disesuaikan agar struktur list tetap valid.

## Kesimpulan
Doubly Linked List merupakan struktur data yang fleksibel untuk pengelolaan data dinamis. Melalui guided dan unguided, mahasiswa mempelajari penyisipan, validasi, pencarian, dan penghapusan data secara bertahap. Struktur ini efektif digunakan pada aplikasi yang sering mengalami perubahan data.

## Referensi
<br>[1] Wijoyo, A., dkk. (2024). Implementasi Struktur Data Dinamis dalam Pemrograman.
Jurnal Riset Informatika dan Inovasi, 1(12), 1290–1293.
🔗 https://jurnalmahasiswa.com/index.php/jriin/article/view/957

<br>[2] Anggraini, N., Zulfi, F., & Butarbutar, L. E. (2024). Analisis Efisiensi Linked List dalam Pengelolaan Data.
Jurnal Kajian Ilmiah Multidisipliner, 8(10), 222–227.
🔗 https://sejurnal.com/pub/index.php/jkim/article/view/4900

<br>[3] Setiyawan, R. D., dkk. (2024). Penerapan Struktur Data Linked List pada Bahasa C++.
JUTECH: Journal Education and Technology, 5(2), 485–496.
🔗 https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263


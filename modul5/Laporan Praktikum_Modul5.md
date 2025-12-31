# <h1 align="center">Laporan Praktikum Modul 5- Singly Linked List (Bagian Kedua)</h1>
<p align="center">Muhammad Fahruli Ma'ruf - 103112400057</p>

## Dasar Teori
Singly Linked List adalah struktur data linear yang tersusun dari beberapa node yang saling terhubung. Setiap node memiliki dua bagian, yaitu data dan pointer yang menunjuk ke node berikutnya. Berbeda dengan array, data pada linked list tidak disimpan berurutan di memori sehingga ukurannya bisa berubah-ubah sesuai kebutuhan.

Kelebihan Singly Linked List terletak pada kemudahan operasi insert, delete, dan update data. Namun, kekurangannya adalah tidak adanya akses langsung ke elemen tertentu sehingga untuk mengakses atau mencari data, program harus menelusuri node satu per satu dari awal. Karena sifat ini, algoritma Linear Search lebih cocok digunakan dibandingkan Binary Search pada linked list.
## Guided

### 1. Guided1

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai`
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil nullptr

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};
typedef buah dataBuah;
typedef struct node *address;
struct node{
    dataBuah isidata;
    address next;
};

struct linkedList{
    address first;
};

bool listEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodebaru);
void insertAfter(linkedList &List, address nodebaru, address Prev);
void insertLast(linkedList &List, address nodebaru);
void deleteFirst(linkedList &List);
void delLast(linkedList &List);
void deleteAfter(address &List, address &nodehapus, address nodeprev);
int nbList(linkedList List);
void deletelist(linkedList &List);

//materi modul 5 (part 1 update)
void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address prev);

#endif
```

```C++

#include "listbuah.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

//Materi Modul 5 - Update Operations
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
```C++
#include "listbuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC,nodeD,nodeE;   
    createList(List);

    nodeA=alokasi("jeruk",100,3000);
    nodeB=alokasi("apel",75,4000);
    nodeC=alokasi("pir",87,5000);
    nodeD=alokasi("semangka",43,11500); 
    nodeE=alokasi("durian",15,31450);

    insertFirst(List,nodeA);
    insertLast(List,nodeB);
    insertAfter(List,nodeC,nodeA);
    insertAfter(List,nodeD,nodeC);
    insertLast(List,nodeE);

    cout<<" isi list buat dilakukan insert"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List,nodeD);

    cout<<" isi list buah setelah dilakukan update"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    return 0;
}   
```
program digunakan untuk mengelola data buah menggunakan Singly Linked List. Operasi yang diterapkan meliputi penambahan data di awal, akhir, dan setelah node tertentu, serta pembaruan data pada node pertama, terakhir, dan setelah node tertentu. Program ini menunjukkan bahwa Singly Linked List memudahkan proses manipulasi data tanpa harus memindahkan data lainnya.
### 2. Guided2

```C++
#include <iostream>
using namespace std;

struct Node { 
    int data;
    Node* next;
};

Node *linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    
    Node* result = linearSearch(head, 20);

    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Program tersebut menerapkan algoritma Linear Search pada Singly Linked List. Proses pencarian dilakukan dengan membandingkan data pada setiap node secara berurutan hingga data ditemukan atau seluruh node sudah diperiksa. Metode ini sederhana dan sesuai dengan karakteristik linked list yang bersifat sekuensial.
## Unguided 

### 1. Binary Search

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    Node* temp = *head_ref;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = new_node;
}

Node* getMiddle(Node* start, Node* end) {
    if (start == nullptr)
        return nullptr;

    Node* slow = start;
    Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;
    int iteration = 1;

    while (start != end) {
        Node* mid = getMiddle(start, end);

        cout << "Iterasi " << iteration
             << ": Mid = " << mid->data << " (indeks tengah)";

        if (mid->data == key) {
            cout << " -> DITEMUKAN!" << endl << endl;
            return mid;
        } 
        else if (mid->data < key) {
            cout << " -> Cari di bagian kanan" << endl;
            start = mid->next;
        } 
        else {
            cout << " -> Cari di bagian kiri" << endl;
            end = mid;
        }
        iteration++;
    }

    cout << "Tidak ada elemen tersisa" << endl << endl;
    return nullptr;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "BINARY SEARCH PADA LINKED LIST" << endl;

    Node* head = nullptr;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    append(&head, 60);

    cout << "Linked List yang dibuat: ";
    printList(head);

    int key;
    cout << "Mencari nilai: ";
    cin >> key;

    cout << "\nProses Pencarian:\n";
    Node* result = binarySearch(head, key);

    if (result != nullptr) {
        cout << "Hasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result << endl;

        if (result->next != nullptr)
            cout << "Data berikutnya: " << result->next->data << endl;
        else
            cout << "Data berikutnya: NULL" << endl;
    } 
    else {
        cout << "Hasil: Nilai " << key
             << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1_1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul5/Cuplikan%20layar%202025-12-31%20163849.png)
##### Output 2
![Screenshot Output Unguided1_2](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul5/Cuplikan%20layar%202025-12-31%20163900.png)

Program untuk mengimplementasikan operasi binary search dalam single linked list.Walaupun program dapat menemukan data yang dicari, prosesnya kurang efisien karena pencarian node tengah harus dilakukan dengan penelusuran dari awal list.

### 2. Linear Search

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

/* Menambahkan node di akhir linked list */
void append(Node*& head, int new_data) {
    Node* new_node = new Node{new_data, nullptr};

    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* current = head;
    while (current->next != nullptr)
        current = current->next;

    current->next = new_node;
}

/* Linear Search */
Node* linearSearch(Node* head, int key) {
    int index = 1;

    for (Node* current = head; current != nullptr; current = current->next) {
        cout << "Memeriksa node " << index << ": " << current->data;

        if (current->data == key) {
            cout << " (SAMA) -> DITEMUKAN!" << endl << endl;
            return current;
        } else {
            cout << " (tidak sama)" << endl;
        }
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl << endl;
    return nullptr;
}

/* Menampilkan isi linked list */
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;

    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Linked List yang dibuat: ";
    printList(head);

    int key;
    cout << "Mencari nilai: ";
    cin >> key;

    cout << "\nProses Pencarian:\n";
    Node* result = linearSearch(head, key);

    if (result != nullptr) {
        cout << "Hasil: Nilai " << key << " DITEMUKAN dalam linked list!" << endl;
        cout << "Alamat node: " << result << endl;

        if (result->next != nullptr)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Node berikutnya: NULL" << endl;
    } else {
        cout << "Hasil: Nilai " << key
             << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}


```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2_1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week5/Screenshot%20Output%20Unguided2_1.png)
##### Output 2
![Screenshot Output Unguided2_2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week5/Screenshot%20Output%20Unguided2_2.png)

Program ini mengimplementasikan operasi linear search dalam single linked list, yang melakukan pencarian secara bertahap dari node pertama hingga terakhir. Dibandingkan Binary Search pada linked list, metode ini lebih sederhana dan lebih efisien karena hanya membutuhkan satu kali penelusuran.

## Kesimpulan
Singly Linked List cocok digunakan untuk pengolahan data yang bersifat dinamis karena mendukung operasi insert, delete, dan update dengan mudah. Untuk proses pencarian data, Linear Search merupakan metode yang paling sesuai, sedangkan Binary Search kurang efektif karena keterbatasan akses langsung pada linked list. Oleh karena itu, pemilihan algoritma pencarian harus disesuaikan dengan struktur data yang digunakan.
## Referensi
<br>[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022).
Introduction to Algorithms (4th ed.). Cambridge, MA: MIT Press.
ISBN: 978-0262046305.
https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/
<br>[2] Malik, D. S. (2021).
Data Structures Using C++ (2nd ed.). Boston, MA: Cengage Learning.
ISBN: 978-0357114087.
https://www.cengage.com/c/data-structures-using-c-2e-malik/
<br>[3] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2020).
Data Structures and Algorithms in C++ (2nd ed.). Hoboken, NJ: Wiley.
ISBN: 978-1119699091.
https://www.wiley.com/en-us/Data+Structures+and+Algorithms+in+C%2B%2B-p-9781119699091

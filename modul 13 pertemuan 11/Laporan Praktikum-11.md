# <h1 align="center">Laporan Praktikum Modul 11 - Multi Linked List </h1>
<p align="center">Muhammad Fahruli Ma'ruf - 103112400057</p>

## Dasar Teori
Multi Linked List merupakan struktur data yang menyimpan elemen secara bertingkat. Setiap elemen utama (parent) memiliki keterkaitan dengan sekumpulan elemen lain (child). Hubungan ini memungkinkan satu data induk menampung banyak data turunan di dalam satu struktur yang sama.
Berbeda dengan linked list biasa yang hanya memiliki satu jalur penelusuran, Multi Linked List mengharuskan proses traversal dilakukan secara berlapis. Penelusuran dimulai dari list parent, kemudian dilanjutkan ke list child milik parent tersebut. Struktur ini sering digunakan untuk memodelkan data berelasi, seperti kategori dan item, atau kelompok dan anggota.
Penggunaan pointer pada Multi Linked List membuat pengelolaan data menjadi lebih fleksibel, terutama dalam operasi penambahan dan penghapusan data tanpa harus memindahkan elemen lain di memori.

## Guided

### 1.Multi Linked List (Sistem Kategori Makanan)
#### multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild;   //alias pointer ke struct nodeChild

struct  nodeChild{ //node child
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak{ //list child
    NodeChild first;    
    NodeChild last;
};

struct nodeParent{ //node parent
 string idKategoriMakanan;
 string namaKategoriMakanan;
 NodeParent next;
 NodeParent prev;
 listAnak L_Anak; //list child
};

struct listInduk{ //list parent
    NodeParent first;
    NodeParent last;
};

//create list 
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &Lanak);

//alokasi &d elokasi parent
NodeParent alokasiNodeParent(string idkategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &NodeInduk);

//alokasi & delokasi child
NodeChild alokasiNodeChild(string idmakanan, string namamakanan);
void dealokasiNodeChild(NodeChild &NodeAnak);

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev); 
void findChildByID(listInduk &LInduk, string IDCari);

//operasi print
void printStrukturMLL(listInduk &LInduk);

#endif
```
#### multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++; 
        }
    }
}
```
#### main.cpp
```C++
#include "multilist.h"
#include <iostream>
using namespace std;

int main(){
    //1.instalasi List
    listInduk LInduk;
    createListInduk(LInduk);

    //2.membuat Data Parent (kategori makanan)
    NodeParent k01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, k01);
    NodeParent k02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, k02);
    NodeParent k03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, k03);
    cout<<endl;

    //3.masukkan Data Child (menu makanan) ke kategori tertentu
    //-->isi kategori makanan berat (k01)
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng");
    insertLastChild(k01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(k01->L_Anak, M02);  
    //--> isi kategori minuman (k02)
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D02);
    NodeChild D03 = alokasiNodeChild("D03", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D03);
    //--> isi kategori dessert (k03)
    NodeChild S01 = alokasiNodeChild("DS01", "Puding Coklat");
    insertLastChild(k03->L_Anak, S01);
    cout << endl;  

    //4.print mll setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    //5.searching node child
    findChildByID(LInduk, "D01");
    cout << endl;
    //6.delete node child
    deleteAfterChild(k01->L_Anak, M01);//menghapus node child ayam bakar madu
    cout<< endl;
    //7.delete node parent
    deleteAfterParent(LInduk, k02); //menghapus node parent minuman
    cout << endl;
    //8.print mll setelah delete
    printStrukturMLL(LInduk);
    cout << endl;
    return 0;
}
```
Program ini dibuat dengan dua jenis data, yaitu data parent dan data child. Setiap parent memiliki sebuah list child yang dapat diisi lebih dari satu data.

## Unguided 
### 1. Insert dan Print Multi Linked List
#### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct GolHewan {
    string id;
    string nama;
};

struct Hewan {
    string id;
    string nama;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct Parent *AdrParent;
typedef struct Child *AdrChild;

struct Child {
    Hewan data;
    AdrChild next;
    AdrChild prev;
};

struct ListChild {
    AdrChild first;
    AdrChild last;
};

struct Parent {
    GolHewan data;
    AdrParent next;
    AdrParent prev;
    ListChild anak;
};

struct ListParent {
    AdrParent first;
    AdrParent last;
};

void initParent(ListParent &L);
void initChild(ListChild &L);

AdrParent newParent(string id, string nama);
AdrChild newChild(string id, string nama, string habitat, bool ekor, float bobot);

void addParentLast(ListParent &L, AdrParent P);
void addChildLast(ListChild &L, AdrChild C);

void tampilMLL(ListParent L);

#endif

```
#### MultiLL.cpp
```C++
#include "MultiLL.h"

void initParent(ListParent &L){
    L.first = L.last = NULL;
}

void initChild(ListChild &L){
    L.first = L.last = NULL;
}

AdrParent newParent(string id, string nama){
    AdrParent P = new Parent;
    P->data.id = id;
    P->data.nama = nama;
    initChild(P->anak);
    P->next = P->prev = NULL;
    return P;
}

AdrChild newChild(string id, string nama, string habitat, bool ekor, float bobot){
    AdrChild C = new Child;
    C->data.id = id;
    C->data.nama = nama;
    C->data.habitat = habitat;
    C->data.ekor = ekor;
    C->data.bobot = bobot;
    C->next = C->prev = NULL;
    return C;
}

void addParentLast(ListParent &L, AdrParent P){
    if(L.first == NULL){
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void addChildLast(ListChild &L, AdrChild C){
    if(L.first == NULL){
        L.first = L.last = C;
    } else {
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}

void tampilMLL(ListParent L){
    AdrParent P = L.first;
    int i = 1;
    while(P != NULL){
        cout << "=== Parent " << i++ << " ===\n";
        cout << "ID Golongan : " << P->data.id << endl;
        cout << "Nama Golongan : " << P->data.nama << endl;

        AdrChild C = P->anak.first;
        if(C == NULL){
            cout << "(tidak ada child)\n";
        } else {
            int j = 1;
            while(C != NULL){
                cout << " - Child " << j++ << endl;
                cout << "    ID Hewan : " << C->data.id << endl;
                cout << "    Nama Hewan : " << C->data.nama << endl;
                cout << "    Habitat : " << C->data.habitat << endl;
                cout << "    Ekor : " << C->data.ekor << endl;
                cout << "    Bobot : " << C->data.bobot << endl;
                C = C->next;
            }
        }
        cout << "------------------------\n";
        P = P->next;
    }
}

```
#### main.cpp
```C++
#include "MultiLL.h"

int main(){
    ListParent L;
    initParent(L);

    AdrParent G1 = newParent("G001","Aves");
    AdrParent G2 = newParent("G002","Mamalia");
    AdrParent G3 = newParent("G003","Pisces");
    AdrParent G4 = newParent("G004","Amfibi");
    AdrParent G5 = newParent("G005","Reptil");

    addParentLast(L,G1);
    addParentLast(L,G2);
    addParentLast(L,G3);
    addParentLast(L,G4);
    addParentLast(L,G5);

    addChildLast(G1->anak, newChild("AV001","Cendrawasih","Hutan",1,0.3));
    addChildLast(G1->anak, newChild("AV002","Bebek","Air",1,2));

    addChildLast(G2->anak, newChild("M001","Harimau","Hutan",1,200));
    addChildLast(G2->anak, newChild("M003","Gorila","Hutan",0,160));
    addChildLast(G2->anak, newChild("M002","Kucing","Darat",1,4));

    addChildLast(G4->anak, newChild("AM001","Kodok","Sawah",0,0.2));

    tampilMLL(L);
    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul%2013%20pertemuan%2011/ungaided1/Cuplikan%20layar%202026-01-03%20154510.png)

##### Output 2
![Output Program 2](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul%2013%20pertemuan%2011/ungaided1/Cuplikan%20layar%202026-01-03%20154519.png)

**Program C++ ini** melakukan penambahan beberapa data parent terlebih dahulu, kemudian diikuti dengan penambahan data child pada parent tertentu.
Setelah seluruh data dimasukkan, struktur Multi Linked List ditampilkan untuk memastikan bahwa hubungan antara parent dan child telah terbentuk dengan benar. Hasil program menunjukkan bahwa setiap data child berhasil tersimpan pada parent yang sesuai..

### 2. Search Hewan Tidak Berekor
#### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct GolHewan {
    string id;
    string nama;
};

struct Hewan {
    string id;
    string nama;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct Parent *AdrParent;
typedef struct Child *AdrChild;

struct Child {
    Hewan data;
    AdrChild next;
    AdrChild prev;
};

struct ListChild {
    AdrChild first;
    AdrChild last;
};

struct Parent {
    GolHewan data;
    AdrParent next;
    AdrParent prev;
    ListChild anak;
};

struct ListParent {
    AdrParent first;
    AdrParent last;
};

void initParent(ListParent &L);
void initChild(ListChild &L);

AdrParent newParent(string id, string nama);
AdrChild newChild(string id, string nama, string habitat, bool ekor, float bobot);

void addParentLast(ListParent &L, AdrParent P);
void addChildLast(ListChild &L, AdrChild C);

void tampilMLL(ListParent L);

void searchHewanTidakBerekor(ListParent L);

#endif
```
#### MultiLL.cpp
```C++
#include "MultiLL.h"

/* ===== INIT LIST ===== */
void initParent(ListParent &L){
    L.first = L.last = NULL;
}

void initChild(ListChild &L){
    L.first = L.last = NULL;
}

/* ===== CREATE NODE ===== */
AdrParent newParent(string id, string nama){
    AdrParent P = new Parent;
    P->data.id = id;
    P->data.nama = nama;
    initChild(P->anak);
    P->next = P->prev = NULL;
    return P;
}

AdrChild newChild(string id, string nama, string habitat, bool ekor, float bobot){
    AdrChild C = new Child;
    C->data.id = id;
    C->data.nama = nama;
    C->data.habitat = habitat;
    C->data.ekor = ekor;
    C->data.bobot = bobot;
    C->next = C->prev = NULL;
    return C;
}

/* ===== INSERT PARENT ===== */
void addParentLast(ListParent &L, AdrParent P){
    if(L.first == NULL){
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

/* ===== INSERT CHILD ===== */
void addChildLast(ListChild &L, AdrChild C){
    if(L.first == NULL){
        L.first = L.last = C;
    } else {
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}

/* ===== PRINT MULTI LINKED LIST ===== */
void tampilMLL(ListParent L){
    AdrParent P = L.first;
    int i = 1;

    while(P != NULL){
        cout << "=== Parent " << i++ << " ===" << endl;
        cout << "ID Golongan : " << P->data.id << endl;
        cout << "Nama Golongan : " << P->data.nama << endl;

        AdrChild C = P->anak.first;
        if(C == NULL){
            cout << "(tidak ada child)" << endl;
        } else {
            int j = 1;
            while(C != NULL){
                cout << " - Child " << j++ << endl;
                cout << "    ID Hewan : " << C->data.id << endl;
                cout << "    Nama Hewan : " << C->data.nama << endl;
                cout << "    Habitat : " << C->data.habitat << endl;
                cout << "    Ekor : " << C->data.ekor << endl;
                cout << "    Bobot : " << C->data.bobot << endl;
                C = C->next;
            }
        }
        cout << "------------------------" << endl;
        P = P->next;
    }
}

/* ===== UNGUIDED 2 : SEARCH HEWAN TIDAK BEREKOR ===== */
void searchHewanTidakBerekor(ListParent L){
    AdrParent P = L.first;
    int posParent = 1;

    while(P != NULL){
        AdrChild C = P->anak.first;
        int posChild = 1;

        while(C != NULL){
            if(C->data.ekor == false){
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->data.nama
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Hewan : " << C->data.id << endl;
                cout << "Nama Hewan : " << C->data.nama << endl;
                cout << "Habitat : " << C->data.habitat << endl;
                cout << "Ekor : " << C->data.ekor << endl;
                cout << "Bobot : " << C->data.bobot << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Golongan : " << P->data.id << endl;
                cout << "Nama Golongan : " << P->data.nama << endl;
                cout << "------------------------" << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
        posParent++;
    }
}
```
#### main.cpp
```C++
#include "MultiLL.h"

int main(){
    ListParent L;
    initParent(L);

    AdrParent G1 = newParent("G001","Aves");
    AdrParent G2 = newParent("G002","Mamalia");
    AdrParent G3 = newParent("G003","Pisces");
    AdrParent G4 = newParent("G004","Amfibi");
    AdrParent G5 = newParent("G005","Reptil");

    addParentLast(L,G1);
    addParentLast(L,G2);
    addParentLast(L,G3);
    addParentLast(L,G4);
    addParentLast(L,G5);

    addChildLast(G1->anak, newChild("AV001","Cendrawasih","Hutan",1,0.3));
    addChildLast(G1->anak, newChild("AV002","Bebek","Air",1,2));

    addChildLast(G2->anak, newChild("M001","Harimau","Hutan",1,200));
    addChildLast(G2->anak, newChild("M003","Gorila","Hutan",0,160));
    addChildLast(G2->anak, newChild("M002","Kucing","Darat",1,4));

    addChildLast(G4->anak, newChild("AM001","Kodok","Sawah",0,0.2));

    cout << "\n=== HASIL SEARCH HEWAN TIDAK BEREKOR ===\n";
    searchHewanTidakBerekor(L);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Output Program 1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul%2013%20pertemuan%2011/ungaided2/Cuplikan%20layar%202026-01-03%20162148.png)

**Program C++ ini** dilakukan pencarian data child berdasarkan atribut tertentu, yaitu hewan yang tidak memiliki ekor. Proses pencarian dilakukan dengan menelusuri seluruh list parent dan memeriksa setiap child yang ada di dalamnya.
Jika kondisi pencarian terpenuhi, program akan menampilkan informasi data child beserta data parent yang menaunginya. Hal ini menunjukkan bahwa Multi Linked List dapat digunakan untuk melakukan pencarian data secara terstruktur meskipun melibatkan lebih dari satu tingkat list.

### 3. Delete Parent dan Print Ulang
#### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

/* ===== STRUCT DATA ===== */
struct GolHewan {
    string id;
    string nama;
};

struct Hewan {
    string id;
    string nama;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct Parent *AdrParent;
typedef struct Child *AdrChild;

/* ===== CHILD ===== */
struct Child {
    Hewan data;
    AdrChild next;
    AdrChild prev;
};

struct ListChild {
    AdrChild first;
    AdrChild last;
};

/* ===== PARENT ===== */
struct Parent {
    GolHewan data;
    AdrParent next;
    AdrParent prev;
    ListChild anak;
};

struct ListParent {
    AdrParent first;
    AdrParent last;
};

/* ===== PROTOTYPE ===== */
void initParent(ListParent &L);
void initChild(ListChild &L);

AdrParent newParent(string id, string nama);
AdrChild newChild(string id, string nama, string habitat, bool ekor, float bobot);

void addParentLast(ListParent &L, AdrParent P);
void addChildLast(ListChild &L, AdrChild C);

void tampilMLL(ListParent L);

/* UNGUIDED 2 */
void searchHewanTidakBerekor(ListParent L);

/* UNGUIDED 3 */
void deleteAfterParent(ListParent &L, AdrParent prec);

#endif

```
#### MultiLL.cpp
```C++
#include "MultiLL.h"

/* ===== INIT ===== */
void initParent(ListParent &L){
    L.first = L.last = NULL;
}

void initChild(ListChild &L){
    L.first = L.last = NULL;
}

/* ===== CREATE NODE ===== */
AdrParent newParent(string id, string nama){
    AdrParent P = new Parent;
    P->data.id = id;
    P->data.nama = nama;
    initChild(P->anak);
    P->next = P->prev = NULL;
    return P;
}

AdrChild newChild(string id, string nama, string habitat, bool ekor, float bobot){
    AdrChild C = new Child;
    C->data.id = id;
    C->data.nama = nama;
    C->data.habitat = habitat;
    C->data.ekor = ekor;
    C->data.bobot = bobot;
    C->next = C->prev = NULL;
    return C;
}

/* ===== INSERT PARENT ===== */
void addParentLast(ListParent &L, AdrParent P){
    if(L.first == NULL){
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

/* ===== INSERT CHILD ===== */
void addChildLast(ListChild &L, AdrChild C){
    if(L.first == NULL){
        L.first = L.last = C;
    } else {
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}

/* ===== PRINT ===== */
void tampilMLL(ListParent L){
    AdrParent P = L.first;
    int i = 1;

    while(P != NULL){
        cout << "=== Parent " << i++ << " ===" << endl;
        cout << "ID Golongan : " << P->data.id << endl;
        cout << "Nama Golongan : " << P->data.nama << endl;

        AdrChild C = P->anak.first;
        if(C == NULL){
            cout << "(tidak ada child)" << endl;
        } else {
            int j = 1;
            while(C != NULL){
                cout << " - Child " << j++ << endl;
                cout << "    ID Hewan : " << C->data.id << endl;
                cout << "    Nama Hewan : " << C->data.nama << endl;
                cout << "    Habitat : " << C->data.habitat << endl;
                cout << "    Ekor : " << C->data.ekor << endl;
                cout << "    Bobot : " << C->data.bobot << endl;
                C = C->next;
            }
        }
        cout << "------------------------" << endl;
        P = P->next;
    }
}

/* ===== UNGUIDED 2 : SEARCH ===== */
void searchHewanTidakBerekor(ListParent L){
    AdrParent P = L.first;

    while(P != NULL){
        AdrChild C = P->anak.first;
        int posChild = 1;

        while(C != NULL){
            if(C->data.ekor == false){
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->data.nama
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Hewan : " << C->data.id << endl;
                cout << "Nama Hewan : " << C->data.nama << endl;
                cout << "Habitat : " << C->data.habitat << endl;
                cout << "Ekor : " << C->data.ekor << endl;
                cout << "Bobot : " << C->data.bobot << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Golongan : " << P->data.id << endl;
                cout << "Nama Golongan : " << P->data.nama << endl;
                cout << "------------------------" << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
    }
}

/* ===== UNGUIDED 3 : DELETE PARENT ===== */
void deleteAfterParent(ListParent &L, AdrParent prec){
    if(prec != NULL && prec->next != NULL){
        AdrParent del = prec->next;

        // putuskan parent
        prec->next = del->next;
        if(del->next != NULL){
            del->next->prev = prec;
        } else {
            L.last = prec;
        }

        // hapus semua child
        AdrChild C;
        while(del->anak.first != NULL){
            C = del->anak.first;
            del->anak.first = C->next;
            delete C;
        }

        delete del;
    }
}

```
#### main.cpp
```C++
#include "MultiLL.h"

int main(){
    ListParent L;
    initParent(L);

    AdrParent G1 = newParent("G001","Aves");
    AdrParent G2 = newParent("G002","Mamalia");
    AdrParent G3 = newParent("G003","Pisces");
    AdrParent G4 = newParent("G004","Amfibi");
    AdrParent G5 = newParent("G005","Reptil");

    addParentLast(L,G1);
    addParentLast(L,G2);
    addParentLast(L,G3);
    addParentLast(L,G4);
    addParentLast(L,G5);

    addChildLast(G1->anak, newChild("AV001","Cendrawasih","Hutan",1,0.3));
    addChildLast(G1->anak, newChild("AV002","Bebek","Air",1,2));

    addChildLast(G2->anak, newChild("M001","Harimau","Hutan",1,200));
    addChildLast(G2->anak, newChild("M003","Gorila","Hutan",0,160));
    addChildLast(G2->anak, newChild("M002","Kucing","Darat",1,4));

    addChildLast(G4->anak, newChild("AM001","Kodok","Sawah",0,0.2));

    cout << "\n=== HASIL SEARCH HEWAN TIDAK BEREKOR ===\n";
    searchHewanTidakBerekor(L);

    cout << "\n=== SETELAH DELETE PARENT G004 ===\n";
    deleteAfterParent(L, G3); // G3 adalah sebelum G4
    tampilMLL(L);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Output Program 1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul%2013%20pertemuan%2011/ungaided3/Cuplikan%20layar%202026-01-03%20162912.png)


**Program C++ ini** proses penghapusan satu data parent beserta seluruh data child yang dimilikinya. Penghapusan dilakukan dengan memperhatikan hubungan pointer agar struktur list tetap konsisten setelah node dihapus.
Setelah proses delete selesai, struktur Multi Linked List ditampilkan kembali. Hasilnya menunjukkan bahwa data parent yang dihapus beserta seluruh child-nya sudah tidak ada, sementara data lain tetap tersusun dengan baik.
## Kesimpulan
Dari hasil praktikum, dapat disimpulkan bahwa Multi Linked List merupakan struktur data yang efektif untuk mengelola data bertingkat. Operasi insert, search, dan delete dapat dilakukan dengan baik selama pengaturan pointer dilakukan secara benar. Praktikum ini membantu meningkatkan pemahaman mengenai pengelolaan data berelasi menggunakan struktur data dinamis.
Dari pengamatan operasi yang dilakukan, dapat disimpulkan bahwa struktur data Multi Linked List memberikan fleksibilitas tinggi dalam manajemen data berelasi, memungkinkan penambahan maupun penghapusan data tanpa perlu memindahkan elemen lain secara keseluruhan. Traversal pada list parent dan child dapat dilakukan secara efisien untuk tujuan pencarian dan penampilan data secara terstruktur. Praktikum ini memberikan pemahaman yang kuat mengenai implementasi pointer dalam struktur data kompleks dan menjadi dasar untuk mempelajari struktur data lanjutan lainnya.

## Referensi  
[1]. GeeksforGeeks. (2023). Linked List Data Structure.
https://www.geeksforgeeks.org/data-structures/linked-list/

[2]. Programiz. (2024). Linked List in C++.
https://www.programiz.com/dsa/linked-list

[3]. TutorialsPoint. (2023). Data Structures – Linked Lists.
https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm

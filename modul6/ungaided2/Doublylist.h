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

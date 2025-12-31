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

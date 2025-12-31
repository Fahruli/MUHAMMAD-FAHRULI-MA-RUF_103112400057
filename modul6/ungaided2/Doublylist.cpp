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

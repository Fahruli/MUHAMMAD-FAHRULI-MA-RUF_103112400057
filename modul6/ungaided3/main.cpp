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

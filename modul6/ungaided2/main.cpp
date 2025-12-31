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

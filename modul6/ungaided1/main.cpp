#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    address P;

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan nomor polisi : ";
        cin >> x.nopol;
        cout << "Masukkan warna kendaraan : ";
        cin >> x.warna;
        cout << "Masukkan tahun kendaraan : ";
        cin >> x.thnBuat;

        P = alokasi(x);
        insertLast(L, P);
    }

    printInfo(L);
    return 0;
}

#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

int main() {
    QueueEksedisi Q;
    createQueue(Q);

    int menu;
    
    do {
        cout << "\n--- Komaniya Ekspress ---\n";
        cout << "1. Input data paket\n";
        cout << "2. Hapus data paket (deQueue)\n";
        cout << "3. Tampilkan queue\n";
        cout << "4. Hitung total biaya pengiriman\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            Paket P;
            cout << "Kode Resi: "; getline(cin, P.KodeResi);
            cout << "Nama Pengirim: "; getline(cin, P.NamaPengirim);
            cout << "Berat Barang (kg): "; cin >> P.BeratBarang; cin.ignore();
            cout << "Tujuan: "; getline(cin, P.Tujuan);

            if (enQueue(Q, P))
                cout << "Paket berhasil ditambahkan!\n";
            else
                cout << "Queue penuh!\n";
        }

        else if (menu == 2) {
            if (deQueue(Q))
                cout << "Paket pertama berhasil dihapus!\n";
            else
                cout << "Queue kosong!\n";
        }

        else if (menu == 3) {
            viewQueue(Q);
        }

        else if (menu == 4) {
            cout << "Total Biaya Pengiriman: Rp "
                 << TotalBiayaPengiriman(Q) << "\n";
        }

    } while (menu != 0);

    return 0;
}
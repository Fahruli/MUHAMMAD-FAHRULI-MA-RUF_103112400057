#include <iostream>
#include <vector>
#include "StackMahasiswa.h"

using namespace std;

int main() {
    StackMahasiswa S;
    createStack(S);

    cout << "Membuat stack kosong...\n";

    Mahasiswa m;

    m.Nama = "Venti"; m.NIM = "11111";
    m.NilaiTugas = 75.7f; m.NilaiUTS = 82.1f; m.NilaiUAS = 65.5f;
    Push(S, m);

    m.Nama = "Xiao"; m.NIM = "22222";
    m.NilaiTugas = 87.4f; m.NilaiUTS = 88.9f; m.NilaiUAS = 81.9f;
    Push(S, m);

    m.Nama = "Kazuha"; m.NIM = "33333";
    m.NilaiTugas = 92.3f; m.NilaiUTS = 88.8f; m.NilaiUAS = 82.4f;
    Push(S, m);

    m.Nama = "Wanderer"; m.NIM = "44444";
    m.NilaiTugas = 95.5f; m.NilaiUTS = 85.5f; m.NilaiUAS = 90.5f;
    Push(S, m);

    m.Nama = "Lynette"; m.NIM = "55555";
    m.NilaiTugas = 77.7f; m.NilaiUTS = 65.4f; m.NilaiUAS = 79.9f;
    Push(S, m);


    m.Nama = "Chasca"; m.NIM = "66666";
    m.NilaiTugas = 99.9f; m.NilaiUTS = 93.6f; m.NilaiUAS = 87.3f;
    Push(S, m);

    cout << "\n--- Stack Setelah Push 6 Mahasiswa ---\n";
    View(S);

    cout << "\n--- Melakukan Pop 1x ---\n";
    Mahasiswa popped = Pop(S);
    cout << "Mahasiswa yang di-pop:\n";
    cout << "  Nama: " << popped.Nama << ", NIM: " << popped.NIM 
         << ", NilaiAkhir: " << popped.NilaiAkhir << "\n";

    cout << "\n--- Stack Setelah 1x Pop ---\n";
    View(S);

    cout << "\n--- Update posisi ke-3 dengan data Heizou ---\n";
    Mahasiswa heizou;
    heizou.Nama = "Heizou"; heizou.NIM = "77777";
    heizou.NilaiTugas = 99.9f; heizou.NilaiUTS = 88.8f; heizou.NilaiUAS = 77.7f;
    Update(S, 3, heizou); 

    cout << "\n--- Stack Setelah Update Posisi 3 ---\n";
    View(S);

    cout << "\n--- Searching NilaiAkhir di rentang [85.5, 95.5] ---\n";
    float minR = 85.5f, maxR = 95.5f;
    vector<int> found = SearchNilaiAkhir(S, minR, maxR);
    if (found.empty()) {
        cout << "Tidak ada mahasiswa dengan NilaiAkhir dalam rentang tersebut.\n";
    } else {
        cout << "Ditemukan pada posisi (1-based): ";
        for (size_t i = 0; i < found.size(); ++i) {
            cout << found[i] << (i+1 < found.size() ? ", " : "");
        }
        cout << "\nDetail mahasiswa yang ditemukan:\n";
        for (int posOneBased : found) {
            int idx = posOneBased - 1;
            cout << "Posisi " << posOneBased << " -> Nama: " << S.data[idx].Nama
                 << ", NIM: " << S.data[idx].NIM
                 << ", NilaiAkhir: " << S.data[idx].NilaiAkhir << "\n";
        }
    }

    cout << "\n--- Bagian B: MaxNilaiAkhir ---\n";
    float maxVal;
    vector<int> posMax;
    MaxNilaiAkhir(S, maxVal, posMax);
    if (posMax.empty()) {
        cout << "Stack kosong, tidak ada nilai maksimum.\n";
    } else {
        cout << "NilaiAkhir tertinggi = " << maxVal << "\n";
        cout << "Ditemukan pada posisi(1-based): ";
        for (size_t i = 0; i < posMax.size(); ++i) {
            cout << posMax[i] << (i+1 < posMax.size() ? ", " : "");
        }
        cout << "\nDetail:\n";
        for (int p : posMax) {
            int idx = p - 1;
            cout << "Posisi " << p << " -> Nama: " << S.data[idx].Nama
                 << ", NIM: " << S.data[idx].NIM << "\n";
        }
    }

    cout << "\nSelesai.\n";
    return 0;
}

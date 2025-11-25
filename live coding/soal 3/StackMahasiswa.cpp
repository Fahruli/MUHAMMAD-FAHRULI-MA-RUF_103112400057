#include "StackMahasiswa.h"
#include <iostream>
#include <iomanip>

using namespace std;

static float hitungNilaiAkhir(const Mahasiswa &m) {
    return (0.2f * m.NilaiTugas) + (0.4f * m.NilaiUTS) + (0.4f * m.NilaiUAS);
}

bool isEmpty(const StackMahasiswa &S) {
    return S.Top == -1;
}

bool isFull(const StackMahasiswa &S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S, const Mahasiswa &M_in) {
    if (isFull(S)) {
        cout << "Stack overflow: tidak bisa push, stack penuh.\n";
        return;
    }
    Mahasiswa M = M_in;
    M.NilaiAkhir = hitungNilaiAkhir(M);
    S.Top++;
    S.data[S.Top] = M;
}

Mahasiswa Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack underflow: stack kosong. Mengembalikan Mahasiswa kosong.\n";
        Mahasiswa empty;
        empty.Nama = "";
        empty.NIM = "";
        empty.NilaiTugas = empty.NilaiUTS = empty.NilaiUAS = empty.NilaiAkhir = 0.0f;
        return empty;
    }
    Mahasiswa temp = S.data[S.Top];
    S.Top--;
    return temp;
}

// posisi: 1-based (1 = bottom awal? Untuk kemudahan pengguna, kita anggap posisi 1 = index 0)
void Update(StackMahasiswa &S, int posisi, const Mahasiswa &M_in) {
    if (posisi < 1 || posisi > S.Top + 1) {
        cout << "Posisi update di luar jangkauan. (1 sampai " << (S.Top + 1) << ")\n";
        return;
    }
    int idx = posisi - 1; // convert ke 0-based
    Mahasiswa M = M_in;
    M.NilaiAkhir = hitungNilaiAkhir(M);
    S.data[idx] = M;
}

void View(const StackMahasiswa &S) {
    cout << fixed << setprecision(2);
    cout << "---------- VIEW STACK (Top = " << S.Top << ") ----------\n";
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }
    // tampilkan dari Top ke Bawah agar mirip stack display
    for (int i = S.Top; i >= 0; --i) {
        cout << "Posisi (stack index) " << (i+1) << ":\n";
        cout << "  Nama       : " << S.data[i].Nama << "\n";
        cout << "  NIM        : " << S.data[i].NIM << "\n";
        cout << "  NilaiTugas : " << S.data[i].NilaiTugas << "\n";
        cout << "  NilaiUTS   : " << S.data[i].NilaiUTS << "\n";
        cout << "  NilaiUAS   : " << S.data[i].NilaiUAS << "\n";
        cout << "  NilaiAkhir : " << S.data[i].NilaiAkhir << "\n";
        cout << "--------------------------------------\n";
    }
}

std::vector<int> SearchNilaiAkhir(const StackMahasiswa &S, float minRange, float maxRange) {
    std::vector<int> foundPositions;
    for (int i = 0; i <= S.Top; ++i) {
        float na = S.data[i].NilaiAkhir;
        if (na >= minRange && na <= maxRange) {
            foundPositions.push_back(i+1); // return 1-based posisi
        }
    }
    return foundPositions;
}

void MaxNilaiAkhir(const StackMahasiswa &S, float &maxValue, std::vector<int> &positions) {
    positions.clear();
    if (isEmpty(S)) {
        maxValue = -1.0f;
        return;
    }
    maxValue = S.data[0].NilaiAkhir;
    for (int i = 1; i <= S.Top; ++i) {
        if (S.data[i].NilaiAkhir > maxValue) {
            maxValue = S.data[i].NilaiAkhir;
        }
    }
    for (int i = 0; i <= S.Top; ++i) {
        if (S.data[i].NilaiAkhir == maxValue) positions.push_back(i+1); // 1-based
    }
}

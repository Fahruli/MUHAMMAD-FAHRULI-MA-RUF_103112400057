#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
#include <vector>

const int MAX = 6;

struct Mahasiswa {
    std::string Nama;
    std::string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
    float NilaiAkhir; // dihitung: 20% Tugas + 40% UTS + 40% UAS
};

struct StackMahasiswa {
    Mahasiswa data[MAX];
    int Top;
};

// ADT functions / procedures
bool isEmpty(const StackMahasiswa &S);
bool isFull(const StackMahasiswa &S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, const Mahasiswa &M);
Mahasiswa Pop(StackMahasiswa &S);
void Update(StackMahasiswa &S, int posisi, const Mahasiswa &M);
void View(const StackMahasiswa &S);
std::vector<int> SearchNilaiAkhir(const StackMahasiswa &S, float minRange, float maxRange);
void MaxNilaiAkhir(const StackMahasiswa &S, float &maxValue, std::vector<int> &positions);

#endif // STACKMAHASISWA_H

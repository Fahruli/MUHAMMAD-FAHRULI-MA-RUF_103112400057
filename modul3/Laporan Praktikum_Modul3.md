# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Muhammad Fahruli Ma'ruf - 103112400057</p>

## Dasar Teori
Array dua dimensi digunakan untuk menyimpan data terstruktur, sedangkan pointer digunakan untuk mengakses dan memanipulasi data melalui alamat memori. Dengan mengombinasikan array 2D, pointer, serta fungsi, program dapat melakukan pengolahan data seperti menampilkan dan menukar nilai secara efektif dan terstruktur
## Guided

### 1. Mahasiswa (Modular) 

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

//definisi tipe (struct)
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

//deklarasi primitif(fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```
```C++
#include<iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah: " << rata2 (mhs) << endl;
    system("pause");

 return 0;
}
```
Program ini mengimplementasikan konsep modularitas dengan memisahkan definisi struct dan deklarasi fungsi (mahasiswa.h), implementasi fungsi (mahasiswa.cpp yang tidak ditampilkan namanya), dan fungsi utama (main.cpp yang tidak ditampilkan namanya) untuk menginput data mahasiswa dan menghitung rata-ratanya.

### 2. Mahasiswa (Non Modular)

```C++
#include <iostream>
using namespace std;
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};
void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah: " << rata2 (mhs) << endl;
    system("pause");

 return 0;
}
```
Program untuk menyimpan NIM dan dua nilai, kemudian menghitung dan menampilkan rata-rata kedua nilai tersebut.

## Unguided 

### 1. Program Data Mahasiswa

```C++

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

void inputMahasiswa(Mahasiswa &m) {
    cout << "Nama   : ";
    cin.ignore();
    getline(cin, m.nama);
    cout << "NIM    : ";
    getline(cin, m.nim);
    cout << "Nilai UTS   : ";
    cin >> m.uts;
    cout << "Nilai UAS   : ";
    cin >> m.uas;
    cout << "Nilai Tugas: ";
    cin >> m.tugas;

    m.nilaiAkhir = hitungNilaiAkhir(m.uts, m.uas, m.tugas);
}

void tampilMahasiswa(Mahasiswa m) {
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "Nilai Akhir : " << m.nilaiAkhir << endl;
    cout << "------------------------" << endl;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Jumlah melebihi batas!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        inputMahasiswa(mhs[i]);
    }

    cout << "\n=== DATA MAHASISWA ===\n";
    for (int i = 0; i < n; i++) {
        tampilMahasiswa(mhs[i]);
    }

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1_1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul3/Cuplikan%20layar%202025-12-31%20093533.png)

Program untuk menginput data (nama, NIM, nilai UTS, UAS, dan Tugas) mahasiswa secara berulang hingga maksimal 10 data, kemudian menghitung dan menampilkan nilai akhir.Menekankan pada pengelolaan data mahasiswa dalam jumlah banyak menggunakan array dan struct, serta penggunaan fungsi untuk menghitung nilai akhir agar program lebih terstruktur, efisien, dan mudah dipahami.

### 2. Program Implementasi ADT 

```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodeMapel = "STD";

    pelajaran pel = create_pelajaran(namaMapel, kodeMapel);
    tampil_pelajaran(pel);

    return 0;
}
```
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

pelajaran create_pelajaran(string namaMapel, string kodeMapel) {
    pelajaran pel;
    pel.namaMapel = namaMapel;
    pel.kodeMapel = kodeMapel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Pelajaran : " << pel.kodeMapel << endl;
}
```
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodeMapel);
void tampil_pelajaran(pelajaran pel);

#endif
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul3/Cuplikan%20layar%202025-12-31%20093815.png)

Program tersebut menunjukkan penerapan ADT (Abstract Data Type), di mana data pelajaran (namaMapel dan kodeMapel) dipisahkan dari cara penggunaannya. Struktur dan fungsi didefinisikan di file ADT, sedangkan main.cpp hanya memakai fungsi tersebut. Tujuannya agar program rapi, modular, dan mudah dikembangkan.

### 3.Program tukar Array dengan Pointer

```C++
#include <iostream>

using namespace std;

void tampilkan(const int M[3][3], const char* label);
void tukarArrayptr(int M1[3][3], int M2[3][3]);
void tukarNilaiptr(int *ptr1, int *ptr2); 

int main() {
    
    int MatriksA[3][3] = {
        {3, 2, 1},
        {4, 6, 5},
        {7, 9, 8}
    };
    
    int MatriksB[3][3] = {
        {12, 10, 11},
        {16, 15, 13},
        {14, 17, 19}
    };
        
    cout << "===== Matriks Awal =====" << endl;
    tampilkan(MatriksA, "Matriks A ");
    tampilkan(MatriksB, "Matriks B ");
    
 
    cout << "\nMelakukan penukaran SEMUA elemen Matriks A dan B..." << endl;
    tukarArrayptr(MatriksA, MatriksB); 
    
    cout << "\n--- Matriks Akhir ---" << endl;
    tampilkan(MatriksA, "Matriks A ");
    tampilkan(MatriksB, "Matriks B "); 

    return 0;
}

void tampilkan(const int M[3][3], const char* label) {
    cout << "\n" << label << ":" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArrayptr(int M1[3][3], int M2[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tukarNilaiptr(&M1[i][j], &M2[i][j]);
        }
    }
}
void tukarNilaiptr(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided3](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul3/Cuplikan%20layar%202025-12-31%20093815.png)

Program membuat dua array 2D berukuran 3×3, lalu menukar elemen tertentu di kedua array tersebut. Selain itu, pointer digunakan untuk menukar nilai dua variabel secara langsung (pass by reference). Tujuannya agar memahami cara mengakses, memanipulasi data array, dan penggunaan pointer dalam C++.

## Kesimpulan
Berdasarkan pengerjaan soal 1, 2, dan 3, dapat disimpulkan bahwa penerapan konsep dasar pemrograman C++ seperti array, struct, fungsi, pointer, dan Abstract Data Type (ADT) sangat penting dalam membangun program yang terstruktur dan mudah dipahami.

Pada soal 1, penggunaan array of struct memungkinkan pengelolaan data banyak mahasiswa secara efisien, sementara fungsi digunakan untuk memisahkan proses perhitungan nilai akhir agar program lebih modular. Pada soal 2, konsep ADT diterapkan dengan memisahkan definisi tipe data dan operasi ke dalam file yang berbeda, sehingga meningkatkan keterbacaan dan kemudahan pengembangan program. Selanjutnya, pada soal 3, penggunaan array dua dimensi dan pointer menunjukkan cara manipulasi data secara langsung melalui alamat memori serta penerapan konsep pass by reference.

Secara keseluruhan, ketiga soal tersebut saling melengkapi dalam melatih pemahaman pemrograman terstruktur, modularitas program, serta pengelolaan data dan memori secara efektif menggunakan bahasa C++.
## Referensi
<br>[1] Stroustrup, B. (2013). The C++ Programming Language (4th Edition). Addison-Wesley.
https://www.stroustrup.com/4th.html
<br>[2] Malik, D. S. (2018). C++ Programming: From Problem Analysis to Program Design. Cengage Learning.
https://www.cengage.com/c/c-programming-from-problem-analysis-to-program-design-8e-malik
<br>[3] Deitel, P., & Deitel, H. (2017). C++ How to Program. Pearson Education.
https://www.pearson.com/en-us/subject-catalog/p/c-how-to-program/P200000003295
<br>[4] GeeksforGeeks. (2022). Abstract Data Type (ADT) in Data Structures.
https://www.geeksforgeeks.org/abstract-data-types/
<br>[5] TutorialsPoint. (2021). C++ Arrays and Pointers.
https://www.tutorialspoint.com/cplusplus/cpp_arrays.htm
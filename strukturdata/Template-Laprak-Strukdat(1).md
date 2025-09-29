# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Fahruli Ma'ruf - 103112400057</p>

## Dasar Teori
C++ adalah bahasa pemrograman turunan C yang mendukung paradigma prosedural dan berorientasi objek (OOP). Bahasa ini bersifat compiled, sehingga kode diterjemahkan langsung menjadi bahasa mesin dan menghasilkan program yang cepat serta efisien. Struktur program C++ terdiri atas header (misalnya #include <iostream> untuk fasilitas input–output), namespace (using namespace std;), dan fungsi main() sebagai titik awal eksekusi. Pembuatan pola angka memanfaatkan perulangan bersarang (nested loop), di mana loop luar mengatur jumlah baris sedangkan loop dalam mencetak angka menurun, tanda bintang, dan angka menaik dengan bantuan operator aritmatika, perbandingan, serta increment/decrement untuk mengontrol nilai iterasi.

## Guided 

### 1. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "masukkan angka:";
    cin >> angka;
    cout << "angka yang anda masukkan adalah:" << angka << endl;
    return 0;
}
```
Menerima input bilangan bulat dari pengguna dan setelah itu menampilkannya kembali ke layar.

### 2. ...

```C++
#include <iostream>
using namespace std;
int main() {
    int angka1, angka2;
    cout << "masukkan angka1 :";
    cin >> angka1;
    cout << "masukkan angka2:";
    cin >> angka2;

    cout << "penjumlahan :" << angka1 + angka2 << endl;
    cout << "pengurangan :" << angka1 - angka2 << endl;
    cout << "perkalian :" << angka1 * angka2 << endl;
    cout << "pembagian :" << angka1 / angka2 << endl;
    cout << "sisa bagi :" << angka1 % angka2 << endl;
    return 0;
}
```
Menerima inputtan dari dua bilangan bulat, kemudian menghitung dan menampilkan hasil dari penjumlahan,pengurangan,perkalian,pembagian, dan sisa bagi.

### 3. ...

```C++
#include <iostream>
using namespace std;
int main() {
    int angka1, angka2;
    cout << "masukkan angka1 :";
    cin >> angka1;
    cout << "masukkan angka2:";
    cin >> angka2;

    if (angka1 < angka2) {
      cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
        }

    if (angka1 == angka2){
       cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 != angka2){
       cout << angka1 << " angka berbeda " << angka2 << endl;
    }

    int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;   
    cout << "masukan pilihan: " << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "penjumlahan: " << angka1 + angka2 << endl;
            break;
        case 2:
            cout << " pengurangan: " << angka1 - angka2 << endl;
            break;
        default:
            cout << "pilihan salah" << endl;
}
    return 0;
}
```
Menerima input dua bilangan bulat,kemudian membandingkan angka (lebih dari atau kurang dari) lalu memilih opsi (1 penjumlahan atau 2 pengurangan) dan menampilkan hasil dari opsi yang dipilih.

### 4. ...

```C++
#include <iostream>
using namespace std;

 int main(){
    int angka1;
    cout << "masukan angka1 : ";
    cin >> angka1;

    for (int i = 0; i  < angka1; i++){
      cout << i << " - ";
    }
    cout << endl;


    int j = 10;
    while (j > angka1){
      cout << j << " - ";
      j--;
    }

    cout << endl;
    int k = 10;
    do {
      cout << k << " - ";
    }while (k < angka1);

     return  0;
    
 } 
 ```
 Menerima input satu bilangan bulat kemudian didemostrasikan tiga jenis perulangan.

 ### 5. ...

```C++
#include<iostream>
using namespace std;

int main(){
    const int MAX = 5;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << endl;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
    }

    int j = 0;
    while(j < MAX){
        cout << "nama siswa : " << siswa[j].nama << ", nilai : " << siswa[j].nilai << endl;
    }
    return 0;
}
```
Sebuah program untuk menyimpan dan menampilkan data rapor siswa.
## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    float x1, x2;

    cout << "Masukkan angka pertama : ";
    cin >> x1;
    cout << "Masukkan angka kedua   : ";
    cin >> x2;

    cout << fixed << setprecision(2);
    cout << "\n=== HASIL PERHITUNGAN ===" << endl;
    cout << "Penjumlahan : " << x1 + x2 << endl;
    cout << "Pengurangan : " << x1 - x2 << endl;
    cout << "Perkalian   : " << x1 * x2 << endl;

    if (x2 != 0) {
        cout << "Pembagian   : " << x1 / x2 << endl;
    } else {
        cout << "Pembagian   : Tidak bisa (pembagi 0)" << endl;
    }

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1]https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/strukturdata/WhatsApp%20Image%202025-09-29%20at%2022.35.53.jpeg



penjelasan unguided 1 
Program C++ ini meminta dua angka dari pengguna, lalu menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian.
Header <iomanip> dipakai untuk mengatur hasil perhitungan agar tampil dengan dua angka desimal (fixed << setprecision(2)).
Percabangan if memastikan pembagian hanya dilakukan jika angka kedua bukan 0, sehingga mencegah error.

### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
#include <string>
using namespace std;

string angkaKeKata(int x) {
    const string satuan[]  = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
    const string belasan[] = {"sepuluh","sebelas","dua belas","tiga belas","empat belas",
                              "lima belas","enam belas","tujuh belas","delapan belas","sembilan belas"};
    const string puluhan[] = {"","","dua puluh","tiga puluh","empat puluh",
                              "lima puluh","enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};

    if (x >= 0 && x <= 9) {
        return satuan[x];
    } 
    else if (x >= 10 && x <= 19) {
        return belasan[x - 10];
    } 
    else if (x >= 20 && x <= 99) {
        if (x % 10 == 0) {
            return puluhan[x / 10];
        } else {
            return puluhan[x / 10] + " " + satuan[x % 10];
        }
    } 
    else if (x == 100) {
        return "seratus";
    }
    return "di luar jangkauan";
}

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (cin.fail()) {
        cout << "Input tidak valid! Harap masukkan angka." << endl;
        return 1;
    }

    if (n >= 0 && n <= 100) {
        cout << n << " = " << angkaKeKata(n) << endl;
    } else {
        cout << "Angka harus antara 0 sampai 100!" << endl;
    }

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1]https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/strukturdata/WhatsApp%20Image%202025-09-29%20at%2022.37.21.jpeg

penjelasan unguided 2
Inti program tersebut adalah mengubah angka 0–100 yang dimasukkan pengguna menjadi bentuk kata dalam bahasa Indonesia dengan memanfaatkan fungsi, array string, dan logika percabangan.

### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Masukkan angka: ";
    cin >> x;

    int spasi = 1; 

    for (int i = x; i >= 1; i--) {
        for (int j = 1; j <= spasi; j++) {
            cout << " ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << "*";
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        cout << endl;
        spasi++;
    }
    for (int j = 1; j <= spasi; j++) {
        cout << " ";
    }
    cout << "*" << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1]https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/strukturdata/WhatsApp%20Image%202025-09-29%20at%2022.37.54.jpeg


penjelasan unguided 3
Inti program tersebut adalah mencetak pola angka berbentuk segitiga yang bergeser ke kanan, dengan angka menurun di kiri, tanda * di tengah, dan angka menaik di kanan, menggunakan perulangan dan penambahan spasi tiap baris.

## Kesimpulan
Pemahaman struktur dasar, perulangan, dan operator dalam C++ memungkinkan pembuatan program pola angka seperti mirror number yang menampilkan susunan angka menurun dan menaik dengan karakter khusus secara terstruktur dan efisien.
...

## Referensi
[1]Rizki Dwi Oktaviana. ARTIKEL ILMIAH BAHASA PEMROGRAMAN C++. Program Studi Teknik Informatika Politeknik Purbaya, Tegal.
Sumber membahas sejarah, fitur, struktur program, operator, serta contoh penerapan bahasa C++
https://www.academia.edu/41591022/ARTIKEL_ILMIAH_BAHASA_PEMROGRAMAN_C
<br>...

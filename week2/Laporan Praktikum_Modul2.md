# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Muhammad Fahruli Ma'ruf - 103112400057</p>

## Dasar Teori
Dalam bahasa pemrograman C, baik array maupun pointer memiliki peran penting dalam pengelolaan data dan memori, yaitu:
Array adalah kumpulan elemen bertipe sama yang tersimpan berurutan di memori dan diakses menggunakan indeks. Nama array mewakili alamat elemen pertama dan memiliki ukuran tetap.

Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Pointer lebih fleksibel karena bisa diarahkan ke alamat berbeda dan digunakan untuk manipulasi data atau alokasi memori dinamis.

Meskipun sering digunakan bersama, array dan pointer berbeda secara konsep: array adalah blok data tetap, sedangkan pointer hanyalah penunjuk ke lokasi data.

Dalam C, nama array dapat “berubah” menjadi pointer ke elemen pertama, sehingga keduanya tampak serupa saat digunakan dalam operasi seperti arr[i] atau *(arr + i).


### 1. ...

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i <= 5; i++){
        cout << "masukkan volume indeks ke-" << i << " : ";
        cin >> arr[i];
    } 
    int j = 0 ;
    while(j < 5){
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
penjelasan singkat guided 1
Program tersebut menerima 5 angka dari pengguna, lalu menampilkan kembali angka-angka tersebut.
### 2. ...

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

       //perkalian matriks 2x2
    for (int i = 0; i < 2; i++){                  //perulangan baris
        for(int j = 0; j < 2; j++){              //perulangan kolom
            for(int k = 0; k < 2; k++){         //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "hasil perkalian : " << endl;
    tampilkanHasil(arrD);
    return 0;
}
```
penjelasan singkat guided 2
Program ini digunakan untuk melakukan penjumlahan dan perkalian dua matriks 2x2, lalu menampilkan hasilnya.

### 3. ...

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int*ptr=arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for (int i = 0; i < 5; i++){
        cout<<"eleem array ke-0"<< i+1<<"menggunakan pointer"<<*(ptr+i)<<endl;
    }

    //mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; i++){
        cout<<"Elemen array ke-"<< i+1 <<"menggunakan indeks"<<arr[i]<<endl;
    }
    return 0;
    
}
```
penjelasan singkat guided 3
Tujuan utama program ini adalah untuk memperlihatkan hubungan antara array dan pointer, serta cara mengakses elemen array dengan dua metode yang berbeda namun menghasilkan nilai yang sama.Hal ini memperlihatkan bahwa dalam C++, nama array sebenarnya adalah pointer ke elemen pertamanya, sehingga elemen array dapat diakses baik menggunakan pointer maupun indeks.

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
 Penjelasan singkat guided 4
 Penjelasan ini  menunjukkan perbedaan cara kerja tiga jenis perulangan (loop) dalam C++, yaitu for, while, dan do-while.

## Unguided 

### 1. 

```C++
#include <iostream>
using namespace std;

const int N = 3;

void tampil(const int M[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << M[i][j] << (j + 1 < N ? '\t' : '\n');
		}
	}
}

void jumlahMatriks(const int A[N][N], const int B[N][N], int C[N][N]) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			C[i][j] = A[i][j] + B[i][j];
}

void kurangMatriks(const int A[N][N], const int B[N][N], int C[N][N]) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			C[i][j] = A[i][j] - B[i][j];
}

void kaliMatriks(const int A[N][N], const int B[N][N], int C[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int sum = 0;
			for (int k = 0; k < N; ++k) sum += A[i][k] * B[k][j];
			C[i][j] = sum;
		}
	}
}

int main() {
	int A[N][N] = {
		{7, 12, 22},
		{31, 6, 41},
		{15, 19, 36}
	};
	int B[N][N] = {
		{11, 34, 7},
		{3, 25, 41},
		{5, 18, 33}
	};
	int C[N][N];

	int pilih;
	do {
		cout << "--- Menu Program Matriks ---\n";
		cout << "1. Penjumlahan matriks\n";
		cout << "2. Pengurangan matriks\n";
		cout << "3. Perkalian matriks\n";
		cout << "4. Keluar\n";
		cout << "Pilih: ";
		if (!(cin >> pilih)) return 0;

		switch (pilih) {
			case 1:
				jumlahMatriks(A, B, C);
				cout << "\nHasil A + B:\n";
				tampil(C);
				cout << '\n';
				break;
			case 2:
				kurangMatriks(A, B, C);
				cout << "\nHasil A - B:\n";
				tampil(C);
				cout << '\n';
				break;
			case 3:
				kaliMatriks(A, B, C);
				cout << "\nHasil A x B:\n";
				tampil(C);
				cout << '\n';
				break;
			case 4:
				cout << "Keluar.\n";
				break;
			default:
				cout << "Pilihan tidak valid.\n\n";
		}
	} while (pilih != 4);

	return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1] https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/week2/Screenshot%20Output%20Unguided1.jpeg

penjelasan unguided 1 
Inti tujuan program ini adalah untuk mempraktikkan operasi aritmetika pada matriks (penjumlahan, pengurangan, dan perkalian) menggunakan fungsi terpisah serta menampilkan hasilnya melalui menu interaktif di C++.

### 2. 

```C++
#include <iostream>
using namespace std;

int main() {
	int panjang = 10, lebar = 5, luas = 0, keliling = 0;

	int *ptrPanjang = &panjang;
	int *ptrLebar = &lebar;

	cout << "--- Nilai Awal ---\n";
	cout << "Panjang: " << panjang << '\n';
	cout << "Lebar: " << lebar << "\n\n";

	luas = (*ptrPanjang) * (*ptrLebar);
	keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

	cout << "--- Hasil Perhitungan ---\n";
	cout << "Luas Persegi Panjang: " << luas << '\n';
	cout << "Keliling Persegi Panjang: " << keliling << "\n\n";

	*ptrPanjang = 12;
	*ptrLebar = 6;

	luas = (*ptrPanjang) * (*ptrLebar);
	keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

	cout << "--- Nilai Setelah Diubah Melalui Pointer ---\n";
	cout << "Panjang Baru: " << panjang << '\n';
	cout << "Lebar Baru: " << lebar << '\n';
	cout << "Luas Baru: " << luas << '\n';
	cout << "Keliling Baru: " << keliling << '\n';

	return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1] https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/week2/Screenshot%20Output%20Unguided2.jpeg

penjelasan unguided 2
Tujuan program ini adalah untuk menunjukkan cara penggunaan pointer dalam mengakses dan mengubah nilai variabel, serta menghitung luas dan keliling persegi panjang menggunakan nilai yang diambil dari pointer.

## Kesimpulan
Array dan pointer memiliki fungsi penting dalam bahasa C. Array digunakan untuk menyimpan data secara berurutan dengan ukuran tetap, sedangkan pointer digunakan untuk mengakses dan mengelola alamat memori secara fleksibel. Keduanya saling berkaitan namun berbeda secara konsep, di mana array berfokus pada penyimpanan data, sementara pointer berfokus pada pengelolaan alamat memori.

## Referensi
[1] Brawlyvonfabre. (n.d.). Array dan Pointer. Diakses pada 6 Oktober 2025, dari https://brawlyvonfabre.blogspot.com/p/array-dan-pointer.html
[2] Penelitian.id. (2021, Juli). Perbedaan Array dan Pointer Bahasa C. Diakses dari https://www.penelitian.id/2021/07/perbedaan-array-dan-pointer-bahasa-c.html
[3] Zulfan. (n.d.). Makalah Mengenai Array dan Pointer. Diakses dari https://id.scribd.com/document/783356061/MAKALAH-ZULFAN-MENGENAI-ARRAY-DAN-POINTER-ZULFAN
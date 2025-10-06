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
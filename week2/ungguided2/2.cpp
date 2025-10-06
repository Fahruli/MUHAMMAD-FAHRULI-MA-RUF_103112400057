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
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

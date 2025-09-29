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

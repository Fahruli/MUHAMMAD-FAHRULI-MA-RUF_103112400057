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

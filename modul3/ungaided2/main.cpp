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

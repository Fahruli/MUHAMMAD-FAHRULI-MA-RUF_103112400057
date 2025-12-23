#include "mll.h"

// ================= CREATE =================
void MLL::createListParent() {
    LP.first = LP.last = NULL;
}

void MLL::createListChild(Parent *P) {
    P->firstChild = P->lastChild = NULL;
}

// ================= ALOKASI =================
Parent* MLL::alokasiNodeParent(string id, string nama) {
    Parent *P = new Parent;
    P->IDGenre = id;
    P->namaGenre = nama;
    P->next = P->prev = NULL;
    P->firstChild = P->lastChild = NULL;
    return P;
}

Child* MLL::alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    Child *C = new Child;
    C->IDFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = C->prev = NULL;
    return C;
}

// ================= DEALOKASI =================
void MLL::dealokasiNodeParent(Parent *P) {
    delete P;
}

void MLL::dealokasiNodeChild(Child *C) {
    delete C;
}

// ================= INSERT =================
void MLL::insertFirstParent(Parent *P) {
    if (LP.first == NULL) {
        LP.first = LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void MLL::insertLastChild(Parent *P, Child *C) {
    if (P->firstChild == NULL) {
        P->firstChild = P->lastChild = C;
    } else {
        P->lastChild->next = C;
        C->prev = P->lastChild;
        P->lastChild = C;
    }
}

// ================= DELETE =================
void MLL::hapusListChild(Parent *P) {
    Child *C = P->firstChild;
    while (C != NULL) {
        Child *temp = C;
        C = C->next;
        dealokasiNodeChild(temp);
    }
    P->firstChild = P->lastChild = NULL;
}

void MLL::deleteAfterParent(string idParent) {
    Parent *P = LP.first;

    while (P != NULL && P->IDGenre != idParent) {
        P = P->next;
    }

    if (P != NULL && P->next != NULL) {
        Parent *hapus = P->next;

        hapusListChild(hapus);

        P->next = hapus->next;
        if (hapus->next != NULL)
            hapus->next->prev = P;
        else
            LP.last = P;

        dealokasiNodeParent(hapus);
    }
}

// ================= SEARCH =================
void MLL::searchFilmByRatingRange(float min, float max) {
    Parent *P = LP.first;
    int posParent = 1;

    while (P != NULL) {
        Child *C = P->firstChild;
        int posChild = 1;

        while (C != NULL) {
            if (C->ratingFilm >= min && C->ratingFilm <= max) {
                cout << "\nData Film ditemukan pada list child dari node parent "
                     << P->namaGenre << " pada posisi ke-" << posChild << endl;

                cout << "--- Data Film (Child) ---\n";
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "ID Film : " << C->IDFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit\n";
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;

                cout << "--- Data Genre (Parent) ---\n";
                cout << "ID Genre : " << P->IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << posParent << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
        posParent++;
    }
}

// ================= PRINT =================
void MLL::printStrukturMLL() {
    Parent *P = LP.first;
    int i = 1;

    while (P != NULL) {
        cout << "\n=== Parent " << i << " ===\n";
        cout << "ID Genre : " << P->IDGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;

        Child *C = P->firstChild;
        int j = 1;
        while (C != NULL) {
            cout << " - Child " << j << " :\n";
            cout << "   ID Film : " << C->IDFilm << endl;
            cout << "   Judul Film : " << C->judulFilm << endl;
            cout << "   Durasi Film : " << C->durasiFilm << " menit\n";
            cout << "   Tahun Tayang : " << C->tahunTayang << endl;
            cout << "   Rating Film : " << C->ratingFilm << endl;
            C = C->next;
            j++;
        }
        P = P->next;
        i++;
    }
}

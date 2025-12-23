#ifndef MLL_H
#define MLL_H

#include <iostream>
using namespace std;

// ===== CHILD NODE (FILM) =====
struct Child {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    Child *next, *prev;
};

// ===== PARENT NODE (GENRE) =====
struct Parent {
    string IDGenre;
    string namaGenre;
    Parent *next, *prev;
    Child *firstChild, *lastChild;
};

// ===== LIST =====
struct ListParent {
    Parent *first, *last;
};

class MLL {
private:
    ListParent LP;

public:
    // create
    void createListParent();
    void createListChild(Parent *P);

    // alokasi & dealokasi
    Parent* alokasiNodeParent(string id, string nama);
    Child* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
    void dealokasiNodeParent(Parent *P);
    void dealokasiNodeChild(Child *C);

    // insert
    void insertFirstParent(Parent *P);
    void insertLastChild(Parent *P, Child *C);

    // delete
    void hapusListChild(Parent *P);
    void deleteAfterParent(string idParent);

    // search
    void searchFilmByRatingRange(float min, float max);

    // print
    void printStrukturMLL();
};

#endif

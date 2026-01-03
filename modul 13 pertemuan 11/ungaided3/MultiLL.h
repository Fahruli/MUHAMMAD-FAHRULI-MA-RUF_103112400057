#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

/* ===== STRUCT DATA ===== */
struct GolHewan {
    string id;
    string nama;
};

struct Hewan {
    string id;
    string nama;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct Parent *AdrParent;
typedef struct Child *AdrChild;

/* ===== CHILD ===== */
struct Child {
    Hewan data;
    AdrChild next;
    AdrChild prev;
};

struct ListChild {
    AdrChild first;
    AdrChild last;
};

/* ===== PARENT ===== */
struct Parent {
    GolHewan data;
    AdrParent next;
    AdrParent prev;
    ListChild anak;
};

struct ListParent {
    AdrParent first;
    AdrParent last;
};

/* ===== PROTOTYPE ===== */
void initParent(ListParent &L);
void initChild(ListChild &L);

AdrParent newParent(string id, string nama);
AdrChild newChild(string id, string nama, string habitat, bool ekor, float bobot);

void addParentLast(ListParent &L, AdrParent P);
void addChildLast(ListChild &L, AdrChild C);

void tampilMLL(ListParent L);

/* UNGUIDED 2 */
void searchHewanTidakBerekor(ListParent L);

/* UNGUIDED 3 */
void deleteAfterParent(ListParent &L, AdrParent prec);

#endif

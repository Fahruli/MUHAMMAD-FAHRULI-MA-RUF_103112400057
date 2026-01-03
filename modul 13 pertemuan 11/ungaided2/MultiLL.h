#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

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

struct Child {
    Hewan data;
    AdrChild next;
    AdrChild prev;
};

struct ListChild {
    AdrChild first;
    AdrChild last;
};

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

void initParent(ListParent &L);
void initChild(ListChild &L);

AdrParent newParent(string id, string nama);
AdrChild newChild(string id, string nama, string habitat, bool ekor, float bobot);

void addParentLast(ListParent &L, AdrParent P);
void addChildLast(ListChild &L, AdrChild C);

void tampilMLL(ListParent L);

void searchHewanTidakBerekor(ListParent L);

#endif

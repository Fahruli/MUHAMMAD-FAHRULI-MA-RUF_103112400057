#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct {
    address first;
} List;

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
void printInfo(List L);
int nbList(List L);
void deleteList(List &L);

#endif

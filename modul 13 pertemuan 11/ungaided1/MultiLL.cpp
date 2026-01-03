#include "MultiLL.h"

void initParent(ListParent &L){
    L.first = L.last = NULL;
}

void initChild(ListChild &L){
    L.first = L.last = NULL;
}

AdrParent newParent(string id, string nama){
    AdrParent P = new Parent;
    P->data.id = id;
    P->data.nama = nama;
    initChild(P->anak);
    P->next = P->prev = NULL;
    return P;
}

AdrChild newChild(string id, string nama, string habitat, bool ekor, float bobot){
    AdrChild C = new Child;
    C->data.id = id;
    C->data.nama = nama;
    C->data.habitat = habitat;
    C->data.ekor = ekor;
    C->data.bobot = bobot;
    C->next = C->prev = NULL;
    return C;
}

void addParentLast(ListParent &L, AdrParent P){
    if(L.first == NULL){
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void addChildLast(ListChild &L, AdrChild C){
    if(L.first == NULL){
        L.first = L.last = C;
    } else {
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}

void tampilMLL(ListParent L){
    AdrParent P = L.first;
    int i = 1;
    while(P != NULL){
        cout << "=== Parent " << i++ << " ===\n";
        cout << "ID Golongan : " << P->data.id << endl;
        cout << "Nama Golongan : " << P->data.nama << endl;

        AdrChild C = P->anak.first;
        if(C == NULL){
            cout << "(tidak ada child)\n";
        } else {
            int j = 1;
            while(C != NULL){
                cout << " - Child " << j++ << endl;
                cout << "    ID Hewan : " << C->data.id << endl;
                cout << "    Nama Hewan : " << C->data.nama << endl;
                cout << "    Habitat : " << C->data.habitat << endl;
                cout << "    Ekor : " << C->data.ekor << endl;
                cout << "    Bobot : " << C->data.bobot << endl;
                C = C->next;
            }
        }
        cout << "------------------------\n";
        P = P->next;
    }
}

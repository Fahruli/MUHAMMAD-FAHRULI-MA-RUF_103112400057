#include "MultiLL.h"

/* ===== INIT ===== */
void initParent(ListParent &L){
    L.first = L.last = NULL;
}

void initChild(ListChild &L){
    L.first = L.last = NULL;
}

/* ===== CREATE NODE ===== */
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

/* ===== INSERT PARENT ===== */
void addParentLast(ListParent &L, AdrParent P){
    if(L.first == NULL){
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

/* ===== INSERT CHILD ===== */
void addChildLast(ListChild &L, AdrChild C){
    if(L.first == NULL){
        L.first = L.last = C;
    } else {
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}

/* ===== PRINT ===== */
void tampilMLL(ListParent L){
    AdrParent P = L.first;
    int i = 1;

    while(P != NULL){
        cout << "=== Parent " << i++ << " ===" << endl;
        cout << "ID Golongan : " << P->data.id << endl;
        cout << "Nama Golongan : " << P->data.nama << endl;

        AdrChild C = P->anak.first;
        if(C == NULL){
            cout << "(tidak ada child)" << endl;
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
        cout << "------------------------" << endl;
        P = P->next;
    }
}

/* ===== UNGUIDED 2 : SEARCH ===== */
void searchHewanTidakBerekor(ListParent L){
    AdrParent P = L.first;

    while(P != NULL){
        AdrChild C = P->anak.first;
        int posChild = 1;

        while(C != NULL){
            if(C->data.ekor == false){
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->data.nama
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Hewan : " << C->data.id << endl;
                cout << "Nama Hewan : " << C->data.nama << endl;
                cout << "Habitat : " << C->data.habitat << endl;
                cout << "Ekor : " << C->data.ekor << endl;
                cout << "Bobot : " << C->data.bobot << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Golongan : " << P->data.id << endl;
                cout << "Nama Golongan : " << P->data.nama << endl;
                cout << "------------------------" << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
    }
}

/* ===== UNGUIDED 3 : DELETE PARENT ===== */
void deleteAfterParent(ListParent &L, AdrParent prec){
    if(prec != NULL && prec->next != NULL){
        AdrParent del = prec->next;

        // putuskan parent
        prec->next = del->next;
        if(del->next != NULL){
            del->next->prev = prec;
        } else {
            L.last = prec;
        }

        // hapus semua child
        AdrChild C;
        while(del->anak.first != NULL){
            C = del->anak.first;
            del->anak.first = C->next;
            delete C;
        }

        delete del;
    }
}

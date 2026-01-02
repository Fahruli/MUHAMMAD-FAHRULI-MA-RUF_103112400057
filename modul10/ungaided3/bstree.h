#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

/* fungsi dasar */
address alokasi(infotype x);
void insertNode(address &root, infotype x);

/* traversal */
void printInorder(address root);
void printPreorder(address root);
void printPostorder(address root);

/* nomor 2 */
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif

#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

// Membuat queue kosong
void createQueue(QueueEksedisi &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(QueueEksedisi Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(QueueEksedisi Q) {
    return (Q.tail == MAX - 1);
}

bool enQueue(QueueEksedisi &Q, Paket P) {
    if (isFull(Q)) return false;

    if (isEmpty(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.data[Q.tail] = P;
    return true;
}

bool deQueue(QueueEksedisi &Q) {
    if (isEmpty(Q)) return false;

    if (Q.head == Q.tail) {
        Q.head = Q.tail = -1;
        return true;
    }

    for (int i = Q.head; i < Q.tail; i++) {
        Q.data[i] = Q.data[i + 1];
    }
    Q.tail--;

    return true;
}

void viewQueue(QueueEksedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong.\n";
        return;
    }

    cout << "\nIsi Queue:\n";
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << "- " << Q.data[i].KodeResi << ", "
             << Q.data[i].NamaPengirim << ", "
             << Q.data[i].BeratBarang << "kg, "
             << Q.data[i].Tujuan << "\n";
    }
}

long long TotalBiayaPengiriman(QueueEksedisi Q) {
    long long biaya = 0;
    for (int i = Q.head; i <= Q.tail; i++) {
        biaya += Q.data[i].BeratBarang * 8250;
    }
    return biaya;
}
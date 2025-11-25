#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <string>
using namespace std;

const int MAX = 5;

// Struktur Paket
struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

// Struktur Queue Ekspedisi
struct QueueEksedisi {
    Paket data[MAX];
    int head;
    int tail;
};

// Prototipe fungsi
void createQueue(QueueEksedisi &Q);
bool isEmpty(QueueEksedisi Q);
bool isFull(QueueEksedisi Q);
bool enQueue(QueueEksedisi &Q, Paket P);
bool deQueue(QueueEksedisi &Q);
void viewQueue(QueueEksedisi Q);
long long TotalBiayaPengiriman(QueueEksedisi Q);

#endif
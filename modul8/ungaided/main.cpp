#include <iostream>
#include "queue.h"
using namespace std;

// deklarasi fungsi dari file alternatif
void enqueue(Queue &Q, infotype x);
void dequeue(Queue &Q);

int main(){
    Queue Q;
    CreateQueue(Q);

    cout << "H - T | Queue Info\n";
    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}

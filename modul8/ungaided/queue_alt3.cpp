#include <iostream>
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return Q.head == -1;
}

bool isFullQueue(Queue Q){
    return (Q.tail + 1) % MAX == Q.head;
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "queue penuh\n";
    } else {
        if(isEmptyQueue(Q)){
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = x;
    }
}

void dequeue(Queue &Q){
    if(!isEmptyQueue(Q)){
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAX;
        }
    }
}

void printInfo(Queue Q){
    if(isEmptyQueue(Q)){
        cout << "empty queue\n";
    } else {
        cout << "H=" << Q.head << " T=" << Q.tail << " | ";
        int i = Q.head;
        while(true){
            cout << Q.info[i] << " ";
            if(i == Q.tail) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

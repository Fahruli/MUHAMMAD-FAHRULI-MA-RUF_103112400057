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
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "queue penuh\n";
    } else {
        if(isEmptyQueue(Q)){
            Q.head = 0;
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

void dequeue(Queue &Q){
    if(!isEmptyQueue(Q)){
        Q.head++;
        if(Q.head > Q.tail){
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void printInfo(Queue Q){
    if(isEmptyQueue(Q)){
        cout << "empty queue\n";
    } else {
        cout << "H=" << Q.head << " T=" << Q.tail << " | ";
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}

# <h1 align="center">Laporan Praktikum Modul 14 - Graph </h1>
<p align="center">Muhammad Fahruli Ma'ruf - 103112400057</p>

## Dasar Teori
Graph merupakan struktur data non-linier yang terdiri dari simpul (vertex) dan sisi (edge) untuk merepresentasikan hubungan antar data. Graph tidak berarah memiliki hubungan dua arah antar simpul, sehingga jika satu simpul terhubung dengan simpul lain, maka keduanya saling bertetangga.

Graph dapat direpresentasikan menggunakan adjacency matrix atau adjacency list. Adjacency list lebih efisien untuk graph dinamis dan pada praktikum ini direalisasikan menggunakan multi linked list. Untuk menelusuri graph digunakan algoritma Depth First Search (DFS) yang bersifat mendalam dan Breadth First Search (BFS) yang bersifat melebar berdasarkan level simpul.

## Guided

### 1.Graph
#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```
#### graph_edge.cpp
```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph x) {
    adrNode p = G->first;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->nextNode;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        //Insert First di list Edge
        pStart->firstEdge = newEdge;
    }
}
```
#### graph_init.cpp
```C++
#include "graph.h"

void createGraph(Graph &G) {
    G->first = NULL;
}

adrNode allocateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = false;
    P->firstEdge = NULL;
    P->nextNode = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G->first == NULL) {
        G->first = P;
    } else {
        adrNode Q = G->first;
        while (Q->nextNode != NULL) {
            Q = Q->nextNode;
        }
        Q->nextNode = P;
    }
}
```

#### graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode p = G->first;
    while (p != NULL) {
        cout << "Node " << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->node->info << " ";
            e = e->next;
        }
        cout << endl;
        p = p->nextNode;
    }
}
```

#### main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Create Graph
    Graph G = new elmGraph;
    createGraph(G);

    // 2. Insert Nodes
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // 3. Connect Nodes (Edges)
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    // 4. Print Graph Structure
    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```
Program ini dilakukan pembuatan struktur dasar graph menggunakan adjacency list berbasis pointer. Program mencakup proses inisialisasi graph, penambahan simpul, penghubungan antar simpul menggunakan edge, serta penampilan struktur graph. Tahapan ini bertujuan untuk memahami konsep dasar graph dan cara kerja multi linked list dalam merepresentasikan hubungan antar data.

## Unguided 
### 1. Implementasi Graph Tidak Berarah Lengkap dengan DFS dan BFS
#### Graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```
#### Graph.cpp
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode InsertNode(Graph &G, infoGraph X) {
    adrNode N = new ElmNode;
    N->info = X;
    N->visited = 0;
    N->firstEdge = NULL;
    N->next = NULL;

    if (G.first == NULL)
        G.first = N;
    else {
        adrNode temp = G.first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = N;
    }
    return N;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode N = G.first;
    while (N != NULL) {
        cout << N->info << " : ";
        adrEdge E = N->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        N = N->next;
    }
}

void ResetVisited(Graph &G) {
    adrNode N = G.first;
    while (N != NULL) {
        N->visited = 0;
        N = N->next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1)
        return;

    cout << N->info << " ";
    N->visited = 1;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->node);
        E = E->next;
    }
}

struct Queue {
    adrNode data;
    Queue* next;
};

void enqueue(Queue* &front, Queue* &rear, adrNode N) {
    Queue* Q = new Queue{N, NULL};
    if (rear == NULL)
        front = rear = Q;
    else {
        rear->next = Q;
        rear = Q;
    }
}

adrNode dequeue(Queue* &front, Queue* &rear) {
    if (front == NULL)
        return NULL;
    Queue* Q = front;
    adrNode N = Q->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete Q;
    return N;
}

void PrintBFS(Graph G, adrNode start) {
    Queue *front = NULL, *rear = NULL;

    start->visited = 1;
    enqueue(front, rear, start);

    while (front != NULL) {
        adrNode N = dequeue(front, rear);
        cout << N->info << " ";

        adrEdge E = N->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                enqueue(front, rear, E->node);
            }
            E = E->next;
        }
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');
    adrNode E = InsertNode(G, 'E');
    adrNode F = InsertNode(G, 'F');
    adrNode Gg = InsertNode(G, 'G');
    adrNode H = InsertNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << " GRAPH \n";
    PrintInfoGraph(G);

    cout << "\nDFS : ";
    PrintDFS(G, A);
    ResetVisited(G);

    cout << "\nBFS : ";
    PrintBFS(G, A);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/Fahruli/MUHAMMAD-FAHRULI-MA-RUF_103112400057/blob/main/modul%2014/ungaided1/Cuplikan%20layar%202026-01-03%20182327.png)

**Program C++ ini** graph dikembangkan menjadi graph tidak berarah dan dilengkapi dengan algoritma DFS dan BFS. DFS menelusuri graph secara mendalam hingga simpul terdalam, sedangkan BFS menelusuri graph secara bertahap berdasarkan tingkat kedalaman simpul menggunakan queue. Variabel visited digunakan untuk memastikan setiap simpul hanya dikunjungi satu kali.
## Kesimpulan
Dari praktikum Modul 14 dapat disimpulkan bahwa struktur data graph efektif untuk merepresentasikan hubungan data yang kompleks. Implementasi graph menggunakan multi linked list memudahkan pengelolaan simpul dan sisi secara dinamis. Algoritma DFS dan BFS memiliki karakteristik penelusuran yang berbeda dan dapat digunakan sesuai kebutuhan permasalahan.

## Referensi
[1].Cormen, T. H., et al. (2022). Introduction to Algorithms. MIT Press.
https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/

[2]. Sedgewick, R., & Wayne, K. (2023). Algorithms. Princeton University.
https://algs4.cs.princeton.edu/home/

[3]. GeeksforGeeks. (2024). Graph Data Structure.
https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/

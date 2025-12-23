#ifndef GRAP_H
#define GRAP_H

#include <iostream>
using namespace std;

struct Edge;
struct Node;

struct Edge {
    Node *to;
    Edge *next;
};

struct Node {
    char nama;
    bool aktif;
    bool visited;
    Edge *firstEdge;
    Node *next;
};

class Graph {
private:
    Node *firstNode;

public:
    Graph();

    Node* createNode(char nama);
    void addNode(char nama);
    void addEdge(char from, char to);

    Node* findNode(char nama);

    void resetVisited();
    void DFS(Node *start, char ignored);

    bool isConnected(char ignored);
    void analisisKotaKritis();

    void printGraph();
};

#endif

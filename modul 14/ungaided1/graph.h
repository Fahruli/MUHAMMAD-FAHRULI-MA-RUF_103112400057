#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

// Prototype
void CreateGraph(Graph &G);
adrNode CreateNode(infoGraph X);
adrEdge CreateEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
adrNode FindNode(Graph G, infoGraph X);

void PrintInfoGraph(Graph G);
void ResetVisited(Graph G);

void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif

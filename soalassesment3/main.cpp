#include "grap.h"

int main() {
    Graph G;

    G.addNode('A');
    G.addNode('B');
    G.addNode('C');
    G.addNode('D');
    G.addNode('E');

    G.addEdge('A', 'B');
    G.addEdge('B', 'E');
    G.addEdge('B', 'C');
    G.addEdge('C', 'D');

    G.printGraph();
    G.analisisKotaKritis();

    return 0;
}

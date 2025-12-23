#include "grap.h"

Graph::Graph() {
    firstNode = NULL;
}

Node* Graph::createNode(char nama) {
    Node *N = new Node;
    N->nama = nama;
    N->aktif = true;
    N->visited = false;
    N->firstEdge = NULL;
    N->next = NULL;
    return N;
}

void Graph::addNode(char nama) {
    Node *N = createNode(nama);
    N->next = firstNode;
    firstNode = N;
}

Node* Graph::findNode(char nama) {
    Node *temp = firstNode;
    while (temp != NULL) {
        if (temp->nama == nama)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void Graph::addEdge(char from, char to) {
    Node *A = findNode(from);
    Node *B = findNode(to);

    if (A && B) {
        Edge *e1 = new Edge{B, A->firstEdge};
        A->firstEdge = e1;

        Edge *e2 = new Edge{A, B->firstEdge};
        B->firstEdge = e2;
    }
}

void Graph::resetVisited() {
    Node *temp = firstNode;
    while (temp != NULL) {
        temp->visited = false;
        temp = temp->next;
    }
}

void Graph::DFS(Node *start, char ignored) {
    if (!start || start->visited || start->nama == ignored)
        return;

    start->visited = true;

    Edge *E = start->firstEdge;
    while (E != NULL) {
        if (E->to->nama != ignored)
            DFS(E->to, ignored);
        E = E->next;
    }
}

bool Graph::isConnected(char ignored) {
    resetVisited();

    Node *start = firstNode;
    while (start != NULL && start->nama == ignored)
        start = start->next;

    if (!start)
        return true;

    DFS(start, ignored);

    Node *temp = firstNode;
    while (temp != NULL) {
        if (temp->nama != ignored && !temp->visited)
            return false;
        temp = temp->next;
    }
    return true;
}

void Graph::analisisKotaKritis() {
    cout << "\nAnalisis Kota Kritis (Single Point of Failure)\n";
    Node *temp = firstNode;

    while (temp != NULL) {
        if (!isConnected(temp->nama)) {
            cout << "[PERINGATAN] Kota " << temp->nama
                 << " adalah KOTA KRITIS!\n";
            cout << "-> Jika lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << temp->nama
                 << " aman (redundansi oke).\n";
        }
        temp = temp->next;
    }
}

void Graph::printGraph() {
    cout << "Membangun Jaringan Distribusi Vaksin\n";
    Node *N = firstNode;

    while (N != NULL) {
        cout << "Node " << N->nama << " terhubung ke: ";
        Edge *E = N->firstEdge;
        while (E != NULL) {
            cout << E->to->nama << " ";
            E = E->next;
        }
        cout << endl;
        N = N->next;
    }
}

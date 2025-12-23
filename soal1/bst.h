#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left, *right, *parent;
};

class BST {
private:
    Node *root;

public:
    BST();

    bool isEmpty();
    void createTree();

    Node* newNode(string nama, float berat, string tier);
    void insertNode(string nama, float berat, string tier);

    void inOrder();
    Node* mostLeft();
    Node* mostRight();
    Node* searchByBeratBadan(float berat);

    Node* getRoot();

private:
    void inOrder(Node *node);
};

#endif

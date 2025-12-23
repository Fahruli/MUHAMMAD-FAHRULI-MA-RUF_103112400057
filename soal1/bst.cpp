#include "bst.h"

BST::BST() {
    root = NULL;
}

bool BST::isEmpty() {
    return root == NULL;
}

void BST::createTree() {
    root = NULL;
}

Node* BST::newNode(string nama, float berat, string tier) {
    Node *node = new Node();
    node->namaMember = nama;
    node->beratBadan = berat;
    node->tierMember = tier;
    node->left = node->right = node->parent = NULL;
    return node;
}

void BST::insertNode(string nama, float berat, string tier) {
    Node *node = newNode(nama, berat, tier);

    if (isEmpty()) {
        root = node;
        return;
    }

    Node *current = root;
    Node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (berat < current->beratBadan)
            current = current->left;
        else
            current = current->right;
    }

    node->parent = parent;
    if (berat < parent->beratBadan)
        parent->left = node;
    else
        parent->right = node;
}

void BST::inOrder(Node *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->beratBadan << " - ";
        inOrder(node->right);
    }
}

void BST::inOrder() {
    cout << "=== Traversal InOrder ===\n";
    inOrder(root);
    cout << endl;
}

Node* BST::mostLeft() {
    Node *current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* BST::mostRight() {
    Node *current = root;
    while (current->right != NULL)
        current = current->right;
    return current;
}

Node* BST::searchByBeratBadan(float berat) {
    Node *current = root;
    while (current != NULL) {
        if (berat == current->beratBadan)
            return current;
        else if (berat < current->beratBadan)
            current = current->left;
        else
            current = current->right;
    }
    return NULL;
}

Node* BST::getRoot() {
    return root;
}

#include "bst.h"

int main() {
    BST tree;
    tree.createTree();

    // Insert data sesuai soal
    tree.insertNode("Rizkina Azizah", 60, "Basic");
    tree.insertNode("Hakan Ismail", 50, "Bronze");
    tree.insertNode("Olivia Saevali", 65, "Silver");
    tree.insertNode("Felix Pedrosa", 47, "Gold");
    tree.insertNode("Gamel Al Ghifari", 56, "Platinum");
    tree.insertNode("Mutiara Fauziah", 52, "Bronze");
    tree.insertNode("Hanif Al Faiz", 70, "Basic");
    tree.insertNode("Davi Ilyas", 68, "Silver");
    tree.insertNode("Abdad Mubarak", 81, "Gold");

    // InOrder Traversal
    tree.inOrder();

    // Most Left & Most Right
    cout << "\nNode MostLeft : " << tree.mostLeft()->beratBadan << endl;
    cout << "Node MostRight : " << tree.mostRight()->beratBadan << endl;

    // Search berat badan 70
    float cari = 70;
    Node *hasil = tree.searchByBeratBadan(cari);

    if (hasil != NULL) {
        cout << "\nData ditemukan dalam BST!\n";
        cout << "--- Data Node Yang Dicari ---\n";
        cout << "Nama Member : " << hasil->namaMember << endl;
        cout << "Berat Badan : " << hasil->beratBadan << endl;
        cout << "Tier Member : " << hasil->tierMember << endl;

        if (hasil->parent != NULL) {
            cout << "\n--- Data Parent ---\n";
            cout << "Nama Member : " << hasil->parent->namaMember << endl;
            cout << "Berat Badan : " << hasil->parent->beratBadan << endl;
            cout << "Tier Member : " << hasil->parent->tierMember << endl;
        }

        if (hasil->left != NULL) {
            cout << "\n--- Data Child Kiri ---\n";
            cout << "Nama Member : " << hasil->left->namaMember << endl;
            cout << "Berat Badan : " << hasil->left->beratBadan << endl;
            cout << "Tier Member : " << hasil->left->tierMember << endl;
        }

        if (hasil->right != NULL) {
            cout << "\n--- Data Child Kanan ---\n";
            cout << "Nama Member : " << hasil->right->namaMember << endl;
            cout << "Berat Badan : " << hasil->right->beratBadan << endl;
            cout << "Tier Member : " << hasil->right->tierMember << endl;
        }
    }

    return 0;
}

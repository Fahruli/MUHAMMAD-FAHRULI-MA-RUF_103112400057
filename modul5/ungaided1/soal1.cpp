#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    Node* temp = *head_ref;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = new_node;
}

Node* getMiddle(Node* start, Node* end) {
    if (start == nullptr)
        return nullptr;

    Node* slow = start;
    Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;
    int iteration = 1;

    while (start != end) {
        Node* mid = getMiddle(start, end);

        cout << "Iterasi " << iteration
             << ": Mid = " << mid->data << " (indeks tengah)";

        if (mid->data == key) {
            cout << " -> DITEMUKAN!" << endl << endl;
            return mid;
        } 
        else if (mid->data < key) {
            cout << " -> Cari di bagian kanan" << endl;
            start = mid->next;
        } 
        else {
            cout << " -> Cari di bagian kiri" << endl;
            end = mid;
        }
        iteration++;
    }

    cout << "Tidak ada elemen tersisa" << endl << endl;
    return nullptr;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "BINARY SEARCH PADA LINKED LIST" << endl;

    Node* head = nullptr;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    append(&head, 60);

    cout << "Linked List yang dibuat: ";
    printList(head);

    int key;
    cout << "Mencari nilai: ";
    cin >> key;

    cout << "\nProses Pencarian:\n";
    Node* result = binarySearch(head, key);

    if (result != nullptr) {
        cout << "Hasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result << endl;

        if (result->next != nullptr)
            cout << "Data berikutnya: " << result->next->data << endl;
        else
            cout << "Data berikutnya: NULL" << endl;
    } 
    else {
        cout << "Hasil: Nilai " << key
             << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}

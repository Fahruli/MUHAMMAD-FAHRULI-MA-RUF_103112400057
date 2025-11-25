#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    cout << "Inserted: " << value << endl;
}


void deleteLast() {
    if (tail == nullptr) {
        cout << "List kosong, tidak bisa delete.\n";
        return;
    }

    cout << "Deleted: " << tail->data << endl;

    Node* temp = tail;

    if (head == tail) { 
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
}

void viewForward() {
    if (head == nullptr) {
        cout << "List kosong.\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    if (!head) return;

    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }

    if (temp != nullptr) {
        head = temp->prev;
    }

    tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "Menu 1 insert(end), 2 delete(last), 3 view(depan), 4 reverse & view(depan), 0 exit\n";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                insertEnd(value);
                break;

            case 2:
                deleteLast();
                break;

            case 3:
                viewForward();
                break;

            case 4:
                reverseList();
                viewForward();
                break;

            default:
                cout << "Menu tidak valid.\n";
        }
    }

    return 0;
}
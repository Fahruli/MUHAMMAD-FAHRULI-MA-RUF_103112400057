#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next;
    Node(const string& s) : name(s), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    // Insert nama di akhir list
    void insertEnd(const string& s) {
        Node* node = new Node(s);
        if (!head) {
            head = node;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }

    bool deleteFirst(const string& s) {
        if (!head) return false;
        if (head->name == s) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return true;
        }
        Node* prev = head;
        Node* cur = head->next;
        while (cur) {
            if (cur->name == s) {
                prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    void viewList() const {
        if (!head) {
            cout << "List kosong.\n";
            return;
        }
        cout << "Isi list:\n";
        Node* cur = head;
        int idx = 1;
        while (cur) {
            cout << idx << ". " << cur->name << '\n';
            cur = cur->next;
            ++idx;
        }
    }

    int countAndShowEvenNames() const {
        if (!head) {
            cout << "List kosong.\n";
            return 0;
        }
        Node* cur = head;
        int count = 0;
        cout << "Nama dengan jumlah huruf genap:\n";
        while (cur) {
            int len = (int)cur->name.length();
            if (len % 2 == 0) {
                cout << "- " << cur->name << " (jumlah huruf: " << len << ")\n";
                ++count;
            }
            cur = cur->next;
        }
        cout << "Total nama dengan jumlah huruf genap: " << count << '\n';
        return count;
    }

    ~SinglyLinkedList() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int pilihan;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1 - insert\n";
        cout << "2 - delete\n";
        cout << "3 - view\n";
        cout << "4 - hitung genap\n";
        cout << "0 - exit\n";
        cout << "Masukkan pilihan: ";
        if (!(cin >> pilihan)) {
            cout << "Input tidak valid, keluar.\n";
            break;
        }
        cin.ignore(); 
        if (pilihan == 0) {
            cout << "Keluar program.\n";
            break;
        }
        if (pilihan == 1) {
            cout << "Masukkan nama: ";
            string nama;
            getline(cin, nama);
            if (nama.empty()) {
                cout << "Nama kosong tidak dimasukkan.\n";
            } else {
                list.insertEnd(nama);
                cout << "Berhasil memasukkan \"" << nama << "\" ke akhir list.\n";
            }
        } else if (pilihan == 2) {
            cout << "Masukkan nama yang akan dihapus: ";
            string nama;
            getline(cin, nama);
            if (list.deleteFirst(nama)) {
                cout << "Nama \"" << nama << "\" berhasil dihapus (first occurrence).\n";
            } else {
                cout << "Nama \"" << nama << "\" tidak ditemukan.\n";
            }
        } else if (pilihan == 3) {
            list.viewList();
        } else if (pilihan == 4) {
            list.countAndShowEvenNames();
        } else {
            cout << "Pilihan tidak dikenal.\n";
        }
    }

    return 0;
}

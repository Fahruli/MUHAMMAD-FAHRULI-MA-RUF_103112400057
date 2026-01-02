#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    // INPUT + CETAK INPUT (PERSIS MODUL)
    char ch;
    while ((ch = cin.get()) != '\n') {
        cout << ch;
        push(S, ch - '0');
    }
    cout << endl;

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray2D(int A[3][3], int B[3][3], int x, int y) {
    int temp = A[x][y];
    A[x][y] = B[x][y];
    B[x][y] = temp;
}

void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int x = 10, y = 20;
    int *px = &x;
    int *py = &y;

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);

    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    tukarArray2D(A, B, 1, 1);

    cout << "\nArray A sesudah ditukar:\n";
    tampilArray(A);

    cout << "\nArray B sesudah ditukar:\n";
    tampilArray(B);

    cout << "\nNilai sebelum ditukar (pointer):\n";
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(px, py);

    cout << "Nilai sesudah ditukar (pointer):\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}

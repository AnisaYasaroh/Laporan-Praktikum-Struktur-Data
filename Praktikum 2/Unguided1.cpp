#include <iostream>
using namespace std;

int main() {
    const int arr_size = 10;
    int arr[arr_size];

    cout << "Data Array : ";
    for (int i = 0; i < arr_size; i++) {
    cin >> arr[i];
    }

    cout << "Nomor Genap  : ";
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;

    cout << "Nomor Ganjil : ";
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;

 return 0;
}
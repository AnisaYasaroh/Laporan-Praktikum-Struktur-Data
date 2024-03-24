#include <iostream>
using namespace std;

int main(){
    int x, y, z;
    cout << "Masukkan jumlah elemen x : ";
    cin >> x;
    cout << "Masukkan jumlah elemen y : ";
    cin >> y;
    cout << "Masukkan jumlah elemen z : ";
    cin >> z;
    
    int arr[x][y][z];
    // Input elemen
    for (int a = 0; a < x; a++){
        for (int b = 0; b < y; b++){
            for (int c = 0; c < z; c++){
                cout << "Masukkan elemen Array[" << a << "][" << b << "][" << c << "]: ";
                cin >> arr[a][b][c];
            }
        }
    }
    
    // Output Array
    for (int a = 0; a < x; a++){
        for (int b = 0; b < y; b++){
            for (int c = 0; c < z; c++){
                cout << "Data Array[" << a << "][" << b << "][" << c << "] = " << arr[a][b][c] << endl;
            }
        }
    }
 
    // Tampilan array
    for (int a = 0; a < x; a++){
        for (int b = 0; b < y; b++){
            for (int c = 0; c < z; c++){
                cout << arr[a][b][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
return 0;
}
#include <iostream>
using namespace std;

int main(){
    int arr[100], i, sum = 0, max, min;
    float avg;
    char choice;

    cout << "Masukan jumlah array : ";
    cin>> i;

    cout << "Masukan " << i << " angka : ";
    for (int x=0; x<i; x++){
        cin>> arr[x];
    }
    max = arr[0];
    min = arr[0];
    for (int x=0; x<i; x++){
        sum += arr[x];
        if (arr[x] > max){
            max = arr[x];
        }
        if ( arr[x] < min){
            min = arr[x];
        }
    }
    avg = (float) sum / i;

    cout << "\nSilahkan pilih menu : " << endl;
    cout << "A. Cari nilai maksimum" << endl;
    cout << "B. Cari nilai minimum" << endl;
    cout << "C. Cari nilai rata-rata" << endl;
    cout << "Pilihan Anda : ";
    cin >> choice;

    switch (choice){
        case 'A':
        case 'a':
            cout << "Nilai maksimum : " << max << endl;
        break;

        case 'B':
        case 'b':
            cout << "Nilai manimum : " << min << endl;
        break;

        case 'C':
        case 'c':
            cout << "Nilai rata-rata : " << avg << endl;
        break;

    default:
        cout << "Pilihan tidak valid." << endl;
        
    }
    return 0;
}
#include <iostream>
using namespace std;

int main (){
    int r;
    const double phi = 3.14;

    cout << "Masukan jari-jari = ";
    cin >> r;

    double volume_bola = (4.0/3.0) * phi * r * r * r;
 
    cout << "Volume bola tersebut adalah " << volume_bola << endl;

    return 0;
}
#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama;
    string jurusan;
    int angkatan;
};

int main (){
    Mahasiswa mhs1;

    mhs1.nama = "Anisa Yasaroh";
    mhs1.jurusan = "Teknik Informatika";
    mhs1.angkatan = 2023;

    cout << "---- Data Mahasiswa 1 -------" << endl;
    cout << "Nama     = " << mhs1.nama << endl;
    cout << "Jurusan  = " << mhs1.jurusan << endl;
    cout << "Angkatan = " << mhs1.angkatan << endl;

    return 0;
}
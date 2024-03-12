#include <iostream>
using namespace std;

class Handphone {
    public :
        string jenis;
        int tahun_buat;
        void tampilkan_data (){
            cout << "Jenis Handphone  = " << jenis << endl;
            cout << "Tahun Pembuatan  = " << tahun_buat << endl;
        }          
};
int main (){
    Handphone telepon1;
    telepon1.jenis = "Iphone";
    telepon1.tahun_buat = 2007;
    telepon1.tampilkan_data();

    Handphone telepon2;
    telepon2.jenis = "Samsung";
    telepon2.tahun_buat = 2009;
    telepon2.tampilkan_data();

    return 0;
}

#include <iostream>
#include <map>
using namespace std;

int main (){
    //membuat objek map
    map<string, int> umur;

    //memasukkan data ke dalam map
    umur ["Anisa"] = 18;
    umur ["Fitri"] = 19;
    umur ["Syifa"] = 20;

    //mencetak data dari map
    cout << "Umur Anisa = " << umur["Anisa"] << endl;
    cout << "Umur Fitri = " << umur["Fitri"] << endl;
    cout << "Umur Syifa = " << umur["Syifa"] << endl;

    //mengubah data di dalam map
    umur ["Anisa"] = 19;

    //mencetak data yang sudah diubah
    cout << "Umur Anisa setelah diubah = " << umur["Anisa"] << endl;

return 0;
}
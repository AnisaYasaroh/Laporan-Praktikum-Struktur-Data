#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int Data [7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort(){
    int temp, min, i, j;
    for(i=0; i<7; i++){
        min = i;
        for(j = i+1; j<7; j++){
            if(Data[j]<Data[min])
            {
                min = j;
            }
        }
        temp = Data[i];
        Data[i] = Data[min];
        Data[min] = temp;
    }
}

void binarysearch() {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal<=akhir)
    {
        tengah = (awal + akhir)/2;
        if(Data[tengah] == cari)
        {
            b_flag = 1;
            break;
        }
        else if(Data[tengah]<cari)
        awal = tengah + 1;
        else
        akhir = tengah - 1;
    }
    if (b_flag == 1)
    cout <<"\n Data ditemukan pada indeks ke-"<<tengah<<endl;
    else 
    cout <<"\n Data tidak ditemukan\n";
}
int main()
{
    cout<<"\t BINARY SEARCH "<<endl;
    cout<<"\n Data : ";

    for(int x = 0; x<7; x++)
        cout<<setw(3)<<Data[x];
    cout<<endl;

    cout<<"\n Masukkan data yang ingin Anda cari :";
    cin>>cari;
    cout<<"\n Data diurutkan : ";

selection_sort();
    for(int x = 0; x<7;x++)
        cout<<setw(3)<<Data[x];

cout<<endl;

binarysearch();

_getche();
return EXIT_SUCCESS;
}
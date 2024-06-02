#include <iostream>

using namespace std;
void selectionSort(string &huruf, int a_63)
{
    int x, y, min;
    for (x = 0; x < a_63 - 1; x++)
    {
        min = x;
        for (y = x + 1; y < a_63; y++)
            if (huruf[y] < huruf[min])
                min = y;
        char temp = huruf[x];
        huruf[x] = huruf[min];
        huruf[min] = temp;
    }
}
int binarySearch(string huruf, int kiri, int kanan, char target)
{
    while (kiri <= kanan)
    {
        int mid = kiri + (kanan - kiri) / 2;
        if (huruf[mid] == target)
            return mid;
        if (huruf[mid] < target)
            kiri = mid + 1;
        else
            kanan = mid - 1;
    }
    return -1;
}
int main()
{
    string kalimat;
    char input;
    cout << "---------------------------------------" << endl;
    cout << "      Pencarian Huruf pada Kalimat     " << endl;
    cout << "---------------------------------------" << endl;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);
    cout << "Masukkan huruf yang ingin dicari : ";
    cin >> input;
    cout << endl;
    selectionSort(kalimat, kalimat.size());
    int result = binarySearch(kalimat, 0, kalimat.size() - 1, input);
    if (result == -1)
    {
        cout << "Huruf yang Anda cari tidak ditemukan!" << endl;
    }
    else
    {
        cout << "Huruf setelah diurutkan : " << kalimat << endl;
        cout << "Huruf ditemukan pada indeks ke- " << result << endl;
    }
    return 0;
}
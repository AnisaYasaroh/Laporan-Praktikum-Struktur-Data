#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int TABLE_SIZE = 11;
string NIM_63;
int nilai;
class HashNode
{
public:
    string NIM_63;
    int nilai;
    HashNode(string NIM_63, int nilai)
    {
        this->NIM_63 = NIM_63;
        this->nilai = nilai;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string NIM_63, int nilai)
    {
        int hash_val = hashFunc(NIM_63);
        for (auto node : table[hash_val])
        {
            if (node->NIM_63 == NIM_63)
            {
                node->nilai = nilai;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(NIM_63, nilai));
    }
    void remove(string NIM_63)
    {
        int hash_val = hashFunc(NIM_63);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->NIM_63 == NIM_63)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    int search(string NIM_63)
    {
        int hash_val = hashFunc(NIM_63);
        for (auto node : table[hash_val])
        {
            if (node->NIM_63 == NIM_63)
            {
                return node->nilai;
            }
        }
        return -1; // return -1 if NIM is not found
    }
    void findNimByScore(int minScore, int maxScore)
    {
        bool found = false;
        for (int a = 0; a < TABLE_SIZE; a++)
        {
            for (auto pair : table[a])
            {
                if (pair != nullptr && pair->nilai >= minScore && pair->nilai <= maxScore)
                {
                    cout << pair-> NIM_63 << " memiliki nilai " << pair->nilai << endl;
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout << "Tidak ada mahasiswa yang memiliki nilai antara " << minScore << " and " << maxScore << endl;
        }
    }
    void print()
    {
        for (int a = 0; a < TABLE_SIZE; a++)
        {
            cout << a << ": ";
            for (auto pair : table[a])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair-> NIM_63 << ", " << pair->nilai << "]";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap data;
    string NIM;
    int nilai_mhs;
    while (true)
    {
        int menu;
        cout << "\nMenu" << endl;
        cout << "1. Tambah data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Mencari data berdasarkan NIM" << endl;
        cout << "4. Mencari data berdasarkan nilai" << endl;
        cout << "5. Cetak data" << endl;
        cout << "6. Exit" << endl;
        cout << "Masukkkan pilihan : ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "Masukkan NIM : ";
            cin >> NIM;
            cout << "Masukkan nilai : ";
            cin >> nilai_mhs;
            data.insert(NIM, nilai_mhs);
            break;
        case 2:
            cout << "Masukkan NIM yang akan dihapus : ";
            cin >> NIM;
            data.remove(NIM);
            cout << "Data berhasil dihapus" << endl;
            break;
        case 3:
            cout << "Masukkan NIM yang akan dicari : ";
            cin >> NIM;
            cout << "NIM " << NIM << " memiliki nilai " << data.search(NIM) << endl;
            break;
        case 4:
            int x, y;
            cout << "Masukkan rentang nilai minimal : ";
            cin >> x;
            cout << "Masukkan rentang nilai maksimal : ";
            cin >> y;
            data.findNimByScore(x, y);
            break;
        case 5:
            data.print();
            break;
        case 6:
            return 0;
        default:
            cout << "Menu tidak tersedia!" << endl;
            break;
        }
    }
return 0;
}
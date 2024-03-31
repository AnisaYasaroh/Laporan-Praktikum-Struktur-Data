#include <iostream>
#include <string>

using namespace std;

struct node {
    string name;
    int age;
    node* next;
};

class linked_list{
private:
    node* head, * tail;

public:
    linked_list(){
        head = NULL;
        tail = NULL;
    }

    // tambah awal
    void add_first(string name, int age){
        node* temp = new node;
        temp->name = name;
        temp->age = age;
        temp->next = head;
        head = temp;
        if (tail == NULL)
        {
            tail = temp;
        }
    }
    // tambah akhir
    void add_last(string name, int age){
        node* temp = new node;
        temp->name = name;
        temp->age = age;
        temp->next = NULL;
        if (tail == NULL)
        {
            head = temp;
            tail = temp;
        } else{
            tail->next = temp;
            tail = temp;
        }
    }
    // tambah tengah
    void add_middle(int pos, string name, int age){
        node* prev = new node;
        node* cur = new node;
        node* temp = new node;
        cur = head;
        for (int a = 1; a < pos; a++)
        {
            prev = cur;
            cur = cur->next;
        }
        temp->name = name;
        temp->age = age;
        prev->next = temp;
        temp->next = cur;
    }
    // ubah tengah
    void edit_middle(int pos, string name, int age){
        node* temp = new node;
        temp = head;
        for (int a = 1; a < pos; a++)
        {
            temp = temp->next;
        }
        temp->name = name;
        temp->age = age;
    }
    // tampilkan jumlah data
    void count_data(){
        int count = 0;
        node* temp = new node;
        temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << "Jumlah Data: " << count << endl;
    }
    
    // hapus data
    void delete_data(int pos)
    {
        node* prev = new node;
        node* cur = new node;
        cur = head;
        for (int a = 1; a < pos; a++)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
    }

    // tampilkan data
    void display(){
        node* temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << "Nama : " << temp->name << ", Usia : " << temp->age << endl;
            temp = temp->next;
        }
    }
};

int main(){
    linked_list l;
    
    // input data
    int choice;
    string name;
    int age;
    int pos;
    
    do {
        cout << endl;
        cout << "Menu Utama: " << endl;
        cout << "1. Tambahkan Awal" << endl;
        cout << "2. Tambahkan Akhir" << endl;
        cout << "3. Tambahkan Tengah" << endl;
        cout << "4. Ubah Tengah" << endl;
        cout << "5. Hapus Data" << endl;
        cout << "6. Tampilkan Jumlah Data" << endl;
        cout << "7. Tampilkan Seluruh Data" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilih Menu : ";
        cin >> choice;
    switch (choice)
    {
        case 1:
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan Usia : ";
            cin >> age;
            l.add_first(name, age);
            break;
        case 2:
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan Usia : ";
            cin >> age;
            l.add_last(name, age);
            break;
        case 3:
            cout << "Masukkan Posisi : ";
            cin >> pos;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan Usia : ";
            cin >> age;
            l.add_middle(pos, name, age);
            break;
        case 4:
            cout << "Masukkan Posisi : ";
            cin >> pos;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan Usia : ";
            cin >> age;
            l.edit_middle(pos, name, age);
            break;
        case 5:
            cout << "Masukkan Posisi : ";
            cin >> pos;
            l.delete_data(pos);
            break;
        case 6:
            l.count_data();
            break;
        case 7:
            l.display();
            break;
        case 8:
            cout << "Program Selesai" << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    } while (choice != 8);
    return 0;
}
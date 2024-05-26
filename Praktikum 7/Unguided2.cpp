#include <iostream>
using namespace std;

const int maximalQueue = 5;
int length = 0;

struct Node
{
    string nama_63;
    string nim_63;
    Node *next;
};

Node *head;
Node *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

bool isFull()
{
    return (length == maximalQueue);
}

bool isEmpty()
{
    return head == NULL;
}

void enqueueAntrian(string nama_63, string nim_63)
{
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        Node *baru = new Node;
        baru->nama_63 = nama_63;
        baru->nim_63 = nim_63;
        baru->next = NULL;
        if (isEmpty())
        {
            head = tail = baru;
        }
        else
        {
            tail->next = baru;
            tail = baru;
        }
        length++;
        cout << endl << "Berhasil Masuk Antrian" << endl;
    }
}

void dequeueAntrian()
{
    if (!isEmpty())
    {
        Node *hapus = head;
        if (head->next != NULL)
        {
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
            delete hapus;
        }
        length--;
    }
    else
    {
        cout << "Tidak ada antrian" << endl;
    }
}

void clearQueue()
{
    Node *bantu = head;
    while (bantu != NULL)
    {
        Node *hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    length = 0;
}

void viewQueue()
{
    if (!isEmpty())
    {
        Node *bantu = head;
        int index = 1;
        while (bantu != NULL)
        {
            cout << index << ". " << bantu->nama_63 << " - " << bantu->nim_63 << endl;
            bantu = bantu->next;
            index++;
        }
        cout << endl;
    }
    else
    {
        cout << "Antrian masih kosong" << endl;
    }
}

int countQueue()
{
    return length;
}

int main()
{
    init();
    do
    {
        int choice;
        string nama_63, nim_63;
        cout << "------------------------------------" << endl;
        cout << "          ANTRIAN MAHASISWA         " << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Keluar Antrian" << endl;
        cout << "3. Jumlah Antrian" << endl;
        cout << "4. Lihat Antrian" << endl;
        cout << "5. Hapus Antrian " << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih :  ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama_63);
            cout << "Masukkan NIM : ";
            cin >> nim_63;
            enqueueAntrian(nama_63, nim_63);
            break;

        case 2:
            dequeueAntrian();
            cout << "Berhasil keluar" << endl;
            break;

        case 3:
            cout << "Jumlah Antrian : " << countQueue() << endl;
            break;

        case 4:
            viewQueue();
            break;

        case 5:
            clearQueue();
            cout << "Data berhasil dihapus" << endl;
            break;

        case 0:
            cout << "Terima kasih telah menggunakan program ini" << endl;
            return 0;

        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    } while (true);

    return 0;
}

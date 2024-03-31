#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Node { // Deklarasi Class Node untuk Double Linked List
public:
    string ProductName;
    int harga;
    Node* prev;
    Node* next;
};

class DoublyLinkedList { // Deklarasi Class DoublyLinkedList untuk Double Linked List
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void tambahproduk(string ProductName, int harga) { // Menambahkan produk ke dalam linked list di bagian atas
        Node* newNode = new Node;
        newNode->ProductName = ProductName;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }

    void hapusproduk() { // Menghapus produk teratas dari linked list
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    bool ubahproduk(string Oldproductname, string Newsproductname, int Hargaterbaru) { // Mengubah data produk berdasarkan nama produk
        Node* current = head;
        while (current != nullptr) {
            if (current->ProductName == Oldproductname) {
                current->ProductName = Newsproductname;
                current->harga = Hargaterbaru;
                return true;
            }
            current = current->next;
        }
        return false; // Mengembalikan false jika data produk tidak ditemukan
    }

    void sisipposisi(string ProductName, int harga, int posisi) { // Menambahkan data produk pada posisi tertentu
        if (posisi < 1) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->ProductName = ProductName;
        newNode->harga = harga;
        if (posisi == 1) { // Jika posisi adalah 1 maka tambahkan data produk di depan linked list
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr) {
                head->prev = newNode;
            }
            else {
                tail = newNode;
            }
            head = newNode;
            return;
        }
        Node* current = head;
        for (int i = 1; i < posisi - 1 && current != nullptr; ++i) { // Looping sampai posisi sebelum posisi yang diinginkan (Posisi - 1)
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode; // Pointer prev node setelah current menunjuk ke newNode jika node setelah current tidak nullptr
        }
        else {
            tail = newNode;
        }
        current->next = newNode;
    }

    void hapusposisi(int posisi) { // Menghapus data produk pada posisi tertentu
        if (posisi < 1 || head == nullptr) {
            cout << "Posisi tidak ada atau list kosong" << endl;
            return;
        }
        Node* current = head;
        if (posisi == 1) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete current;
            return;
        }
        for (int i = 1; current != nullptr && i < posisi; ++i) { // Looping sampai posisi yang diinginkan
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        else {
            tail = current->prev;
        }
        current->prev->next = current->next;
        delete current;
    }

    void hapussemua() { // Menghapus semua data produk
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void tampilan() { // Menampilkan data produk
        Node* current = head;
        cout << "\nBerikut daftar Produk dan harga yang tersedia saat ini:" << endl;
        cout << left << setw(20) << "Nama Produk" << "Harga" << endl;
        while (current != nullptr) {
            cout << left << setw(20) << current->ProductName << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list; // Deklarasi objek list dari class DoublyLinkedList

    list.tambahproduk("Hanasui", 30000);
    list.tambahproduk("Wardah", 50000);
    list.tambahproduk("Skintific", 100000);
    list.tambahproduk("Somethinc", 150000);
    list.tambahproduk("Originote", 60000);

    cout << "\n==========Selamat datang di Beautime Purwokerto===========" << endl;
    list.tampilan();

    while (true) { // Looping menu utama
        cout << "\nMenu Beautime Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        int pilihan;
        cout << "Pilih Menu: ";
        cin >> pilihan;
        switch (pilihan) { // Switch case untuk memilih menu
        case 1: {
            string ProductName;
            int harga;
            cout << "Masukkan nama produk: ";
            cin >> ProductName;
            cout << "Masukkan harga: ";
            cin >> harga;
            list.tambahproduk(ProductName, harga); // Memanggil fungsi tambah_produk
            cout << "Produk berhasil ditambahkan teratas" << endl;
            break;
        }
        case 2: {
            list.hapusproduk(); // Memanggil fungsi hapus_produk
            cout << "Produk teratas berhasil dihapus" << endl;
            break;
        }
        case 3: {
            string Oldproductname, Newsproductname;
            int Hargaterbaru;
            cout << "Input nama produk lama: ";
            cin >> Oldproductname;
            cout << "Input nama produk baru: ";
            cin >> Newsproductname;
            cout << "Input harga baru: ";
            cin >> Hargaterbaru;
            bool updated = list.ubahproduk(Oldproductname, Newsproductname, Hargaterbaru); // Memanggil fungsi ubah_produk
            if (!updated) {
                cout << "Data produk tidak ditemukan" << endl;
            }
            else {
                cout << "Data produk berhasil diupdate" << endl;
            }
            break;
        }
        case 4: {
            string ProductName;
            int harga, position;
            cout << "Input nama produk: ";
            cin >> ProductName;
            cout << "Input harga: ";
            cin >> harga;
            cout << "Input posisi: ";
            cin >> position;
            list.sisipposisi(ProductName, harga, position); // Memanggil fungsi sisipkan_posisi_tertentu
            cout << "Produk berhasil ditambahkan pada posisi " << position << endl;
            break;
        }
        case 5: {
            int position;
            cout << "Input posisi yang ingin dihapus: ";
            cin >> position;
            list.hapusposisi(position); // Memanggil fungsi hapus_posisi_tertentu

            break;
        }
        case 6: {
            list.hapussemua(); // Memanggil fungsi hapus_semua
            break;
        }
        case 7: {
            list.tampilan(); // Memanggil fungsi display
            break;
        }
        case 8: {
            return 0;
        }
        default: {
            cout << "Input Invalid" << endl;
            break;
        }
        }
    }
    return 0;
}
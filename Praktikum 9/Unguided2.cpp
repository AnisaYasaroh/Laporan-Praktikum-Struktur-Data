#include <iostream>
#include <string>

using namespace std;

// Node tree
struct Node {
    string data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat node baru
Node* createNode(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node ke tree
Node* insertNode(Node* root, string data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Fungsi untuk menampilkan inorder traversal tree
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Fungsi untuk menampilkan child dari suatu node
void displayChild(Node* root, string parent) {
    if (root == NULL) return;
    if (root->data == parent) {
        if (root->left != NULL)
            cout << "Child kiri dari " << parent << ": " << root->left->data << endl;
        if (root->right != NULL)
            cout << "Child kanan dari " << parent << ": " << root->right->data << endl;
        return;
    }
    displayChild(root->left, parent);
    displayChild(root->right, parent);
}

// Fungsi untuk menampilkan descendant dari suatu node
void displayDescendant(Node* root, string parent) {
    if (root == NULL) return;
    if (root->data == parent) {
        cout << "Descendant dari " << parent << ": ";
        inorderTraversal(root->left);
        inorderTraversal(root->right);
        cout << endl;
        return;
    }
    displayDescendant(root->left, parent);
    displayDescendant(root->right, parent);
}

// Fungsi utama sesuai NIM
void Anisa_2311102063() {
    Node* root = NULL;
    int choice;
    string data, parent;

    do {
        cout << "\n----------------------------------------" << endl;
        cout << "                MENU                      " << endl;
        cout << "----------------------------------------  " << endl;
        cout << "1. Masukan Node                           " << endl;
        cout << "2. Menampilkan inorder traversal          " << endl;
        cout << "3. Menampilkan child of a node            " << endl;
        cout << "4. Menampilkan descendant of a node       " << endl;
        cout << "5. Keluar                                 " << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data untuk node baru: ";
                cin >> data;
                root = insertNode(root, data);
                break;
            case 2:
                cout << "Inorder traversal tree: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Masukkan nama node yang ingin ditampilkan child-nya: ";
                cin >> parent;
                displayChild(root, parent);
                break;
            case 4:
                cout << "Masukkan nama node yang ingin ditampilkan descendant-nya: ";
                cin >> parent;
                displayDescendant(root, parent);
                break;
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 5);
}

int main() {
    Anisa_2311102063();
    return 0;
}
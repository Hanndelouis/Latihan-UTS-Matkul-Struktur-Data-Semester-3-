#include <iostream>
#include <string>

using namespace std;

struct NodeKamus {
    string kata;
    string arti;
    NodeKamus* left;
    NodeKamus* right;
};

NodeKamus* root = nullptr;
string riwayat[5];
int jmlRiwayat = 0;

void insertBST(NodeKamus*& node, string k, string a) {
    if (!node) {
        node = new NodeKamus{k, a, nullptr, nullptr};
        cout << "Kata '" << k << "' berhasil ditambahkan.\n";
        return;
    }
    if (k < node->kata) insertBST(node->left, k, a);
    else if (k > node->kata) insertBST(node->right, k, a);
    else cout << "Kata sudah ada di kamus!\n"; 
}

void updateRiwayat(string k) {
    for (int i = 4; i > 0; i--) {
        riwayat[i] = riwayat[i - 1]; 
    }
    riwayat[0] = k; 
    if (jmlRiwayat < 5) jmlRiwayat++;
}

void searchBST(string k) {
    NodeKamus* current = root;
    while (current) {
        if (k == current->kata) {
            cout << "Arti: " << current->arti << "\n";
            updateRiwayat(k); 
            return;
        }
        if (k < current->kata) current = current->left;
        else current = current->right;
    }
    cout << "Kata '" << k << "' tidak ditemukan.\n";
}

void displayRiwayat() {
    if (jmlRiwayat == 0) return void(cout << "Riwayat pencarian kosong.\n");
    cout << "5 Pencarian Terakhir:\n";
    for (int i = 0; i < jmlRiwayat; i++) {
        cout << i + 1 << ". " << riwayat[i] << "\n";
    }
}

void cleanUp(NodeKamus* node) {
    if (!node) return;
    cleanUp(node->left);
    cleanUp(node->right);
    delete node;
}

int main() {
    int menu = 0; string k, a;
    while (menu != 4) {
        cout << "\n1.Tambah Kata 2.Cari Kata 3.Riwayat 4.Keluar | Pilih: ";
        cin >> menu;
        if (menu == 1) {
            cout << "Input Kata : "; cin >> k; cin.ignore();
            cout << "Input Arti : "; getline(cin, a);
            insertBST(root, k, a);
        } else if (menu == 2) {
            cout << "Cari Kata  : "; cin >> k;
            searchBST(k);
        } else if (menu == 3) {
            displayRiwayat();
        }
    }
    cleanUp(root); 
    return 0;
}
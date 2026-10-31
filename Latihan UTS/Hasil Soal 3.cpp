#include <iostream>
#include <string>

using namespace std;

struct NodeFolder {
    string namaFolder;
    NodeFolder* parent;
    NodeFolder* firstChild;
    NodeFolder* nextSibling;
};

NodeFolder* root = new NodeFolder{"root", nullptr, nullptr, nullptr};
NodeFolder* current = root;

void mkdir(string nama) {
    NodeFolder* newNode = new NodeFolder{nama, current, nullptr, nullptr};
    if (!current->firstChild) {
        current->firstChild = newNode;
    } else {
        NodeFolder* temp = current->firstChild;
        while (temp->nextSibling) temp = temp->nextSibling;
        temp->nextSibling = newNode;
    }
}

void ls() {
    if (!current->firstChild) {
        cout << "(Kosong)\n";
        return;
    }
    for (NodeFolder* p = current->firstChild; p; p = p->nextSibling) {
        cout << p->namaFolder << "  ";
    }
    cout << "\n";
}

void cd(string nama) {
    if (nama == "..") {
        if (current->parent) current = current->parent;
        else cout << "Sudah di root!\n";
        return;
    }
    for (NodeFolder* p = current->firstChild; p; p = p->nextSibling) {
        if (p->namaFolder == nama) {
            current = p;
            return;
        }
    }
    cout << "Folder tidak ditemukan!\n";
}

void cleanUp(NodeFolder* node) {
    if (!node) return;
    cleanUp(node->firstChild);
    cleanUp(node->nextSibling);
    delete node;
}

int main() {
    string cmd, arg;
    cout << "Sistem File Aktif. (Ketik 'exit' untuk keluar)\n";
    while (true) {
        cout << current->namaFolder << "> ";
        cin >> cmd;
        if (cmd == "mkdir") {
            cin >> arg; mkdir(arg);
        } else if (cmd == "ls") {
            ls();
        } else if (cmd == "cd") {
            cin >> arg; cd(arg);
        } else if (cmd == "exit") {
            break;
        } else {
            cout << "Perintah tidak valid.\n";
        }
    }
    cleanUp(root); 
    return 0;
}
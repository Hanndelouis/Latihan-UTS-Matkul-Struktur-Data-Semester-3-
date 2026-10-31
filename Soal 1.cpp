#include <iostream>
using namespace std;

struct Pasien {
    string idPasien, nama, keluhan;
    Pasien* next;
} *front = nullptr, *rear = nullptr;

void enqueue() {
    Pasien* p = new Pasien();
    cout << "Input ID, Nama, Keluhan (pisahkan enter):\n";
    cin >> p->idPasien; cin.ignore();
    getline(cin, p->nama);
    getline(cin, p->keluhan);
    p->next = nullptr;
    
    if (!front) front = rear = p;
    else { rear->next = p; rear = p; }
}

void dequeue() {
    if (!front) return void(cout << "Antrean kosong!\n");
    Pasien* p = front;
    cout << "Memanggil: " << p->nama << " (" << p->keluhan << ")\n";
    front = front->next;
    if (!front) rear = nullptr;
    delete p;
}

void display() {
    if (!front) return void(cout << "Antrean kosong!\n");
    for (Pasien* p = front; p; p = p->next)
        cout << "[" << p->idPasien << "] " << p->nama << " - " << p->keluhan << "\n";
}

int main() {
    int menu = 0;
    while (menu != 4) {
        cout << "\n1.Tambah Pasien 2.Panggil Pasien 3.Cek Pasien 4.Keluar | Pilih: ";
        cin >> menu;
        
        if (menu == 1) enqueue();
        else if (menu == 2) dequeue();
        else if (menu == 3) display();
    }
    
    while (front) { Pasien* p = front; front = front->next; delete p; }
}
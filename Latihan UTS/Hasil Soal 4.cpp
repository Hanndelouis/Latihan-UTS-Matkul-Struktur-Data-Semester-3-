#include <iostream>
#include <string>

using namespace std;

struct Pesanan {
    string idPesanan;
    string namaBarang;
    int jumlah;
};

Pesanan* antrean = nullptr;
int kapasitas = 0;
int q_front = -1;
int q_rear = -1;
int elemenTerpakai = 0;

bool isFull() {
    return (q_front == 0 && q_rear == kapasitas - 1) || (q_front == q_rear + 1);
}

bool isEmpty() {
    return q_front == -1;
}

void enqueue() {
    if (isFull()) return void(cout << "Antrean penuh!\n");
    
    Pesanan p;
    cout << "ID Pesanan   : "; cin >> p.idPesanan; cin.ignore();
    cout << "Nama Barang  : "; getline(cin, p.namaBarang);
    cout << "Jumlah       : "; cin >> p.jumlah;

    if (q_front == -1) q_front = 0;
    q_rear = (q_rear + 1) % kapasitas; 
    antrean[q_rear] = p;
    elemenTerpakai++;
    cout << "Pesanan " << p.idPesanan << " masuk antrean.\n";
}

void dequeue() {
    if (isEmpty()) return void(cout << "Antrean kosong!\n");
    
    Pesanan p = antrean[q_front];
    cout << "\n--- NOTA PEMROSESAN ---\n";
    cout << "Memproses ID : " << p.idPesanan << "\nBarang       : " << p.namaBarang << " (x" << p.jumlah << ")\n";
    
    if (q_front == q_rear) { 
        q_front = -1;
        q_rear = -1;
    } else {
        q_front = (q_front + 1) % kapasitas;
    }
    elemenTerpakai--;
}

void display() {
    if (isEmpty()) return void(cout << "Antrean kosong!\n");
    
    cout << "\nKapasitas: " << elemenTerpakai << "/" << kapasitas << "\nDaftar Antrean:\n";
    int i = q_front;
    while (true) {
        cout << "[" << antrean[i].idPesanan << "] " << antrean[i].namaBarang << " (x" << antrean[i].jumlah << ")\n";
        if (i == q_rear) break;
        i = (i + 1) % kapasitas;
    }
}

int main() {
    cout << "Masukkan kapasitas maksimal antrean toko: ";
    cin >> kapasitas;
    
    antrean = new Pesanan[kapasitas];
    
    int menu = 0;
    while (menu != 4) {
        cout << "\n1.Terima 2.Proses 3.Cek 4.Keluar | Pilih: ";
        cin >> menu;
        if (menu == 1) enqueue();
        else if (menu == 2) dequeue();
        else if (menu == 3) display();
    }
    
    delete[] antrean;
    return 0;
}
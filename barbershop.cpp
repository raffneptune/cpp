#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class Barbershop {
private:
    queue<string> antrian;  // Antrian pelanggan
    bool buka;  // Status barbershop

public:
    Barbershop() : buka(true) {}

    void bukaBarbershop() {
        cout << "Barbershop sedang buka, silakan masuk!" << endl;
    }

    void tutupBarbershop() {
        buka = false;
        cout << "Barbershop sudah tutup. Terima kasih sudah datang!" << endl;
    }

    void tambahPelanggan(const string& nama) {
        if (buka) {
            antrian.push(nama);
            cout << nama << " telah masuk ke antrian." << endl;
        } else {
            cout << "Barbershop sudah tutup. Anda tidak bisa mendaftar." << endl;
        }
    }

    void prosesPelanggan() {
        if (!antrian.empty()) {
            string pelanggan = antrian.front();
            antrian.pop();
            cout << "Sedang melayani " << pelanggan << "..." << endl;
            this_thread::sleep_for(chrono::seconds(2));  // Simulasi pemotongan rambut
            cout << pelanggan << " telah selesai dilayani." << endl;
        } else {
            cout << "Tidak ada pelanggan di antrian." << endl;
        }
    }

    void tampilkanAntrian() {
        if (!antrian.empty()) {
            cout << "Antrian pelanggan:" << endl;
            int no = 1;
            queue<string> temp = antrian;
            while (!temp.empty()) {
                cout << no++ << ". " << temp.front() << endl;
                temp.pop();
            }
        } else {
            cout << "Tidak ada pelanggan di antrian." << endl;
        }
    }
};

int main() {
    Barbershop barbershop;
    barbershop.bukaBarbershop();

    while (true) {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Tambah Pelanggan" << endl;
        cout << "2. Proses Pelanggan" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Tutup Barbershop" << endl;
        cout << "5. Keluar" << endl;
        
        int pilihan;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        cin.ignore();  // Menghindari masalah input buffer setelah cin >> pilihan

        if (pilihan == 1) {
            string nama;
            cout << "Masukkan nama pelanggan: ";
            getline(cin, nama);
            barbershop.tambahPelanggan(nama);
        }
        else if (pilihan == 2) {
            barbershop.prosesPelanggan();
        }
        else if (pilihan == 3) {
            barbershop.tampilkanAntrian();
        }
        else if (pilihan == 4) {
            barbershop.tutupBarbershop();
            break;
        }
        else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        }
        else {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    }

    return 0;
}
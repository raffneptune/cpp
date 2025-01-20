#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Kereta {
public:
    string nama_kereta;
    string tujuan;
    string waktu_berangkat;
    int kapasitas;
    int terisi;

    Kereta(string nama, string tujuan, string waktu, int kapasitas)
        : nama_kereta(nama), tujuan(tujuan), waktu_berangkat(waktu), kapasitas(kapasitas), terisi(0) {}

    void tampilkan_info() {
        cout << "Nama Kereta: " << nama_kereta << endl;
        cout << "Tujuan: " << tujuan << endl;
        cout << "Waktu Berangkat: " << waktu_berangkat << endl;
        cout << "Kapasitas: " << kapasitas << endl;
        cout << "Terisi: " << terisi << "/" << kapasitas << endl;
        cout << endl;
    }

    void pesan_tiket(int jumlah_tiket) {
        if (terisi + jumlah_tiket <= kapasitas) {
            terisi += jumlah_tiket;
            cout << "Berhasil memesan " << jumlah_tiket << " tiket untuk " << nama_kereta << "." << endl;
        } else {
            cout << "Maaf, hanya tersisa " << kapasitas - terisi << " tiket untuk " << nama_kereta << "." << endl;
        }
    }
};

class SistemKereta {
private:
    vector<Kereta> kereta_list;

public:
    void tambah_kereta(const Kereta& kereta) {
        kereta_list.push_back(kereta);
    }

    void tampilkan_jadwal() {
        cout << "Jadwal Kereta:" << endl;
        for (auto& kereta : kereta_list) {
            kereta.tampilkan_info();
        }
    }

    void pesan_tiket_kereta(const string& nama_kereta, int jumlah_tiket) {
        bool ditemukan = false;
        for (auto& kereta : kereta_list) {
            if (kereta.nama_kereta == nama_kereta) {
                kereta.pesan_tiket(jumlah_tiket);
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan) {
            cout << "Kereta dengan nama " << nama_kereta << " tidak ditemukan." << endl;
        }
    }
};

int main() {
    SistemKereta sistem_kereta;

    // Menambahkan kereta ke sistem
    Kereta kereta1("Ekspres Jakarta", "Bandung", "10:00", 100);
    Kereta kereta2("Argo Bromo", "Surabaya", "15:00", 150);
    Kereta kereta3("Kelas Ekonomi", "Yogyakarta", "12:00", 200);

    sistem_kereta.tambah_kereta(kereta1);
    sistem_kereta.tambah_kereta(kereta2);
    sistem_kereta.tambah_kereta(kereta3);

    int pilihan;
    string nama_kereta;
    int jumlah_tiket;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Tampilkan Jadwal Kereta" << endl;
        cout << "2. Pesan Tiket Kereta" << endl;
        cout << "3. Keluar" << endl;

        cout << "Pilih menu (1/2/3): ";
        cin >> pilihan;

        if (pilihan == 1) {
            sistem_kereta.tampilkan_jadwal();
        } else if (pilihan == 2) {
            cout << "Masukkan nama kereta yang ingin dipesan: ";
            cin.ignore(); // Mengabaikan newline yang tersisa
            getline(cin, nama_kereta);
            cout << "Masukkan jumlah tiket yang ingin dipesan: ";
            cin >> jumlah_tiket;
            sistem_kereta.pesan_tiket_kereta(nama_kereta, jumlah_tiket);
        } else if (pilihan == 3) {
            cout << "Terima kasih telah menggunakan sistem kereta." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Buku {
public:
    string judul;
    string penulis;
    int tahun_terbit;

    Buku(string j, string p, int t) : judul(j), penulis(p), tahun_terbit(t) {}

    void tampilkan() {
        cout << "Judul: " << judul << ", Penulis: " << penulis << ", Tahun Terbit: " << tahun_terbit << endl;
    }
};

class Perpustakaan {
private:
    vector<Buku> daftar_buku;

public:
    void tambah_buku(const Buku& buku) {
        daftar_buku.push_back(buku);
        cout << "Buku '" << buku.judul << "' berhasil ditambahkan." << endl;
    }

    void hapus_buku(const string& judul) {
        for (auto it = daftar_buku.begin(); it != daftar_buku.end(); ++it) {
            if (it->judul == judul) {
                daftar_buku.erase(it);
                cout << "Buku '" << judul << "' berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Buku '" << judul << "' tidak ditemukan." << endl;
    }

    void tampilkan_buku() {
        if (daftar_buku.empty()) {
            cout << "Tidak ada buku di perpustakaan." << endl;
        } else {
            cout << "Daftar Buku Perpustakaan:" << endl;
            for (const auto& buku : daftar_buku) {
                buku.tampilkan();
            }
        }
    }
};

void menu() {
    Perpustakaan perpustakaan;

    while (true) {
        cout << "\nMenu Perpustakaan:" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Hapus Buku" << endl;
        cout << "3. Tampilkan Daftar Buku" << endl;
        cout << "4. Keluar" << endl;

        int pilihan;
        cout << "Pilih menu (1/2/3/4): ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer input

        if (pilihan == 1) {
            string judul, penulis;
            int tahun_terbit;

            cout << "Masukkan judul buku: ";
            getline(cin, judul);
            cout << "Masukkan penulis buku: ";
            getline(cin, penulis);
            cout << "Masukkan tahun terbit buku: ";
            cin >> tahun_terbit;

            Buku buku_baru(judul, penulis, tahun_terbit);
            perpustakaan.tambah_buku(buku_baru);

        } else if (pilihan == 2) {
            string judul;
            cout << "Masukkan judul buku yang akan dihapus: ";
            getline(cin, judul);
            perpustakaan.hapus_buku(judul);

        } else if (pilihan == 3) {
            perpustakaan.tampilkan_buku();

        } else if (pilihan == 4) {
            cout << "Terima kasih! Keluar dari program." << endl;
            break;

        } else {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
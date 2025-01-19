#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Barang {
public:
    string nama;
    double harga;
    int jumlah;
    double total;

    // Konstruktor untuk membuat objek Barang
    Barang(string nama, double harga, int jumlah) {
        this->nama = nama;
        this->harga = harga;
        this->jumlah = jumlah;
        this->total = harga * jumlah;
    }

    // Menampilkan rincian barang
    void tampilkanRincian() {
        cout << nama << " - Harga: " << harga << " - Jumlah: " << jumlah << " - Total: " << total << endl;
    }
};

class Kasir {
public:
    vector<Barang> daftarBarang;
    double totalHarga;

    // Konstruktor untuk inisialisasi
    Kasir() {
        totalHarga = 0;
    }

    // Menambah barang ke daftar belanja
    void tambahBarang(string nama, double harga, int jumlah) {
        Barang barang(nama, harga, jumlah);
        daftarBarang.push_back(barang);
        totalHarga += barang.total;
        cout << nama << " x" << jumlah << " ditambahkan ke daftar belanja." << endl;
    }

    // Menampilkan rincian belanja
    void tampilkanRincian() {
        cout << "\n--- Rincian Belanja ---" << endl;
        for (const auto& barang : daftarBarang) {
            barang.tampilkanRincian();
        }
        cout << "\nTotal Belanja: " << totalHarga << endl;
    }

    // Proses pembayaran dan menghitung kembalian
    void bayar(double uangDibayar) {
        if (uangDibayar >= totalHarga) {
            double kembalian = uangDibayar - totalHarga;
            cout << "\nTotal yang harus dibayar: " << totalHarga << endl;
            cout << "Uang yang dibayar: " << uangDibayar << endl;
            cout << "Kembalian: " << kembalian << endl;
        } else {
            cout << "\nUang yang dibayar kurang dari total belanja. Transaksi dibatalkan." << endl;
        }
    }
};

int main() {
    Kasir kasir;
    int pilihan;
    string namaBarang;
    double harga;
    int jumlah;
    double uangDibayar;

    while (true) {
        cout << "\nMenu Kasir" << endl;
        cout << "1. Tambah barang" << endl;
        cout << "2. Tampilkan rincian belanja" << endl;
        cout << "3. Bayar" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1/2/3/4): ";
        cin >> pilihan;
        cin.ignore(); // Clear buffer setelah input pilihan

        if (pilihan == 1) {
            cout << "Masukkan nama barang: ";
            getline(cin, namaBarang);
            cout << "Masukkan harga barang: ";
            cin >> harga;
            cout << "Masukkan jumlah barang: ";
            cin >> jumlah;
            kasir.tambahBarang(namaBarang, harga, jumlah);
        } else if (pilihan == 2) {
            kasir.tampilkanRincian();
        } else if (pilihan == 3) {
            kasir.tampilkanRincian();
            cout << "Masukkan uang yang dibayar: ";
            cin >> uangDibayar;
            kasir.bayar(uangDibayar);
        } else if (pilihan == 4) {
            cout << "Terima kasih, sampai jumpa!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>

using namespace std;

// Daftar produk dan harga
unordered_map<string, int> produk = {
    {"Apel", 10000},
    {"Pisang", 8000},
    {"Jeruk", 12000},
    {"Mangga", 15000},
    {"Semangka", 20000}
};

// Fungsi untuk menampilkan daftar produk
void tampilkanProduk() {
    cout << "\nDaftar Produk Supermarket:\n";
    for (const auto& item : produk) {
        cout << item.first << ": Rp " << item.second << endl;
    }
}

// Fungsi untuk menambah barang ke keranjang
void tambahKeKeranjang(unordered_map<string, int>& keranjang, const string& produk, int jumlah) {
    if (keranjang.find(produk) != keranjang.end()) {
        keranjang[produk] += jumlah;
    } else {
        keranjang[produk] = jumlah;
    }
}

// Fungsi untuk menghitung total belanjaan
int hitungTotal(const unordered_map<string, int>& keranjang) {
    int total = 0;
    for (const auto& item : keranjang) {
        total += produk.at(item.first) * item.second;
    }
    return total;
}

int main() {
    unordered_map<string, int> keranjang;
    string pilihan;
    int jumlah;
    
    while (true) {
        tampilkanProduk();
        cout << "\nMasukkan nama produk yang ingin dibeli (atau ketik 'selesai' untuk keluar): ";
        getline(cin, pilihan);
        
        if (pilihan == "selesai" || pilihan == "Selesai") {
            break;
        }
        
        // Memeriksa apakah produk yang dimasukkan ada di daftar produk
        if (produk.find(pilihan) == produk.end()) {
            cout << "Produk tidak tersedia. Silakan pilih produk yang ada.\n";
            continue;
        }
        
        cout << "Berapa banyak " << pilihan << " yang ingin Anda beli? ";
        cin >> jumlah;
        cin.ignore();  // Membersihkan buffer input
        
        // Menambahkan produk ke keranjang
        tambahKeKeranjang(keranjang, pilihan, jumlah);
    }
    
    // Menampilkan keranjang belanja
    cout << "\nKeranjang Belanja Anda:\n";
    int total = 0;
    for (const auto& item : keranjang) {
        cout << item.first << ": " << item.second << " x Rp " << produk.at(item.first)
             << " = Rp " << produk.at(item.first) * item.second << endl;
        total += produk.at(item.first) * item.second;
    }
    
    cout << fixed << setprecision(0) << "\nTotal Belanja: Rp " << total << endl;
    
    return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Cafe {
private:
    unordered_map<string, int> menu;  // Menyimpan menu dan harga
    unordered_map<string, int> pesanan;  // Menyimpan pesanan dan jumlah

public:
    // Konstruktor untuk mengisi menu kafe
    Cafe() {
        menu["Kopi"] = 15000;
        menu["Teh"] = 10000;
        menu["Espresso"] = 20000;
        menu["Cappuccino"] = 25000;
        menu["Kue"] = 12000;
    }

    // Menampilkan menu
    void tampilkanMenu() {
        cout << "\n--- Menu Kafe ---" << endl;
        for (const auto& item : menu) {
            cout << item.first << ": Rp " << item.second << endl;
        }
    }

    // Menambah pesanan
    void tambahPesanan() {
        string pesananItem;
        int jumlah;

        while (true) {
            tampilkanMenu();
            cout << "\nMasukkan nama item yang ingin dipesan (ketik 'selesai' untuk mengakhiri): ";
            getline(cin, pesananItem);
            if (pesananItem == "selesai") {
                break;
            }

            if (menu.find(pesananItem) != menu.end()) {
                cout << "Berapa banyak " << pesananItem << " yang ingin dipesan? ";
                cin >> jumlah;
                cin.ignore();  // Untuk menghindari masalah dengan getline setelah cin

                pesanan[pesananItem] += jumlah;
                cout << jumlah << " " << pesananItem << " telah ditambahkan ke pesanan." << endl;
            } else {
                cout << "Item tidak ada dalam menu. Silakan coba lagi." << endl;
            }
        }
    }

    // Menghitung total harga pesanan
    int hitungTotal() {
        int total = 0;
        for (const auto& item : pesanan) {
            total += menu[item.first] * item.second;
        }
        return total;
    }

    // Menampilkan pesanan dan total harga
    void tampilkanPesanan() {
        if (pesanan.empty()) {
            cout << "\nTidak ada pesanan." << endl;
        } else {
            cout << "\n--- Pesanan Anda ---" << endl;
            for (const auto& item : pesanan) {
                cout << item.first << " x " << item.second << " = Rp " << menu[item.first] * item.second << endl;
            }
            cout << "\nTotal yang harus dibayar: Rp " << hitungTotal() << endl;
        }
    }
};

int main() {
    Cafe cafe;
    int pilihan;

    while (true) {
        cout << "\n--- Selamat Datang di Kafe! ---" << endl;
        cout << "1. Lihat Menu" << endl;
        cout << "2. Tambah Pesanan" << endl;
        cout << "3. Lihat Pesanan dan Total" << endl;
        cout << "4. Keluar" << endl;
        
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
        cin.ignore();  // Membersihkan buffer input

        switch (pilihan) {
            case 1:
                cafe.tampilkanMenu();
                break;
            case 2:
                cafe.tambahPesanan();
                break;
            case 3:
                cafe.tampilkanPesanan();
                break;
            case 4:
                cout << "Terima kasih telah mengunjungi kafe kami. Sampai jumpa!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
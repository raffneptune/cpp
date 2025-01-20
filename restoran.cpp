#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Menu {
public:
    string nama;
    int harga;

    Menu(string n, int h) : nama(n), harga(h) {}
};

class Restoran {
private:
    vector<Menu> menu;
    vector<pair<Menu, int>> pesanan; // Pasangan Menu dan jumlahnya

public:
    Restoran() {
        menu.push_back(Menu("Nasi Goreng", 25000));
        menu.push_back(Menu("Mie Goreng", 20000));
        menu.push_back(Menu("Sate Ayam", 30000));
        menu.push_back(Menu("Ayam Penyet", 35000));
        menu.push_back(Menu("Es Teh", 5000));
        menu.push_back(Menu("Es Jeruk", 7000));
    }

    void tampilkanMenu() {
        cout << "\nMenu Restoran:" << endl;
        for (int i = 0; i < menu.size(); ++i) {
            cout << i + 1 << ". " << menu[i].nama << " - Rp" << menu[i].harga << endl;
        }
    }

    void tambahPesanan() {
        tampilkanMenu();
        int pilihan;
        cout << "\nPilih nomor menu untuk dipesan (0 untuk selesai): ";
        cin >> pilihan;

        if (pilihan == 0) return;

        if (pilihan > 0 && pilihan <= menu.size()) {
            int jumlah;
            cout << "Berapa banyak " << menu[pilihan - 1].nama << " yang ingin dipesan? ";
            cin >> jumlah;
            pesanan.push_back(make_pair(menu[pilihan - 1], jumlah));
            cout << jumlah << " " << menu[pilihan - 1].nama << " ditambahkan ke pesanan." << endl;
        } else {
            cout << "Nomor menu tidak valid!" << endl;
        }
    }

    int hitungTotal() {
        int total = 0;
        for (auto& p : pesanan) {
            total += p.first.harga * p.second;
        }
        return total;
    }

    void tampilkanPesanan() {
        if (pesanan.empty()) {
            cout << "\nBelum ada pesanan." << endl;
        } else {
            cout << "\nPesanan Anda:" << endl;
            for (auto& p : pesanan) {
                cout << p.first.nama << " x " << p.second << " - Rp" << p.first.harga * p.second << endl;
            }
            cout << "Total Harga: Rp" << hitungTotal() << endl;
        }
    }
};

int main() {
    Restoran restoran;
    int pilihan;

    while (true) {
        cout << "\n-- Menu Utama --" << endl;
        cout << "1. Lihat Menu" << endl;
        cout << "2. Tambah Pesanan" << endl;
        cout << "3. Tampilkan Pesanan" << endl;
        cout << "4. Hitung Total" << endl;
        cout << "5. Keluar" << endl;

        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                restoran.tampilkanMenu();
                break;
            case 2:
                restoran.tambahPesanan();
                break;
            case 3:
                restoran.tampilkanPesanan();
                break;
            case 4:
                cout << "Total Harga: Rp" << restoran.hitungTotal() << endl;
                break;
            case 5:
                cout << "Terima kasih telah berkunjung!" << endl;
                return 0;
            default:
                cout << "Opsi tidak valid!" << endl;
        }
    }

    return 0;
}
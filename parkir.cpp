#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Parkir {
private:
    int kapasitas;
    vector<string> kendaraanParkir;

public:
    Parkir(int kapasitas) {
        this->kapasitas = kapasitas;
    }

    void masukParkir() {
        if (kendaraanParkir.size() < kapasitas) {
            string kendaraan;
            cout << "Masukkan nama kendaraan yang ingin parkir: ";
            cin.ignore(); // Untuk menghindari masalah dengan newline character
            getline(cin, kendaraan);
            kendaraanParkir.push_back(kendaraan);
            cout << kendaraan << " berhasil masuk ke area parkir." << endl;
        } else {
            cout << "Parkir sudah penuh!" << endl;
        }
    }

    void keluarParkir() {
        string kendaraan;
        cout << "Masukkan nama kendaraan yang ingin keluar: ";
        cin.ignore(); // Untuk menghindari masalah dengan newline character
        getline(cin, kendaraan);

        auto it = find(kendaraanParkir.begin(), kendaraanParkir.end(), kendaraan);
        if (it != kendaraanParkir.end()) {
            kendaraanParkir.erase(it);
            cout << kendaraan << " telah keluar dari area parkir." << endl;
        } else {
            cout << kendaraan << " tidak ditemukan di parkir." << endl;
        }
    }

    void statusParkir() {
        if (kendaraanParkir.empty()) {
            cout << "Area parkir kosong." << endl;
        } else {
            cout << "Kendaraan yang terparkir:" << endl;
            for (const auto& kendaraan : kendaraanParkir) {
                cout << kendaraan << endl;
            }
        }
    }
};

int main() {
    int kapasitasParkir;
    cout << "Masukkan kapasitas parkir: ";
    cin >> kapasitasParkir;

    Parkir parkir(kapasitasParkir);

    int pilihan;
    do {
        cout << "\nPilih menu:" << endl;
        cout << "1. Masukkan kendaraan" << endl;
        cout << "2. Keluarkan kendaraan" << endl;
        cout << "3. Lihat status parkir" << endl;
        cout << "4. Keluar" << endl;

        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                parkir.masukParkir();
                break;
            case 2:
                parkir.keluarParkir();
                break;
            case 3:
                parkir.statusParkir();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan sistem parkir!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
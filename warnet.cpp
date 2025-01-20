#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

class Komputer {
public:
    int nomor;
    bool tersedia;
    time_t mulaiSewa;
    double durasiSewa;

    Komputer(int nom) {
        nomor = nom;
        tersedia = true;
        mulaiSewa = 0;
        durasiSewa = 0;
    }

    void sewa() {
        if (tersedia) {
            tersedia = false;
            mulaiSewa = time(0);  // mencatat waktu saat komputer disewa
            cout << "Komputer " << nomor << " telah disewa." << endl;
        } else {
            cout << "Komputer " << nomor << " sedang disewa." << endl;
        }
    }

    void selesaiSewa() {
        if (!tersedia) {
            time_t selesaiSewa = time(0);  // waktu saat komputer selesai disewa
            durasiSewa = difftime(selesaiSewa, mulaiSewa) / 60;  // durasi dalam menit
            double biaya = durasiSewa * 2000;  // biaya per menit misalnya 2000 IDR
            tersedia = true;
            mulaiSewa = 0;
            cout << "Komputer " << nomor << " selesai disewa. Durasi: " << fixed << setprecision(2) << durasiSewa << " menit." << endl;
            cout << "Biaya yang harus dibayar: Rp " << fixed << setprecision(2) << biaya << endl;
        } else {
            cout << "Komputer " << nomor << " belum disewa." << endl;
        }
    }
};

class Warnet {
private:
    vector<Komputer> komputer;

public:
    Warnet(int jumlahKomputer) {
        for (int i = 0; i < jumlahKomputer; i++) {
            komputer.push_back(Komputer(i + 1));
        }
    }

    void tampilkanKomputer() {
        cout << "\nDaftar Komputer:" << endl;
        for (auto &kom : komputer) {
            string status = kom.tersedia ? "Tersedia" : "Sedang disewa";
            cout << "Komputer " << kom.nomor << ": " << status << endl;
        }
    }

    void sewaKomputer(int nomor) {
        if (nomor >= 1 && nomor <= komputer.size()) {
            komputer[nomor - 1].sewa();
        } else {
            cout << "Nomor komputer tidak valid!" << endl;
        }
    }

    void selesaiKomputer(int nomor) {
        if (nomor >= 1 && nomor <= komputer.size()) {
            komputer[nomor - 1].selesaiSewa();
        } else {
            cout << "Nomor komputer tidak valid!" << endl;
        }
    }
};

void menu() {
    Warnet warnet(5);  // Misalkan ada 5 komputer di warnet
    while (true) {
        cout << "\n--- Menu Warnet ---" << endl;
        cout << "1. Tampilkan Daftar Komputer" << endl;
        cout << "2. Sewa Komputer" << endl;
        cout << "3. Selesai Sewa Komputer" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                warnet.tampilkanKomputer();
                break;
            case 2: {
                cout << "Masukkan nomor komputer yang ingin disewa: ";
                int nomorSewa;
                cin >> nomorSewa;
                warnet.sewaKomputer(nomorSewa);
                break;
            }
            case 3: {
                cout << "Masukkan nomor komputer yang selesai disewa: ";
                int nomorSelesai;
                cin >> nomorSelesai;
                warnet.selesaiKomputer(nomorSelesai);
                break;
            }
            case 4:
                cout << "Terima kasih telah menggunakan layanan warnet!" << endl;
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}
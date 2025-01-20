#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Kelas untuk kendaraan
class Kendaraan {
public:
    string nama;
    string golongan;

    Kendaraan(string n, string g) : nama(n), golongan(g) {}
};

// Kelas untuk Gerbang Tol
class GerbangTol {
private:
    vector<Kendaraan> antrian;

public:
    // Menambah kendaraan ke antrian
    void tambahAntrian(const string& nama, const string& golongan) {
        antrian.push_back(Kendaraan(nama, golongan));
        cout << nama << " ditambahkan ke antrian.\n";
    }

    // Memproses kendaraan pertama dalam antrian
    void prosesKendaraan() {
        if (!antrian.empty()) {
            cout << antrian[0].nama << " sedang diproses.\n";
            antrian.erase(antrian.begin()); // Hapus kendaraan pertama
        } else {
            cout << "Antrian kosong, tidak ada kendaraan yang diproses.\n";
        }
    }

    // Menampilkan antrian kendaraan
    void tampilkanAntrian() const {
        if (!antrian.empty()) {
            cout << "Antrian kendaraan saat ini:\n";
            for (const auto& kendaraan : antrian) {
                cout << kendaraan.nama << " - " << kendaraan.golongan << endl;
            }
        } else {
            cout << "Antrian kosong.\n";
        }
    }
};

// Kelas untuk Sistem Tol
class SistemTol {
public:
    int tarifGolongan1;
    int tarifGolongan2;
    int tarifGolongan3;

    SistemTol() : tarifGolongan1(5000), tarifGolongan2(10000), tarifGolongan3(15000) {}

    // Menghitung biaya tol berdasarkan golongan dan jarak
    void hitungBiaya(const string& golongan, int jarak) const {
        int tarif = 0;
        if (golongan == "golongan_1") {
            tarif = tarifGolongan1;
        } else if (golongan == "golongan_2") {
            tarif = tarifGolongan2;
        } else if (golongan == "golongan_3") {
            tarif = tarifGolongan3;
        } else {
            cout << "Golongan kendaraan tidak valid!\n";
            return;
        }

        int biaya = tarif * jarak;
        cout << "Biaya tol untuk " << golongan << " dengan jarak " << jarak << " km adalah: " << biaya << " IDR\n";
    }
};

// Program utama
int main() {
    GerbangTol gerbang;
    SistemTol sistem;

    // Menambah kendaraan ke antrian
    gerbang.tambahAntrian("Mobil Kecil - Golongan 1", "golongan_1");
    gerbang.tambahAntrian("Truk Kecil - Golongan 2", "golongan_2");
    gerbang.tambahAntrian("Truk Besar - Golongan 3", "golongan_3");

    // Menampilkan antrian kendaraan
    gerbang.tampilkanAntrian();

    // Proses kendaraan pertama
    gerbang.prosesKendaraan();

    // Menghitung biaya tol untuk kendaraan pertama
    sistem.hitungBiaya("golongan_1", 10);  // Misalnya jarak 10 km

    return 0;
}
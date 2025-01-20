#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Daftar nama siswa/pegawai
vector<string> daftar_nama = {"Ali", "Budi", "Citra", "Dewi", "Eka"};

// Menyimpan status absensi
vector<string> absensi(daftar_nama.size(), "");

void catat_absensi() {
    cout << "Daftar Nama:" << endl;
    for (size_t i = 0; i < daftar_nama.size(); i++) {
        cout << i + 1 << ". " << daftar_nama[i] << endl;
    }

    for (size_t i = 0; i < daftar_nama.size(); i++) {
        char status;
        cout << "Apakah " << daftar_nama[i] << " hadir? (y/n): ";
        cin >> status;

        if (status == 'y' || status == 'Y') {
            absensi[i] = "Hadir";
        } else if (status == 'n' || status == 'N') {
            absensi[i] = "Tidak Hadir";
        } else {
            absensi[i] = "Status Tidak Valid";
        }
    }

    cout << "\nAbsensi Hari Ini:" << endl;
    for (size_t i = 0; i < daftar_nama.size(); i++) {
        cout << daftar_nama[i] << ": " << absensi[i] << endl;
    }
}

int main() {
    // Menjalankan fungsi untuk mencatat absensi
    catat_absensi();

    return 0;
}
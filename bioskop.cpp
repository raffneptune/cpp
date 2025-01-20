#include <iostream>
using namespace std;

// Menampilkan daftar film yang tersedia
void showFilms() {
    cout << "Daftar Film yang Tersedia:" << endl;
    cout << "1. Film A - Harga: Rp 50000" << endl;
    cout << "2. Film B - Harga: Rp 60000" << endl;
    cout << "3. Film C - Harga: Rp 70000" << endl;
    cout << "4. Film D - Harga: Rp 55000" << endl;
}

// Memilih film yang diinginkan oleh pengguna
int pilihFilm() {
    int pilihan;
    while (true) {
        cout << "\nPilih film (1-4): ";
        cin >> pilihan;
        if (pilihan >= 1 && pilihan <= 4) {
            return pilihan;
        } else {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    }
}

// Mendapatkan nama film berdasarkan pilihan
string getFilmName(int pilihan) {
    switch (pilihan) {
        case 1: return "Film A";
        case 2: return "Film B";
        case 3: return "Film C";
        case 4: return "Film D";
        default: return "Film Tidak Diketahui";
    }
}

// Proses membeli tiket
void beliTiket() {
    int pilihan, jumlahTiket, totalHarga;

    while (true) {
        showFilms();
        pilihan = pilihFilm();

        // Menghitung harga berdasarkan film yang dipilih
        switch (pilihan) {
            case 1: totalHarga = 50000; break;
            case 2: totalHarga = 60000; break;
            case 3: totalHarga = 70000; break;
            case 4: totalHarga = 55000; break;
            default: totalHarga = 0; break;
        }

        // Input jumlah tiket
        cout << "Masukkan jumlah tiket yang ingin dibeli: ";
        cin >> jumlahTiket;

        totalHarga *= jumlahTiket; // Menghitung total harga

        // Menampilkan hasil pembelian
        cout << "\nTiket untuk film " << getFilmName(pilihan) 
             << " (" << jumlahTiket << " tiket) berhasil dipesan." << endl;
        cout << "Total harga: Rp " << totalHarga << endl;

        // Tanya apakah ingin membeli tiket lagi
        char lagi;
        cout << "\nApakah Anda ingin membeli tiket lagi? (y/t): ";
        cin >> lagi;

        if (tolower(lagi) == 't') {
            cout << "Terima kasih telah membeli tiket di bioskop kami!" << endl;
            break;
        }
    }
}

int main() {
    beliTiket();
    return 0;
}
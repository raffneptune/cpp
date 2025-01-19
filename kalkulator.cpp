#include <iostream>
using namespace std;

// Fungsi untuk penjumlahan
double tambah(double x, double y) {
    return x + y;
}

// Fungsi untuk pengurangan
double kurang(double x, double y) {
    return x - y;
}

// Fungsi untuk perkalian
double kali(double x, double y) {
    return x * y;
}

// Fungsi untuk pembagian
double bagi(double x, double y) {
    if (y != 0) {
        return x / y;
    } else {
        cout << "Tidak bisa membagi dengan nol" << endl;
        return 0;  // Mengembalikan nilai 0 jika pembagian dengan nol
    }
}

int main() {
    int pilihan;
    double num1, num2;

    // Menampilkan menu operasi
    cout << "Pilih operasi:" << endl;
    cout << "1. Tambah" << endl;
    cout << "2. Kurang" << endl;
    cout << "3. Kali" << endl;
    cout << "4. Bagi" << endl;

    // Meminta input pilihan operasi
    cout << "Masukkan pilihan (1/2/3/4): ";
    cin >> pilihan;

    // Meminta input angka
    cout << "Masukkan angka pertama: ";
    cin >> num1;
    cout << "Masukkan angka kedua: ";
    cin >> num2;

    // Melakukan operasi sesuai dengan pilihan pengguna
    switch (pilihan) {
        case 1:
            cout << num1 << " + " << num2 << " = " << tambah(num1, num2) << endl;
            break;
        case 2:
            cout << num1 << " - " << num2 << " = " << kurang(num1, num2) << endl;
            break;
        case 3:
            cout << num1 << " * " << num2 << " = " << kali(num1, num2) << endl;
            break;
        case 4:
            double hasilBagi = bagi(num1, num2);
            if (num2 != 0) {  // Mengecek apakah pembagian berhasil
                cout << num1 << " / " << num2 << " = " << hasilBagi << endl;
            }
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }

    return 0;
}
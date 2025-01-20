#include <iostream>
#include <iomanip>

using namespace std;

// Menampilkan menu pilihan bahan bakar
void displayMenu() {
    cout << "Selamat datang di SPBU!" << endl;
    cout << "Pilih jenis bahan bakar:" << endl;
    cout << "1. Premium (Rp 10.000 per liter)" << endl;
    cout << "2. Pertalite (Rp 12.000 per liter)" << endl;
    cout << "3. Pertamax (Rp 15.000 per liter)" << endl;
}

// Menghitung total harga berdasarkan jenis bahan bakar dan jumlah liter
double calculateTotalPrice(int fuelType, double liters) {
    double pricePerLiter = 0;

    if (fuelType == 1) {
        pricePerLiter = 10000;  // Harga Premium
    } else if (fuelType == 2) {
        pricePerLiter = 12000;  // Harga Pertalite
    } else if (fuelType == 3) {
        pricePerLiter = 15000;  // Harga Pertamax
    }

    return pricePerLiter * liters;
}

int main() {
    int fuelType;
    double liters, totalPrice;

    // Menampilkan menu dan meminta input jenis bahan bakar
    displayMenu();
    cout << "Masukkan pilihan (1/2/3): ";
    cin >> fuelType;

    if (fuelType < 1 || fuelType > 3) {
        cout << "Pilihan tidak valid." << endl;
        return 1;
    }

    // Meminta input jumlah liter
    cout << "Masukkan jumlah liter: ";
    cin >> liters;

    if (liters <= 0) {
        cout << "Jumlah liter tidak valid." << endl;
        return 1;
    }

    // Menghitung total harga
    totalPrice = calculateTotalPrice(fuelType, liters);

    // Menampilkan struk pembayaran
    cout << fixed << setprecision(0);  // Menampilkan harga tanpa desimal
    cout << "\n--- STRUK PEMBAYARAN ---" << endl;
    if (fuelType == 1) {
        cout << "Bahan Bakar: Premium" << endl;
    } else if (fuelType == 2) {
        cout << "Bahan Bakar: Pertalite" << endl;
    } else if (fuelType == 3) {
        cout << "Bahan Bakar: Pertamax" << endl;
    }
    cout << "Jumlah Liter: " << liters << " liter" << endl;
    cout << "Total Pembayaran: Rp " << totalPrice << endl;
    cout << "-------------------------" << endl;
    cout << "Terima kasih telah menggunakan layanan kami!" << endl;

    return 0;
}
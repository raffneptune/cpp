#include <iostream>
using namespace std;

// Fungsi untuk menghitung gaji total
double hitungGaji(double gajiPokok, double tunjangan, double potongan) {
    return gajiPokok + tunjangan - potongan;
}

int main() {
    double gajiPokok, tunjangan, potongan, gajiTotal;
    
    // Menampilkan judul program
    cout << "Program Perhitungan Gaji Karyawan" << endl;
    
    // Input data
    cout << "Masukkan gaji pokok: Rp ";
    cin >> gajiPokok;
    cout << "Masukkan tunjangan: Rp ";
    cin >> tunjangan;
    cout << "Masukkan potongan: Rp ";
    cin >> potongan;
    
    // Menghitung gaji total
    gajiTotal = hitungGaji(gajiPokok, tunjangan, potongan);
    
    // Menampilkan hasil perhitungan
    cout << "\nRingkasan Gaji:" << endl;
    cout << "Gaji Pokok: Rp " << gajiPokok << endl;
    cout << "Tunjangan: Rp " << tunjangan << endl;
    cout << "Potongan: Rp " << potongan << endl;
    cout << "Gaji Total: Rp " << gajiTotal << endl;
    
    return 0;
}
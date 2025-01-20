#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
private:
    string model;
    int price;
    int stock;

public:
    Vehicle(string model, int price, int stock) : model(model), price(price), stock(stock) {}

    // Menampilkan informasi kendaraan
    void displayInfo() {
        cout << "Model: " << model << ", Harga: Rp" << price << ", Stok: " << stock << endl;
    }

    // Mengupdate stok setelah pembelian
    void updateStock(int quantity) {
        stock -= quantity;
        if (stock < 0) {
            stock = 0;
        }
    }

    // Memeriksa ketersediaan stok
    bool isAvailable(int quantity) {
        return stock >= quantity;
    }

    int getPrice() {
        return price;
    }

    string getModel() {
        return model;
    }

    int getStock() {
        return stock;
    }
};

class VehicleDealer {
private:
    vector<Vehicle> vehicles;

public:
    // Menambahkan kendaraan ke diler
    void addVehicle(string model, int price, int stock) {
        Vehicle vehicle(model, price, stock);
        vehicles.push_back(vehicle);
    }

    // Menampilkan semua kendaraan yang tersedia
    void displayVehicles() {
        if (vehicles.empty()) {
            cout << "Tidak ada kendaraan di diler." << endl;
            return;
        }
        cout << "\nKendaraan yang Tersedia di Diler:" << endl;
        for (size_t i = 0; i < vehicles.size(); ++i) {
            cout << (i + 1) << ". ";
            vehicles[i].displayInfo();
        }
    }

    // Pembelian kendaraan
    void purchaseVehicle() {
        displayVehicles();
        if (vehicles.empty()) {
            return;
        }

        int choice, quantity;
        cout << "\nPilih kendaraan (masukkan nomor): ";
        cin >> choice;
        cout << "Berapa banyak yang ingin dibeli? ";
        cin >> quantity;

        if (choice < 1 || choice > vehicles.size()) {
            cout << "Pilihan tidak valid." << endl;
            return;
        }

        Vehicle& selectedVehicle = vehicles[choice - 1];
        if (selectedVehicle.isAvailable(quantity)) {
            int totalPrice = selectedVehicle.getPrice() * quantity;
            cout << "\nPembelian Sukses! Total Harga: Rp" << totalPrice << endl;
            selectedVehicle.updateStock(quantity);
        } else {
            cout << "\nStok tidak cukup." << endl;
        }
    }
};

int main() {
    VehicleDealer dealer;

    // Menambahkan beberapa kendaraan ke diler
    dealer.addVehicle("Mobil Sedan", 300000000, 10);
    dealer.addVehicle("Motor Sport", 100000000, 5);
    dealer.addVehicle("Mobil SUV", 500000000, 3);

    int choice;
    while (true) {
        cout << "\n--- Menu Diler Kendaraan ---" << endl;
        cout << "1. Lihat kendaraan yang tersedia" << endl;
        cout << "2. Pembelian kendaraan" << endl;
        cout << "3. Keluar" << endl;

        cout << "\nPilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dealer.displayVehicles();
                break;
            case 2:
                dealer.purchaseVehicle();
                break;
            case 3:
                cout << "Terima kasih telah mengunjungi diler kami!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
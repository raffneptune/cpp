#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RentalItem {
public:
    string name;
    int rate_per_hour;

    RentalItem(string name, int rate_per_hour) {
        this->name = name;
        this->rate_per_hour = rate_per_hour;
    }

    int calculate_cost(int hours) {
        return rate_per_hour * hours;
    }
};

class RentalSystem {
public:
    vector<RentalItem> items;

    RentalSystem() {
        // Menambahkan beberapa barang yang bisa disewa
        items.push_back(RentalItem("Sepeda", 5000));
        items.push_back(RentalItem("Skuter", 10000));
        items.push_back(RentalItem("Mobil", 50000));
    }

    void display_items() {
        cout << "Barang yang tersedia untuk disewa:" << endl;
        for (size_t i = 0; i < items.size(); i++) {
            cout << i + 1 << ". " << items[i].name << " - Rp" << items[i].rate_per_hour << " per jam" << endl;
        }
    }

    void rent_item() {
        display_items();

        int choice;
        cout << "Pilih barang yang ingin disewa (1/2/3): ";
        cin >> choice;

        if (choice < 1 || choice > items.size()) {
            cout << "Pilihan tidak valid!" << endl;
            return;
        }

        int hours;
        cout << "Berapa jam Anda ingin menyewa " << items[choice - 1].name << "? ";
        cin >> hours;

        int total_cost = items[choice - 1].calculate_cost(hours);
        cout << "Total biaya untuk menyewa " << items[choice - 1].name
             << " selama " << hours << " jam adalah: Rp" << total_cost << endl;
    }
};

int main() {
    RentalSystem rental_system;

    while (true) {
        cout << "\nSelamat datang di sistem rental!" << endl;
        cout << "1. Sewa barang" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilih menu: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            rental_system.rent_item();
        } else if (choice == 2) {
            cout << "Terima kasih telah menggunakan sistem rental!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    }

    return 0;
}
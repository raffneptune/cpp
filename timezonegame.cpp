#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Struktur untuk menyimpan data pengguna
struct User {
    string name;
    int kredit;
    vector<string> permainan;
};

// Database pengguna
vector<User> users;

// Fungsi untuk mendaftar pengguna baru
void registerUser() {
    string name;
    cout << "Masukkan nama pengguna: ";
    cin >> name;

    // Cek apakah pengguna sudah terdaftar
    for (const auto& user : users) {
        if (user.name == name) {
            cout << "Pengguna dengan nama " << name << " sudah terdaftar.\n";
            return;
        }
    }

    // Menambahkan pengguna baru ke dalam database
    User newUser;
    newUser.name = name;
    newUser.kredit = 0;
    users.push_back(newUser);
    cout << "Selamat datang, " << name << "! Akun Anda telah dibuat.\n";
}

// Fungsi untuk membeli kredit
void buyCredits(string userName) {
    int creditAmount;
    cout << "Berapa banyak kredit yang ingin Anda beli? (1 kredit = 5000 IDR): ";
    cin >> creditAmount;

    // Cari pengguna berdasarkan nama
    for (auto& user : users) {
        if (user.name == userName) {
            user.kredit += creditAmount;
            cout << creditAmount << " kredit telah ditambahkan ke akun Anda.\n";
            return;
        }
    }

    cout << "Pengguna tidak ditemukan. Silakan mendaftar terlebih dahulu.\n";
}

// Fungsi untuk bermain game
void playGame(string userName) {
    // Cari pengguna berdasarkan nama
    for (auto& user : users) {
        if (user.name == userName) {
            if (user.kredit < 1) {
                cout << "Anda tidak memiliki kredit cukup untuk bermain game. Silakan beli kredit terlebih dahulu.\n";
                return;
            }

            cout << "Pilih permainan yang ingin dimainkan:\n";
            cout << "1. Pac-Man (1 kredit)\n";
            cout << "2. Street Fighter (2 kredit)\n";
            cout << "3. Racing Game (3 kredit)\n";
            int gameChoice;
            cout << "Masukkan nomor permainan: ";
            cin >> gameChoice;

            if (gameChoice == 1 && user.kredit >= 1) {
                user.kredit -= 1;
                cout << "Anda sedang bermain Pac-Man! Semoga berhasil!\n";
            } else if (gameChoice == 2 && user.kredit >= 2) {
                user.kredit -= 2;
                cout << "Anda sedang bermain Street Fighter! Bertarunglah dengan kuat!\n";
            } else if (gameChoice == 3 && user.kredit >= 3) {
                user.kredit -= 3;
                cout << "Anda sedang bermain Racing Game! Gaspol!\n";
            } else {
                cout << "Anda tidak memiliki kredit cukup untuk memilih permainan ini.\n";
                return;
            }

            // Simulasi hasil permainan (acak)
            srand(time(0));
            int result = rand() % 2; // 0 = Kalah, 1 = Menang
            cout << "Memulai permainan...\n";
            cout << "Hasil permainan: " << (result == 1 ? "Menang" : "Kalah") << "\n";
            user.permainan.push_back(result == 1 ? "Menang" : "Kalah");
            return;
        }
    }

    cout << "Pengguna tidak ditemukan. Silakan mendaftar terlebih dahulu.\n";
}

// Fungsi untuk mengecek saldo kredit
void checkBalance(string userName) {
    // Cari pengguna berdasarkan nama
    for (const auto& user : users) {
        if (user.name == userName) {
            cout << "Sisa kredit Anda: " << user.kredit << " kredit.\n";
            return;
        }
    }

    cout << "Pengguna tidak ditemukan. Silakan mendaftar terlebih dahulu.\n";
}

// Menu utama
int main() {
    cout << "Selamat datang di Timezone Mall!\n";

    while (true) {
        cout << "\nMenu Utama:\n";
        cout << "1. Daftar pengguna baru\n";
        cout << "2. Beli kredit\n";
        cout << "3. Mainkan game\n";
        cout << "4. Cek saldo kredit\n";
        cout << "5. Keluar\n";

        int choice;
        cout << "Pilih menu (1/2/3/4/5): ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            string userName;
            cout << "Masukkan nama pengguna untuk membeli kredit: ";
            cin >> userName;
            buyCredits(userName);
        } else if (choice == 3) {
            string userName;
            cout << "Masukkan nama pengguna untuk bermain game: ";
            cin >> userName;
            playGame(userName);
        } else if (choice == 4) {
            string userName;
            cout << "Masukkan nama pengguna untuk cek saldo: ";
            cin >> userName;
            checkBalance(userName);
        } else if (choice == 5) {
            cout << "Terima kasih telah bermain di Timezone Mall! Sampai jumpa lagi!\n";
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        }
    }

    return 0;
}
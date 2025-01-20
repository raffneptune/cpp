#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Daftar kartu dalam deck
const vector<string> deck = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

// Fungsi untuk menghitung nilai kartu
int card_value(const string& card) {
    if (card == "J" || card == "Q" || card == "K") {
        return 10;
    } else if (card == "A") {
        return 11; // Menganggap Ace = 11 untuk kesederhanaan
    } else {
        return stoi(card); // Kartu angka (2-10)
    }
}

// Fungsi untuk membagikan kartu secara acak
string deal_card(vector<string>& deck) {
    int index = rand() % deck.size();
    string card = deck[index];
    deck.erase(deck.begin() + index); // Hapus kartu yang sudah dibagikan
    return card;
}

// Fungsi untuk menghitung total nilai kartu dalam hand
int calculate_hand(const vector<string>& hand) {
    int total = 0;
    for (const string& card : hand) {
        total += card_value(card);
    }
    return total;
}

// Fungsi utama untuk menjalankan permainan
void start_game() {
    vector<string> deck_copy = deck; // Salinan deck untuk permainan
    srand(time(0)); // Menginisialisasi seed untuk random number generator

    // Kartu untuk pemain dan dealer
    vector<string> player_hand, dealer_hand;

    // Membagikan dua kartu untuk pemain dan dealer
    player_hand.push_back(deal_card(deck_copy));
    player_hand.push_back(deal_card(deck_copy));
    dealer_hand.push_back(deal_card(deck_copy));
    dealer_hand.push_back(deal_card(deck_copy));

    // Menampilkan kartu awal pemain dan dealer (satu kartu dealer tersembunyi)
    cout << "Kartu Anda: ";
    for (const string& card : player_hand) {
        cout << card << " ";
    }
    cout << "dengan nilai " << calculate_hand(player_hand) << endl;
    cout << "Kartu Dealer: " << dealer_hand[0] << " dan kartu tersembunyi" << endl;

    // Giliran pemain
    while (calculate_hand(player_hand) < 21) {
        string action;
        cout << "Apakah Anda ingin 'Hit' atau 'Stand'? ";
        cin >> action;
        if (action == "hit" || action == "Hit") {
            player_hand.push_back(deal_card(deck_copy));
            cout << "Kartu Anda sekarang: ";
            for (const string& card : player_hand) {
                cout << card << " ";
            }
            cout << "dengan nilai " << calculate_hand(player_hand) << endl;
        } else if (action == "stand" || action == "Stand") {
            break;
        } else {
            cout << "Pilihan tidak valid. Pilih 'Hit' atau 'Stand'." << endl;
        }
    }

    // Jika pemain melebihi 21
    if (calculate_hand(player_hand) > 21) {
        cout << "Nilai kartu Anda melebihi 21! Anda kalah!" << endl;
        return;
    }

    // Giliran dealer (dealer akan 'hit' sampai total kartu >= 17)
    cout << "Kartu Dealer sekarang: ";
    for (const string& card : dealer_hand) {
        cout << card << " ";
    }
    cout << "dengan nilai " << calculate_hand(dealer_hand) << endl;

    while (calculate_hand(dealer_hand) < 17) {
        cout << "Dealer memukul kartu..." << endl;
        dealer_hand.push_back(deal_card(deck_copy));
        cout << "Kartu Dealer sekarang: ";
        for (const string& card : dealer_hand) {
            cout << card << " ";
        }
        cout << "dengan nilai " << calculate_hand(dealer_hand) << endl;
    }

    // Menentukan pemenang
    int player_total = calculate_hand(player_hand);
    int dealer_total = calculate_hand(dealer_hand);

    if (dealer_total > 21) {
        cout << "Dealer melebihi 21! Anda menang!" << endl;
    } else if (player_total > dealer_total) {
        cout << "Anda menang!" << endl;
    } else if (player_total < dealer_total) {
        cout << "Dealer menang!" << endl;
    } else {
        cout << "Hasil seri!" << endl;
    }
}

int main() {
    cout << "Selamat datang di permainan Dealer Kartu!" << endl;
    start_game();
    return 0;
}
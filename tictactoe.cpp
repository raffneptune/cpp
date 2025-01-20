#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menampilkan papan permainan
void print_board(const vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i * 3] << " | " << board[i * 3 + 1] << " | " << board[i * 3 + 2] << " \n";
        if (i < 2) {
            cout << "---|---|---\n";
        }
    }
    cout << "\n";
}

// Fungsi untuk mengecek apakah pemain menang
bool check_win(const vector<char>& board, char player) {
    int win_conditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // baris
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // kolom
        {0, 4, 8}, {2, 4, 6}              // diagonal
    };

    for (int i = 0; i < 8; i++) {
        if (board[win_conditions[i][0]] == player &&
            board[win_conditions[i][1]] == player &&
            board[win_conditions[i][2]] == player) {
            return true;
        }
    }
    return false;
}

// Fungsi untuk mengecek apakah papan penuh
bool is_board_full(const vector<char>& board) {
    for (char space : board) {
        if (space == ' ') {
            return false;
        }
    }
    return true;
}

// Fungsi utama permainan
void play_game() {
    vector<char> board(9, ' ');  // papan Tic Tac Toe kosong
    char current_player = 'X';

    while (true) {
        print_board(board);

        // Meminta pemain untuk memilih posisi
        int move;
        cout << "Player " << current_player << ", pilih posisi (1-9): ";
        cin >> move;

        // Validasi input
        if (move < 1 || move > 9 || board[move - 1] != ' ') {
            cout << "Posisi tidak valid atau sudah terisi, coba lagi.\n";
            continue;
        }

        // Menandai posisi dengan simbol pemain saat ini
        board[move - 1] = current_player;

        // Mengecek apakah pemain menang
        if (check_win(board, current_player)) {
            print_board(board);
            cout << "Selamat! Pemain " << current_player << " menang!\n";
            break;
        }

        // Mengecek apakah papan penuh (seri)
        if (is_board_full(board)) {
            print_board(board);
            cout << "Permainan berakhir dengan seri!\n";
            break;
        }

        // Ganti giliran pemain
        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

// Fungsi utama
int main() {
    play_game();
    return 0;
}
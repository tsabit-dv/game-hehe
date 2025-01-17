#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>

using namespace std;

string getColor(int number) {
    if (number == 0) return "Green";
    return (number % 2 == 0) ? "Black" : "Red";
}

int spinWheel() {
    return rand() % 37;
}

// Fungsi utama permainan roulette
void playRoulette() {
    double balance = 1000.0; // Saldo awal
    vector<string> logs;     // Log permainan
    map<string, int> payouts = {
        {"number", 35}, 
        {"color", 2},   
        {"parity", 2}   
    };

    cout << "🎲 Selamat datang di permainan Roulette! 🎲" << endl;
    cout << "Saldo awal Anda: $" << balance << endl;

    while (true) {
        cout << "\nSaldo Anda saat ini: $" << balance << endl;
        cout << "Pilih jenis taruhan:\n";
        cout << "1. Angka (0–36)\n";
        cout << "2. Warna (Red/Black)\n";
        cout << "3. Genap/Ganjil\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        int choice;
        cin >> choice;

        if (choice == 4) {
            cout << "\nTerima kasih telah bermain! Saldo akhir Anda: $" << balance << endl;
            cout << "\nLog Permainan:\n";
            for (const auto& log : logs) {
                cout << log << endl;
            }
            break;
        }

        double bet;
        cout << "Masukkan jumlah taruhan Anda: $";
        cin >> bet;

        if (bet > balance) {
            cout << "Taruhan melebihi saldo Anda! Coba lagi.\n";
            continue;
        }

        balance -= bet;
        int winningNumber = spinWheel();
        string winningColor = getColor(winningNumber);

        if (choice == 1) { 
            int guess;
            cout << "Tebak angka (0–36): ";
            cin >> guess;

            if (guess == winningNumber) {
                double payout = bet * payouts["number"];
                balance += payout;
                logs.push_back("Menang angka! Angka: " + to_string(winningNumber) + " -> Payout: $" + to_string(payout));
                cout << "Selamat! Anda menang $" << payout << "!" << endl;
            } else {
                logs.push_back("Kalah angka! Angka: " + to_string(winningNumber));
                cout << "Maaf, angka yang keluar adalah " << winningNumber << ". Anda kalah.\n";
            }

        } else if (choice == 2) { // Taruhan pada warna
            string guessColor;
            cout << "Tebak warna (Red/Black): ";
            cin >> guessColor;

            if (guessColor == winningColor) {
                double payout = bet * payouts["color"];
                balance += payout;
                logs.push_back("Menang warna! Warna: " + winningColor + " -> Payout: $" + to_string(payout));
                cout << "Selamat! Anda menang $" << payout << "!" << endl;
            } else {
                logs.push_back("Kalah warna! Warna: " + winningColor);
                cout << "Maaf, warna yang keluar adalah " << winningColor << ". Anda kalah.\n";
            }

        } else if (choice == 3) { 
            string guessParity;
            cout << "Tebak (Even/Odd): ";
            cin >> guessParity;

            string winningParity = (winningNumber % 2 == 0) ? "Even" : "Odd";
            if (guessParity == winningParity) {
                double payout = bet * payouts["parity"];
                balance += payout;
                logs.push_back("Menang genap/ganjil! Parity: " + winningParity + " -> Payout: $" + to_string(payout));
                cout << "Selamat! Anda menang $" << payout << "!" << endl;
            } else {
                logs.push_back("Kalah genap/ganjil! Parity: " + winningParity);
                cout << "Maaf, hasilnya adalah " << winningParity << ". Anda kalah.\n";
            }

        } else {
            cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); 
    playRoulette();
    return 0;
}

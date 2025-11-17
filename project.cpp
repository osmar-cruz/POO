#include <iostream>
#include <cstdlib>
#include <ctime>
#include "class_project.cpp"
using namespace std;

int main() {                                          //This is the main program
    cout << "=== SIMPLE ROULETTE GAME ===\n";

    string name;
    double money;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter starting balance: ";
    cin >> money;

    Player player(name, money);
    Roulette roulette;

    char play = 'y';

    while (play == 'y' && player.getBalance() > 0) {
        player.showBalance();

        double amount;
        cout << "\nHow much do you want to bet? ";
        cin >> amount;

        if (!player.betMoney(amount)) {
            continue; // skip this round
        }

        int number;
        cout << "Choose a number (0-36): ";
        cin >> number;

        Bet bet(amount, number);

        int result = roulette.spin();
        cout << "\nThe roulette spins...\n";
        cout << "It landed on: " << result << endl;

        double win = bet.checkWin(result);

        if (win > 0) {
            cout << "You WIN! You gain $" << win << endl;
            player.addMoney(win + amount); // return bet + winnings
        } else {
            cout << "You lost the bet.\n";
        }

        player.showBalance();

        cout << "\nPlay again? (y/n): ";
        cin >> play;
    }

    cout << "\nGame over. Thanks for playing!\n";

    return 0;
}
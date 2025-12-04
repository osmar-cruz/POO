#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
#include <string>
#include "class_project_bet.cpp"
#include "class_project_player1.cpp"
#include "class_project_roulette.cpp"

using namespace std;

class RouletteGame {
private:
    Roulette roulette;
    vector<Player> players;

    void setupGame() {
        int numPlayers;
        cout << "Enter number of players (1-5): ";
        cin >> numPlayers;
        if (numPlayers < 1) numPlayers = 1;
        else if (numPlayers > 5) {
            cout << "Maximum 5 players allowed. Setting to 5.\n";
            numPlayers = 5;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < numPlayers; ++i) {
            string name;
            double money;
            cout << "Enter name for Player " << (i + 1) << ": ";
            getline(cin, name);
            cout << "Enter starting balance for " << name << ": ";
            cin >> money;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            players.emplace_back(name, money);
        }
        cout << endl;
    }

    BetType askBetType() {
        int type;
        do {
            cout << "Choose bet type: (1) Number  (2) Color  (3) Column: ";
            cin >> type;
        } while (type < 1 || type > 3);
        return static_cast<BetType>(type);
    }

    int askBetChoice(BetType type) {
        int choice;
        if (type == NUMBER) {
            do {
                cout << "Choose number to bet on (0-36): ";
                cin >> choice;
            } while (choice < 0 || choice > 36);
        }
        else if (type == COLOR) {
            do {
                cout << "Choose color (0 = green, 1 = red, 2 = black): ";
                cin >> choice;
            } while (choice < 0 || choice > 2);
        }
        else if (type == COLUMN) {
            do {
                cout << "Choose column (1, 2, or 3): ";
                cin >> choice;
            } while (choice < 1 || choice > 3);
        }
        return choice;
    }

public:
    void run() {
        cout << "=== ROULETTE GAME ===\n";
        setupGame();

        char play = 'y';
        while (play == 'y') {
            bool active = false;
            for (auto &p : players)
                if (p.getBalance() > 0)
                    active = true;

            if (!active) {
                cout << "All players are out of money. Game over.\n";
                break;
            }

            struct PlayerBet {
                int playerIndex;
                Bet bet;
            };
            vector<PlayerBet> roundBets;

            for (size_t i = 0; i < players.size(); ++i) {
                Player &player = players[i];
                if (player.getBalance() <= 0) {
                    cout << player.getName() << " has no money left.\n";
                    continue;
                }

                player.showBalance();
                double amount;
                cout << "Enter bet amount for " << player.getName() << ": ";
                cin >> amount;

                if (!player.betMoney(amount)) continue;

                BetType type = askBetType();
                int choice = askBetChoice(type);
                roundBets.push_back({static_cast<int>(i), Bet(amount, type, choice)});
            }

            if (roundBets.empty()) {
                cout << "No bets placed this round.\n";
                break;
            }

            int result = roulette.spin();
            cout << "\n>>> The roulette landed on: " << result << "\n";

            for (const auto &pb : roundBets) {
                Player &player = players[pb.playerIndex];
                double win = pb.bet.checkWin(result);
                if (win > 0) {
                    player.addMoney(win + pb.bet.getAmount());
                    cout << player.getName() << " WON $" << win << "! New balance: $" << player.getBalance() << "\n";
                } else {
                    cout << player.getName() << " lost the bet. New balance: $" << player.getBalance() << "\n";
                }
            }

            cout << "\nPlay another round? (y/n): ";
            cin >> play;
            cout << endl;
        }

        cout << "=== GAME OVER ===\n";
    }
};

int main() {
    RouletteGame game;
    game.run();
    return 0;
}


}


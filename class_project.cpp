#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Roulette {                             //This is the class roulette
private:
    int lastNumber;

public:
    Roulette() {
        srand(time(0));   // random seed
        lastNumber = 0;
    }

    int spin() {
        lastNumber = rand() % 37; // 0 - 36
        return lastNumber;
    }

    int getLastNumber() {
        return lastNumber;
    }
};

class Player {                        //This is the class player
private:
    string name;
    double balance;

public:
    Player(string n, double b) {
        name = n;
        balance = b;
    }

    double getBalance() {
        return balance;
    }

    void showBalance() {
        cout << "Balance: $" << balance << endl;
    }

    bool betMoney(double amount) {
        if (amount > balance) {
            cout << "Not enough balance." << endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    void addMoney(double amount) {
        balance += amount;
    }
};

class Bet {                                  //This is the class bet
public:
    double amount;
    int chosenNumber; // only number bet in this simple version

    Bet(double a, int n) {
        amount = a;
        chosenNumber = n;
    }

    double checkWin(int result) {
        if (result == chosenNumber) {
            return amount * 35;  // payout 35:1
        }
        return 0; // lost
    }
};

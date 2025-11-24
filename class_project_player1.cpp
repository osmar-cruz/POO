#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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
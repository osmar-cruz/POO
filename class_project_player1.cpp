#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Base class Person to represent a generic person with a name
class Person {
private:
    string name;

public:
    // Constructor
    Person(string n) : name(n) {}

    // Getter for name
    string getName() const {
        return name;
    }

    // Setter for name
    void setName(string n) {
        name = n;
    }
};

// Player class inherits from Person and adds balance and betting behavior
class Player : public Person {
private:
    double balance;

public:
    // Constructor takes a name and starting balance, and calls the base Person constructor
    Player(string n, double b) : Person(n), balance(b) {}

    // Returns the current balance
    double getBalance() const {
        return balance;
    }

    // Displays the player's name and current balance
    void showBalance() const {
        cout << getName() << "'s balance: $" << balance << endl;
    }

    // Attempts to deduct the bet amount from balance (if sufficient funds)
    // Returns true if the bet is placed, false if there's not enough balance
    bool betMoney(double amount) {
        if (amount > balance) {
            cout << getName() << " doesn't have enough balance for that bet." << endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    // Adds money to the player's balance (used for winnings payouts)
    void addMoney(double amount) {
        balance += amount;
    }
};

        balance += amount;
    }

};

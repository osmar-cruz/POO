#include <iostream>
#include <set>

using namespace std;

enum BetType { NUMBER = 1, COLOR = 2, COLUMN = 3 };

class Bet {
private:
    double amount;
    BetType type;
    int choice; // If NUMBER: 0–36; if COLOR: 0=green, 1=red, 2=black; if COLUMN: 1,2,3

public:
    Bet(double amt, BetType t, int c) : amount(amt), type(t), choice(c) {}

        // Static helpers to identify color and column from result
    static int checkColor(int n) {
        if (n == 0) return 0;
        static const set<int> reds = {
            1,3,5,7,9,12,14,16,18,
            19,21,23,25,27,30,32,34,36
        };
        return (reds.count(n) ? 1 : 2);
    }

    static int checkColumn(int n) {
        if (n == 0) return 0;
        int mod = n % 3;
        if (mod == 1) return 1;
        if (mod == 2) return 2;
        return 3;
    }


    double getAmount() const {
        return amount;
    }

    int getChoice() const {
        return choice;
    }

    BetType getType() const {
        return type;
    }

    double checkWin(int result) const {
        if (type == NUMBER) {
            if (result == choice) {
                return amount * 35; // 35:1 payout
            }
        }
        else if (type == COLOR) {
            int color = getColor(result);
            if (choice == 0 && result == 0) {
                return amount * 35; // green (0)
            } else if (choice == 1 && color == 1) {
                return amount * 1;  // red
            } else if (choice == 2 && color == 2) {
                return amount * 1;  // black
            }
        }
        else if (type == COLUMN) {
            int col = getColumn(result);
            if (col == choice) {
                return amount * 2; // 2:1 payout
            }
        }

        return 0; // loss
    }

private:
    // 0 = green, 1 = red, 2 = black
    int getColor(int n) const {
        if (n == 0) return 0;
        static const set<int> reds = {
            1,3,5,7,9,12,14,16,18,
            19,21,23,25,27,30,32,34,36
        };
        return (reds.count(n) ? 1 : 2);
    }

    // returns 1, 2, or 3 if in column; 0 if not (like 0)
    int getColumn(int n) const {
        if (n == 0) return 0;
        int mod = n % 3;
        if (mod == 1) return 1;
        if (mod == 2) return 2;
        return 3;
    }
};

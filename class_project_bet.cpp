#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

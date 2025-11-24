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

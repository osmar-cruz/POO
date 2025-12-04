#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Roulette {  // Class representing the roulette wheel
private:
    int lastNumber;

public:
    Roulette() {
        srand(time(0));  // Seed the random number generator once when the roulette is created
        lastNumber = 0;
    }

    // Spins the wheel and returns a random number between 0 and 36
    int spin() {
        lastNumber = rand() % 37;
        return lastNumber;
    }

    // Returns the last number that was spun
    int getLastNumber() const {
        return lastNumber;
    }
};

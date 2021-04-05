#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class ParkingSystem {
    int m[4];
public:
    ParkingSystem(int big, int medium, int small) {
        m[1] = big, m[2] = medium, m[3] = small;
    }

    bool addCar(int c) {
        if (m[c] == 0) return false;
        --m[c];
        return true;
    }
};

int main() {
}

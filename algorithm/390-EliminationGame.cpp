#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 : iteratively simulate the whole procedure, O(nlogn)
class Solution_it {
public:
    int lastRemaining(int n) {
        int num = n;
        bool lefting = true;
        int head = 1;
        int step = 1;
        while (num > 1) {
            if (lefting || num % 2) head += step;
            num /= 2;
            step *= 2;
            lefting = !lefting;
        }
        return head;;
    }
};


// Solution 2 : recursively
class Solution_re {
public:
    int lastRemaining(int n) {
        if (n == 1) return 1;
        return 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};


int main() {
    return 0;
}

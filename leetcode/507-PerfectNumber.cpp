#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 0;
        for (long long i = 2; i*i <= num; ++i) {
            if (num%i == 0) {
                sum += i;
                sum += num/i;
            }
        }
        return sum+1 == num;
    }
};


int main() {
    return 0;
}

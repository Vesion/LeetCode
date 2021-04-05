#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// greedy
class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for (char c : n) {
            if (c == '9') return 9;
            res = max(res, c-'0');
        }
        return res;
    }
};

int main() {
}

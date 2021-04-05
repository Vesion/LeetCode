#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while (n != 1) {
            res += n/2;
            n = (n-1)/2 + 1;
        }
        return res;
    }
};

int main() {
}

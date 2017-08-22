#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        long res = stol(s);
        return (res > n && res <= INT_MAX) ? res : -1;
    }
};


int main() {
    return 0;
}

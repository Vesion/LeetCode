#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    using ll = long long;
    int nextGreaterElement(int n) {
        string ns = to_string(n);
        bool f = next_permutation(ns.begin(), ns.end());
        if (!f) return -1;
        ll nn = stoll(ns);
        if (nn > INT_MAX) return -1;
        return nn;
    }
};


int main() {
    return 0;
}

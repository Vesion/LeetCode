#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 10) return a;
        vector<int> p;
        for (int i = 9; i > 1; --i) {
            while (a%i == 0) {
                p.push_back(i);
                a /= i;
            }
        }
        if (a > 1) return 0;
        long long res = 0;
        for (int i = p.size()-1; i >= 0; --i) {
            res = res*10 + p[i];
            if (res > INT_MAX) return 0;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.smallestFactorization(4) << endl;
    return 0;
}

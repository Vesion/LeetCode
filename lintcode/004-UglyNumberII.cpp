#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        int c = 0;
        while (true) {
            auto t = *s.begin();
            if (++c == n) return t;
            s.erase(t);
            s.insert(t*2);
            s.insert(t*3);
            s.insert(t*5);
        }
        return 0; // never
    }
};

int main() {
    Solution s;
    cout << s.nthUglyNumber(100) << endl;
    return 0;
}

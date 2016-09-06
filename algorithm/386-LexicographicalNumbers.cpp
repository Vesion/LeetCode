#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

// Solution 0 : naive sort, O(k*n*logn) time, TLE
class Solution_sort {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        iota(result.begin(), result.end(), 1);

        auto cmp = [](int a, int b) {
            vector<int> av, bv;
            while (a) { av.push_back(a%10); a /= 10; }
            while (b) { bv.push_back(b%10); b /= 10; }
            reverse(av.begin(), av.end());
            reverse(bv.begin(), bv.end());

            auto ai = av.begin(), bi = bv.begin();
            while (ai != av.end() && bi != bv.end()) {
                if (*ai < *bi) return true;
                if (*ai > *bi) return false;
                ++ai, ++bi;
            }
            if (bi != bv.end()) return true;
            return false;
        };

        cout << cmp(101, 110) <<endl;

        sort(result.begin(), result.end(), cmp);
        return result;
    }
};


// Solution 1 : generating numbers in lexical order
//      When current number is 45, the next number may be :
//          45 * 10 = 450
//          45 + 1 = 46 (but be careful with ...9)
//          45 / 10 + 1 = 5
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int cur = 1;
        for (int i = 1; i <= n; ++i) {
            result.push_back(cur);
            if (cur*10 <= n) cur *= 10;
            else if (cur+1 <= n && cur%10 != 9) cur += 1;
            else {
                while ((cur/10)%10 == 9) cur /= 10;
                cur = cur/10 + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    auto r = s.lexicalOrder(998);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

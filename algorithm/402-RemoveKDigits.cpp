#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// greedy, stack
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        k = n-k;
        string res;
        for (int i = 0; i < n; ++i) {
            while (!res.empty() && num[i] < res.back() && (int)res.size()+n-i > k) res.pop_back();
            if ((int)res.size() < k) res.push_back(num[i]);
        }
        auto it = res.find_first_not_of('0');
        if (it == string::npos) return "0";
        return res.substr(it);
    }
};


int main() {
    return 0;
}


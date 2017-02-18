#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 : trivial dfs
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        dfs(num, 0, 0, res);
        return res;
    }
    
    void dfs(int num, int start, int board, vector<string>& res) {
        if (num == 0) {
            int minute = board & 0b111111;
            int hour = board >> 6;
            if (minute < 60 && hour < 12) res.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
            return;
        }
        
        for (int i = start; i < 10; ++i) dfs(num-1, i+1, board|(1<<i), res);
    }
};


// Solution 2 : enumerate
class Solution_2 {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bitset<4>(h).count() + bitset<6>(m).count() != (size_t)num) continue;
                res.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    auto r = s.readBinaryWatch(6);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}


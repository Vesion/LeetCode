#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 : trivial dfs
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        if (num > 8) return {};
        vector<string> res;
        dfs(num, 0, 0, res);
        return res;
    }

    void dfs(int num, int start, int path, vector<string>& res) {
        if (num == 0) {
            int minute = path & 0b111111;
            int hour = path >> 6;
            if (hour >= 0 && hour <= 11 && minute >= 0 && minute <= 59)
                res.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
            return;
        }

        for (int i = start; i < 10; ++i) {
            int mask = 1 << i;
            dfs(num-1, i+1, path|mask, res);
        }
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
    auto r = s.readBinaryWatch(2);
    cout << r.size() <<endl;
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}


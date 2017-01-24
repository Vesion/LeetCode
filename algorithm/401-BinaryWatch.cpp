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
        dfs(0, num, 0, res);
        return res;
    }
    
    void dfs(int start, int num, int led, vector<string>& res) {
        if (num == 0) {
            int hour = led & 0b1111;
            int minute = led >> 4;
            if (hour <= 11 && minute <= 59)
                res.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "")+to_string(minute));
            return;
        }
        for (int i = start; i < 10; ++i) {
            dfs(i+1, num-1, led|(1<<i), res);
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
    Solution_2 s;
    auto r = s.readBinaryWatch(2);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}


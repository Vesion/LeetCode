#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;


// Solution 1 : naive dfs
class Solution_dfs {
public:
    int t[10];
    vector<string> result;

    void push_result() {
        int hour = 0;
        for (int i = 0; i < 4; ++i)
            hour = (hour << 1) | t[i];
        if (hour > 11) return;
        int minute = 0;
        for (int i = 4; i < 10; ++i)
            minute = (minute << 1) | t[i];
        if (minute > 59) return;
        string h = to_string(hour);
        result.push_back(to_string(hour) + ":" + (minute < 10 ? "0" + to_string(minute) : to_string(minute)));
    }

    void dfs(int c, int start) {
        if (c == 0) {
            push_result();
            return;
        }
        if (start+c > 10) return;
        for (int i = start; i < 10; ++i) {
            t[i] = 1;
            dfs(c-1, i+1);
            t[i] = 0;
        }
    }

    vector<string> readBinaryWatch(int num) {
        fill_n(t, 10, 0);
        result.clear();
        dfs(num, 0);
        return result;
    }
};


// Solution 2 : skillful enumerate
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if ((int)bitset<10>(h << 6 | m).count() == num)
                    result.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    auto r = s.readBinaryWatch(0);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

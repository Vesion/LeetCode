#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        string res;
        int count = 0; char prev = 0;
        for (char c : chars) {
            if (c != prev) {
                if (prev) res += prev;
                if (count > 1) res += to_string(count);
                count = 1; prev = c;
            } else {
                ++count;
            }
        }
        res += prev;
        if (count > 1) res += to_string(count);
        for (int i = 0; i < res.size(); ++i) chars[i] = res[i];
        return res.size();
    }
};

int main() {

}
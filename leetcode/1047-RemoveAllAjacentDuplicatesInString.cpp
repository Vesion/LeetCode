#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (char c : S) {
            if (res.empty() || res.back() != c) res += c;
            else res.pop_back();
        }
        return res;
    }
};

int main() {

}
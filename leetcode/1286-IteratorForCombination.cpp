#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// k indexes, e.g. n = 10, k = 3
// 0,1,2 -> 0,1,3 -> ... -> 0,1,9 -> 0,2,3 -> ... -> 0,8,9 -> 1,2,3 -> ... -> 7,8,9
class CombinationIterator {
    vector<int> p;  // p[i] is the pointer of ith number out of k
    string s;
    int n, k;
    bool has;
public:
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        n = s.size();
        k = combinationLength;
        p.resize(k);
        has = true;
        for (int i = 0; i < k; ++i) p[i] = i;
    }

    string next() {
        string res;
        for (int i = 0; i < k; ++i) res += s[p[i]];
        has = false;
        for (int i = k-1; i >= 0; --i) {
            if (p[i] != i+n-k) {
                ++p[i];
                // after incrementing p[i], need reset p[i+1...k)
                for (int j = i+1; j < k; ++j) p[j] = p[i]+j-i;
                has = true;
                break;
            }
        }
        return res;
    }

    bool hasNext() {
        return has;
    }
};


// could use bitmap to represent indexes, like
// abcde, k = 3
// 11100 -> abc
// 11010 -> abd

int main() {
}

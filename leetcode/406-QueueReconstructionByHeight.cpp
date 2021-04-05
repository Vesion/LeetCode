#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://discuss.leetcode.com/topic/60394/easy-concept-with-python-c-java-solution
//
// Thinking process:
// Firstly, if there are only the tallest people, how to sort them with k? Obvious the one with smaller k goes first.
// Then for those are second tallest people, how to insert them into sorted tallest people queue? Like above, the one with smaller k insert first.
// And third tallest, fourth tallest and so on.
//
// Why this strategy is correct, the key is :
// People are only counting taller or equal-height others standing in front of them. So a smallest person is completely irrelevant for all taller ones.

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
             [](const vector<int>& p1, const vector<int>& p2) {
                 if (p1[0] == p2[0]) return p1[1] < p2[1];
                 return p1[0] > p2[0];
             });
        vector<vector<int>> res;
        for (const vector<int>& p : people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};


int main() {
    return 0;
}

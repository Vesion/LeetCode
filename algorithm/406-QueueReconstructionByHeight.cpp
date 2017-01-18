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
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), 
                [](const pair<int, int>& p1, const pair<int ,int>& p2) {
                    return (p1.first > p2.first) || (p1.first == p2.first && p1.second < p2.second);
                });
        vector<pair<int, int>> result;
        for (auto &p : people)
            result.insert(result.begin()+p.second, p);
        return result;
    }
};


int main() {
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        for (int i = 0; i < (int)list1.size(); ++i) m[list1[i]] = i;
        int mins = INT_MAX;
        for (int i = 0; i < (int)list2.size(); ++i) {
            if (m.count(list2[i])) mins = min(mins, i+m[list2[i]]);
        }
        vector<string> res;
        for (int i = 0; i < (int)list2.size(); ++i) {
            if (m.count(list2[i]) && i+m[list2[i]] == mins) res.push_back(list2[i]);
        }
        return res;
    }
};


int main() {
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        for (int& i : candies) s.insert(i);
        int k = s.size(), n = candies.size();
        return k >= n/2 ? n/2 : k;
    }
};


int main() {
    return 0;
}

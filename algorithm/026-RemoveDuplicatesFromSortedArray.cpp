#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// use STL unique
int removeDuplicates(vector<int>& nums) {
    //sort(nums.begin(), nums.end()); // should call sort before call unique, but here sorted list has been promised in quesion
    vector<int>::iterator u = unique(nums.begin(), nums.end());
    return (u - nums.begin());
}

int main() {
    vector<int> a{1, 1, 2, 2, 3};
    cout << removeDuplicates(a);
    return 0;
}

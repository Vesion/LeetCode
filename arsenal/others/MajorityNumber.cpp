#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The classical Majority Number Problem
// Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array.
//
// Solution : Boyer Moore Voting Algorithm


// Version 1 : The simplest, find the number occurs more than 1/2
int majorityNumber(vector<int>& nums) {
    int count = 1, result = 0;
    for (auto &num : nums) {
        if (num == result)
            ++count;
        else if (count == 0) {
            count = 1;
            result = num;
        }
        else --count;
    }
    return result;
}


// Version 2 : Find the number occurs more than 1/3
vector<int> majorityElement(vector<int>& nums) {
    int r1 = 0, c1 = 0, r2 = 1, c2 = 0;
    for (int& num : nums) {
        if (num == r1) ++c1;
        else if (num == r2) ++c2;
        else {
            if (c1 == 0) { r1 = num; c1 = 1; }
            else if (c2 == 0) { r2 = num; c2 = 1; }
            else { --c1; --c2; }
        }
    }
    c1 = c2 = 0;
    for (int& num : nums) {
        if (num == r1) ++c1;
        else if (num == r2) ++c2;
    }
    vector<int> res;
    if (c1 > (int)nums.size()/3) res.push_back(r1);
    if (c2 > (int)nums.size()/3) res.push_back(r2);
    return res;
}


int main() {
    return 0;
}

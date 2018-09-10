#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Given an array size n, return one of it's permutation, the probability of returning any one of n! permutations must be the same.
// Fisher Yates Algorithm
//
// How does this work?
// The probability that ith element (including the last one) goes to last position is 1/n, because we randomly pick an element in first iteration.
//
// The probability that ith element goes to second last position can be proved to be 1/n by dividing it in two cases.
//      Case 1: i = n-1 (index of last element):
//          The probability of last element going to second last position is = (probability that last element doesn't stay at its original position) x (probability that the index picked in previous step is picked again so that the last element is swapped)
//          So the probability = ((n-1)/n) x (1/(n-1)) = 1/n
//      Case 2: 0 < i < n-1 (index of non-last):
//          The probability of ith element going to second position = (probability that ith element is not picked in previous iteration) x (probability that ith element is picked in this iteration)
//          So the probability = ((n-1)/n) x (1/(n-1)) = 1/n

// We can easily generalize above proof for any other position.

vector<int> shuffle(vector<int>& nums) {
    vector<int> res = nums;
    for (int i = res.size()-1; i >= 0; --i) {
        swap(res[i], res[rand()%(i+1)]);
    }
    return res;
}


int main() {
    vector<int> nums = {1, 2, 3, 4, 5}; 
    auto r = shuffle(nums);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}


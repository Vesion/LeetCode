#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

// Solution 1 : two multisets, use it as a heap
// similar to 295-FindMedianFromDataStream
class Solution_1 {
private:
    multiset<int, greater<int>> small;
    multiset<int> large;
    void push(int num) {
        if (small.empty() || num <= *small.begin()) small.insert(num);
        else large.insert(num);
        balance();
    }
    
    void pop(int num) {
        auto sit = small.find(num);
        if (sit != small.end()) small.erase(sit);
        else large.erase(large.find(num));
        balance();
    }

    void balance() {
        if (small.size() > large.size()+1) {
            large.insert(*small.begin());
            small.erase(small.begin());
        }
        if (large.size() > small.size()) {
            small.insert(*large.begin());
            large.erase(large.begin());
        }
    }
    
    double median() {
        if (small.size() > large.size()) return *small.begin();
        else return ((long long)*small.begin() + *large.begin()) * 0.5;
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            push(nums[i]);
            if (i >= k-1) {
                if (i >= k) pop(nums[i-k]);
                res.push_back(median());
            }
        }
        return res;
    }
};


// Solution 2 : one multiset, use it as a BST
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> bst(nums.begin(), nums.begin()+k);
        auto mid = next(bst.begin(), k/2);
        
        vector<double> res;
        res.push_back(((double)*mid + *next(mid, k%2-1)) / 2);
        
        for (int i = k; i < (int)nums.size(); ++i) {
            bst.insert(nums[i]);
            if (*mid > nums[i]) --mid;
            
            if (*mid >= nums[i-k]) ++mid;
            // bst.erase(nums[i-k]) is wrong, because it will erase all numbers equal to nums[i-k]
            // we should erase only one number, so find it first
            bst.erase(bst.lower_bound(nums[i-k]));
            
            res.push_back(((double)*mid + *next(mid, k%2-1)) / 2);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums = { 7,9,3,8,0,2,4,8,3,9 };
    auto r = s.medianSlidingWindow(nums, 1);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

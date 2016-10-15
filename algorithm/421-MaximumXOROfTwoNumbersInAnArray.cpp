#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;


// Solution 1 : Trie, but MLE
class Solution_trie {
public:
    struct Node { Node* next[2]; };
    Node* root;

    void insert(int num) {
        auto cur = root;
        for (int i = 31; i >= 0; --i) {
            int id = (num>>i) & 1;
            if (cur->next[id] == NULL) cur->next[id] = new Node();
            cur = cur->next[id];
        }
    }

    int query(int num) {
        int result = 0;
        auto cur = root;
        for (int i = 31; i >= 0; --i) {
            int id = (num>>i) & 1;
            if (cur->next[id^1] != NULL) {
                result |= (1<<i);
                cur = cur->next[id^1];
            } else
                cur = cur->next[id];
        }
        return result;
    }

    int findMaximumXOR(vector<int>& nums) {
        if (nums.empty()) return 0;
        root = new Node();
        for (auto num : nums) insert(num);
        int result = INT_MIN;        
        for (auto num : nums) result = max(result, query(num));
        return result;
    }
};


// Solution 2 : hash set
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0, mask = 0;        
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> s;
            for (int num : nums) s.insert(num & mask);
            int tmp = result | (1 << i);
            for (int prefix : s) {
                if (s.count(tmp ^ prefix)) {
                    result = tmp;
                    break;
                }
            }
        }
        return result;
    }
};



int main() {
    Solution s;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << s.findMaximumXOR(nums)<<endl;
    return 0;
}

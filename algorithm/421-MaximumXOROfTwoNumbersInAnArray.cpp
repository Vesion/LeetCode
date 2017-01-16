#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

// Solution 1 : trie
class Solution {
private:
    struct TrieNode { 
        TrieNode* nexts[2]; 
        TrieNode() { nexts[0] = nexts[1] = NULL; } // do not forget init pointers!
    };
    TrieNode* root;

    void insert(int num) {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; --i) {
            int val = (num >> i) & 1;
            if (!cur->nexts[val]) cur->nexts[val] = new TrieNode;
            cur = cur->nexts[val];
        }
    }

    int query(int num) {
        int xor_sum = 0;
        TrieNode* cur = root;
        for (int i = 31; i >= 0; --i) {
            int val = (num >> i) & 1;
            if (cur->nexts[val^1]) {
                xor_sum |= (1 << i);
                cur = cur->nexts[val^1]; // think about why this
            } else
                cur = cur->nexts[val];
        }
        return xor_sum;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.empty()) return 0;
        root = new TrieNode;
        for (int num : nums) insert(num);
        int res = 0;
        for (int num : nums) res = max(res, query(num));
        return res;
    }
};


// Solution 2 : use std::unordered_set to simulate trie, very skillful
class Solution_2 {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int prefix = 0;
        unordered_set<int> s;
        for (int i = 31; i >= 0; --i) {
            prefix |= (1 << i);
            s.clear();
            for (int num : nums) s.insert(num & prefix);
            int candidate = res | (1 << i);
            // if a^b = c, then a^c = b, b^c = a
            // find if there exists two numbers their xor is candidate
            for (int p : s) {
                if (s.count(candidate ^ p)) { 
                    res = candidate; 
                    break; 
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << s.findMaximumXOR(nums) <<endl;
    return 0;
}


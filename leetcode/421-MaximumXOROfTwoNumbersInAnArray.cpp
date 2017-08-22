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
        TrieNode () { fill_n(nexts, 2, nullptr); }
    };
    TrieNode* root;
    
    void insert(int num) {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; --i) {
            int c = (num>>i)&1;
            if (!cur->nexts[c]) cur->nexts[c] = new TrieNode();
            cur = cur->nexts[c];
        }
    }
    
    int xorQuery(int num) {
        TrieNode* cur = root;
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            int c = (num>>i)&1;
            res <<= 1;
            if (cur->nexts[!c]) {
                res |= 1;
                cur = cur->nexts[!c];
            } else cur = cur->nexts[c];
        }
        return res;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.empty()) return 0;
        root = new TrieNode();
        int res = 0;
        for (int& num : nums) insert(num);
        for (int& num : nums) res = max(res, xorQuery(num));
        return res;
    }
};


// Solution 2 : use std::unordered_set to simulate trie, very skillful
class Solution_2 {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int prefix = 0;
        for (int i = 31; i >= 0; --i) {
            unordered_set<int> s;
            prefix |= (1<<i);
            for (int& num : nums) s.insert(num&prefix);

            int candidate = res | (1<<i);

            // if a^b = c, then a^c = b, b^c = a
            // find if there exists two numbers their xor is candidate
            for (int num : s) {
                if (s.count(num^candidate)) {
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


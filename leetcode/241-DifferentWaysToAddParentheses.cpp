#include <iostream>
#include <string>
#include <vector>
using namespace std;

// the famous 'Add Parentheses' problem
// similar to 095-UniqueBinarySearchTreesII, they are both belong to 'Catalan Number' problem
// these kinds of problem should be naturally be solved recursively

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < (int)input.size(); ++i) {
            char c = input[i];
            if (!isdigit(c)) {
                for (int left : diffWaysToCompute(input.substr(0, i))) {
                    for (int right : diffWaysToCompute(input.substr(i+1))) {
                        res.push_back(c == '+' ? left+right : (c == '-' ? left-right : left*right));
                    }
                }
            }
        }
        return res.empty() ? vector<int>({stoi(input)}) : res;
    }
};

int main() {
    return 0;
}

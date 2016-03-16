#include <iostream>
#include <string>
#include <vector>
using namespace std;

// the famous 'Add Parentheses' problem
// similar to 095-UniqueBinarySearchTreesII, they are both belong to 'Catalan Number' problem
// these kinds of problem should be naturally be solved recursively

vector<int> diffWaysToCompute(string input) {
    vector<int> output;
    int n = input.size();
    for (int i = 0; i < n; ++i) {
        char c = input[i];
        if (c == '+' || c == '-' || c == '*') {
            // Split input string into two parts and solve them recursively
            for (int left : diffWaysToCompute(input.substr(0, i)))
                for (int right : diffWaysToCompute(input.substr(i+1)))
                    output.push_back(c == '+' ? left+right : c == '-' ? left-right : left*right);
        }
    }
    return output.empty() ? vector<int>{stoi(input)} : output; // if the input string contains only number
}

int main() {
    auto r = diffWaysToCompute("2*3-4*5");
    for (auto i:r) cout << i << " "; cout << endl;
    return 0;
}

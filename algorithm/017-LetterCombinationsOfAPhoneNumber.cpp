#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> letterCombinations(string digits) {
    //                       0   1     2      3      4      5      6      7       8      9
    const string phone[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;

    if (digits.size() == 0)
        return result;

    result.push_back("");

    for (int i = 0; i < digits.size(); ++i) {
        int d = digits[i] - '0';
        int m = result.size();
        int n = phone[d].size();

        result.resize(m * n);

        for (int j = 0; j < m; ++j) {
            string s = result[j];
            for (int k = 0; k < n; ++k) {
                string t = s;
                result[j + m * k] = (t += phone[d][k]);
            }
        }
    }
    return result;
}

int main() {
    auto result = letterCombinations("02");
    for (auto i = result.begin(); i != result.end(); ++i) {
        cout << *i << endl;
    }
    return 0;
}

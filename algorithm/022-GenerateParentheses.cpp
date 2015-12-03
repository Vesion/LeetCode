#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// beautiful recursion solution
// should use intermediate storage to save time
vector<string> generateParenthesis(int n) {
    if (n == 0) return vector<string>(1, "");
    if (n == 1) return vector<string>(1, "()");
    vector<string> result;
    for (int i = 0; i < n; ++i) {
        for (auto inner : generateParenthesis(i))
            for (auto outer : generateParenthesis(n - 1- i))
                result.push_back(outer + "(" + inner + ")");
    }
    return result;
}

int main() {
    for (auto s : generateParenthesis(3))
        cout << s << endl;
    return 0;
}

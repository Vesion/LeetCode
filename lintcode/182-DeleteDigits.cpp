#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string DeleteDigits(string A, int k) {
        int n = A.size(), r = n-k;
        string result = "";
        for (int i = 0; i < n; ++i) {
            while (!result.empty() && A[i] < result.back() && result.size()+n-i-1 >= r)
                result.pop_back();
            if (result.size() < r) result.push_back(A[i]);
        }
        int i = 0;
        while (result[i] == '0') ++i;
        return result.substr(i);
    }
};

int main() {
    Solution s;
    cout << s.DeleteDigits("90249", 2) << endl;
    return 0;
}

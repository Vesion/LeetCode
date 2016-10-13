#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        if (n < 0) return {};    
        vector<string> result(n);
        for (int i = 1; i <= n; ++i) {
            if (i%15 == 0) result[i-1] = "FizzBuzz";
            else if (i%3 == 0) result[i-1] = "Fizz";
            else if (i%5 == 0) result[i-1] = "Buzz";
            else result[i-1] = to_string(i);
        }
        return result;
    }
};

int main() {
    Solution s;
    auto r = s.fizzBuzz(15);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

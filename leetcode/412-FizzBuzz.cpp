#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int three = 3, five = 5;
        vector<string> result(n);
        for (int i = 1; i <= n; ++i) {
            if (i != three && i != five) result[i-1] = to_string(i);
            else {
                if (i == three) { result[i-1] += "Fizz"; three += 3; }
                if (i == five) { result[i-1] += "Buzz"; five += 5; }
            }
        }
        return result;
    }
};


int main() {
    Solution s;
    return 0;
}

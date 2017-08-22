#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// count
class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (char& c : word) if ('Z'-c >= 0) ++count;
        return (count == 0) || (count == (int)word.size()) || (count == 1 && 'Z'-word[0] >= 0);
    }
};


int main() {
    return 0;
}

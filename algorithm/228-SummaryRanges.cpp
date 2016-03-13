#include <iostream>
#include <vector>
#include <string>
using namespace std;

void add(vector<string>& result, int start, int end) {
    if (start != end)
        result.push_back(to_string(start) + "->" + to_string(end));
    else
        result.push_back(to_string(end));
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    int n = nums.size();
    if (n == 0) return result;
    int start = nums[0], end = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] == end+1) ++end;
        else {
            add(result, start, end);
            start = end = nums[i];
        }
    }
    add(result, start, end);
    return result;
}

int main() {
    vector<int> nums = {1, 4, 6, 8};
    auto r = summaryRanges(nums);
    for (auto s:r) cout << s << endl;
    return 0;
}

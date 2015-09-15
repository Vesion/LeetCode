#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// common solution
//// nested for-loop: O(n^2) time complexity
//vector<int> twoSum(vector<int>& nums, int target) {
    //vector<int> result;
    //for (vector<int>::size_type i=0; i<nums.size()-1; ++i) {
        //for (vector<int>::size_type j=i+1; j<nums.size(); ++j) {
            //if (nums[i] + nums[j] == target) {
                //result.push_back(i+1);
                //result.push_back(j+1);
            //}
        //} 
    //}
    //return result;
//}

// hash-map solution
// 'key' is number, 'value' is number's position: O(n) time complexity
// Traverse the array once, if map finds target-num[i], the position of target-num[i] and this num are results (the former must be less than the latter), else map this number and its position.
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i=0; i<nums.size(); ++i) {
        if (m.find(target-nums[i]) != m.end())
            return vector<int>{m[target-nums[i]]+1, i+1};
        m[nums[i]] = i;
    }
    return vector<int>();
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout<<twoSum(nums, 11)[0]<<endl;
    cout<<twoSum(nums, 11)[1]<<endl;
    return 0;
}

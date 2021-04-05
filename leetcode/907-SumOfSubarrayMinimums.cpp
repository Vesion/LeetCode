#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;


// mono-increasing stack
class Solution {
public:
    using ll = long long;
    const int kMod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        arr.push_back(-1);
        stack<int> st;
        ll res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int j = st.top(); st.pop();
                int k = st.empty() ? -1 : st.top();
                // for arr[j], we will find in which subarrays it is the minimum number:
                // 1. for numbers from j to i-1, they must be larger than arr[j],
                //    because if a number in this range is smaller than arr[j], j should not be in stack
                // 2. for numbes from k+1 to j, they must be larger than arr[j],
                //    because if a number in this range is smaller than arr[j], they should not be popped out
                res = (res + ll(arr[j])*(i-j)*(j-k)) % kMod;
            }
            st.push(i);
        }
        return res;
    }
};


int main() {

}

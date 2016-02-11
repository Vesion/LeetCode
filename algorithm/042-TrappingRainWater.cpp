#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// solution1: use a stack to store bars
//      if current bar is smaller than top one, push it
//      else solve all bars which are greater than or equal to current bar, and pop them
// O(n) O(n)
int trap_stack(vector<int>& height) {
    if (height.size() == 0)
        return 0;
    stack<int> bars; // store index, not real height
    int water = 0;
    for (int i = 0; i < height.size(); ++i) {
        int bottom = 0;
        while (!bars.empty()) {
            int left_pos = bars.top();
            int left = height[left_pos];
            int right_pos = i;
            int right = height[i];

            water += (min(left, right) - bottom) * (right_pos - left_pos - 1);
            //  __    __
            // |  |  |  |
            // |  |__|  |
            // |________| height
            //  ^      ^
            // left   right
            cout << "i " << i << " water " << water << endl;
            
            bottom = left;
            if (height[i] >= left)
                bars.pop();
            else
                break; // if height[i] is smaller than bars's top, ignore and stop solve
        }
        bars.push(i);
    }
    return water;
}

// solution2: get current bar's max left bar and max right bar
//      each bar can hold min(maxleft, maxright)-bar water
//      accumulate each bar's water
// O(n) O(n)
int trap_leftright(vector<int>& height) {
    if (height.size() == 0)
        return 0;
    int n = height.size();
    int water = 0;
    vector<int> max_left(n, 0);
    vector<int> max_right(n, 0);

    for (int i = 1; i < n; ++i) {
        max_left[i] = max(max_left[i-1], height[i-1]);
        max_right[n-i-1] = max(max_right[n-i], height[n-i]);
    }

    for (int i = 0; i < n; ++i) {
        int bar = min(max_left[i], max_right[i]);
        if (bar > height[i])
            water += bar - height[i];
    }

    return water;
}

// solution3: firstly find the highest bar
//      then divide all bars into two pars with the highest bar
//      calculate two parts' water repectively
// O(n) O(1)
// this solution is very skillful
int trap_twoparts(vector<int>& height) {
    if (height.size() == 0)
        return 0;
    int water = 0;
    int top = 0;
    for (int i = 0; i < height.size(); ++i) {
        if (height[i] > height[top])
            top = i;
    }

    for (int i = 0, peak = 0; i < top; ++i) {
        if (peak < height[i]) {
            peak = height[i];
        } else {
            water += (peak - height[i]);
        }
    }
    for (int i = height.size() - 1, peak = 0; i > top; --i) {
        if (peak < height[i]) {
            peak = height[i];
        } else {
            water += (peak - height[i]);
        }
    }

    return water;
}

int main() {
    vector<int> a({4, 3, 4, 5, 6, 4, 2});
    cout << trap_twoparts(a) << endl;
    return 0;
}
